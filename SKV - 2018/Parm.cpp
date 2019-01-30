#include "stdafx.h"
#include "Error.h"
#include <iostream>
#include "Parm.h"

extern int flag_in;
using namespace std;
namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		bool in = false, out = false, log = false, syn = false;
		PARM par;
		wchar_t *buf;
		for (int i = 1; i < argc; i++)
		{
			if (wcslen(argv[i]) >= PARM_MAX_SIZE)
			{
				ERROR_THROW(101);
			}
			if (buf = wcsstr(argv[i], parm_in))
			{
				wcscpy_s(par.in, buf + wcslen(parm_in));
				in = true;
			}
			if (buf = wcsstr(argv[i], parm_out))
			{
				wcscpy_s(par.out, buf + wcslen(parm_out));
				out = true;
			}
			if (buf = wcsstr(argv[i], parm_log))
			{
				wcscpy_s(par.log, buf + wcslen(parm_log));
				log = true;
			}
		
		}
		if (in == false)
		{
			 ERROR_THROW(100);
		}
		if (out == false)
		{
			wcscpy_s(par.out, par.in);
			wcsncat_s(par.out, parm_out_default_ext, wcslen(parm_out_default_ext));
		}
		if (log == false)
		{
			wcscpy_s(par.log, par.in);
			wcsncat_s(par.log, parm_log_default_ext, wcslen(parm_log_default_ext));
		}
		if (syn == false)
		{
			wcscpy_s(par.syn, par.in);
			wcsncat_s(par.syn, parm_syn_default_ext, wcslen(parm_syn_default_ext));
		}
		
		return par;
	}
};