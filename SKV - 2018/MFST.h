#pragma once
using namespace std;
#include "LT.h"
#include "Greibach.h"
#include "Parm.h"
#define MFST_TRACE_START	setw(4) << left << "Шаг:"\
							<< setw(20) << left << " Правило" \
							<< setw(30) << left << " Входная лента" \
							<< setw(20) << left << " Стек" << endl;
#define MFST_TRACE1	 setw(4) << left << ++FST_TRACE_n << ": "\
					<< setw(20) << left << rule.getCRule(rbuf, nrulechain)\
					<< setw(30) << left << getCLenta(lbuf, lenta_position)\
					<< setw(20) << left << getCSt(sbuf) << endl; 
#define MFST_TRACE2	setw(4) << left << FST_TRACE_n << ": "\
					<< setw(20) << left << " "\
					<< setw(30) << left << getCLenta(lbuf, lenta_position)\
					<< setw(20) << left << getCSt(sbuf) << endl;
#define MFST_TRACE3	 setw(4) << left << ++FST_TRACE_n << ": "\
					<< setw(20) << left << " "\
					<< setw(30) << left << getCLenta(lbuf, lenta_position)\
					<< setw(20) << left << getCSt(sbuf) << endl;
#define MFST_TRACE4(c)	 setw(4) << left << ++FST_TRACE_n << ": " << setw(20) << left << c << endl;
#define MFST_TRACE5(c)	setw(4) << left << FST_TRACE_n << ": " << setw(20) << left << c << endl;
#define MFST_TRACE6(c, k)	 setw(4) << left << FST_TRACE_n << ": " << setw(20) << left << c << k << endl;
#define MFST_TRACE7	 setw(4) << left << state.lenta_position<< ": "\
					<< setw(20) << left << rule.getCRule(rbuf, state.nrulechain) << endl;
#define MFST_DIAGN_MAXSIZE	2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER	3
#include <stack>
typedef std::stack<short>	MFSTSTSTACK;			// Стек автомата

namespace MFST
{
	struct MfstState
	{
		short lenta_position;
		short nrule;
		short nrulechain;
		MFSTSTSTACK st;
		MfstState();
		MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain);
		MfstState(short pposition, MFSTSTSTACK pst, short pnrule, short pnrulechain);
	};

	struct Mfst
	{
		enum RC_STEP
		{
			NS_OK,
			NS_NORULE,
			NS_NORULECHAIN,
			NS_ERROR,
			TS_OK,
			TS_NOK,
			LENTA_END,
			SURPRISE
		};

		struct MfstDiagnosis
		{
			short lenta_position;
			RC_STEP rc_step;
			short nrule;
			short nrule_chain;
			MfstDiagnosis();
			MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain);
		} diagnosis[MFST_DIAGN_NUMBER];

		GRBALPHABET* lenta;
		short lenta_position;
		short nrule;
		short nrulechain;
		short lenta_size;
		GRB::Greibach grebach;
		LT::LexTable lexTable;
		MFSTSTSTACK st;
		std::stack<MfstState> storestate;

		Mfst();
		Mfst(LT::LexTable plex, GRB::Greibach pgrebach);
		char* getCSt(char* buf);
		char* getCLenta(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool savestate(wchar_t synfile[]);
		bool reststate(wchar_t synfile[]);
		bool push_chain(GRB::Rule::Chain chain);
		RC_STEP step(wchar_t synfile[]);
		bool start(wchar_t outfile[], wchar_t synfile[]);
		bool savediagnosis(RC_STEP pprc_step);
		void printrules(wchar_t synfile[]);

		struct Deducation
		{
			short size;
			short* nrules;
			short* nrulechains;
			Deducation() { size = 0; nrules = 0; nrulechains = 0; }
		} deducation;

		bool savededucation();
	};
}