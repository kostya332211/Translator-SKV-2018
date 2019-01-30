#pragma once

#define PARM_MAX_SIZE	300
#include "MFST.h"


namespace Parm {
	const wchar_t parm_in[] = L"-in:";
	const wchar_t parm_out[] = L"-out:";
	const wchar_t parm_log[] = L"-log:";
	const wchar_t parm_out_default_ext[] = L".out";
	const wchar_t parm_syn_default_ext[] = L".syn";
	const wchar_t parm_log_default_ext[] = L".log";

	struct PARM
	{

		wchar_t in[PARM_MAX_SIZE];
		wchar_t out[PARM_MAX_SIZE];
		wchar_t log[PARM_MAX_SIZE];
		wchar_t syn[PARM_MAX_SIZE];

	};
	PARM getparm(int argc, _TCHAR* argv[]);
};