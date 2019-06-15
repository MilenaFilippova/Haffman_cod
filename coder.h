#ifndef CODER_H_INCLUDED
#define CODER_H_INCLUDED
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "sort.h"
#include "node.h"
#include "decoder.h"

using namespace std;


map<char,int> gur;//журнал с перечнем соответсвия символа и веса
char symb;
Node* root;
void Tree(ifstream& file)
{
	
	while(!file.eof())	//читаем файл
	{
		symb=file.get();//счет кол-ва символов
		gur[symb]++ ;
	}
	
	list<Node* >heapNode;//список 
	
	for(map<char,int>::iterator it=gur.begin();it!=gur.end();it++)
	{
		Node* p=new Node;
		p->symbol=it->first; 
		p->w=it->second;
		heapNode.push_back(p); //добавление в список Node
	}

	//создаем дерево пока heapNode не кончится
	while(heapNode.size() != 1)
	{
		//сортировка списка
		heapNode.sort(MySort());
		Node* Son_L=heapNode.front();
		heapNode.pop_front();
		Node* Son_R=heapNode.front();
		heapNode.pop_front();
		Node* parent=new Node(Son_L,Son_R);
		heapNode.push_back(parent);
	}

	Node* root=heapNode.front();
	BuildCodeTable(root);
}

//сжимаем
void mycoder(const char* in_Name,const char* out_Name)
{
	ifstream file(in_Name, ios:: binary);

	Tree(file);
	file.clear();//переставить указатель на начало
	file.seekg(0);

	ofstream fileZip(out_Name,ios::binary);

	int count=0;	//счетчик бит
	char buf=0;	//переменная в которую будем собирать биты

	symb=file.get();
	while(!file.eof())
	{
		
		vector<bool> x=table[symb];
		for(int n=0;n<x.size();n++)
		{
			buf = buf | x[n] << (7 - count);
			count++;
			if(count==8)
			{
				count=0;	//собрали буфер
				fileZip << buf;
				buf=0;
			}
		}
	}
	if(count!=0)
	{
		fileZip << buf;		
	}

	file.close();//закроем поток
	fileZip.close();
}


#endif
