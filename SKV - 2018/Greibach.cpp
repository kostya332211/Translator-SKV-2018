#include "stdafx.h"
#include "Greibach.h"
#include <cstring>
#define GRB_ERROR_SERIES 600

namespace GRB
{
	Greibach greibach(NS('S'), TS('$'),			// Стартовый символ, дно стека
7,										// Количество правил
		Rule(NS('S'), GRB_ERROR_SERIES + 0,		
		3,									
		Rule::Chain(6, TS('m'), TS('{'), TS('<'), NS('N'), TS('}'), NS('S')),
		Rule::Chain(15, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'),
		TS('{'), TS('<'), NS('N'), TS('<'), TS('r'),TS('i'), TS('>'), TS('}'), NS('S')),
		Rule::Chain(1, TS('.'))
),
		Rule(NS('I'), GRB_ERROR_SERIES + 6,		
			2,								
			Rule::Chain(1, TS('i')),
			Rule::Chain(3, TS('i'), TS(','), NS('I'))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 1,		
			14,									
			Rule::Chain(5, TS('t'), NS('I'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(3, TS('t'), NS('I'), TS('>')),
			Rule::Chain(5, TS('z'), TS('i'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(3, TS('z'), TS('i'), TS('>')),
			Rule::Chain(6, TS('i'), TS('='), NS('V'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(4, TS('i'), TS('='), NS('V'), TS('>')),
			Rule::Chain(5, TS('s'), TS('i'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(3, TS('s'), TS('i'), TS('>')),
			Rule::Chain(5, TS('n'), TS('i'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(3, TS('n'), TS('i'), TS('>')),
			Rule::Chain(15, TS('g'), TS('('), NS('X'), TS('q'), NS('X'), TS(')'), TS('>'), TS('<'), TS('['), TS('>'), TS('<'), NS('N'), TS('<'), TS(']'), TS('>')),
			Rule::Chain(17, TS('g'), TS('('), NS('X'), TS('q'), NS('X'), TS(')'), TS('>'), TS('<'), TS('['), TS('>'), TS('<'), NS('N'), TS('<'), TS(']'), TS('>'), TS('<'), NS('N')),
			Rule::Chain(15, TS('h'), TS('('), NS('X'), TS('q'), NS('X'), TS(')'), TS('>'), TS('<'), TS('['), TS('>'), TS('<'), NS('N'), TS('<'), TS(']'), TS('>')),
			Rule::Chain(17, TS('h'), TS('('), NS('X'), TS('q'), NS('X'), TS(')'), TS('>'), TS('<'), TS('['), TS('>'), TS('<'), NS('N'), TS('<'), TS(']'), TS('>'), TS('<'), NS('N'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 3,
			2,
			Rule::Chain(4, TS('t'), TS('i'), TS(','), TS('F')),
			Rule::Chain(2, TS('t'), TS('i'))
		),
		Rule(NS('V'), GRB_ERROR_SERIES + 2,	
			13,
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(5, TS('c'), TS('i'), TS('('), NS('Z'), TS(')')),
			Rule::Chain(4, TS('a'), TS('('), NS('Z'), TS(')')),
			Rule::Chain(4, TS('b'), TS('('), TS('i'), TS(')')),
			Rule::Chain(7, TS('c'), TS('p'), TS('('), TS('i'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('c'), TS('a'), TS('('), TS('i'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('c'), TS('b'), TS('('), TS('i'), TS(','), TS('i'), TS(')')),
			Rule::Chain(5, TS('c'), TS('d'), TS('('), TS('i'), TS(')')),
			Rule::Chain(3, TS('i'), TS('v'), NS('V')),
			Rule::Chain(3, TS('l'), TS('v'), NS('V')),
			Rule::Chain(3, TS('('), NS('V'), TS(')')),
			Rule::Chain(5, TS('('), NS('V'), TS(')'), TS('v'), NS('V'))
		),
		Rule(NS('Z'), GRB_ERROR_SERIES + 4,	
			4,
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('Z')),
			Rule::Chain(3, TS('l'), TS(','), NS('Z'))
		),
		Rule(NS('X'), GRB_ERROR_SERIES + 5,
			1,
			Rule::Chain(1, TS('i'))
		)

	);

	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)
	{
		nt = new GRBALPHABET[size = psize];
		int* p = (int*)&s;
		for (short i = 0; i < psize; i++)
			nt[i] = (GRBALPHABET)p[i];
	}

	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...)
	{
		nn = pnn;
		iderror = piderror;
		chains = new Chain[size = psize];
		Chain* p = &c;
		for (int i = 0; i < size; i++)
			chains[i] = p[i];
	}

	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)
	{
		startN = pstartN;
		stbottomT = pstbottom;
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i = 0; i < size; i++)
			rules[i] = p[i];
	}

	Greibach getGreibach()
	{
		return greibach;
	}

	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)   //верхн элем стека, набор правил
	{
		short rc = -1;
		short k = 0;
		while (k < size && rules[k].nn != pnn)   //смотрит правила для нетерминалов
			k++;
		if (k < size)
			prule = rules[rc = k];
		return rc;
	}

	Rule Greibach::getRule(short n)
	{
		Rule rc;
		if (n < size)
			rc = rules[n];
		return rc;
	}

	char* Rule::getCRule(char* b, short nchain)					// Получить правило в виде N -> цепочка
	{
		char bchain[200];
		b[0] = Chain::alphabet_to_char(nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		chains[nchain].getCChain(bchain);
		strcat_s(b, sizeof(bchain) + 5, bchain);
		return b;
	}

	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)  //символ на ленте, номер правила, номера цепочек правил
	{
		short rc = -1;
		while (j < size && chains[j].nt[0] != t)    //первый символ для первого правила
			++j;
		rc = (j < size ? j : -1);
		if (rc >= 0)
			pchain = chains[rc];
		return rc;
	}

	char* Rule::Chain::getCChain(char* b)					// Получить первую сторону правила
	{
		for (int i = 0; i < size; i++)
			b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	}
}