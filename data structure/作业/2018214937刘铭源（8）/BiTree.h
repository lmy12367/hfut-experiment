#ifndef BITREE_H
#define BITREE_H
#include <iostream>
using namespace std;

struct bnode{
	char data;
	bnode* lchild;
	bnode* rchild;
	bnode* parent;
	int ltag;
	int rtag;
};

class BiTree
{
	public:
		BiTree();
		void create(bnode *&T);
		void visit(bnode* T);
		void postorder(bnode* T);
		void Parent(bnode* T); 
		void postThread(bnode* T); 
		void PostOrderTraverse(bnode* T);
		
		bnode* root;
	private: 
		bnode* pre;
		
};

#endif
