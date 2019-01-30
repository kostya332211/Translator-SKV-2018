#pragma once
#define ID_MAXSIZE 5
#define ID_STAND_FUNCTION 15
#define TI_MAXSIZE 4096
#define TI_INT_DEFAULT 0x00000000
#define TI_STR_DEFAULT 0x00
#define TI_NULLIDX 0xffffffff
#define TI_STR_MAXSIZE 255


namespace IT {
	enum IDDATATYPE { INT = 1, STR = 2, NAN_VAR = 3 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, F_S = 5, EXPRESSION = 6, CALLFUNC = 7, ECALLFUNC = 8};

	struct Entry {
		int idxfirstLE;
		char vision[300];
		int sn;
		char id[300];
		IDDATATYPE iddatatype;
		IDTYPE idtype;
		union {
			int vint;
			struct {
				
				char len;
				char str[TI_STR_MAXSIZE - 1];
			} vstr[TI_STR_MAXSIZE];
		} value;
		bool was = false;
	};

	struct IdTable {
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsId(IdTable& idtable, char id[ID_MAXSIZE]);
	int IsId1(IdTable& idtable, Entry& it_entry);
	void Delete(IdTable& idtable);
};