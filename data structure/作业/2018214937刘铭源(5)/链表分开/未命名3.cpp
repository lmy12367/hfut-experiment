#include "head.h"
link_queue::link_queue()
{
	front = new node;
	rear = front;
	front ->next = NULL;
	count = 0;
}
bool link_queue::empty()
{
	return front == rear;
}
e_code link_queue::get_front(int &x)
{
	if(empty())
		return underflow;
	x = front ->next ->date;
	return success;
}
e_code link_queue::append(const int &x)
{
	node * s = new node;
	s ->date = x;
	s ->next = NULL;
	rear ->next = s;
	rear = s;
	count++;
	return success;
}
e_code link_queue::serve()//出队列运算
{
	node * u;
	if (empty())
	{
		return underflow;
	}
	u = front ->next;
	front ->next = u ->next;
	delete u;
	count --;
	if (front ->next == NULL)
	{
		rear = front;
	}
	return success;
}
link_queue::~link_queue()
{

}

node * link_queue::sort_fast(node * head)
{
        //链表归并排序
            if(head == NULL || head->next == NULL)return head;
        else
        {
            //快慢指针找到中间节点
            node *fast = head,*slow = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sort_fast(head);//前半段排序
            slow = sort_fast(slow);//后半段排序
            return merge(fast,slow);
        }
        
}
node * link_queue::merge(node *head1, node *head2)
{
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    node *res , *p ;
    if(head1->date < head2->date)
        {res = head1;
		 head1 = head1->next;
		}
    else
	{
	res = head2;
	head2 = head2->next;
	}
    p = res; 
    while(head1 != NULL && head2 != NULL)
        {
            if(head1->date < head2->date)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
    if(head1 != NULL)
		p->next = head1;
    else if(head2 != NULL)
		p->next = head2;
    return res;
} 
