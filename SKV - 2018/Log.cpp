#include "stdafx.h"
#include "Log.h"
#include "Error.h"
#include "In.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;

namespace Log
{
	LOG GetLog(wchar_t logfile[])
	{
		LOG log;
		wcscpy_s(log.logfile, logfile);
		ofstream *FILE = new ofstream;
		(*FILE).open(logfile);
		if (!(*FILE).is_open()){
			 ERROR_THROW(102);
		}
		log.stream = FILE;
		
		return log;
	}
	LOG GetSyn(wchar_t logfile[])
	{
		LOG syn;
		wcscpy_s(syn.logfile, logfile);
		ofstream *FILE1 = new ofstream;
		(*FILE1).open(logfile);
		if (!(*FILE1).is_open()) {
			ERROR_THROW(103);
		}
		syn.stream = FILE1;

		return syn;
	}

	void WriteLine(LOG log, char* txt, ...)
	{
		char** ptxt = &txt;
		char buf[PARM_MAX_SIZE];
		strcpy_s(buf, txt);
		*ptxt++;
		for (; (strcmp(*ptxt, "") != 0); *ptxt++)
			strcat_s(buf, *ptxt);
		*log.stream << buf << endl;

	}

	void WriteLine(LOG log, wchar_t* txt, ...)
	{
		wchar_t** ptxt = &txt;
		wchar_t buf[PARM_MAX_SIZE];
		char chBuf[PARM_MAX_SIZE];
		wcscpy_s(buf, txt);
		*ptxt++;
		for (; (wcscmp(*ptxt, L"") != 0); *ptxt++)
			wcscat_s(buf, *ptxt);
		wcstombs(chBuf, buf, PARM_MAX_SIZE);
		*log.stream << chBuf << endl;
	}

	
	void WriteLog(LOG log)
	{
		char Date[50];
		struct tm *date;
		const time_t timer = time(NULL);
		date = localtime(&timer);
		strftime(Date, 50, "%d.%m.%Y %H:%M:%S, %A", date);
		*log.stream << "----Протокол----" << "\t";
		*log.stream << "Дата: " << Date << endl;

	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char in[PARM_MAX_SIZE], out[PARM_MAX_SIZE], logf[PARM_MAX_SIZE];
		wcstombs(in, parm.in, PARM_MAX_SIZE);
		wcstombs(out, parm.out, PARM_MAX_SIZE);
		wcstombs(logf, parm.log, PARM_MAX_SIZE);
		*log.stream << "----Параметры----" << endl;
		*log.stream << "-log: " << logf << endl;
		*log.stream << "-out: " << out << endl;
		*log.stream << "-in: " << in << endl << endl;
		log.stream->close();
	}

	void WriteIn(LOG log, In::IN in)
	{
		
		*log.stream << "----Исходные данные----" << endl;
		*log.stream << "Количество символов: " << in.size << endl;
		*log.stream << "Количество строк: " << in.lines + 1 <<endl;
		*log.stream << "Проигнорировано: " << in.ignore<<endl;
	}
	
	void WriteError(LOG log, Error::ERROR e)
	{
		*log.stream << "Ошибка " << e.id << ": " << e.message << "  Строка: " << e.inext.line + 1 << ", символ: " << e.inext.col << endl;
	}

	void WriteErrorOUT(wchar_t outfile[], Error::ERROR e)
	{
		ofstream fout;
		fout.open(outfile);
		fout << "Ошибка " << e.id << ": " << e.message << "  Строка: " << e.inext.line + 1 << ", символ: " << e.inext.col << endl;
		fout.close();
	}

	void Close(LOG log)
	{
		(*log.stream).close();

	}
};