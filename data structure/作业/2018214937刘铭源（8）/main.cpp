#include <iostream>
#include "BiTree.h"
using namespace std;

int main()
{   
	cout<<"����һ��������������"<<endl;
	BiTree t;
	t.create(t.root);
	t.Parent(t.root);
	t.postThread(t.root);
	t.PostOrderTraverse(t.root);
	
	return 0;
}


