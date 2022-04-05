//以链栈的形式实现运算
#include <iostream>
using namespace std;
template<typename elementtype>
class node
{
    public:
          int data;
          node* next=NULL;
};
class stack
{
    public:
          stack();//构造函数
          ~stack();//析构函数
          bool empty()const;//判空
          bool full()const;//判满
          char* get_top(int &x);//取栈顶元素
          bool push(int x);//元素入栈
          bool pop();//删除栈顶
    private:
        int count;
        node* top;
};
template <typename elementtype>
stack<elementtype>::stack() {
    count = 0;
    top=NULL;
}

template <typename elementtype>
bool stack<elementtype>::empty() {
   return count==0;
}
template <typename elementtype>
char* stack<elementtype>::get_top(elementtype &x) {
    if (empty())
            return false;
        x = top->data;
        return true;
}
template <typename elementtype>
bool stack<elementtype>::push(elementtype x) {
   s=new node;
   s->data=x;
   s->next=top;
   top=s;
   count++;
   return true;
}
template <typename elementtype>
bool stack<elementtype>::pop() {
    if(empty())
        return false;
        u=top;
        top->next=u->next;
        delete u;
        count--;
        return true;
}
stack::~stack()
{
    while(!empty())
        pop();
}
bool isnumber(char x) {
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

//判断运算符优先级的函数
int priority(char x) {
    if (x == '+' || x == '-')
        return 0;
    else if (x == '*' || x == '/')
        return 1;
    else if (x == '(' || x == ')')
        return -1;
    else if (x == '#')
        return -2;
}

//运算的函数
int calculate(string s) {
    int number;
    char operate;
    char top;
    int a,b;

    for (unsigned int i = 0; i < s.size(); ++i) {
        if (isnumber(s[i])) {
            int Temp = 0;
            string temp;

            temp += s[i];
            while (isnumber(s[++i]))
                temp += s[i];
            for (unsigned int j = 0; j < temp.size(); ++j) {
                Temp = Temp * 10 + temp[j] - 48;
            }
            number.push(Temp);
            temp.clear();
        }//将字符数字转换成整形数字
        if (!isnumber(s[i])) {
            if (operate.empty()) {
                operate.push(s[i]);
            }//入栈第一个符号'#'
            else {
                operate.get_top(top);

                if (priority(s[i])>priority(top) || s[i] == '(') {
                    operate.push(s[i]);
                }//入栈高优先级的运算符
                else {
                    while (priority(s[i]) <= priority(top)) {
                        if (top == '#'&&s[i] == '#') {
                            int answer;

                            operate.pop();
                            number.get_top(answer);
                            cout << "\n答案是：" << answer << endl;
                            number.pop();
                            return 0;
                        }//当运算符实现完全后，只剩下'#'
                        else if (top == '('&&s[i] == ')') {
                            ++i;
                        }//当左右括号相遇时，跳过右括号，删除左括号
                        else {
                            number.get_top(a);

                            number.pop();
                            number.get_top(b);
                            number.pop();
                        }
                        if (top == '+') {
                            b += a;
                            number.push(b);
                        }
                        else if (top == '-') {
                            b -= a;
                            number.push(b);
                        }
                        else if (top == '*') {
                            b *= a;
                            number.push(b);
                        }
                        else if (top == '/') {
                            b /= a;
                            number.push(b);
                        }
                        operate.pop();
                        operate.get_top(top);//取前一个运算符，用于与现在扫描的运算符进行比较
                    }//将优先级高的运算符实现计算
                    operate.push(s[i]);//用于当top=='#'时，将最后一个运算符入栈
                }
            }
        }//扫描运算符，并判断优先级，以及运算
    }//主循环
}//对运算符的扫描，和数字字符的转化，以及计算

int main() {
    string expression;
    cout << "输入一个用'#'开头和结尾的表达式：" << endl;
    cin >> expression;
    calculate(expression);
    cin.get(), cin.get();
}


