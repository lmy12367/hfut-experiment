#include <iostream>
#include "BiTree.h"
using namespace std;

int main()
{   
	cout<<"输入一棵线索二叉树："<<endl;
	BiTree t;
	t.create(t.root);
	t.Parent(t.root);
	t.postThread(t.root);
	t.PostOrderTraverse(t.root);
	
	return 0;
}


