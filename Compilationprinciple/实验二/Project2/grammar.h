#pragma once
#ifndef _grammar_
#define _grammar_

#include <list>
#include <set>
#include <vector>
#define N 50

using namespace std;

//�����ķ��࣬�����ķ������ͼ�¼�����ķ�
class Grammar {
public:
    //���������ķ�
    list<char> grammarTable[N][N];
    //�����ս��ַ�
    char terminalChar[N];
    //�����ս��ַ��ĸ���
    int terNum;
    //����ÿ�еĲ���ʽ�ĸ���
    int countEachRow[N];
    //�����ķ�����
    int count;

    Grammar() {
        terNum = 0;
    }
};
//����ÿ�����ս����FIRST����
class FIRST {
public:
    //����ÿ�����ս����FIRST����
    set<char> First[N];
    //������ս��
    char nonTerminal[N];
    //�����Ƿ�������Ӧ��FIRST��
    bool flag[N] = { 0 };
    //�����Ѽ���FIRST���ĸ���
    int calCount;

    FIRST() {
        calCount = 0;
    }

};
class Position {
public:
    int x;
    int y;
    Position() {
        x = -1;
        y = -1;
    }
};
//����ÿ�����ս����FOLLOW����
class FOLLOW {
public:
    //����ÿ�����ս����FOLLOW����
    set<char> Follow[N];
    //������ս��
    char nonTerminal[N];
    //�����Ƿ�������Ӧ��FOLLOW��
    bool flag[N] = { 0 };
    //�����Ѽ���Follow���ĸ���
    int calCount;
    //�������ʽ������
    vector<Position> position[N];

    FOLLOW() {
        calCount = 0;
    }
};

#endif // _grammar_