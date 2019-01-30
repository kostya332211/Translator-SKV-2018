#pragma once
#include "LT.h"
#include "IT.h"
#include <string>
#include <cstring>

namespace CodeGeneration {
	void CodeGeneration(wchar_t out_asm[], LT::LexTable lextable, IT::IdTable idtable);
	bool CheckId(std::string a, IT::IdTable idtable);
	bool CheckStr(std::string a, IT::IdTable idtable);
	bool CheckInt(std::string a, IT::IdTable idtable);
	bool IsNum(std::string a);
}