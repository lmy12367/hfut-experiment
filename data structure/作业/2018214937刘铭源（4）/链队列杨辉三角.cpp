#include <iostream>
using namespace std;
class node
{
   public:
        int data;
        node*next=NULL;
};
class queue
{
   public:
         queue();
         ~queue();
         bool empty()const;
         bool full()const;
         int get_front(int &x)const;
         void append(const int x);
         void serve();
   private:
         int count;
         node *front,*rear;
};
queue::queue()
{
    front=new node;
    rear=front;
    front->next=NULL;
    count=0;
}
bool stack::empty()
{
    return front==rear;
}
int queue::get_front(int &x)const
{
    if(empty())
        return underflow;
    x=front->next->data;
    return success;
}
void queue::append(const int x)
{
    node*s=new node;
    s->data=x;
    s->next=NULL;
    rear->next=s;
    rear=s;
    count ++;
    return success;
}
void queue::serve()
{
    node*u;
    if(empty())
        return underflow;
    u=front->next;
    front->next=u->next;
    delete u;
    count--;
    if(front->next==NULL)
        rear=front;
    return success;
}
queue::~queue()
{
    while(!empty())
        serve();
    delete front;
}
void blank(int a)
{
	for(int k = 0;k < a;k++)
		cout<<"  ";
}

void put(int n)
{
	int s1,s2;
	queue q;
	blank(n+1);
	cout<<1<<endl;
	q.append(1);
	for(int i = 2;i < n + 1;i++)
	{
		s1 = 0;
		blank(n-i+2);
		for(int j = 0;j < i - 1;j++)
		{
			s2 = q.get_top();
			cout<<s1 + s2<<"   ";
			q.append(s1 + s2);
			q.serve();
			s1 = s2;
		}
		cout<<1<<endl;
		q.append(1);
	}
}
int main()
{
	int number;
	cout<<"输入你想要显示的行数：";
	cin>>number;
	put(number);
	return 0;
}
