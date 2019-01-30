#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
#include <iomanip>
#include <string>
namespace Log {
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream *stream;
	};
	static const LOG INITLOG = { L"",NULL };
	LOG GetLog(wchar_t logfile[]);
	LOG GetSyn(wchar_t logfile[]);
	void WriteLine(LOG log, char *txt, ...);
	void WriteLine(LOG log, wchar_t *txt, ...);
	void WriteLog(LOG log);
	void WriteParm(LOG log, Parm::PARM parm);
	void WriteIn(LOG log, In::IN in);
	void WriteError(LOG log, Error::ERROR e);
	void WriteErrorOUT(wchar_t outfile[], Error::ERROR e);
	void Close(LOG log);
};
