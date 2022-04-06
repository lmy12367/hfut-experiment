#pragma once
#ifndef _LR_
#define _LR_
#include<cstring>
using namespace std;

class Grammar {
public:
    //����ʽ�ĸ���
    int grammarNum;
    //�������ʽ����
    string formula[100] = { " ","E->E+T","E->T","T->T*F","T->F","F->(E)","F->i" };

    Grammar() {
        grammarNum = 6;
    }
};
//����LR�ķ��ķ�����
class LRAnalyseTable {
public:
    char terminalChar[100] = { 'i','+','*','(',')','#' };
    //�����ս���ĸ���
    int terNum = 6;
    char nonTerminalChar[100] = { 'E','T','F' };
    //������ս���ĸ���
    int nonTerNum = 3;
    //����״̬��
    int statusNum = 12;
    string action[12][6] = { {"s5","","","s4","",""},{"","s6","","","","acc"},{"","r2","s7","","r2","r2"},{"","r4","r4","","r4","r4"},{"s5","","","s4","",""},{"","r6","r6","","r6","r6"},{"s5","","","s4","",""}
    ,{"s5","","","s4","",""},{"","s6","","","s11",""},{"","r1","s7","","r1","r1"},{"","r3","r3","","r3","r3"},{"","r5","r5","","r5","r5"} };
    int goTo[12][3] = { {1,2,3},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{8,2,3},{-1,-1,-1},{-1,9,3},{-1,-1,10},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1} };
    //��ȡ�ս��������
    int getTerminalIndex(char var) {
        for (int i = 0; i < terNum; i++) {
            if (terminalChar[i] == var) {
                return i;
            }
        }
        return -1;
    }
    //��ȡ���ս��������
    int getNonTerminalIndex(char var) {
        for (int i = 0; i < nonTerNum; i++) {
            if (nonTerminalChar[i] == var) {
                return i;
            }
        }
        return -1;
    }
};

#endif // _LR_
