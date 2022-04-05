#include<iostream>
using namespace std;
enum e_code{success,overflow,underflow};

struct node
{
public:
	int date;
	node * next;
};
class link_queue
{
public:
	link_queue();
	~link_queue();
	bool empty();
	e_code get_front(int &x);
	e_code  append(const int &x);//
	e_code serve();
	node * sort_fast(node * head);//«–∏Ó 
    node *merge(node *head1, node *head2);//≈≈–Ú÷ÿ◊È 
	int count;
	node * front,*rear;
};
