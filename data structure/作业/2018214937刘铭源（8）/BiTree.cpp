#include "BiTree.h"

BiTree::BiTree()
{
	root = NULL;
	pre=root;
}

void BiTree::create(bnode *&T)
{
	char x;
	cin >>x;
	if(x=='.')T=NULL;
	else
	{
		T=new bnode;
		T->data=x;
		create(T->lchild);
		create(T->rchild);
	} 
	
}

void BiTree::visit(bnode* T)
{
	cout<<T->data<<endl;;
}

void BiTree::postorder(bnode* T)
{
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		visit(T);
	}
}

void BiTree::Parent(bnode* T)
{
	
	if(T!=NULL)
	{
		Parent(T->lchild);
		Parent(T->rchild);
		if(T->lchild)
		{
			T->lchild->parent=T;
			T->ltag=0;
		}
		else
		T->ltag=1;
		if(T->rchild)
		{
			T->rchild->parent=T;
			T->rtag=0;
		}
		else
		T->rtag=1;
		
		
	}
	pre=root;
}

void BiTree::postThread(bnode* T)
{
	if(T!=NULL)
	{
		postThread(T->lchild);
		postThread(T->rchild);
		if(T->ltag==1)
		{
			T->lchild=pre;
		}
		if(pre && pre->rtag==1) 
		{
			pre->rchild=T;
		}
		pre=T;
	}
}
void BiTree::PostOrderTraverse(bnode* T)
{
	if(T)
	{
		pre=NULL;
		bnode* p=T;
		while(pre != T)
		{
			while(p->ltag==0 && p->lchild!=pre)
			p=p->lchild;
			
			
			while(p && p->rtag==1)
			{
				visit(p);
				pre = p;
				p = p->rchild;
			}
			
			while(pre != T && p->rchild==pre)
			{
				visit(p);
				pre = p;
				if(pre!=T)
				p=p->parent;
			}
			
			if(p->rtag==0)
			p=p->rchild;
			
		}
	}
}
