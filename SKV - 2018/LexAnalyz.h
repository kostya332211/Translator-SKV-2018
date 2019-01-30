#pragma once
#include "LT.h"
#include "FST.h"
#include "Log.h"
namespace LexAnalyz {
	void LexCheck(char *str, int& count_lines, int& i, LT::LexTable& lextable, LT::Entry& lt_entry, IT::IdTable& idtable, IT::Entry& it_entry);
};