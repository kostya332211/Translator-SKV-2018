#include "stdafx.h"
#include "Error.h"
#include "IT.h"
#include <iostream>
#include <string>

using namespace IT;

IdTable IT::Create(int size) {
	if (size >= TI_MAXSIZE)
		ERROR_THROW(114);
	IdTable itable = { size, 0, new Entry[size] };
	return itable;
}

void IT::Add(IdTable& idtable, Entry entry) {
	if (idtable.size <= idtable.maxsize) {
		idtable.table[idtable.size] = entry;
		idtable.size++;
	}
	else
		ERROR_THROW(2);
}

Entry IT::GetEntry(IdTable& idtable, int n) {
	return idtable.table[n];
}

//int IT::IsId(IdTable& idtable, char id[ID_MAXSIZE], int ii) {
//	bool flag = false;
//	for (int i = 0; i < idtable.size; i++)
//	{
//		flag = false;
//		for (int j = 0; j < ID_MAXSIZE; j++)
//			if (idtable.table[i].id[j] != id[j]) {
//				flag = true;
//				break;
//			}
//		if (flag == false)
//			return i;
//	}
//	return TI_NULLIDX;
//}


int IT::IsId(IdTable& idtable, char id[ID_MAXSIZE]) {
	bool flag = false;
	for (int i = idtable.size - 1; i > -1; i--)
	{
		flag = false;
		for (int j = 0; j < ID_MAXSIZE; j++)
			if (idtable.table[i].id[j] != id[j]) {
				flag = true;
				break;
			}
		if (flag == false)
			return i;
	}
	return TI_NULLIDX;
}

int IT::IsId1(IdTable& idtable, Entry& it_entry) {
	for (int i = idtable.size - 1; i > -1; i--)
	{
		if (it_entry.iddatatype == IT::STR) {
			if (strcmp(idtable.table[i].value.vstr->str, it_entry.value.vstr->str) == 0)
				return i;
		}
		if (it_entry.iddatatype == IT::INT) {
			if (idtable.table[i].value.vint == it_entry.value.vint)
				return i;
		}

	}
	return TI_NULLIDX;
}

void IT::Delete(IdTable& idtable) {
	delete idtable.table;
	idtable.size = 0;
	idtable.maxsize = 0;
}