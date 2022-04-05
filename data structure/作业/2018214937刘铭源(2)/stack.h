#include<iostream>
#include<string>
using namespace std;
const int maxlen = 100;
template <class elementType>//模板
class stack 
{
public:
	stack();
	bool empty() const;
	bool full();
	bool get_top(elementType &x)const;
	bool push(const elementType x);
	bool pop();

private:
	elementType count;
	elementType data[maxlen];
};

template <class elementType>
stack<elementType>::stack()
{
	count = 0;
}

template <class elementType>
bool stack<elementType>::empty()const {
	if (count == 0)return true;
	return false;
}

template <class elementType>
bool stack<elementType>::get_top(elementType &x)const {
	if (empty())return false;
	else {
		x = data[count - 1];
		return true;
	}
}

template <class elementType>
bool stack<elementType>::full() {
	if(count == maxlen)return true;
	return false;
}

template <class elementType>
bool stack<elementType>::push(const elementType x) {
	if (full())return false;
	data[count] = x;
	count++;
	return true;
}

template <class elementType>
bool stack<elementType>::pop() {
	if (empty())return false;
	count--;
	return true;
}


//扫描数字
bool isnumber(char x) {
	if (x >= '0'&&x <= '9')return true;
	else return false;
}

int priority(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '('||x==')')
		return -1;
	else if (x == '#')
		return -2;
	else return 0;
}

int calculate(string s)
{
	stack<int>number;
	stack<char>operate;
	char top;
	int a, b;

     for (unsigned int i = 0; i < s.size(); ++i) 
	{
		if (isnumber(s[i])) 
		{
			int Temp = 0;
			string temp;

			temp += s[i];
			while (isnumber(s[++i]))
				temp += s[i];
			for (unsigned int j = 0; j < temp.size(); ++j) 
			{
				Temp = Temp * 10 + temp[j] - 48;
			}
			number.push(Temp);
			i--;
		}
		if (!isnumber(s[i]))
		{
			if (operate.empty()) 
			{
				operate.push(s[i]);
			}
			else
			{
				operate.get_top(top);

				if (priority(s[i])>priority(top) || s[i] == '(') 
				{
					operate.push(s[i]);
				}
				else 
				{
					while (priority(s[i]) <= priority(top)) 
					{
						if (top == '#'&&s[i] == '#')
						{
							int answer;

						//operate.pop();
							number.get_top(answer);
							cout << "\n答案是：" << answer << endl;
							number.pop();
							return 0;
						}
						else if (top == '('&&s[i] == ')') {
							++i;
						}
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
						operate.get_top(top);
					}
					operate.push(s[i]);
				}
			}
		}
	}
}


