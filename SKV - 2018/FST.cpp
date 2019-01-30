#include "stdafx.h"
#include "FST.h"
#include <algorithm>

namespace FST
{
	RELATION::RELATION(char c, short nn) //ребро символ -> вершина графа переходов конечного автомата
	{
		symbol = c; //символ перехода
		nnode = nn; //номер смежной вершины
	};

	NODE::NODE()					//Вершина графов перехода
	{
		n_relation = 0;				//количство инцидентов ребра
		RELATION *relaions = NULL;			//новое состояние
	};

	NODE::NODE(short n, RELATION rel, ...) // с параметрами
	{
		n_relation = n;
		RELATION *p = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++)
			relations[i] = p[i];			//инцидентные ребра
	};

	Fst::Fst(char* s, short ns, NODE n, ...)			// недетерминированный конечный автомат
	{
		string = s;										//	цепочка
		nstates = ns;									//количество состояний автомата
		nodes = new NODE[ns];							//график переходов
		NODE *p = &n;
		for (int k = 0; k < ns; k++)
			nodes[k] = p[k];
		rstates = new short[nstates];					// возможные состояния на данной позиции
		memset(rstates, 0xff, sizeof(short)*nstates);//rstates-указатель на блок памяти для заполнения
													 // sizeof(short)*nstates- количество байт. которые необходимо заполнить данным символом
													 // 0xff-ередается в виде целого числа, но функция заполняет блок памяти символом, преобразуя это число в символ.
		rstates[0] = 0;
		position = -1;									//текущая позиция в цепочке
	}

	bool step(Fst& fst, short* &rstates)//1 шаг конечного автомата
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);//меняем местами массивы
		for (short i = 0; i < fst.nstates; i++)//количество состояний
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)		//возможностей перехода								
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])//ребро равно позиции
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					};
				};
		};
		return rc;
	};

	bool execute(Fst& fst) //распознование моей цепочки
	{
		short* rstates = new short[fst.nstates];//выделяю память для массива состояний
		short lstring = strlen(fst.string);//которая содержит длину строки
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)//цикл который проходит до последнего символа
		{
			fst.position++;
			rc = step(fst, rstates);//один шаг автомата
		}
		delete[] rstates;//удаляем временный массив
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	};
}