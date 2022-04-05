#include<iostream>
#include<stack>
#include<queue>
//�ڵ�ṹ��
struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value):value(value),left(NULL),right(NULL){}
};
//����������
void inertNode(Node *node,int value){
    if(value<=node->value){
        if(!node->left){
            node->left=new Node(value);
        }
        else{
            inertNode(node->left,value);
        }
    }
    else{
        if(!node->right){
            node->right=new Node(value);
        }
        else{
            inertNode(node->right,value);
        }
    }
}
//ǰ������ݹ�ʵ��
void preOrder(Node *node){
    if(node){
        std::cout<<node->value<<"  ";
        preOrder(node->left);
        preOrder(node->right);
    }

}
//ǰ������ǵݹ�ʵ��
void preOrder1(Node *node){
    if(node==NULL){
        return;
    }
    std::stack<Node *> nstack;
    nstack.push(node);
    while(!nstack.empty()){
        Node *temp=nstack.top();
        std::cout<<temp->value<<"  ";
        nstack.pop();
        if(temp->right){
            nstack.push(temp->right);
        }
        if(temp->left){
            nstack.push(temp->left);
        }
    }

}
//��������ݹ�ʵ��
void inOrder(Node *node){
    if(node){
        inOrder(node->left);
        std::cout<<node->value<<"  ";
        inOrder(node->right);
    }
}
//��������ǵݹ�ʵ��
void inOrder1(Node *node){
    std::stack<Node *> nstack;
    Node *temp=node;
    while(temp||!nstack.empty()){
        if(temp){
            nstack.push(temp);
            temp=temp->left;
        }
        else{
            temp=nstack.top();
            std::cout<<temp->value<<"  ";
            nstack.pop();
            temp=temp->right;
        }
    }
}
//��������ݹ�ʵ��
void posOrder(Node *node){
    if(node){
        posOrder(node->left);
        posOrder(node->right);
        std::cout<<node->value<<" ";
    }
}
//��������ǵݹ�ʵ��
void posOrder1(Node *node){
    if(node==NULL)
        return;
    std::stack<Node *> nstack1, nstack2;
    nstack1.push(node);
    while (!nstack1.empty()){
        Node *temp=nstack1.top();
        nstack1.pop();
        nstack2.push(temp);
        if(temp->left)
            nstack1.push(temp->left);
        if(temp->right)
           nstack1.push(temp->right);
    }
    while(!nstack2.empty())
    {
        std::cout<<nstack2.top()->value<<" ";
        nstack2.pop();
    }
}

//������ȱ���
void broadOrder(Node *node){
    if(!node){
        return;
    }
    std::queue<Node *> qnodes;
    qnodes.push(node);
    while(!qnodes.empty()){
        Node * temp=qnodes.front();
        std::cout<<temp->value<<" ";
        qnodes.pop();
        if(temp->left){
            qnodes.push(temp->left);
        }
        if(temp->right){
            qnodes.push(temp->right);
        }

    }
}
int main(){
    int n;
    while(std::cin>>n){
        n--;
        int value;
        std::cin>>value;
        Node root(value);
        while(n--){
            int newValue;
            std::cin>>newValue;
            inertNode(&root,newValue);
        }
        std::cout<<"������� is:"<<2;
        //preOrder(&root);
        std::cout<<std::endl;
        std::cout<<"������� is:"<<2;
        //inOrder(&root);
        std::cout<<std::endl;
        std::cout<<"������� is:";
        posOrder(&root);
        std::cout<<std::endl;
        std::cout<<"��������ǵݹ�:";
        preOrder1(&root);
        std::cout<<std::endl;
        std::cout<<"��������ǵݹ�:";
        inOrder1(&root);
        std::cout<<std::endl;
        std::cout<<"���������ǵݹ�:";
        posOrder1(&root);
        std::cout<<std::endl;
        std::cout<<"���ȱ��� is:";
        broadOrder(&root);
    }

}
