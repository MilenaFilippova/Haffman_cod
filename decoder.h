#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "sort.h"
#include "node.h"
#include "coder.h"

using namespace std;

void mydecoder(const char* in_Name, const char* out_Name)
{
	//преобразуем в прежний вид текст
	ifstream file(in_Name, ios:: binary);

	Node* smbl = root;
	int count = 0;	//счетчик
	char buf;
	bool x;

	ofstream out(out_Name, ios::binary);
	buf = file.get();
	while (!file.eof())
	{
		x=buf & (1<<(7-count));
		if(x==0)
		{
			smbl = smbl->left;
		}
		else
		{
			smbl = smbl->right;
		}


		if (smbl->left == NULL && smbl->right == NULL)
		{
			out << smbl->symbol;
			smbl = root;
		}
		count++;
		if (count == 8)//до собрания всего байта
		{
				count = 0;
				buf = file.get();
		}
	}

		file.close();
		out.close();
}

#endif
