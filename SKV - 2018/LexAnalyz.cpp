#include "stdafx.h"
#include "LexAnalyz.h"
#include "FST.h"
#define ARR 2



#define GRAF_MAIN 5, \
FST::NODE(1, FST::RELATION('m', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('i', 3)), \
FST::NODE(1, FST::RELATION('n', 4)), \
FST::NODE() \

#define STRLEN 7, \
FST::NODE(1, FST::RELATION('d', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE(1, FST::RELATION('e', 5)), \
FST::NODE(1, FST::RELATION('n', 6)), \
FST::NODE() \

#define SUBSTR 7, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('b', 3)), \
FST::NODE(1, FST::RELATION('d', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('r', 6)), \
FST::NODE() \

#define GRAF_RETURN 7, \
FST::NODE(1, FST::RELATION('r', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('u', 4)), \
FST::NODE(1, FST::RELATION('r', 5)), \
FST::NODE(1, FST::RELATION('n', 6)), \
FST::NODE() \

#define GRAF_PRINT 6, \
FST::NODE(1, FST::RELATION('p', 1)), \
FST::NODE(1, FST::RELATION('r', 2)), \
FST::NODE(1, FST::RELATION('i', 3)), \
FST::NODE(1, FST::RELATION('n', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE() \

#define GRAF_FUNCTION 9, \
FST::NODE(1, FST::RELATION('f', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE(1, FST::RELATION('c', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('i', 6)), \
FST::NODE(1, FST::RELATION('o', 7)), \
FST::NODE(1, FST::RELATION('n', 8)), \
FST::NODE() \

#define GRAF_DECLARE 8, \
FST::NODE(1, FST::RELATION('d', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('c', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE(1, FST::RELATION('a', 5)), \
FST::NODE(1, FST::RELATION('r', 6)), \
FST::NODE(1, FST::RELATION('e', 7)), \
FST::NODE() \

#define GRAF_STRING 7, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('i', 4)), \
FST::NODE(1, FST::RELATION('n', 5)), \
FST::NODE(1, FST::RELATION('g', 6)), \
FST::NODE() \

#define GRAF_INTEGER 8, \
FST::NODE(1, FST::RELATION('i', 1)), \
FST::NODE(1, FST::RELATION('n', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('e', 4)), \
FST::NODE(1, FST::RELATION('g', 5)), \
FST::NODE(1, FST::RELATION('e', 6)), \
FST::NODE(1, FST::RELATION('r', 7)), \
FST::NODE() \

#define GRAF_ID 3, \
FST::NODE(104, FST::RELATION('q', 1), FST::RELATION('w', 1), FST::RELATION('e', 1)  \
, FST::RELATION('r', 1), FST::RELATION('t', 1), FST::RELATION('y', 1), FST::RELATION('u', 1) \
, FST::RELATION('i', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('a', 1) \
, FST::RELATION('s', 1), FST::RELATION('d', 1), FST::RELATION('f', 1), FST::RELATION('g', 1) \
, FST::RELATION('h', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1) \
, FST::RELATION('z', 1), FST::RELATION('x', 1), FST::RELATION('c', 1), FST::RELATION('v', 1) \
, FST::RELATION('b', 1), FST::RELATION('n', 1), FST::RELATION('m', 1) \
, FST::RELATION('Q', 1), FST::RELATION('W', 1), FST::RELATION('E', 1) \
, FST::RELATION('R', 1), FST::RELATION('T', 1), FST::RELATION('Y', 1), FST::RELATION('U', 1) \
, FST::RELATION('I', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('A', 1) \
, FST::RELATION('S', 1), FST::RELATION('D', 1), FST::RELATION('F', 1), FST::RELATION('G', 1) \
, FST::RELATION('H', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1) \
, FST::RELATION('Z', 1), FST::RELATION('X', 1), FST::RELATION('C', 1), FST::RELATION('V', 1) \
, FST::RELATION('B', 1), FST::RELATION('N', 1), FST::RELATION('M', 1) \
, FST::RELATION('q', 2), FST::RELATION('w', 2), FST::RELATION('e', 2)  \
, FST::RELATION('r', 2), FST::RELATION('t', 2), FST::RELATION('y', 2), FST::RELATION('u', 2) \
, FST::RELATION('i', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('a', 2) \
, FST::RELATION('s', 2), FST::RELATION('d', 2), FST::RELATION('f', 2), FST::RELATION('g', 2) \
, FST::RELATION('h', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2) \
, FST::RELATION('z', 2), FST::RELATION('x', 2), FST::RELATION('c', 2), FST::RELATION('v', 2) \
, FST::RELATION('b', 2), FST::RELATION('n', 2), FST::RELATION('m', 2) \
, FST::RELATION('Q', 2), FST::RELATION('W', 2), FST::RELATION('E', 2) \
, FST::RELATION('R', 2), FST::RELATION('T', 2), FST::RELATION('Y', 2), FST::RELATION('U', 2) \
, FST::RELATION('I', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('A', 2) \
, FST::RELATION('S', 2), FST::RELATION('D', 2), FST::RELATION('F', 2), FST::RELATION('G', 2) \
, FST::RELATION('H', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2) \
, FST::RELATION('Z', 2), FST::RELATION('X', 2), FST::RELATION('C', 2), FST::RELATION('V', 2) \
, FST::RELATION('B', 2), FST::RELATION('N',2), FST::RELATION('M', 2)), \
FST::NODE(124, FST::RELATION('q', 1), FST::RELATION('w', 1), FST::RELATION('e', 1)  \
, FST::RELATION('r', 1), FST::RELATION('t', 1), FST::RELATION('y', 1), FST::RELATION('u', 1) \
, FST::RELATION('i', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('a', 1) \
, FST::RELATION('s', 1), FST::RELATION('d', 1), FST::RELATION('f', 1), FST::RELATION('g', 1) \
, FST::RELATION('h', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1) \
, FST::RELATION('z', 1), FST::RELATION('x', 1), FST::RELATION('c', 1), FST::RELATION('v', 1) \
, FST::RELATION('b', 1), FST::RELATION('n', 1), FST::RELATION('m', 1), FST::RELATION('9', 1) \
, FST::RELATION('Q', 1), FST::RELATION('W', 1), FST::RELATION('E', 1), FST::RELATION('E', 2) \
, FST::RELATION('R', 1), FST::RELATION('T', 1), FST::RELATION('Y', 1), FST::RELATION('U', 1) \
, FST::RELATION('I', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('A', 1) \
, FST::RELATION('S', 1), FST::RELATION('D', 1), FST::RELATION('F', 1), FST::RELATION('G', 1) \
, FST::RELATION('H', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1) \
, FST::RELATION('Z', 1), FST::RELATION('X', 1), FST::RELATION('C', 1), FST::RELATION('V', 1) \
, FST::RELATION('B', 1), FST::RELATION('N', 1), FST::RELATION('M', 1), FST::RELATION('0', 1) \
, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1) \
, FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1) \
, FST::RELATION('r', 2), FST::RELATION('t', 2), FST::RELATION('y', 2), FST::RELATION('u', 2) \
, FST::RELATION('i', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('a', 2) \
, FST::RELATION('s', 2), FST::RELATION('d', 2), FST::RELATION('f', 2), FST::RELATION('g', 2) \
, FST::RELATION('h', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2) \
, FST::RELATION('z', 2), FST::RELATION('x', 2), FST::RELATION('c', 2), FST::RELATION('v', 2) \
, FST::RELATION('b', 2), FST::RELATION('n', 2), FST::RELATION('m', 2), FST::RELATION('Q', 1) \
, FST::RELATION('q', 2), FST::RELATION('w', 2), FST::RELATION('e', 2), FST::RELATION('W', 2) \
, FST::RELATION('R', 2), FST::RELATION('T', 2), FST::RELATION('Y', 2), FST::RELATION('U', 2) \
, FST::RELATION('I', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('A', 2) \
, FST::RELATION('S', 2), FST::RELATION('D', 2), FST::RELATION('F', 2), FST::RELATION('G', 2) \
, FST::RELATION('H', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2) \
, FST::RELATION('Z', 2), FST::RELATION('X', 2), FST::RELATION('C', 2), FST::RELATION('V', 2) \
, FST::RELATION('B', 2), FST::RELATION('N', 2), FST::RELATION('M', 2), FST::RELATION('0', 2) \
, FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2) \
, FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)), \
FST::NODE() 



void LexAnalyz::LexCheck(char * str, int & count_lines, int & i, LT::LexTable & lextable, LT::Entry & lt_entry, IT::IdTable & idtable, IT::Entry & it_entry)
{
	using namespace FST;
	using namespace std;
	bool first = true;
	int  lexshet = 0;
	std::string arr[ARR] = { "strlen","substr" };
	
	//FST
/*	if (execute(fst = ::FST(str, GRAF_DECLARE)) == true) {
		lt_entry.lexema[0] = LEX_DECLARE;
		it_entry.idtype = IT::V;
	}
	else if (execute(fst = Fst(str, GRAF_MAIN)) == true)
		lt_entry.lexema[0] = LEX_MAIN;
	else if (execute(fst = Fst(str, fstPrint)) == true)
		lt_entry.lexema[0] = LEX_PRINT;
	else if (execute(fst = Fst(str, fstReturn)) == true)
		lt_entry.lexema[0] = LEX_RETURN;
	else if (execute(fst = Fst(str, fstSlash)) == true) {
		lt_entry.vvalue = str[0];
		lt_entry.lexema[0] = LEX_DIRSLASH;
	}
	else if (execute(fst = Fst(str, fstLeftBrace)) == true)
		lt_entry.lexema[0] = LEX_LEFTBRACE;
	else if (execute(fst = Fst(str, fstRightBrace)) == true)
		lt_entry.lexema[0] = LEX_BRACELET;
	else if (execute(fst = Fst(str, fstLeftThesis)) == true) {
		if (it_entry.idtype == IT::F)
			it_entry.idtype = IT::P;
		lt_entry.lexema[0] = LEX_LEFTHESIS;
	}
	else if (execute(fst = Fst(str, fstRightThesis)) == true) {
		it_entry.idtype = (IT::IDTYPE) - 1;
		lt_entry.lexema[0] = LEX_RIGHTHESIS;
	}
	else if (execute(fst = Fst(str, fstRAVNO)) == true)
		lt_entry.lexema[0] = LEX_ROVNO;
	else if (execute(fst = Fst(str, fstComma)) == true)
		lt_entry.lexema[0] = LEX_COMMA;
	else if (execute(fst = Fst(str, fstPlus)) == true) {
		lt_entry.vvalue = str[0];
		lt_entry.lexema[0] = LEX_PLUS;
	}
	else if (execute(fst = Fst(str, fstMinus)) == true) {
		lt_entry.vvalue = str[0];
		lt_entry.lexema[0] = LEX_MINUS;
	}
	else if (execute(fst = Fst(str, fstSemiColon)) == true)
		lt_entry.lexema[0] = LEX_SEMICOLON;
	else if (execute(fst = Fst(str, fstStar)) == true) {
		lt_entry.vvalue = str[0];
		lt_entry.lexema[0] = LEX_STAR;
	}
	else if (execute(fst = Fst(str, fstFunction)) == true) {
		lt_entry.lexema[0] = LEX_FUNCTION;
		it_entry.idtype = IT::F;
	}
	else if (execute(fst = Fst(str, fstStrType)) == true) {
		lt_entry.lexema[0] = LEX_STRING;
		it_entry.iddatatype = IT::STR;
	}

	else if (execute(fst = Fst(str, fstIntType)) == true) {
		lt_entry.lexema[0] = LEX_INTEGER;
		it_entry.iddatatype = IT::INT;
	}*/
}
