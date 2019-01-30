
#include "stdafx.h"
#include <iostream>
#include <locale>
#include <ctime>
#include <stdio.h>
#include <cwchar>
#include <fstream>
#include <iomanip>
#include <string>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include "MFST.h"
#include "Greibach.h"

using namespace std;
int FST_TRACE_n = -1;
char rbuf[205], sbuf[205], lbuf[1024];
namespace MFST
{
	MfstState::MfstState()
	{
		lenta_position = 0;
		nrule = -1;
		nrulechain = -1;
	}
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain)
	{
		lenta_position = pposition;
		st = pst;
		nrulechain = pnrulechain;
	}
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrule, short pnrulechain)
	{
		lenta_position = pposition;
		st = pst;
		nrule = pnrule;
		nrulechain = pnrulechain;
	}

	Mfst::MfstDiagnosis::MfstDiagnosis()
	{
		lenta_position = -1;
		rc_step = SURPRISE;
		nrule = -1;
		nrule_chain = -1;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain)
	{
		lenta_position = plenta_position;
		rc_step = prc_step;
		nrule = pnrule;
		nrule_chain = pnrule_chain;
	}

	Mfst::Mfst()
	{
		lenta = 0;
		lenta_size = lenta_position = 0;
	}
	Mfst::Mfst(LT::LexTable plex, GRB::Greibach pgrebach)
	{
		grebach = pgrebach;
		lexTable = plex;
		lenta = new short[lenta_size = lexTable.size];
		for (int i = 0; i < lenta_size; i++)
			lenta[i] = TS(lexTable.table[i].lexema[0]);
		lenta_position = 0;
		st.push(grebach.stbottomT);
		st.push(grebach.startN);
		nrulechain = -1;
	}


	Mfst::RC_STEP Mfst::step(wchar_t synfile[])
	{
		ofstream syn;
		syn.open(synfile, std::ios::app); //запись в конец
		RC_STEP rc = SURPRISE;
		if (lenta_position < lenta_size)
		{
			st.top() = abs(st.top());
			if (st.top() > 64 && st.top() < 91) {
				st.top() = -st.top();
			}


			if (ISNS(st.top()))    //если нетерминальный символ      -Нетерминал +Терминал
			{
				GRB::Rule rule;
				if ((nrule = GRB::getGreibach().getRule(st.top(), rule)) >= 0)   // 0 , 1 , 2 , ... 
				{
					GRB::Rule::Chain chain;
					if ((nrulechain = rule.getNextChain(lenta[lenta_position], chain, nrulechain + 1)) >= 0)  //если получили правило
					{
						syn<<MFST_TRACE1
						savestate(synfile);
						st.pop();
						push_chain(chain);
						rc = NS_OK;
						syn<<MFST_TRACE2
					}
					else
					{
						syn<<MFST_TRACE4("TNS_NORULECHAIN/NS_NORULE")
							savediagnosis(NS_NORULECHAIN);
						rc = reststate(synfile) ? NS_NORULECHAIN : NS_NORULE;
					}
				}
				else
					rc = NS_ERROR;
			}
			else if ((st.top() == lenta[lenta_position]))   //если сиволы совпали
			{
				lenta_position++;
				st.pop();
				nrulechain = -1;
				rc = TS_OK;
				syn<<MFST_TRACE3
			}
			else
			{
				syn<<MFST_TRACE4("TS_NOK/NS_NORULECHAIN")
					rc = reststate(synfile) ? TS_NOK : NS_NORULECHAIN;
			}
		}
		else
		{
			rc = LENTA_END;
			syn<<MFST_TRACE4("LENTA_END")
		}
		return rc;
	}

	bool Mfst::push_chain(GRB::Rule::Chain chain)
	{
		for (int i = chain.size - 1; i >= 0; i--)
			st.push(chain.nt[i]);
		return true;
	}
	bool Mfst::savestate(wchar_t synfile[])
	{
		ofstream syn;
		syn.open(synfile, std::ios::app); //запись в конец

		storestate.push(MfstState(lenta_position, st, nrule, nrulechain));
		syn<<MFST_TRACE6("SAVESTATE:", storestate.size());
		return true;
	}
	bool Mfst::reststate(wchar_t synfile[])
	{
		ofstream syn;
		syn.open(synfile, std::ios::app); //запись в конец

		bool rc = false;
		MfstState state;
		if (rc = (storestate.size() > 0))
		{
			state = storestate.top();
			lenta_position = state.lenta_position;
			st = state.st;
			nrule = state.nrule;
			nrulechain = state.nrulechain;
			storestate.pop();
			syn<<MFST_TRACE5("RESSTATE")
				syn<<MFST_TRACE2
		}
		return rc;
	}
	bool Mfst::savediagnosis(RC_STEP prc_step)
	{
		bool rc = false;
		short k = 0;
		while (k < MFST_DIAGN_NUMBER && lenta_position <= diagnosis[k].lenta_position)
			k++;
		if (rc = (k < MFST_DIAGN_NUMBER))
		{
			diagnosis[k] = MfstDiagnosis(lenta_position, prc_step, nrule, nrulechain);
			for (short j = k + 1; j < MFST_DIAGN_NUMBER; j++)
				diagnosis[j].lenta_position = -1;
		}
		return rc;
	}
	bool Mfst::start(wchar_t outfile[], wchar_t synfile[])
	{
		ofstream fout;
		fout.open(outfile, std::ios::app); //запись в конец
		ofstream syn;
		syn.open(synfile, std::ios::app); //запись в конец
		bool rc = false;
		RC_STEP rc_step = SURPRISE;
		char buf[MFST_DIAGN_MAXSIZE];
		rc_step = step(synfile);
		while (rc_step == NS_OK || rc_step == NS_NORULECHAIN || rc_step == TS_OK || rc_step == TS_NOK)  // пока всё збс
			rc_step = step(synfile);

		switch (rc_step)
		{
		case NS_NORULE:
			syn<<MFST_TRACE4("-------> NS_NORULE")
				syn << "--------------------------------------------------------------" << endl;
			//cout << getDiagnosis(0, buf) << endl;
			//cout << buf;
			fout << getDiagnosis(0, buf) << endl;
			//cout << getDiagnosis(1, buf) << endl;
		
			//getDiagnosis(1, buf);
			//getDiagnosis(2, buf);
			break;
		case NS_NORULECHAIN:
			syn<<MFST_TRACE4("------> NS_NORULECHAIN")
				break;
		case NS_ERROR:
			syn << getDiagnosis(0, buf) << endl;
			syn << getDiagnosis(1, buf) << endl;
			//cout << getDiagnosis(1, buf) << endl;
			
			syn << MFST_TRACE4("------> NS_ERROR")
				break;
		case LENTA_END:
			syn<< MFST_TRACE4("-------> NS_LENTA_END")
			   
				syn << "--------------------------------------------------------------" << endl;
			sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d: всего лексем %d, синтаксический анализ выполнен без ошибок", 0, lenta_size);
			syn << setw(4) << left << ": всего лексем " << lenta_size << ", синтаксический анализ выполнен без ошибок" << endl;
			rc = true;
			fout << setw(4) << left << ": всего лексем " << lenta_size << ", синтаксический анализ выполнен без ошибок" << endl;
			fout.close();
			break;
		case SURPRISE:
			syn<< MFST_TRACE4("------> SURPRISE")
				break;
		}
		return rc;
	}


	char* Mfst::getCSt(char* buf)
	{
		for (int i = (signed)st.size() - 1; i >= 0; --i)
		{
			short p = st._Get_container()[i];
			buf[st.size() - 1 - i] = GRB::Rule::Chain::alphabet_to_char(p);
		}
		buf[st.size()] = 0x00;
		return buf;
	}
	char* Mfst::getCLenta(char* buf, short pos, short n)
	{
		short i, k = (pos + n < lenta_size) ? pos + n : lenta_size;
		for (i = pos; i < k; i++)
			buf[i - pos] = GRB::Rule::Chain::alphabet_to_char(lenta[i]);
		buf[i - pos] = 0x00;
		return buf;
	}
	char* Mfst::getDiagnosis(short n, char* buf)
	{
		char* rc = { 0 };
		int errid = 0;
		int lpos = -1;
		if (n < MFST_DIAGN_NUMBER && (lpos = diagnosis[n].lenta_position) >= 0)
		{
			errid = grebach.getRule(diagnosis[n].nrule).iderror;
			Error::ERROR err = Error::geterror(errid);
			sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d: строка %d, %s", err.id, lexTable.table[lpos].sn, err.message);
			rc = buf;
			//cout << err.id ;
			ERROR_THROW_IN(err.id, lexTable.table[lpos].sn + 1,0);
		}
		return rc;
	}

	void Mfst::printrules(wchar_t synfile[])
	{
		ofstream syn;
		syn.open(synfile, std::ios::app); //запись в конец

		MfstState state;
		GRB::Rule rule;
		for (unsigned short i = 0; i < storestate.size(); i++)
		{
			state = storestate._Get_container()[i];
			rule = grebach.getRule(state.nrule);
			syn<<MFST_TRACE7
		}
	}

	bool Mfst::savededucation()
	{
		MfstState state;
		GRB::Rule rule;
		deducation.nrules = new short[deducation.size = storestate.size()];
		deducation.nrulechains = new short[deducation.size];
		for (unsigned short i = 0; i < storestate.size(); i++)
		{
			state = storestate._Get_container()[i];
			deducation.nrules[i] = state.nrule;
			deducation.nrulechains[i] = state.nrulechain;
		}
		return true;
	}
}