#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//���������ṹ
typedef struct BiTNode{
    char ch;          
    struct BiTNode *lchild;        //����
    struct BiTNode *rchild;        //�Һ���
}BiTNode,*BiTree;
//���������
void AddBiTree(BiTree T,BiTree p)
{
    if((p->ch <= T->ch)&&(T->lchild!=NULL))
        AddBiTree(T->lchild,p);
    else if((p->ch <= T->ch)&&(T->lchild==NULL))
        T->lchild=p;
    else if(T->rchild!=NULL)
        AddBiTree(T->rchild,p);
    else T->rchild=p;
}


//ǰ�����
void PreOrderTraverse(BiTree T)
{
    if(T){
        printf("%c ",T->ch);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//�������
void InOrderTraverse(BiTree T)
{
    if(T){
        InOrderTraverse(T->lchild);
        printf("%c ",T->ch);
        InOrderTraverse(T->rchild);
    }
}

//�������
void PostOrderTraverse(BiTree T)
{
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ",T->ch);
    }
}

//���ĸ߶�
int Height(BiTree T)
{
    if(T == NULL)
        return 0;
    else
        return 1 + max(Height(T->lchild), Height(T->rchild));
}

int max(int x, int y)
{
    return(x >= y ? x : y);
}
int main()
{
    char ch;//�������
    BiTree T,p;//��T������ʱ��p
    printf("������������(�Կո�δ������ʶ):");
    scanf("%c",&ch);//�����û�����
    T=NULL;

    while(ch!=' '){//�ж�����
        //�����½��
        if(p=(BiTNode *)malloc(sizeof(BiTNode))){
            p->ch = ch;
            p->lchild = NULL;
            p->rchild = NULL;
        }
        else
        {
            printf("�ڴ�������.\n");
            exit(0);
        }
        if(T==NULL)
            T=p;
        else
            AddBiTree(T,p);
        scanf("%c",&ch);//�����û�����
    }
    //����������
    printf("ǰ�������\n");
    PreOrderTraverse(T);
    printf("\n���������\n");
    InOrderTraverse(T);
    printf("\n���������\n");
    PostOrderTraverse(T);
    printf("\n���ĸ߶ȣ�\n");
    cout << Height(T);
}



