#include "stdafx.h"
#include <iostream>


extern "C"
{
		void OutNum(int a) {
			std::cout << a << std::endl;
		
	}
		void OutStr(char* a) {
			std::cout << a << std::endl;
		}
		int PowNum(int value, int st) {
			while (st != 1) {
				value = value * value;
				st--;
			}
			return value;
		}
		int MaxNum(int a, int b) {
			if (a > b) return a;
			return b;
		}
		int MinNum(int a, int b) {
			if (a < b) return a;
			return b;
		}
		int Strlen(char* a) {
			int ptr = 0;
			while (a[ptr] != '\0') {
				ptr++;
			}
			return ptr;
		}
		char* Substring(char* a,int from,int to) {
			char result[15]="";
			int ptr = 0,ptr_result = 0;
			while (a[ptr] != '\0') {
				if (ptr >= from && ptr <= to) {
					result[ptr_result] = + a[ptr];
					ptr_result++;
				}
				ptr++;
			}
			result[ptr_result] = '\0';
			std::cout << result;
			return result;
		}
		int InputNum() {
			int a;
			std::cin >> a;
			return a;
		}
	
}
