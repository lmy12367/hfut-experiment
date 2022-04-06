#include<iostream>
#include<stdio.h>
#include<cstring>
#include<iomanip>
using namespace std;
//k���� �ؼ��ֱ�
//s���� �ֽ����    �ֽ��������������͹�ϵ���������3�� s ����
//id��ʶ��  ci����
//instring ����Ϊ����Դ����ĵ��ʻ��档
//outtoken ��¼Ϊ����ڲ���ʾ���档
//symbol ����//���ע��  constant��������  alphabet ��ʶ���͹ؼ��ַ���  analysis�������������������ַ��жϵ�����һ��������   showΪ�������
//t Ϊ���ʵ����ࡣ�ؼ��ֵ� t=�����ֽ���� t = ��������������� t = ������ϵ������� t = �����޷������� t = ������ʶ���� t = ��
//row�� line�У����ʵ�λ��

//����ʵ�鱨���еı���д���
const char* k[8] = { "do","end","for","if","printf","scanf","then","while" };   //�ؼ��ֱ�
const char* s1[6] = { ",",";","(",")","[","]" };//�ֽ����
const char* s2[6] = { "+","-","*","/","++","--", };//�����������
const char* s3[7] = { "<=",">",">=","=",">",">=","<>" };//��ϵ�������

//ȫ�ֱ���
int row = 1, line = 1;//ȫ�ֱ���������������
int t, p = 0;//�ֱ���,�Լ���¼ָ��
char instring[100];//��������ĳ��򻺴�
char outtoken[10];//�������
char ci[8], id[8];//��ʱ�������ֺ��ַ�

//��������
void analysis();//��������,��������ʲô�������з���
void symbol();//�����Է���ĸ���ֿ�ͷ���ַ�
void constant();//��������
void alphabet();//������ʶ���͹ؼ���
void show();//�����ʾ����
bool isnumber(char x);//�ж���ĸ
bool isalpha(char x);//�ж�����

//�������
int main()
{
	cout << "�����������#��Ϊ����)��2018214937����Դ�������18-4�ࣩ��" << endl;
	do {          //д��Դ����
		instring[p++] = getchar();
	} while (instring[p - 1] != '#');
	getchar();
	instring[p - 1] = '\0';//�Ե�#
	p = 0;//ָ�����
	cout << left;
	cout << setw(6) << "����" << "        " << setw(6) << "��Ԫ����" << "          " << setw(6) << "����" << "        " << setw(6) << "λ��(�У���)" << endl;
	while (p < strlen(instring))  //ɨ�������ַ�
	{
		analysis();
		show();
	}
	cout << endl << endl << endl << endl << endl;
	return 0;
}

bool isnumber(char x)//�ж�����
{
	return x >= '0' && x <= '9';
}

bool isalpha(char x)//�ж���ĸ
{
	return (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z');
}

void analysis()    //��������������������������
{
	strcpy_s(outtoken, 2, "\0");//���outtoken
	while (instring[p] == ' ' || instring[p] == '\n')//�����ڿո�ͻس���p++ָ����һ��
	{
		if (instring[p] == '\n')    //�س��������ˣ�row++
		{
			row++;
			line = 1;
		}
		p++;
	}   //ִ����֮��ָ��֮���һ�����ǿո���ַ�
	char ch = instring[p];
	if (isalpha(ch))
		alphabet();
	else if (isnumber(ch))
		constant();
	else
		symbol();
}

void constant()//��������
{
	strcpy_s(ci, 2, "\0"); //ʹ��֮ǰ���ci
	t = 5;
	int i = 0;
	while (isnumber(instring[p]))   //���ִ���ci
		ci[i++] = instring[p++];
	while (isalpha(instring[p]) || isnumber(instring[p])) //�������֮������ַ�
	{
		ci[i++] = instring[p++];
		t = 7;    //������
	}
	ci[i] = '\0';//������
	strcpy_s(outtoken, strlen(ci) + 1, ci);
	line++;
	return;
}

void alphabet()//������ʶ�����߹ؼ���
{
	strcpy_s(id, 2, "\0");//ʹ��֮ǰ���id
	int i = 0;
	while (isalpha(instring[p]) || isnumber(instring[p]))  //��ȡ��������ĸ��������
		id[i++] = instring[p++];  //pָ����������֮��ĵ�һ��
	id[i] = '\0';//������
	for (i = 0; i < 8; i++)   //��ؼ��ֱ�
		if (strcmp(id, k[i]) == 0)
		{
			t = 1;             //��ʾ�ؼ���
			line++;
			strcpy_s(outtoken, strlen(id) + 1, id);
			return;   //�ǹؼ���ֱ���˳�����
		}
	for (i = 0; i < strlen(id); i++)//�鿴�Ƿ��Ǳ�ʶ��
		if (!(isalpha(id[i]) || isnumber(id[i])))
		{
			t = 7;//������
			strcpy_s(outtoken, strlen(id) + 1, id);
			line++;
			return;
		}
	line++;
	t = 6;//���ǹؼ�����û�г���Ϊ��ʶ��
	strcpy_s(outtoken, strlen(id) + 1, id);
}


void symbol()
{
	char ch = instring[p++];
	char ch2 = instring[p];
	t = 7;//�����óɳ����־�����û���ҵ���Ϊerror
	switch (ch)   //�ж��ֱ���t
	{
	case '+':
		if (ch2 == '+')    //++�����
			t = 3; break;    //3��ʾ���������
	case '-':
		if (ch2 == '-')    //--�����
			t = 3; break;   //3��ʾ���������
	case '>':    //> ��>=
		if (ch2 == '=')
			t = 4; break;    //4��ʾ��ϵ�����
	case '<':  //<�� <=
		if (ch2 == '=' || ch2 == '>')
			t = 4; break;
	}
	//if����жϾ����������ŵ������
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
		for (int i = 0; i < 6; i++)  //�ֽ���Ƚ�
			if (strcmp(chq, s1[i]) == 0)
			{
				t = 2;             //��ʾ�ֽ��߷�
				break;
			}
		for (int i = 0; i < 6; i++)  //����������Ƚ�
			if (strcmp(chq, s2[i]) == 0)
			{
				t = 3;             //��ʾ���������
				break;
			}
		for (int i = 0; i < 7; i++)  //��ϵ������Ƚ�
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

void show()   //����outtoken��t���
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
		case 1:cout << left << setw(10) << "�ؼ���"; break;
		case 2:cout << left << setw(10) << "�ֽ��"; break;
		case 3:cout << left << setw(10) << "���������"; break;
		case 4:cout << left << setw(10) << "��ϵ�����"; break;
		case 5:cout << left << setw(10) << "�޷�����"; break;
		case 6:cout << left << setw(10) << "��ʶ��"; break;
		}
	}
	cout << "        " << "(" << row << "," << line - 1 << ")" << endl;
}
