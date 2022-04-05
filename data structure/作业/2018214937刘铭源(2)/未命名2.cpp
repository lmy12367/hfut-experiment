#include "stack.h"
#include<iostream>
#include<string>
using namespace std;
int main() 
{
	string bds;
	cout << "输入一个用'#'开头和结尾的表达式：" << endl;
	cin >> bds;
	calculate(bds);
	return 0;
}

