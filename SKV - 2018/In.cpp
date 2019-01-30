#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include "Log.h"
#include "Greibach.h"
#include "MFST.h"
#include "CodeGeneration.h"
#define TEST


#define InputNum 9, \
FST::NODE(1, FST::RELATION('I', 1)), \
FST::NODE(1, FST::RELATION('n', 2)), \
FST::NODE(1, FST::RELATION('p', 3)), \
FST::NODE(1, FST::RELATION('u', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('N', 6)), \
FST::NODE(1, FST::RELATION('u', 7)), \
FST::NODE(1, FST::RELATION('m', 8)), \
FST::NODE() \

#define OutNum 7, \
FST::NODE(1, FST::RELATION('O', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('N', 4)), \
FST::NODE(1, FST::RELATION('u', 5)), \
FST::NODE(1, FST::RELATION('m', 6)), \
FST::NODE() \
	
#define IF 3, \
FST::NODE(1, FST::RELATION('i', 1)), \
FST::NODE(1, FST::RELATION('f', 2)), \
FST::NODE() \

#define MORE 5, \
FST::NODE(1, FST::RELATION('m', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('e', 4)), \
FST::NODE() \

#define LESS 5, \
FST::NODE(1, FST::RELATION('l', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('s', 3)), \
FST::NODE(1, FST::RELATION('s', 4)), \
FST::NODE() \

#define EQUAL 6, \
FST::NODE(1, FST::RELATION('e', 1)), \
FST::NODE(1, FST::RELATION('q', 2)), \
FST::NODE(1, FST::RELATION('u', 3)), \
FST::NODE(1, FST::RELATION('a', 4)), \
FST::NODE(1, FST::RELATION('l', 5)), \
FST::NODE() \


#define NOTEQUAL 9, \
FST::NODE(1, FST::RELATION('n', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('e', 4)), \
FST::NODE(1, FST::RELATION('q', 5)), \
FST::NODE(1, FST::RELATION('u', 6)), \
FST::NODE(1, FST::RELATION('a', 7)), \
FST::NODE(1, FST::RELATION('l', 8)), \
FST::NODE() \

#define OutStr 7, \
FST::NODE(1, FST::RELATION('O', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('S', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('r', 6)), \
FST::NODE() \

#define CALL 5, \
FST::NODE(1, FST::RELATION('c', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('l', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE() \

#define PowNum 7, \
FST::NODE(1, FST::RELATION('P', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('w', 3)), \
FST::NODE(1, FST::RELATION('N', 4)), \
FST::NODE(1, FST::RELATION('u', 5)), \
FST::NODE(1, FST::RELATION('m', 6)), \
FST::NODE() \

#define SUBSTR 7, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('u', 2)), \
FST::NODE(1, FST::RELATION('b', 3)), \
FST::NODE(1, FST::RELATION('s', 4)), \
FST::NODE(1, FST::RELATION('t', 5)), \
FST::NODE(1, FST::RELATION('r', 6)), \
FST::NODE() \

#define STRLEN 7, \
FST::NODE(1, FST::RELATION('S', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE(1, FST::RELATION('e', 5)), \
FST::NODE(1, FST::RELATION('n', 6)), \
FST::NODE() \

#define MinNum 7, \
FST::NODE(1, FST::RELATION('M', 1)), \
FST::NODE(1, FST::RELATION('i', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE(1, FST::RELATION('N', 4)), \
FST::NODE(1, FST::RELATION('u', 5)), \
FST::NODE(1, FST::RELATION('m', 6)), \
FST::NODE() \

#define MaxNum 7, \
FST::NODE(1, FST::RELATION('M', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('x', 3)), \
FST::NODE(1, FST::RELATION('N', 4)), \
FST::NODE(1, FST::RELATION('u', 5)), \
FST::NODE(1, FST::RELATION('m', 6)), \
FST::NODE() \

#define GRAF_INT 4, \
FST::NODE(1, FST::RELATION('i', 1)), \
FST::NODE(1, FST::RELATION('n', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE() \

#define GRAF_NUMBER 3, \
FST::NODE(19,  FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),\
FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('1', 2), FST::RELATION('2', 2), \
FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2)), \
FST::NODE(20,  FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2), \
FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), \
FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)), \
FST::NODE() \

#define GRAF_MAIN 5, \
FST::NODE(1, FST::RELATION('m', 1)), \
FST::NODE(1, FST::RELATION('a', 2)), \
FST::NODE(1, FST::RELATION('i', 3)), \
FST::NODE(1, FST::RELATION('n', 4)), \
FST::NODE() \

#define GRAF_RETURN 7, \
FST::NODE(1, FST::RELATION('r', 1)), \
FST::NODE(1, FST::RELATION('e', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE(1, FST::RELATION('u', 4)), \
FST::NODE(1, FST::RELATION('r', 5)), \
FST::NODE(1, FST::RELATION('n', 6)), \
FST::NODE() \

#define GRAF_WHILE 6, \
FST::NODE(1, FST::RELATION('w', 1)), \
FST::NODE(1, FST::RELATION('h', 2)), \
FST::NODE(1, FST::RELATION('i', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE(1, FST::RELATION('e', 5)), \
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

#define GRAF_STRING 7, \
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('t', 2)), \
FST::NODE(1, FST::RELATION('r', 3)), \
FST::NODE(1, FST::RELATION('i', 4)), \
FST::NODE(1, FST::RELATION('n', 5)), \
FST::NODE(1, FST::RELATION('g', 6)), \
FST::NODE() \


#define GRAF_PLUS 2,\
	FST::NODE(4,FST::RELATION('+', 1),FST::RELATION('-', 1),FST::RELATION('*', 1),FST::RELATION('/', 1)),\
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

#define STR_LIT 3, \
FST::NODE(1, FST::RELATION('\'', 1)), \
FST::NODE(124,			 FST::RELATION('q', 1), FST::RELATION('w', 1), FST::RELATION('e', 1)  \
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
, FST::RELATION('А', 2), FST::RELATION('Б', 2), FST::RELATION('В', 2), FST::RELATION('Г', 2) \
, FST::RELATION('Д', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('a', 2) \
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
FST::NODE() \



extern int symb;
using namespace std;

namespace In {
	IN getin(wchar_t infile[], wchar_t outfile[], wchar_t synfile[], LT::LexTable lextable, IT::IdTable idtable)  //	IN getin(wchar_t infile[],wchar_t outfile[])
	{

		setlocale(0, "rus"); 
		int kavichka = 0;
		std::string remember_id[15];
		IN new_table = { 0, 0, 0, new unsigned char[IN_MAX_LEN_TEXT], IN_CODE_TABLE };
		wchar_t mas2[1024]; //IN_MAX_LEN_TEXT выше допустимого размера массива
		int i = 0, count=0,stroka=1;
		unsigned char aqw[1024];
		int symbols_in_stroke = 0;
		bool is_extern_function = false;
		IN in;
		ifstream fin; // открыли файл для чтения
		ofstream fout;
		fin.open(infile);
		fout.open(outfile, ios_base::app); //в конец
		ofstream syn;
		syn.open(synfile);
		char string[5000];
		char lex_word[100];
		int start_word=0, finish_word=0;  // для преобразования слов в лексемы
		int  lexshet = 0;
		std::string STR= "integer";
		char STR1[] = "integer";
		std::string string_value_lit[100];
		std::string string_value_id[100];
		int how_many_string_value_id2 = 0;
		int string_value_lit_count = 0;
		int string_value_id_count = 0;
		std::string plus_minus[50];
		int  plus_minus_count = 0;
		int string_or_int_count = 0;
		bool first = true;
		bool param_begin = false;
		int main_func = 0;
		int mas_with_num_lit[100];
		int ptr_for_mas_with_num_lit = 0;
		bool main_begin = false;
		int itr = 0;
		int ptr_symb = 0;
		char bufExpression[100];
		int pos_count = 0;

		int ptr_literals = 1;
		int ptr_expression = 1;
		
			if (!fin.is_open())
			{
				ERROR_THROW(110);
			}
			else
			{
				char ch;//unsignd
				while (fin.get(ch)) {
					mas2[i] = ch;
					string[i] = ch;
					
					
					string[i + 1] = '\0';
					if (mas2[i] > 256) { //если кирилица то -65280
						mas2[i] = mas2[i] - 65280;
					}
					if (in.code[mas2[i]] == IN::T || in.code[mas2[i]] == '!') { // если ==T или спец символ
						if (ch == IN_CODE_ENDL) {
							new_table.lines++;
						}
						new_table.text[new_table.size] = ch;
						new_table.text[new_table.size+1] = '\0';
						new_table.size++;
						if (ch == '\n') {
							in.lines++;
							symbols_in_stroke = -1;
						}
						if (in.code[mas2[i]] == '!') {
							aqw[count] = '!';
							aqw[count + 1] = '\0';
						}
						else
						{
							aqw[count] = ch;
							aqw[count + 1] = '\0'; 
						}
						//cout << ch;
						if (ch == '\'') {
							kavichka++;
						}
						if (ch=='>') {
							if (kavichka != 2 && kavichka != 0)
							{
								ERROR_THROW_IN(206, new_table.lines, 0);
							}
							kavichka = 0;
						}
						in.size++;
						symbols_in_stroke++;
						count++; // в обоих случаях элемент записывается в массив
					}
					else if (in.code[mas2[i]] ==	IN::I) { // если == I
						in.ignore++;
						new_table.ignore++;
					}
					else if (in.code[mas2[i]] == IN::F) { // если == F
						 ERROR_THROW_IN(111, in.lines+1, symbols_in_stroke);
					}
					i++;


				}
			}
			if (new_table.size != 0)
				new_table.lines++;
			LT::Entry lt_entry = { '\0' ,'\0', 0, LT_TI_NULLIDX };
			IT::Entry it_entry;
#ifdef TEST

			int pos = 0;
			int pos_in_table_lex = 0;
			int flag = 0;
			int length_word;
			int  ptr_for_next_str=0;
			bool string_begin = false;
			bool table_create = false;
			int lex_buf_count = 0;

			bool tag_begin = false;
			bool func_begin = false;
			while (pos < i)
			{
				
				if (string[pos] == '\n') {
					ptr_for_next_str++;
				}
				if (string[pos-1] == '{') {
					func_begin = true;
				}
				
				if (string[pos] == '}')
				{
					func_begin = false;
					if (main_begin == true) {
						main_begin = false;
					}
				}
				if (string[pos] == '<')
				{
					tag_begin = true;
				}
				if (string[pos-1] == '>')
				{
					tag_begin = false;
				}
				if (func_begin == true && tag_begin == false) {
					pos++;
				}
				else {
					if (string[pos - 1] == '(') param_begin = true;
					if (string[pos - 1] == ')') param_begin = false;

					if (string[pos] == '\'' && string_begin == true) {
						string_begin = false;
					}
					else if (string[pos] == '\'' && string_begin == false) {
						string_begin = true;

					}
					

					wchar_t buf[100];
					int string_lit_count = 0;
					if (string_begin == true) {
						while (string[pos + 1] != '\'') {
							lex_word[string_lit_count] = string[pos];
							buf[string_lit_count] = string[pos];
							string_lit_count++;
							pos++;
						}
						lex_word[string_lit_count] = string[pos];

						lex_word[string_lit_count + 1] = string[pos + 1];

						lex_word[string_lit_count + 2] = '\0';

						string_lit_count = 0;
						pos++;

						flag = 2;
					}
					if ((string[pos] != '\n'&& string[pos] != '<'&& string[pos] != '>' && string[pos] != ' ' && string[pos] != LEX_RIGHTHESIS &&   // если слово
						string[pos] != LEX_LEFTHESIS && string[pos] != LEX_BRACELET				//не начинается на	
						&& string[pos] != LEX_LEFTBRACE && string[pos] != LEX_COMMA &&		//разделяющий символ
						string[pos] != LEX_SEMICOLON && string[pos] != ']' && string[pos] != '[') && flag == 0 && string_begin == false) {
						flag = 1;
						start_word = pos;
					}

					if ((string[pos] == '\n' || string[pos] == ' ' || string[pos] == '<' || string[pos] == '>' || string[pos] == '=' || string[pos] == '+'
						|| string[pos] == '-' || string[pos] == '/' || string[pos] == '*' ||
						string[pos] == LEX_RIGHTHESIS || string[pos] == '[' || string[pos] == ']'||
						string[pos] == LEX_LEFTHESIS || string[pos] == LEX_BRACELET
						|| string[pos] == LEX_LEFTBRACE || string[pos] == LEX_COMMA ||
						string[pos] == LEX_SEMICOLON) && (flag == 1 || flag == 0) && string_begin == false)
					{
						if (flag == 1)
						{
							flag = 2;
						}
						finish_word = pos;
					}
					int check_lex = 0;
					if (flag == 2) {
						if (string_begin == false) {
							length_word = finish_word - start_word;
							lex_word[length_word] = '\0';
							while (start_word < finish_word) {
								lex_word[check_lex] = string[start_word];
								start_word++;
								check_lex++;
							}
						}
						string_begin = false;


						FST::Fst fst_int(lex_word, GRAF_INT);
						FST::Fst ON(lex_word, OutNum);
						FST::Fst OS(lex_word, OutStr);
						FST::Fst fst_main(lex_word, GRAF_MAIN);
						FST::Fst fst_id(lex_word, GRAF_ID);
						FST::Fst fst_plus(lex_word, GRAF_PLUS);
						FST::Fst fst_number(lex_word, GRAF_NUMBER);
						FST::Fst fst_return(lex_word, GRAF_RETURN);
						FST::Fst fst_function(lex_word, GRAF_FUNCTION);
						FST::Fst fst_string(lex_word, GRAF_STRING);
						//FST::Fst fst_substr(lex_word, SUBSTR);
						FST::Fst fst_strlen(lex_word, STRLEN);
						FST::Fst fst_pownum(lex_word, PowNum);
						FST::Fst fst_call(lex_word, CALL);
						FST::Fst fst_if(lex_word, IF);
						FST::Fst fst_more(lex_word, MORE);
						FST::Fst fst_less(lex_word, LESS);
						FST::Fst fst_eq(lex_word, EQUAL);
						FST::Fst fst_noteq(lex_word, NOTEQUAL);
						FST::Fst fst_while(lex_word, GRAF_WHILE);
						FST::Fst fst_input(lex_word, InputNum);
						FST::Fst fst_min(lex_word, MinNum);
						FST::Fst fst_max(lex_word, MaxNum);

						if (lex_word[0] == '\'')
						{
							lt_entry.lexema[0] = LEX_LITERAL;
							lt_entry.lexema[1] = '\0';
							strcpy_s(it_entry.id, "`");
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::STR;
							it_entry.idtype = IT::L;
							mas_with_num_lit[ptr_for_mas_with_num_lit] = idtable.size;
							ptr_for_mas_with_num_lit++;
							char bufffer[6] = "L";
							char bufffer_num[5];
							sprintf_s(bufffer_num, "%d", ptr_literals);
							if (ptr_literals < 10) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = '\0';
								ptr_literals++;
							}
							else if (ptr_literals >= 10 && ptr_literals < 100) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = '\0';
								ptr_literals++;
							}
							else if (ptr_literals >= 100 && ptr_literals < 1000) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = bufffer_num[2];
								bufffer[4] = '\0';
								ptr_literals++;
							}

							strcpy_s(it_entry.id, bufffer);
							strcpy_s(it_entry.value.vstr->str, lex_word);

							it_entry.idxfirstLE = ptr_for_next_str;
							
							IT::Add(idtable, it_entry);
						}
						else if (FST::execute(fst_number)) {
							int lit_value;
							lit_value = atoi(lex_word);

							//cout << "++++++++++++++++++++++++++++" << lextable.table[lextable.size-1].lexema <<"\t"<<lit_value<< endl;
							lt_entry.lexema[0] = LEX_LITERAL;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							char bufffer[6] = "L";
							char bufffer_num[5];
							sprintf_s(bufffer_num, "%d", ptr_literals);
							if (ptr_literals < 10) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = '\0';
								ptr_literals++;
							}
							else if (ptr_literals >= 10 && ptr_literals < 100) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = '\0';
								ptr_literals++;
							}
							else if (ptr_literals >= 100 && ptr_literals < 1000) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = bufffer_num[2];
								bufffer[4] = '\0';
								ptr_literals++;
							}
							
							strcpy_s(it_entry.id, bufffer);
							it_entry.iddatatype = IT::INT;
							it_entry.idtype = IT::L;
							
							it_entry.value.vint = lit_value;
							it_entry.idxfirstLE = ptr_for_next_str;
							//it_entry.visibility = new_visibility;
							IT::Add(idtable, it_entry);


						}
						else if (FST::execute(fst_main)) {
							lt_entry.lexema[0] = LEX_MAIN;
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							main_func++;
							main_begin = true;
							strcpy_s(it_entry.vision, "main");
							strcpy_s(lt_entry.vision, "main");

						}
						else if (FST::execute(ON)) {
							lt_entry.lexema[0] = 'n';
							lt_entry.lexema[1] = '\0';
							 itr = 0;
							while (string[pos + itr] != '>') {
								bufExpression[itr] = string[pos + itr];
								bufExpression[itr+1] = '\0';
								itr++;
							}
							it_entry.idtype = IT::EXPRESSION;
							it_entry.iddatatype = IT::STR;
							it_entry.idxfirstLE = ptr_for_next_str;
							strcpy_s(it_entry.value.vstr->str, bufExpression);
							strcpy_s(it_entry.id, "ON");
						
							IT::Add(idtable, it_entry);


							//std::cout << "\n\n\n\n\n"<<string[pos]<<string[pos+1] << string[pos + 2] << string[pos + 3];
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;


						}
						else if (FST::execute(fst_pownum)) {
							lt_entry.lexema[0] = 'p';
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_while)) {
						lt_entry.lexema[0] = 'h';
						lt_entry.lexema[1] = '\0';
						lt_entry.idxTI = LT_TI_NULLIDX;
						lt_entry.sn = ptr_for_next_str;
						LT::Add(lextable, lt_entry);
						int ptr_pos = pos;
						pos_count = 0;

						while (string[ptr_pos] != '<') {
							/*bufExpression[pos_count] = string[ptr_pos+1];
							pos_count++;*/
							ptr_pos--;
						}
						while (string[ptr_pos + 1] != '>') {
							bufExpression[pos_count] = string[ptr_pos + 1];
							pos_count++;
							ptr_pos++;
						}
						bufExpression[pos_count] = '\0';
						it_entry.idtype = IT::EXPRESSION;
						//it_entry.sn = 
						it_entry.iddatatype = IT::STR;
						it_entry.idxfirstLE = ptr_for_next_str;
						strcpy_s(it_entry.value.vstr->str, bufExpression);



						char bufffer[6] = "E";
						char bufffer_num[5];
						sprintf_s(bufffer_num, "%d", ptr_expression);
						if (ptr_expression < 10) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 10 && ptr_expression < 100) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 100 && ptr_expression < 1000) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = bufffer_num[2];
							bufffer[4] = '\0';
							ptr_expression++;
						}

						strcpy_s(it_entry.id, bufffer);

						IT::Add(idtable, it_entry);

						}
						else if (FST::execute(OS)) {
							lt_entry.lexema[0] = 's';
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							itr = 0;
							while (string[pos + itr] != '>') {
								bufExpression[itr] = string[pos + itr];
								bufExpression[itr + 1] = '\0';
								itr++;
							}
							it_entry.idtype = IT::EXPRESSION;
							//it_entry.sn = 
							it_entry.iddatatype = IT::STR;
							it_entry.idxfirstLE = ptr_for_next_str;
							strcpy_s(it_entry.value.vstr->str, bufExpression);
							strcpy_s(it_entry.id, "OS");

							IT::Add(idtable, it_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}
						
						else if (FST::execute(fst_int)) {  //+
						lt_entry.lexema[0] = LEX_INTEGER;
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						it_entry.iddatatype = IT::INT;
						it_entry.idtype = IT::V;

						}
						else if (FST::execute(fst_more)|| FST::execute(fst_less) || FST::execute(fst_eq) || FST::execute(fst_noteq)) {  //+
						lt_entry.lexema[0] = 'q';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);

						}
						else if (FST::execute(fst_string)) {
							lt_entry.sn = ptr_for_next_str;
							lt_entry.lexema[0] = LEX_STRING;
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::STR;
							it_entry.idtype = IT::V;

						}
						else if (FST::execute(fst_function)) {  //+
							lt_entry.lexema[0] = LEX_FUNCTION;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.idtype = IT::F;

						}
						else if (FST::execute(fst_call)) {  //+
						lt_entry.lexema[0] = 'c';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						//is_extern_function = true;
						int ptr_pos = pos;
						pos_count = 0;
						while (string[ptr_pos] != '<') {
							/*bufExpression[pos_count] = string[ptr_pos+1];
							pos_count++;*/
							ptr_pos--;
						}
						while (string[ptr_pos + 1] != '>') {
							bufExpression[pos_count] = string[ptr_pos + 1];
							pos_count++;
							ptr_pos++;
						}
						bufExpression[pos_count] = '\0';
						it_entry.idtype = IT::ECALLFUNC;
						//it_entry.sn = 
						it_entry.iddatatype = IT::STR;
						it_entry.idxfirstLE = ptr_for_next_str;
						strcpy_s(it_entry.value.vstr->str, bufExpression);



						char bufffer[6] = "E";
						char bufffer_num[5];
						sprintf_s(bufffer_num, "%d", ptr_expression);
						if (ptr_expression < 10) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 10 && ptr_expression < 100) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 100 && ptr_expression < 1000) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = bufffer_num[2];
							bufffer[4] = '\0';
							ptr_expression++;
						}

						strcpy_s(it_entry.id, bufffer);

						IT::Add(idtable, it_entry);
						it_entry.idtype = IT::CALLFUNC;
						it_entry.iddatatype = IT::NAN_VAR;

						//it_entry.idtype = IT::CALLFUNC;
						}
						//else if (FST::execute(fst_substr)) {  //+
						//lt_entry.lexema[0] = 'a';
						//lt_entry.lexema[1] = '\0';
						//lt_entry.sn = ptr_for_next_str;
						//lt_entry.idxTI = LT_TI_NULLIDX;
						//LT::Add(lextable, lt_entry);
						//it_entry.idtype = IT::P;

						//}
						else if (FST::execute(fst_min)) {  //+
						lt_entry.lexema[0] = 'a';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_max)) {  //+
						lt_entry.lexema[0] = 'b';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_strlen)) {  //+
						lt_entry.lexema[0] = 'd';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_input)) {  //+
						lt_entry.lexema[0] = 'z';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						int ptr_pos = pos;
						pos_count = 0;

						while (string[ptr_pos] != '<') {
							/*bufExpression[pos_count] = string[ptr_pos+1];
							pos_count++;*/
							ptr_pos--;
						}
						while (string[ptr_pos + 1] != '>') {
							bufExpression[pos_count] = string[ptr_pos + 1];
							pos_count++;
							ptr_pos++;
						
						}
						bufExpression[pos_count] = '\0';
						it_entry.idtype = IT::EXPRESSION;
						//it_entry.sn = 
						it_entry.iddatatype = IT::STR;
						it_entry.idxfirstLE = ptr_for_next_str;
						strcpy_s(it_entry.value.vstr->str, bufExpression);



						char bufffer[6] = "E";
						char bufffer_num[5];
						sprintf_s(bufffer_num, "%d", ptr_expression);
						if (ptr_expression < 10) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 10 && ptr_expression < 100) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 100 && ptr_expression < 1000) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = bufffer_num[2];
							bufffer[4] = '\0';
							ptr_expression++;
						}

						strcpy_s(it_entry.id, bufffer);

						IT::Add(idtable, it_entry);

						//it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_if)) {  //+
						lt_entry.lexema[0] = 'g';
						lt_entry.lexema[1] = '\0';
						lt_entry.sn = ptr_for_next_str;
						lt_entry.idxTI = LT_TI_NULLIDX;
						LT::Add(lextable, lt_entry);
						int ptr_pos = pos;
						pos_count = 0;

						while (string[ptr_pos] != '<') {
							/*bufExpression[pos_count] = string[ptr_pos+1];
							pos_count++;*/
							ptr_pos--;
						}
						while (string[ptr_pos + 1] != '>') {
							bufExpression[pos_count] = string[ptr_pos + 1];
							pos_count++;
							ptr_pos++;
						}
						bufExpression[pos_count] = '\0';
						it_entry.idtype = IT::EXPRESSION;
						//it_entry.sn = 
						it_entry.iddatatype = IT::STR;
						it_entry.idxfirstLE = ptr_for_next_str;
						strcpy_s(it_entry.value.vstr->str, bufExpression);



						char bufffer[6] = "E";
						char bufffer_num[5];
						sprintf_s(bufffer_num, "%d", ptr_expression);
						if (ptr_expression < 10) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 10 && ptr_expression < 100) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = '\0';
							ptr_expression++;
						}
						else if (ptr_expression >= 100 && ptr_expression < 1000) {
							bufffer[1] = bufffer_num[0];
							bufffer[2] = bufffer_num[1];
							bufffer[3] = bufffer_num[2];
							bufffer[4] = '\0';
							ptr_expression++;
						}

						strcpy_s(it_entry.id, bufffer);

						IT::Add(idtable, it_entry);

						//it_entry.idtype = IT::P;

						}
						else if (FST::execute(fst_return)) {
							lt_entry.sn = ptr_for_next_str;
							lt_entry.lexema[0] = LEX_RETURN;
							lt_entry.lexema[1] = '\0';
							LT::Add(lextable, lt_entry);
							int ptr_pos = pos;
							pos_count = 0;

							while (string[ptr_pos] != '<') {
								/*bufExpression[pos_count] = string[ptr_pos+1];
								pos_count++;*/
								ptr_pos--;
							}
							while (string[ptr_pos + 1] != '>') {
								bufExpression[pos_count] = string[ptr_pos + 1];
								pos_count++;
								ptr_pos++;
							}
							bufExpression[pos_count] = '\0';
							it_entry.idtype = IT::EXPRESSION;
							//it_entry.sn = 
							it_entry.iddatatype = IT::STR;
							it_entry.idxfirstLE = ptr_for_next_str;
							strcpy_s(it_entry.value.vstr->str, bufExpression);



							char bufffer[6] = "E";
							char bufffer_num[5];
							sprintf_s(bufffer_num, "%d", ptr_expression);
							if (ptr_expression < 10) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = '\0';
								ptr_expression++;
							}
							else if (ptr_expression >= 10 && ptr_expression < 100) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = '\0';
								ptr_expression++;
							}
							else if (ptr_expression >= 100 && ptr_expression < 1000) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = bufffer_num[2];
								bufffer[4] = '\0';
								ptr_expression++;
							}
							strcpy_s(it_entry.id, bufffer);

							IT::Add(idtable, it_entry);

						}
						else if (FST::execute(fst_id)) {
						
							
							lt_entry.sn = ptr_for_next_str;
							it_entry.sn = ptr_for_next_str;
							lt_entry.lexema[0] = LEX_ID;
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = idtable.size;
							LT::Add(lextable, lt_entry);
							it_entry.idxfirstLE = ptr_for_next_str;
							strcpy_s(it_entry.id, lex_word);
							if (it_entry.idtype == IT::F) {
								strcpy_s(it_entry.vision, lex_word);
								strcpy_s(lt_entry.vision, lex_word);
								
							}
							else {
								if (it_entry.idtype!=IT::CALLFUNC) {
								strcat_s(it_entry.id, "_");
								strcat_s(it_entry.id, it_entry.vision);
							}
								//}
								is_extern_function = false;
							}
							
						
							int pos_last_symbol;
								
							

							if (it_entry.iddatatype == 1)
							{
								it_entry.value.vint = 0;
							}
							if (it_entry.iddatatype == 2)
							{
								//it_entry.value.vstr.str = "sss";
								strcpy_s(it_entry.value.vstr->str, "@empty@");
							}
							//it_entry.visibility = new_visibility;
							if (param_begin == true) it_entry.idtype = IT::P;
							bool new_elem = true;
							//strspy_s(last_id,it_entr)
							for (int i = 0; i < idtable.size; i++) {
								if (strcmp(idtable.table[i].id, it_entry.id) == 0)  {
									new_elem = false;
								}
							
							}
							if ((new_elem == true)) {
								IT::Add(idtable, it_entry);
							}
							else {
								if (lextable.table[lextable.size - 2].lexema[0] == 't')
								ERROR_THROW_IN(205, ptr_for_next_str, 1);
							}
							it_entry.idtype = IT::V;
							//strcpy_s(remember_id , idtable.table[i].id);

						}



						flag = 0;
					}

					if (string_begin == false) {

						if (string[pos] == '=') {
							lt_entry.lexema[0] = LEX_ROVNO;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							
							int ptr_pos = pos;
							pos_count = 0;
							
							while (string[ptr_pos] != '<') {
								/*bufExpression[pos_count] = string[ptr_pos+1];
								pos_count++;*/
								ptr_pos--;
							}
							while (string[ptr_pos + 1] != '>') {
								bufExpression[pos_count] = string[ptr_pos + 1];
								pos_count++;
								ptr_pos++;

							}
							bufExpression[pos_count] = '\0';
							it_entry.idtype = IT::EXPRESSION;
							//it_entry.sn = 
							it_entry.iddatatype = IT::STR;
							it_entry.idxfirstLE = ptr_for_next_str;
							strcpy_s(it_entry.value.vstr->str, bufExpression);



							char bufffer[6] = "E";
							char bufffer_num[5];
							sprintf_s(bufffer_num, "%d", ptr_expression);
							if (ptr_expression < 10) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = '\0';
								ptr_expression++;
							}
							else if (ptr_expression >= 10 && ptr_expression < 100) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = '\0';
								ptr_expression++;
							}
							else if (ptr_expression >= 100 && ptr_expression < 1000) {
								bufffer[1] = bufffer_num[0];
								bufffer[2] = bufffer_num[1];
								bufffer[3] = bufffer_num[2];
								bufffer[4] = '\0';
								ptr_expression++;
							}

							strcpy_s(it_entry.id, bufffer);

							IT::Add(idtable, it_entry);



							//std::cout << pos;
						}
						if (string[pos] == '<') {
							lt_entry.lexema[0] = '<';
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == '>') {
							lt_entry.lexema[0] = '>';
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}
						if (string[pos] == '(') {
							if (it_entry.idtype == IT::F)
								it_entry.idtype = IT::P;
							lt_entry.lexema[0] = LEX_LEFTHESIS;
							lt_entry.lexema[1] = '\0';
							lt_entry.idxTI = LT_TI_NULLIDX;
							lt_entry.sn = ptr_for_next_str;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;
						}
						if (string[pos] == ')') {
							//it_entry.idtype = (IT::IDTYPE) - 1;
							lt_entry.lexema[0] = LEX_RIGHTHESIS;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == ']') {
							//it_entry.idtype = (IT::IDTYPE) - 1;
							lt_entry.lexema[0] = ']';
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == '[') {
							//it_entry.idtype = (IT::IDTYPE) - 1;
							lt_entry.lexema[0] = '[';
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == ',') {
							lt_entry.lexema[0] = LEX_COMMA;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == ';') {
							lt_entry.lexema[0] = LEX_SEMICOLON;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == '{') {
							lt_entry.lexema[0] = LEX_LEFTBRACE;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == '}') {
							lt_entry.lexema[0] = LEX_BRACELET;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
						}
						if (string[pos] == '+') {
							lt_entry.vvalue = '+';
							lt_entry.lexema[0] = LEX_PLUS;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}
						if (string[pos] == '-') {
							lt_entry.vvalue = '-';
							lt_entry.lexema[0] = LEX_MINUS;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}
						if (string[pos] == '/') {
							lt_entry.vvalue = '/';
							lt_entry.lexema[0] = LEX_DIRSLASH;
							lt_entry.lexema[1] = '\0';
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}
						if (string[pos] == '*') {
							lt_entry.vvalue = '*';
							lt_entry.lexema[0] = LEX_STAR;
							lt_entry.lexema[1] = '\0';
							//lt_entry.vvalue = string[pos];
							lt_entry.sn = ptr_for_next_str;
							lt_entry.idxTI = LT_TI_NULLIDX;
							LT::Add(lextable, lt_entry);
							it_entry.iddatatype = IT::NAN_VAR;

						}

					}
					pos++;


				}
			}
			if (main_func == 0) {
				ERROR_THROW(200);
			}
			else if (main_func >= 2) {
				ERROR_THROW(201);
			}
			//cout << "================"<<endl;
			fout << "----Исходные данные----" << endl;
			fout << "Количество символов: " << in.size << endl;
			fout << "Количество строк: " << in.lines + 1 << endl;
			fout << "Проигнорировано: " << in.ignore << endl;
			//cout << lextable.table[lextable.size - 1].sn;
			int ii = 0;

			{
				lt_entry.lexema[0] = '.';
				lt_entry.lexema[1] = '\0';
				lt_entry.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lt_entry); 
			}


			for (int i = 0; i-1 < lextable.table[lextable.size - 1].sn; i++) {
				fout << i << "\t\t";

				while (lextable.table[ii].sn == i) {
					fout <<lextable.table[ii].lexema;
					//cout << lextable.table[ii].lexema<<"  "<<lextable.table[ii].idxTI<<" "<<endl;
					ii++;
				}
				fout << '\n';
			}

			fout << "IDTYPE : 1 - VAR, 2- FUNC, 3-PAR, 4-LIT 5-STANDART FUNC" << endl;
			fout << "IDDATATYPE : 1 - INT, 2 - STRING" << endl;
			fout << "Number\tID\tIDDTYPE\tIDTYPE\tidxfirstLE visibility" << endl;
			
			for (int i = 0; i < lextable.size; i++)
			{
				//std::cout <<lextable.table[i].lexema;
			}

			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].iddatatype == 1) {
					/*cout << i << '\t' << idtable.table[i].id << '\t' << idtable.table[i].iddatatype << '\t' \
						<< idtable.table[i].idtype << '\t' << idtable.table[i].idxfirstLE << "\t       " << idtable.table[i].visibility <<"\t"<< idtable.table[i].value.vint << "\t" << endl;
					*/
					fout << i << '\t' << idtable.table[i].id << '\t' << idtable.table[i].iddatatype << '\t' \
						<< idtable.table[i].idtype << '\t' << idtable.table[i].idxfirstLE << "\t       " << idtable.table[i].vision << "\t" << idtable.table[i].value.vint << "\t" << endl;
					
				}
				
				else if (idtable.table[i].iddatatype == 2) {
					
					fout << i << '\t' << idtable.table[i].id << '\t' << idtable.table[i].iddatatype << '\t' \
						<< idtable.table[i].idtype << '\t' << idtable.table[i].idxfirstLE << "\t       " << idtable.table[i].vision << "\t" << idtable.table[i].value.vstr->str << '\t' << endl;
							}
				else if (idtable.table[i].iddatatype == 3) {

					fout << i << '\t' << idtable.table[i].id << '\t' << idtable.table[i].iddatatype << '\t' \
						<< idtable.table[i].idtype << '\t' << idtable.table[i].idxfirstLE << "\t       " << idtable.table[i].vision << "\t" << idtable.table[i].value.vstr->str << '\t' << endl;
					ERROR_THROW_IN(203, idtable.table[i].idxfirstLE,0);
					
				}
			}
			
			fout.close();
			syn << MFST_TRACE_START
			syn.close();
			MFST::Mfst mfst(lextable, GRB::getGreibach());
			mfst.start(outfile,synfile);
			mfst.savededucation();
			mfst.printrules(synfile);
			//std::cout << lextable.size;
			in.text = &aqw[0];
			fin.close(); 
			CodeGeneration::CodeGeneration(infile, lextable, idtable);
			
		return in;
#endif TEST
	}
}
