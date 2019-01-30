#include "stdafx.h"
#include "POLISH.h"
#include <map>
#include <stack>
#include <iostream>
#include <sstream>
#include <cctype>
#include "IT.h"

using namespace std;

std::string POLISH::PolishNotation(std::string str, char* vis)
{
	//std::cout << str<<"  ****************";
	bool bracket_close = false;
	int end = 0;
	int leterals=0;
	std::string new_string = "";
	std::string check_lit = "";
	std::string check_lit_too;
	std::string result_string;
	int ptr_check_lit_too = 0;
	int count_literals = 0;
	int mas_literals[100], ptr_for_mas=0;
	int ascii;
	bool check_digit = false;
	bool flag_digit = true;
	int rovno = str.find('=');
	check_lit = str.substr(rovno+1);
	check_lit = check_lit + ' ';
	std::string vision = vis;
	std::string::size_type ind;
	for (int i = 0; i < check_lit.length(); i++) {
		if (check_lit[i] == '+' || check_lit[i] == '-' || check_lit[i] == '*' || check_lit[i] == '/' || check_lit[i] == '(' || check_lit[i] == ')'|| check_lit[i] == '\0' || check_lit[i] == ' ') {
		
			if (!check_lit_too.empty()) {
				count_literals++;
				if (check_digit == true) {
					//	cout << "+++++++++++++";
					mas_literals[ptr_for_mas] = count_literals;
					mas_literals[ptr_for_mas + 1] = '\0';
					ptr_for_mas++;
				}
				else {
					result_string += '_';
					result_string += vision;
				}
			}
				flag_digit = true;
				check_lit_too.clear();
				result_string+=check_lit[i];
			
			
		}
		else {
			check_lit_too += check_lit[i];
			result_string += check_lit[i];
			if (flag_digit == true) {
				ascii = check_lit[i];
				if (ascii > 47 && ascii < 58) {
					check_digit = true;
				}
				else {
					check_digit = false;
					flag_digit = false;
				}
			}
						
		}

	}
	//std::cout << "\t\t\t\t"<<result_string << "\n\n\n";
	while ((ind = result_string.find(' ')) != std::string::npos) // удаление пробелов из входной строки
	{
		result_string.erase(ind, 1);
	}
	std::string srpn;

	std::map<char, size_t> map; // вес символов
	map.insert(std::make_pair('*', 3));
	map.insert(std::make_pair('/', 3));
	map.insert(std::make_pair('+', 2));
	map.insert(std::make_pair('-', 2));
	map.insert(std::make_pair('(', 1));
	std::stack<char> stack;

	for (char c : result_string) 
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		{
			srpn += ' ';
			if (')' == c)
			{
				while (stack.top() != '(')
				{
					srpn += stack.top();
					stack.pop();
					srpn += ' ';
				}
				stack.pop();
			}
			else if ('(' == c)
			{
				stack.push(c);
			}
			else if (stack.empty() || (map[stack.top()] < map[c]))
			{
				stack.push(c);
			}
			else
			{
				do
				{
					srpn += stack.top();
					srpn += ' ';
					stack.pop();
				} while (!(stack.empty() || (map[stack.top()] < map[c])));
				stack.push(c);
			}
		}
		else
		{
			srpn += c;
		}
	}
	while (!stack.empty())
	{
		srpn += ' ';
		srpn += stack.top();
		stack.pop();
	}
	srpn += ' ';
	//std::cout << srpn << std::endl; // результирующая строка в ОПЗ
	
	return srpn;
} 