#include "model.h"
#include<String>
#include<QStack>
#include<iostream>
#include<QString>
#include<cstdlib>
#include<stdlib.h>

using namespace std;


const int maxlen=100;

bool model::isnumber(char x) {
    if (x >= '0'&&x <= '9')return true;
    else return false;
}

int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '!')
        return 3;
    else if (x == '(' || x == ')')
        return -1;
    else if (x == '&' || x == '|')
        return -2;
    else if (x == '#')
        return -3;
    else return 0;
}

model::model()
{

}

void model::get_str(QString s2)
{
    s1=s2;
}

QString model::calculator()
{
    string s;
    s=this->s1.toStdString();
    QStack<int>number;
    QStack<char>operate;
    char top;
    int a, b;
    s='#'+s+'#';

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
                if (s[i] == '!')
                {
                    i++;
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
                    a = number.top();
                    number.pop();
                    a = !a;
                    number.push(a);
                }
                else if (operate.empty())
                {
                    operate.push(s[i]);
                }
                else
                {
                    top=operate.top();

                    if (priority(s[i])>priority(top) || s[i] == '(')
                    {
                        operate.push(s[i]);
                    }//入栈高优先级运算符。
                    else
                    {
                        while (priority(s[i]) <= priority(top))
                        {
                            if (top == '#'&&s[i] == '#')
                            {
                                return QString::number(number.top());
                            }

                            else if (top == '('&&s[i] == ')') {
                                ++i;
                            }
                            else if(top==s[i])
                            {
                                    return "erro";
                        }
                            else {
                                a=number.top();
                                number.pop();
                                b=number.top();
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

                               if(a!=0)
                               {
                                   b=b/a;
                               }
                               else {

                                       return  "erro";

                               }
                            }
                            else if (top == '&') {
                                b = a && b;
                                number.push(b);
                            }
                            else if (top == '|') {
                                b = a || b;
                                number.push(b);
                            }


                            operate.pop();
                            top=operate.top();
                        }
                        operate.push(s[i]);
                   }
               }
            }
        }

}
