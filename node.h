#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <map>
#include <vector>
#include <iostream>
#include "sort.h"
#include "coder.h"
#include "decoder.h"


using namespace std;

class Node
{
	private:
		Node* L;
		Node* R;
	public:
		Node *left;
		Node *right;
		int w;//вес узла
		char symbol;

		//конструктор по умолчанию
		Node()
		{
			left = right = NULL;
			w=0;//вес узла
			symbol=0;
		}

		Node(Node* L,Node* R)
		{
			left=L;
			right=R;
			w=L->w+R->w;
			symbol=0;
		}
		

};



#endif


