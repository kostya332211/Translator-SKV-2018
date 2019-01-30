#include "stdafx.h"
#include "CodeGeneration.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <string.h>
#include "POLISH.h"
#include <stack>
#include "Error.h"
void CodeGeneration::CodeGeneration(wchar_t out_asm[], LT::LexTable lextable, IT::IdTable idtable)
{
	std::cout << std::endl;
	int num_of_ex = 0;
	int count_parametrs = 0;
	int count_parametrs_escho = 0;
	bool if_begin = false, while_begin = false;
	int count_if = 0, count_while = 0;
	using namespace std;
	bool flag_par = false;
	int out_length = wcslen(out_asm);
	int ii = 0;
	out_asm[out_length - 1] = 'm';
	out_asm[out_length - 2] = 's';
	out_asm[out_length - 3] = 'a';
	ofstream fout;
	std::string::size_type ind;
	fout.open("SKV_ASM//SKV_LIB//FILE_ASM//LP_ASM01.asm");
	fout << ".586\n\t.model flat, stdcall\n\tincludelib libucrt.lib\n\tincludelib kernel32.lib\n ExitProcess PROTO :DWORD\n\n";
	fout << "\t\tEXTRN OutStr: proc\n";
	fout << "\t\tEXTRN OutNum: proc\n";
	fout << "\t\tEXTRN PowNum: proc\n";
	fout << "\t\tEXTRN InputNum: proc\n";
	fout << "\t\tEXTRN Strlen: proc\n";
	fout << "\t\tEXTRN MinNum: proc\n";
	fout << "\t\tEXTRN MaxNum: proc\n";
	fout << "\n.stack 4096\n";
	fout << ".const\n";
	for (int i = 0; i < idtable.size; i++)
	{
		if (idtable.table[i].idtype == IT::L )
		{
			fout<< "\t" << idtable.table[i].id;
			if (idtable.table[i].iddatatype == IT::STR)
			{
				if (idtable.table[i].idtype == IT::EXPRESSION) {
					fout << " BYTE \'" << idtable.table[i].value.vstr->str << "\' , 0\n";
				}
				else {
					fout << " BYTE " << idtable.table[i].value.vstr->str << " , 0\n";

				}
			}
			if (idtable.table[i].iddatatype == IT::INT)
			{
				fout << " DWORD " << idtable.table[i].value.vint << endl;
			}
		}
	}
	fout << ".data\n";
	for (int i = 0; i < idtable.size; i++)
	{
		if (idtable.table[i].idtype == IT::V)
		{
			
				fout << "\t" << idtable.table[i].id;
				if (idtable.table[i].iddatatype == IT::STR)
				{
					fout << " DWORD ?\n";
				}
				if (idtable.table[i].iddatatype == IT::INT)
				{
					fout << " SDWORD ?\n";
				}		
		}
	}
	fout << ".code\n";

	
	
	
	bool main_begin = false;
	for (int i = 0; i < lextable.size; i++) {
		if (lextable.table[i].lexema[0] == 'f') {
			for (int iii = 0; iii < idtable.size; iii++) {
				if (lextable.table[i].sn == idtable.table[iii].sn) {
					if (idtable.table[iii].idtype == IT::F) {
						fout << "\t" << idtable.table[iii].id << "  PROC ";
					}
					else if (idtable.table[iii].idtype == IT::P) {
						if (count_parametrs == 0) {
							fout << idtable.table[iii].id << " : ";
							count_parametrs++;
						}
						else {
							fout << ", " << idtable.table[iii].id << " : ";
						}
						if (idtable.table[iii].iddatatype == IT::INT) {
							fout << " sdword ";
						}
						if (idtable.table[iii].iddatatype == IT::STR) {
							fout << " byte ";
						}
					}
				}

			}
		}
		if (lextable.table[i].lexema[0] == LEX_RETURN)
		{
			std::string ret;
			std::string vision;
			for (int r = 0; r < idtable.size; r++) {
				if (idtable.table[r].idxfirstLE == lextable.table[i].sn &&idtable.table[r].idtype == IT::EXPRESSION) {
					ret = idtable.table[r].value.vstr->str;
					vision = idtable.table[r].vision;
					while ((ind = ret.find(' ')) != std::string::npos) // удаление пробелов из входной строки
					{
						ret.erase(ind, 1);
					}
				}
			}

			ret = ret.substr(6);
			ret = ret + "_" + lextable.table[i].vision;

			if (CheckId(ret, idtable) == false) {
				ERROR_THROW_IN(203, lextable.table[i].sn, 0);
			}

			bool isnum = true;
			for (int p = 0; p < ret.length(); p++) {
				if ((int)ret[p] < 47 || (int)ret[p] >58) isnum = false;
			}
			fout << "mov eax, ";
			if (isnum == false) {
				fout << ret << "\n";
			}
			fout << "ret\n";
		}
		if (lextable.table[i].lexema[0] == ')'&&count_parametrs != 0) {
			fout << "\n";
			count_parametrs = 0;

		}
		if (lextable.table[i].lexema[0] == '}') {
			if (main_begin == false) {
				fout << "\t" << lextable.table[i].vision << " ENDP\n\n";
			}
			else if (main_begin == true) {
				fout << "\n\tpush 0 \n\tcall ExitProcess\nmain ENDP\nend main";
			}
		}
		

		if (lextable.table[i].lexema[0] == LEX_OutNum) {
			//	std::cout << lextable.table[i].sn;
			for (int z = 0; z < idtable.size; z++) {
				if (idtable.table[z].idxfirstLE == lextable.table[i].sn) {
					std::string FuncOut = idtable.table[z].value.vstr->str;
					while ((ind = FuncOut.find(' ')) != std::string::npos) // удаление пробелов из входной строки
					{
						FuncOut.erase(ind, 1);
					}
					fout << "\tpush " << FuncOut + '_' << idtable.table[z].vision << endl;
					fout << "\tcall OutNum" << endl;

				}
			}

		}
		if (lextable.table[i].lexema[0] == LEX_MAIN) {
			fout << "main PROC\n";
			main_begin = true;
		}
			//while (lextable.table[i].lexema[0] != '}') {

				if (lextable.table[i].lexema[0] == '='&&lextable.table[i + 1].lexema[0] != 'c') {

					for (int j = 0; j < idtable.size; j++) {
						if (idtable.table[j].idtype == IT::EXPRESSION && idtable.table[j].idxfirstLE == lextable.table[i].sn) {
							std::string to_polish = idtable.table[j].value.vstr->str;
							std::string param_ret;
							std::string result;
							bool inicialized = true;
							std::string buff_to_push = "";
							while ((ind = to_polish.find(' ')) != std::string::npos) // удаление пробелов из входной строки
							{
								to_polish.erase(ind, 1);
							}

							if (to_polish.find('\'') > 0 && to_polish.find('\'') < 100)
							{
								for (int iii = 0; iii < idtable.size; iii++) {
									if (idtable.table[j].idxfirstLE == idtable.table[iii].idxfirstLE && idtable.table[iii].idtype == IT::L) {
										fout << "push offset "<<idtable.table[iii].id << endl;
										fout << "pop eax\n";
										//fout<<"mov "
									}
									//if (tLE && idtable.table[iii].idtype == IT::V) {


								}
								to_polish = to_polish.substr(0, to_polish.find('='))+'_'+idtable.table[j].vision;
								//cout << to_polish;
								if (CheckStr(to_polish, idtable) == false) {
									ERROR_THROW_IN(208, idtable.table[j].idxfirstLE, 0);
								}
								fout <<"mov "<<to_polish << ", eax\n";
															}
							else {
								while ((ind = to_polish.find(' ')) != std::string::npos) // удаление пробелов из входной строки
								{
									to_polish.erase(ind, 1);
								}
								//cout << "!!\t\t\t" << to_polish;

								int z = to_polish.find('=');    //найти =
								param_ret = to_polish.substr(0, z);
								//param_ret = param_ret + "_" + idtable.table[j].vision;
								param_ret = param_ret + "_" + idtable.table[j].vision;
								if (CheckId(param_ret, idtable) == false)
								{
									ERROR_THROW_IN(203,idtable.table[j].sn,0);
								}
								if (CheckInt(param_ret, idtable) == false) {
									ERROR_THROW_IN(207, idtable.table[j].idxfirstLE, 0);
								}
								result = POLISH::PolishNotation(to_polish, idtable.table[j].vision);
							//	std::cout << result << "\n";
								for (int ii = 0; ii < result.length(); ii++) {
									buff_to_push += result[ii];
									if (result[ii] == '+') {
										fout << "pop ebx" << endl;
										fout << "pop eax" << endl;
										fout << "add eax,  ebx" << endl;
										fout << "push eax" << endl;
										buff_to_push = "";
										//ii++;
										inicialized = false;
									}
									else if (result[ii] == '-') {
										fout << "pop ebx" << endl;
										fout << "pop eax" << endl;
										fout << "sub eax,  ebx" << endl;
										fout << "push eax" << endl;
										buff_to_push = "";
										inicialized = false;
									}
									else if (result[ii] == '*') {
										fout << "pop ebx" << endl;
										fout << "pop eax " << endl;
										fout << "mul ebx" << endl;
										fout << "push eax" << endl;
										buff_to_push = "";
										inicialized = false;
									}
									else if (result[ii] == '/') {
										fout << "pop ebx " << endl;
										fout << "pop eax " << endl;
										fout << "mov edx, 0" << endl;
										fout << "div ebx" << endl;
										fout << "push eax" << endl;
										buff_to_push = "";
										inicialized = false;
									}
									else if ((result[ii] == '\0' || result[ii] == ' ') && buff_to_push != " "&& buff_to_push != ""&&buff_to_push != "  "&& buff_to_push != "(") {
										while ((ind = buff_to_push.find(' ')) != std::string::npos) // удаление пробелов из входной строки
										{
											buff_to_push.erase(ind, 1);
										}
										while ((ind = buff_to_push.find('\n')) != std::string::npos) // удаление пробелов из входной строки
										{
											buff_to_push.erase(ind, 1);
										}
										fout << "push " + buff_to_push << endl;
										//cout << buff_to_push << "!";
										if (CheckInt(buff_to_push, idtable) == false && IsNum(buff_to_push)==false) {
											ERROR_THROW_IN(208, idtable.table[j].idxfirstLE, 0);
										}
										buff_to_push = "";
									}

								}
								if (inicialized == true) {
									fout << "pop eax " << endl;
								}
								inicialized = true;
								while ((ind = param_ret.find(' ')) != std::string::npos) // удаление пробелов из входной строки
								{
									param_ret.erase(ind, 1);
								}
								while ((ind = param_ret.find('\n')) != std::string::npos) // удаление пробелов из входной строки
								{
									param_ret.erase(ind, 1);
								}
								fout << "mov " + param_ret + ", eax" << endl;

							}
						}
					}
				}
				if (lextable.table[i].lexema[0] == '[') {
					if (if_begin == true) {
						fout << "@if"<<count_if<<":\n";
					}
					if (while_begin == true) {
						//fout << "@while1:\n";
						//while_begin++;
					}
				}
				if (lextable.table[i].lexema[0] == ']') {
					if (if_begin == true) {
						fout << "@if"<<count_if<<"end:\n";
						if_begin=false;
					}
					if (while_begin == true) {
						fout << "jmp @while" << count_while << "\n";
						fout << "@while" << count_while << "end:\n";
						while_begin=false;
					}
				}
				if (lextable.table[i].lexema[0] == 'z') {
					for (int z = 0; z < idtable.size; z++) {
						if (idtable.table[z].idxfirstLE == lextable.table[i].sn) {
							std::string FuncOut = idtable.table[z].value.vstr->str;
							while ((ind = FuncOut.find(' ')) != std::string::npos) // удаление пробелов из входной строки
							{
								FuncOut.erase(ind, 1);
							}
							FuncOut = FuncOut.substr(8);
							FuncOut = FuncOut + "_" + lextable.table[i].vision;
							//cout << FuncOut;
							fout << "call InputNum\n";
							fout << "mov " << FuncOut << ", eax\n";
						}
					}
				}
				if (lextable.table[i].lexema[0] == 'g') {
					if_begin=true;
					count_if++;
					//std::cout << lextable.table[i].sn;
					for (int z = 0; z < idtable.size; z++) {
						if (idtable.table[z].idxfirstLE == lextable.table[i].sn&& idtable.table[z].idtype == IT::EXPRESSION) {
							std::string FuncOut = idtable.table[z].value.vstr->str;
							
							FuncOut = FuncOut.substr (FuncOut.find('(')+1,FuncOut.length());
						//	cout << "[][][][][]" << FuncOut << endl;
							std::string check_lit;
							std::string more="more", less = "less", equal = "equal", notequal = "notequal";
							bool flag_more = false, flag_less = false, flag_equal = false, flag_notequal = false;
							bool flag_digit = false;
							bool check_digit = true;
							bool eax_or_ebx = true;
							FuncOut = ' ' + FuncOut;
							int ascii;
							for (int i = 0; i < FuncOut.length(); i++) {
								if (FuncOut[i] == ' ' || FuncOut[i] == ')') {
									while ((ind = check_lit.find(' ')) != std::string::npos) // удаление пробелов из входной строки
									{
										check_lit.erase(ind, 1);
									}
									if (!check_lit.empty()) {
										if (check_digit == true) {
											
											
											if (eax_or_ebx == true)
											{
												fout << "mov eax, " << check_lit << endl;
												eax_or_ebx = false;
											}
											else {
												fout << "mov ebx, " << check_lit << endl;
											}
																				}
										else {
											if (check_lit == more) {
												flag_more = true;
											}
											else if (check_lit == less) {
												flag_less = true;
											}
											else if (check_lit == equal) {
												flag_equal = true;
											}
											else if (check_lit == notequal) {
												flag_notequal = true;
											}
											else {
												if (eax_or_ebx == true) {
													fout << "mov eax, " << check_lit + '_' + idtable.table[z].vision << endl;
													eax_or_ebx = false;
												}
												else {
													fout << "mov ebx, " << check_lit + '_' + idtable.table[z].vision << endl;

												}
											}
										}
									}
									 flag_digit = true;
									check_lit.clear();
								}
								else {
									check_lit += FuncOut[i];
									if (flag_digit == true) {
										ascii = FuncOut[i];
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
							fout << "cmp eax, ebx\n";
							if (flag_more == true) {
								fout << "jg @if"<<count_if << endl;
							}
							else if (flag_less == true) {
								fout << "jl @if" << count_if << endl;
							}
							else if (flag_equal == true) {
								fout << "jz @if" << count_if << endl;
							}
							else if (flag_notequal == true) {
								fout << "jnz @if" << count_if << endl;
							}
							
							fout << "jmp @if"<<count_if<<"end\n";

						}
					}

				}
				if (lextable.table[i].lexema[0] == 'h') {
					while_begin=true;
					count_while++;
					//std::cout << lextable.table[i].sn;
					for (int z = 0; z < idtable.size; z++) {
						if (idtable.table[z].idxfirstLE == lextable.table[i].sn&& idtable.table[z].idtype == IT::EXPRESSION) {
							std::string FuncOut = idtable.table[z].value.vstr->str;
							fout << "@while"<<count_while<<":\n";
							FuncOut = FuncOut.substr(FuncOut.find('(') + 1, FuncOut.length());
							//cout << "[][][][][]" << FuncOut << endl;
							std::string check_lit;
							std::string from;
							std::string to;
							std::string more = "more", less = "less", equal = "equal", notequal = "notequal";
							bool flag_more = false, flag_less = false, flag_equal = false, flag_notequal = false;
							bool flag_digit = false;
							bool check_digit = true;
							bool eax_or_ebx = true;
							FuncOut = ' ' + FuncOut;
							int ascii;
							for (int i = 0; i < FuncOut.length(); i++) {
								if (FuncOut[i] == ' ' || FuncOut[i] == ')') {
									while ((ind = check_lit.find(' ')) != std::string::npos) // удаление пробелов из входной строки
									{
										check_lit.erase(ind, 1);
									}
									if (!check_lit.empty()) {
										if (check_digit == true) {


											if (eax_or_ebx == true)
											{
												from = check_lit;
												eax_or_ebx = false;
											}
											else {
												to = check_lit;
											}
										}
										else {
											if (check_lit == more) {
												flag_more = true;
											}
											else if (check_lit == less) {
												flag_less = true;
											}
											else if (check_lit == equal) {
												flag_equal = true;
											}
											else if (check_lit == notequal) {
												flag_notequal = true;
											}
											else {
												if (eax_or_ebx == true) {
													from = check_lit + '_' + idtable.table[z].vision;
													//std::cout << "mov eax, " << check_lit + '_' + idtable.table[z].vision << endl;
													eax_or_ebx = false;
												}
												else {
													to = check_lit + '_' + idtable.table[z].vision;
													//std::cout << "mov ebx, " << check_lit + '_' + idtable.table[z].vision << endl;

												}
											}
										}
									}
									flag_digit = true;
									check_lit.clear();
								}
								else {
									check_lit += FuncOut[i];
									if (flag_digit == true) {
										ascii = FuncOut[i];
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
							fout << "mov eax, " << from << endl;
							fout << "mov ebx, " << to << endl;
							fout << "cmp eax, ebx\n";
							if (flag_more == true) {
								fout << "jl @while"<<count_while<<"end" << endl;
							}
							else if (flag_less == true) {
								fout << "jg @while" << count_while << "end" << endl;
							}
							else if (flag_equal == true) {
								fout << "jnz @while" << count_while << "end" << endl;
							}
							else if (flag_notequal == true) {
								fout << "jz @while" << count_while << "end" << endl;
							}

							//fout << "jmp @while1end\n";

						}
					}

				}
				if (lextable.table[i].lexema[0] == LEX_OutStr) {
					//std::cout << lextable.table[i].sn;
					for (int z = 0; z < idtable.size; z++) {
						if (idtable.table[z].idxfirstLE == lextable.table[i].sn) {
							std::string FuncOut = idtable.table[z].value.vstr->str;
							while ((ind = FuncOut.find(' ')) != std::string::npos) // удаление пробелов из входной строки
							{
								FuncOut.erase(ind, 1);
							}
						
							FuncOut = FuncOut + "_" + idtable.table[z].vision;
							if (CheckId(FuncOut, idtable) == false) {
								ERROR_THROW_IN(203, idtable.table[z].sn, 0);
							}
							fout << "\tpush " << FuncOut << endl;
							fout << "\tcall OutStr" << endl;

						}

					}

				}
				
				if (lextable.table[i].lexema[0] == 'c') {
					//if (lextable.table[i - 1].lexema[0] == '=') func_with_return == true;
					//cout << "\n\n\n\n";
					std::string call_func;
					std::string vision;
					std::string func_to_call;
					std::string param_ret;
					std::string str_buf = "";
					std::string func_name;
					bool itsnum = false, flag = true;
					int check_num;
					for (int z = 0; z < idtable.size; z++) {
						if (idtable.table[z].idxfirstLE == lextable.table[i].sn&&idtable.table[z].idtype==IT::ECALLFUNC) {
							//cout <<idtable.table[z].value.vstr->str << "\n";
							call_func = idtable.table[z].value.vstr->str;
							vision = idtable.table[z].vision;
						}
					}
					int z = call_func.find('=');    
					param_ret = call_func.substr(0, z);

					
					func_name = call_func.substr(z+1);
					while ((ind = func_name.find(' ')) != std::string::npos) // удаление пробелов из входной строки
					{
						func_name.erase(ind, 1);
					}
					//cout << func_name.find('(');
					func_name = func_name.substr(4, func_name.find('(')-4);
					//cout << func_name << "!";
					while ((ind = param_ret.find(' ')) != std::string::npos) // удаление пробелов из входной строки
					{
						param_ret.erase(ind, 1);
					}
					param_ret = param_ret + "_" + vision;
					if (CheckId(param_ret, idtable) == false) {
						ERROR_THROW_IN(203, idtable.table[z].sn, 0);
					}
					//func_name = call_func;
					
					stack<string> st;
					for (int r = 0;r<call_func.length();r++){
						
						if (call_func[r] == '(' || call_func[r] == ')' || call_func[r] == ',' || call_func[r] == ' ') {
							if (call_func[r] == '(') func_to_call = str_buf;
							if (call_func[r] == ',' || call_func[r] == ')') 
							{ 
								if (itsnum == true) {
									//fout << "push "<< str_buf <<"\n";
									st.push(str_buf);
									//cout << "num";
								}
								else {
									//fout << "push " << str_buf + "_" + vision << "\n";
									st.push(str_buf+"_"+vision);
									if (CheckInt(str_buf + "_" + vision,idtable) == true) {
										//cout << "num";
										for (int iiii = 0; iiii < idtable.size; iiii++) {
											if (idtable.table[iiii].vision == func_name && idtable.table[iiii].idtype == IT::P &&idtable.table[iiii].iddatatype==IT::STR) {
												if (flag_par == false) {
													ERROR_THROW_IN(212, idtable.table[iiii].idxfirstLE, 0);
													flag_par = true;
												}
												//cout << "++";
											}
										}
									}
									if (CheckStr(str_buf + "_" + vision, idtable) == true) {
										//cout << "str";
									}
									for (int i = 0; i < idtable.size; i++) {

									}
									//cout << str_buf<<"_"<<vision;
								}
								
							}
							//cout << call_func;
							//cout << str_buf<<"\n";
							str_buf = "";
							flag = true;
							itsnum = false;
						}
						else {
							str_buf += call_func[r];
							check_num = call_func[r];
							if (check_num > 47 && check_num < 58 && flag == true) {
								itsnum = true;
								flag = true;
							}
							else {
								itsnum = false;
								flag = false;
							}
						}
					}
					while (!st.empty())
					{
						fout<<"push "<< st.top()<<"\n";
						st.pop();
						
					}
					fout << "call " << func_to_call << "\n";
					fout << "mov " << param_ret << ", eax\n";
					//cout << "\n" << param_ret;

				}
				

				//i++;
			//}
			
			
		
	
		//}
	}
	
	
	//cout << out_asm;
	
}

bool CodeGeneration::CheckId(std::string a, IT::IdTable idtable)
{
	std::string::size_type ind;
	while ((ind = a.find(' ')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	while ((ind = a.find('\n')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	for (int i = 0; i < idtable.size; i++) {
		if (idtable.table[i].id == a) {
			//std::cout << "================="<<idtable.table[i].id;
			return true;
			 

		}
		else {
			//std::cout << "!!" << idtable.table[i].id;
		}
	}
	return false;
}
bool CodeGeneration::CheckStr(std::string a, IT::IdTable idtable)
{
	std::string::size_type ind;
	while ((ind = a.find(' ')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	while ((ind = a.find('\n')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	for (int i = 0; i < idtable.size; i++) {
		if (idtable.table[i].id == a) {
			if(idtable.table[i].iddatatype==IT::STR)
			return true;

		}
		else {
			//std::cout << "!!" << idtable.table[i].id;
		}
	}
	return false;
}
bool CodeGeneration::CheckInt(std::string a, IT::IdTable idtable)
{
	std::string::size_type ind;
	while ((ind = a.find(' ')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	while ((ind = a.find('\n')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	for (int i = 0; i < idtable.size; i++) {
		if (idtable.table[i].id == a) {
			if (idtable.table[i].iddatatype == IT::INT)
				return true;

		}
		else {
			//std::cout << "!!" << idtable.table[i].id;
		}
	}
	return false;
}
bool CodeGeneration::IsNum(std::string a) {
	std::string::size_type ind;
	while ((ind = a.find(' ')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	while ((ind = a.find('\n')) != std::string::npos) // удаление пробелов из входной строки
	{
		a.erase(ind, 1);
	}
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9' || a[i] == '0') {}
		else { return false; }
	}
	return true;
}
