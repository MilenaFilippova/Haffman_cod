#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "node.h"
#include "coder.h"
#include "decoder.h"
#include <map>
#include <vector>

using namespace std;

vector<bool> code;	//вектор сжатого кода
map<char,vector<bool>>table;

struct MySort
{
	bool operator()(Node* L,Node* R)
	{
		//return R->w->L->w;
		return L<R;
	}
};


void BuildCodeTable(Node* root)
{

	if(root->left!=NULL)
	{
		code.push_back(0);
		BuildCodeTable(root->left);
	}

	if(root->right!=NULL)
	{
		code.push_back(1);
		BuildCodeTable(root->right);
	}

	if(root->left == NULL && root-> right == NULL)
	{
		table[root->symbol] = code;	//записали весь код который шел по дереву
		
	}
	if(code.size() != 0)
	{
		code.pop_back();		//убрали последний 0
	}
}




#endif
