#pragma once
#include"stdafx.h"
#include "Error.h"
#include <iostream>
using namespace Error;

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] = { ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "�������� (-in) �� �����, ��� ����������� �����"),
		ERROR_ENTRY(101, "��������� ������ �������� ���������"),
		ERROR_ENTRY(102, "������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(103, "������ ��� �������� ����� � (-syn)"),
		ERROR_ENTRY_NODEF(104),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "������ ���  �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY_NODEF(112),
	    ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200,"��� ������� ������� main"),
		ERROR_ENTRY(201,"�� ����� ���� ������ ����� ������� main"),
		ERROR_ENTRY(202,"�� ������� ������� ������� ������"),
		ERROR_ENTRY(203,"������������� �� ��������"),
		ERROR_ENTRY(204,"����������� ����� �������������"),
		ERROR_ENTRY(205,"��������� ���������� ��������������"),
		ERROR_ENTRY(206,"����������� ����������� �������"),
		ERROR_ENTRY(207,"���������� ���� string ������ ��������� �������� int"),
		ERROR_ENTRY(208,"���������� ���� int ������ ��������� �������� string"),
		ERROR_ENTRY(209,"������� ������ �����������"),
		ERROR_ENTRY(210,"�� ������� ������� ������� ������"),
		ERROR_ENTRY(211,"������� ��������������� �����������"),
		ERROR_ENTRY(212,"������ � ����� ���������� �������"),
		ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "�������� ��������� ���������"),
		ERROR_ENTRY(601, "��������� ��������"),
		ERROR_ENTRY(602, "������ � ���������"),
		ERROR_ENTRY(603, "������ � ���������� �������"),
		ERROR_ENTRY(604, "������ � ���������� ���������� �������"),
		ERROR_ENTRY(605, "������ � ������� ��� �����"),
		ERROR_ENTRY(606, "������ � � ���������� �������������(��)"),
		 ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
		
	};
	ERROR geterror(int ip)
	{
		ERROR* e = new ERROR;
		if (ip < ERROR_MAX_ENTRY && ip>0)
		{
			
			for (int i = 0; i < ERROR_MAX_ENTRY; i++)
				if (ip == (errors[i].id)) {
					e->id = errors[i].id;
					strcpy_s(e->message, errors[i].message);
					//std::cout <<"������ "<<e->id<<" : "<< e->message;
					return *e;
				}
			
		}
		else
		{
			e->id = errors[0].id;
			strcpy_s(e->message, errors[0].message);
			return *e;
		}
	}
	ERROR geterrorin(int ip, int line = -1, int col = -1)
	{
		ERROR* e = new ERROR;
		//std::cout << e->id << e->message;
		if (ip < ERROR_MAX_ENTRY && ip>0)
		{
			for (int i = 0; i < ERROR_MAX_ENTRY; i++)
				if (ip == (errors[i].id)) {
					e->id = errors[i].id;
					strcpy_s(e->message, errors[i].message);
					e->inext.line = line;
					e->inext.col = col;
					std::cout << "\n������ " << e->id << ": " << e->message<<" , ������ : "<<e->inext.line << " , ������� : " << e->inext.col <<std::endl;
					return *e;
				}
		}
		else
		{
			e->id = errors[0].id;
			strcpy_s(e->message, errors[0].message);
			return *e;
		}
	}
};