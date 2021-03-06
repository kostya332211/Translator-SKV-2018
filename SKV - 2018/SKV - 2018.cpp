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
#pragma warning (disable:4996)
//#define TEST_ERROR
//#define TEST_PARM
//#define TEST_IN
#define TEST_LOG



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	bool error = false;
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::GetLog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		LT::LexTable lextable = LT::Create(999);
		IT::IdTable idtable = IT::Create(999);
		In::IN in = In::getin(parm.in, parm.log, parm.syn, lextable, idtable);
		
	}
	catch (Error::ERROR e)
	{
		cout  <<"Ошибка "<<e.id<<" : "<< e.message << endl;
		if (e.id < 100 && e.id > 103) {
			Log::WriteError(log, e);
		}
		error = true;
	}
	catch (...) {
		cout << "ss";
	}
	if (error ==false)
	std::cout << "Исходный код успешно транслирован в ассемблерный файл" << endl;
    return 0;
}


