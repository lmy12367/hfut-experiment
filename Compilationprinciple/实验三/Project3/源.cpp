
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "LR.h"

using namespace std;

//����״̬ջ
vector<int> status;
//�������ջ
vector<char> sign;
//����������ַ���
vector<char> inputStr;
//��¼������ַ���
string inputVal;
//�����ķ�
Grammar grammar;
//����LR������
LRAnalyseTable analyseTable;
//��ȡ������ַ���
void readStr();
//��ջ�����������,i=0,����status�е��ַ���,i=1,����sign�е��ַ�����i=2����inputStr
string vectTrancStr(int i);
//�ܿأ���������ַ������з���
void LRAnalyse();

int main()
{
    readStr();
    LRAnalyse();
    return 0;
}
//��ȡ������ַ���
void readStr() {
    char ch;
    cout << "LR��1��������������#�����������ˣ�����Դ��2018214937���������18-4��" << endl;
    cout << "������������ַ�����";
    cin >> ch;
    while (ch != '#') {
        inputVal += ch;
        inputStr.push_back(ch);
        cin >> ch;
    }
    //��#��������
    inputStr.push_back('#');
    inputVal += '#';
}
//��ջ�����������,i=0,����status�е��ַ���,i=1,����sign�е��ַ�����i=2����inputStr�е��ַ���
string vectTrancStr(int i) {
    char buf[100];
    int count = 0;
    //���״̬ջ
    if (i == 0) {
        vector<int>::iterator it = status.begin();
        //������ת��Ϊ�ַ���
        string str, tempStr;
        for (it; it != status.end(); it++) {
            stringstream ss;
            ss << *it;
            ss >> tempStr;
            str += tempStr;
        }
        return str;
    }
    //�������ջ
    else if (i == 1) {
        vector<char>::iterator it = sign.begin();
        for (it; it != sign.end(); it++) {
            buf[count] = *it;
            count++;
        }
    }
    //������������ַ���
    else {
        vector<char>::iterator it = inputStr.begin();
        for (it; it != inputStr.end(); it++) {
            buf[count] = *it;
            count++;
        }
    }
    buf[count] = '\0';
    string str(buf);
    return str;
}
//�ܿأ���������ַ������з���
void LRAnalyse() {
    //����
    int step = 1;
    //��״̬0��ջ
    status.push_back(0);
    //��#�������ջ
    sign.push_back('#');
    //�����ʼջ״̬
    cout << setw(10) << "����" << setw(10) << "״̬ջ" << setw(10) << "����ջ" << setw(10) << "���봮" << setw(25) << "����˵��" << endl;
    //��ʼ״̬
    int s = 0;
    //����֮ǰ��״̬
    int oldStatus;
    //��ȡ��ʼ����
    char ch = inputStr.front();
    //���action[s][ch] =="acc" ��������ɹ�
    while (analyseTable.action[s][analyseTable.getTerminalIndex(ch)] != "acc") {
        //��ȡ�ַ���
        string str = analyseTable.action[s][analyseTable.getTerminalIndex(ch)];
        //���strΪ�գ���������
        if (str.size() == 0) {
            cout << "����" << endl;
            cout << inputVal << "Ϊ�Ƿ����Ŵ�" << endl;
            return;
        }
        //��ȡr��s���������
        stringstream ss;
        ss << str.substr(1);
        ss >> s;
        //������ƽ�
        if (str.substr(0, 1) == "s") {
            cout << setw(10) << step << setw(10) << vectTrancStr(0) << setw(10) << vectTrancStr(1) << setw(10) << vectTrancStr(2) << setw(10) << "A" << "CTION[" << status.back() << "," << ch << "]=S" << s << "," << "״̬" << s << "��ջ" << endl;
            //���������ջ
            sign.push_back(ch);
            inputStr.erase(inputStr.begin());
            //��״̬������ջ
            status.push_back(s);
        }
        //����ǹ�Լ
        else if (str.substr(0, 1) == "r") {
            //��ȡ��S������ʽ
            string formu = grammar.formula[s];
            //cout<<s<<endl;
            int strSize = formu.size();
            //������ʽת��Ϊ�ַ�����
            char buf[100];
            strcpy_s(buf, formu.c_str());
            //��ȡ����ʽ�����ַ�
            char nonTerCh = buf[0];
            //��ȡ����ջ�ĳ�ջ����
            int popCount = strSize - 3;
            //�������
            vector<int>::reverse_iterator rit = status.rbegin();
            int i = 0;
            for (rit; rit != status.rend(); rit++) {
                i++;
                if (i == popCount + 1) {
                    oldStatus = *rit;
                    break;
                }
            }
            int r = s;
            //�޸�s
            s = analyseTable.goTo[oldStatus][analyseTable.getNonTerminalIndex(nonTerCh)];
            cout << setw(10) << step << setw(10) << vectTrancStr(0) << setw(10) << vectTrancStr(1) << setw(10) << vectTrancStr(2) << setw(10) << "r" << r << (string)":" + grammar.formula[r] + (string)"��Լ,GOTO{" << oldStatus << "," << nonTerCh << ")=" << s << "��ջ" << endl;
            //�Է���ջ���г�ջ��״̬ջ���г�ջ
            for (int i = 0; i < popCount; i++) {
                sign.pop_back();
                status.pop_back();
            }
            //�ٶԲ���ʽ�Ŀ�ʼ������ջ
            sign.push_back(nonTerCh);
            //�ٰ��µ�״̬��ջ
            status.push_back(s);
        }
        else {
            //ʲô��������
        }
        //��������1
        step++;

        //��ȡջ��״̬
        s = status.back();
        //��ȡ������ַ�
        ch = inputStr.front();
    }
    cout << setw(10) << step << setw(10) << vectTrancStr(0) << setw(10) << vectTrancStr(1) << setw(10) << vectTrancStr(2) << setw(10) << "A" << "cc:�����ɹ�" << endl;
    cout << inputVal << "Ϊ�Ϸ����Ŵ�" << endl;
}
