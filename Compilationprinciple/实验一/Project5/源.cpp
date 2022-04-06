#include<iostream>
#include<stdio.h>
#include<cstring>
#include<iomanip>
using namespace std;
//k数组 关键字表
//s数组 分界符表    分界符、算术运算符和关系运算符放在3张 s 表中
//id标识符  ci常数
//instring 数组为输入源程序的单词缓存。
//outtoken 记录为输出内部表示缓存。
//symbol 分析//后的注释  constant常数分析  alphabet 标识符和关键字分析  analysis分析函数，根据输入字符判断调用哪一个函数。   show为输出函数
//t 为单词的种类。关键字的 t=１；分界符的 t = ２；算术运算符的 t = ３；关系运算符的 t = ４；无符号数的 t = ５；标识符的 t = ６
//row行 line列，单词的位置

//根据实验报告中的表进行创建
const char* k[8] = { "do","end","for","if","printf","scanf","then","while" };   //关键字表
const char* s1[6] = { ",",";","(",")","[","]" };//分解符表
const char* s2[6] = { "+","-","*","/","++","--", };//算术运算符表
const char* s3[7] = { "<=",">",">=","=",">",">=","<>" };//关系运算符表

//全局变量
int row = 1, line = 1;//全局变量，保存行列数
int t, p = 0;//种别码,以及记录指针
char instring[100];//保存输入的程序缓存
char outtoken[10];//用于输出
char ci[8], id[8];//暂时保存数字和字符

//函数声明
void analysis();//分析函数,决定调用什么函数进行分析
void symbol();//分析以非字母数字开头的字符
void constant();//分析常数
void alphabet();//分析标识符和关键字
void show();//输出显示函数
bool isnumber(char x);//判断字母
bool isalpha(char x);//判断数字

//程序入口
int main()
{
	cout << "请输入程序（以#号为结束)（2018214937刘铭源软件工程18-4班）：" << endl;
	do {          //写入源程序
		instring[p++] = getchar();
	} while (instring[p - 1] != '#');
	getchar();
	instring[p - 1] = '\0';//吃掉#
	p = 0;//指针归零
	cout << left;
	cout << setw(6) << "单词" << "        " << setw(6) << "二元序列" << "          " << setw(6) << "类型" << "        " << setw(6) << "位置(行，列)" << endl;
	while (p < strlen(instring))  //扫描输入字符
	{
		analysis();
		show();
	}
	cout << endl << endl << endl << endl << endl;
	return 0;
}

bool isnumber(char x)//判断数字
{
	return x >= '0' && x <= '9';
}

bool isalpha(char x)//判断字母
{
	return (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z');
}

void analysis()    //分析函数，调用其他分析函数
{
	strcpy_s(outtoken, 2, "\0");//清空outtoken
	while (instring[p] == ' ' || instring[p] == '\n')//不等于空格和回车则p++指向下一个
	{
		if (instring[p] == '\n')    //回车即换行了，row++
		{
			row++;
			line = 1;
		}
		p++;
	}   //执行完之后指向之后第一个不是空格的字符
	char ch = instring[p];
	if (isalpha(ch))
		alphabet();
	else if (isnumber(ch))
		constant();
	else
		symbol();
}

void constant()//分析常数
{
	strcpy_s(ci, 2, "\0"); //使用之前清空ci
	t = 5;
	int i = 0;
	while (isnumber(instring[p]))   //数字存入ci
		ci[i++] = instring[p++];
	while (isalpha(instring[p]) || isnumber(instring[p])) //如果数字之后接着字符
	{
		ci[i++] = instring[p++];
		t = 7;    //即出错
	}
	ci[i] = '\0';//结束符
	strcpy_s(outtoken, strlen(ci) + 1, ci);
	line++;
	return;
}

void alphabet()//分析标识符或者关键字
{
	strcpy_s(id, 2, "\0");//使用之前清空id
	int i = 0;
	while (isalpha(instring[p]) || isnumber(instring[p]))  //读取连续的字母数字序列
		id[i++] = instring[p++];  //p指向连续序列之后的第一个
	id[i] = '\0';//结束符
	for (i = 0; i < 8; i++)   //查关键字表
		if (strcmp(id, k[i]) == 0)
		{
			t = 1;             //表示关键字
			line++;
			strcpy_s(outtoken, strlen(id) + 1, id);
			return;   //是关键字直接退出程序
		}
	for (i = 0; i < strlen(id); i++)//查看是否是标识符
		if (!(isalpha(id[i]) || isnumber(id[i])))
		{
			t = 7;//即出错
			strcpy_s(outtoken, strlen(id) + 1, id);
			line++;
			return;
		}
	line++;
	t = 6;//不是关键字且没有出错即为标识符
	strcpy_s(outtoken, strlen(id) + 1, id);
}


void symbol()
{
	char ch = instring[p++];
	char ch2 = instring[p];
	t = 7;//先设置成出错标志，如果没有找到即为error
	switch (ch)   //判断种别码t
	{
	case '+':
		if (ch2 == '+')    //++运算符
			t = 3; break;    //3表示算数运算符
	case '-':
		if (ch2 == '-')    //--运算符
			t = 3; break;   //3表示算数运算符
	case '>':    //> 和>=
		if (ch2 == '=')
			t = 4; break;    //4表示关系运算符
	case '<':  //<和 <=
		if (ch2 == '=' || ch2 == '>')
			t = 4; break;
	}
	//if语句判断具有两个符号的运算符
	if (ch == '>' && ch2 == '=' || ch == '<' && ch2 == '=' || ch == '<' && ch2 == '>' || ch == '+' && ch2 == '+' || ch == '-' && ch2 == '-')
	{
		p++;
		outtoken[0] = ch;
		outtoken[1] = ch2;
		outtoken[2] = '\0';
		line++;
		return;
	}
	else
	{
		char chq[2];
		chq[0] = ch;
		chq[1] = '\0';
		for (int i = 0; i < 6; i++)  //分解符比较
			if (strcmp(chq, s1[i]) == 0)
			{
				t = 2;             //表示分界线符
				break;
			}
		for (int i = 0; i < 6; i++)  //算术运算符比较
			if (strcmp(chq, s2[i]) == 0)
			{
				t = 3;             //表示算术运算符
				break;
			}
		for (int i = 0; i < 7; i++)  //关系运算符比较
			if (strcmp(chq, s3[i]) == 0)
			{
				t = 4;
				break;
			}
	}
	line++;
	outtoken[0] = ch;
	outtoken[1] = '\0';
	return;
}

void show()   //根据outtoken和t输出
{
	cout << left;
	if (t == 7)
		cout << setw(6) << outtoken << "        " << setw(6) << "Error" << setw(11) << " " << setw(10) << "Error";
	else
	{
		cout << left;
		cout << setw(6) << outtoken << "        " << "<" << t << "," << outtoken;
		cout << setw(6 - strlen(outtoken)) << ">" << "        ";
		switch (t)
		{
		case 1:cout << left << setw(10) << "关键字"; break;
		case 2:cout << left << setw(10) << "分界符"; break;
		case 3:cout << left << setw(10) << "算术运算符"; break;
		case 4:cout << left << setw(10) << "关系运算符"; break;
		case 5:cout << left << setw(10) << "无符号数"; break;
		case 6:cout << left << setw(10) << "标识符"; break;
		}
	}
	cout << "        " << "(" << row << "," << line - 1 << ")" << endl;
}
