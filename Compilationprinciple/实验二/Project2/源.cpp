#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <stack>
#include "grammar.h"

using namespace std;

//����һ���ķ������
Grammar grammar;
//����FIRST��
FIRST first;
//���塤FOLLOW��
FOLLOW follow;
//����Ԥ�������
string analyseTable[N][N];
//���һ���ַ��Ƿ�Ϊ���ս��ַ�
bool isNonTerminal(char var);
//���һ���ַ��Ƿ�Ϊ����
bool isEmpty(char var);
//���һ���ַ��Ƿ�Ϊ�ս��ַ�
bool isTerminal(char var);
//�ӿ���̨��ȡ�ķ�������
void readGrammar();
//�ж�һ������ʽ�Ƿ������FIRST�����ܷ���true������false
bool canCalFIRST(int i);
//�����ܹ�����FIRST���Ĳ���ʽ
void calFIRST();
//��ȡ����ս��ַ����ڵ�����
int getNonTerminalIndex(char var);
//����i��FIRST���Ƿ��п���
bool hasEmpty(int i);
//�ж��Ƿ��ܼ���FIRST��(���ַ������ս��)
bool adjustFIRST(int i);
//�����������ϵĲ�������set(i) = set(i) �� set(j)
void calSetUnion(int i, int j);
//����calCount
int reloadCalCount();
//����FIRST��
void calFIRSTSet();
//���first��
void printFIRST();
//��ȡ������ÿһ�����ս���ڲ���ʽ�����������������������У�
void getPosition();
//��FIRST��ȥ�ռ���FOLLOW����i����FOLLOW,i����FIRST��
void calFollowAndFirstUnion(int i, int j);
//��������FOLLOW���Ĳ���,��set(i) = set(i) �� set(j)
void calFollowAndFollowUnion(int i, int j);
//����FOLLOW����calCount
int reloadFOLLOWCalCount();
//����FOLLOW��
void calFOLLOWSet();
//��ȡÿһ�����ս����FOLLOW��
void getFollowSet();
//��ӡFOLLOW��
void printFOLLOW();
//��ȡ�ս����Grammar.terminal[]�е�����
int getTerminalIndex(char var);
//������������ʽ��First��,i,jΪ��Ӧ����ʽ������
set<char> buildFirstForOne(int i, int j);
//������ʽ�ַ�תΪ�ַ���,i,jΪ��Ӧ����ʽ������
string charToString(int i, int j);
//����Ԥ�������
void bulidAnalyseTable();
//��ӡԤ�������
void printAnalyseTable();
//��vector�е��ַ�ת��Ϊ�ַ���
string veToString(vector<char>& vec);
//���ַ�������ѡ���ת��Ϊ�ַ���
string toString(char buf[], int start, int end);
//���ĺ��������﷨���з���
void analyseGrammar();


int main()
{
    readGrammar();
    calFIRSTSet();
    printFIRST();

    getFollowSet();
    printFOLLOW();
    bulidAnalyseTable();
    printAnalyseTable();
    analyseGrammar();
    return 0;
}
//�ӿ���̨��ȡ�ķ�������
void readGrammar() {
    //��������ĵ�i���ķ�
    string str;
    //�ѵ�i���ķ�ת��Ϊ�ַ�����
    char buf[100] = { 0 };
    int i = 0;
    int index = 0;
    int count = 0;
    //��ʱ������ս��ַ�
    set<char> ter;
    cout << "�������ķ�����������#�س�������������@���棬���ƣ�2018214937����Դ �������18-4�ࣩ��" << endl;
    cin >> str;
    strcpy_s(buf, str.c_str());
    while (str != "#") {
        i = 0;
        count = 0;
        grammar.grammarTable[index][count].push_back(buf[i]);
        //��ȥ"->"
        i += 3;
        //����Ƿ񵽱߽�
        while ((int)buf[i] != 0) {
            //�����⵽"|"
            if ((int)buf[i] == 124) {
                count++;
                i++;
                //������ʼ�ַ�
                grammar.grammarTable[index][count].push_back(buf[0]);
                //�������ʽ��ÿ���ַ�
                grammar.grammarTable[index][count].push_back(buf[i]);
                //������ս��ַ��򱣴�
                if (isTerminal(buf[i])) {
                    ter.insert(buf[i]);
                }
                i++;
            }
            else {
                //�������ʽ��ÿ���ַ�
                grammar.grammarTable[index][count].push_back(buf[i]);
                //������ս��ַ��򱣴�
                if (isTerminal(buf[i])) {
                    ter.insert(buf[i]);
                }
                i++;
            }
        }
        grammar.countEachRow[index] = count + 1;
        index++;
        cin >> str;
        strcpy_s(buf, str.c_str());
    }
    //�����ķ�����
    grammar.count = index;
    //�����ս��ַ�
    set<char>::iterator it = ter.begin();
    for (it; it != ter.end(); it++) {
        grammar.terminalChar[grammar.terNum] = *it;
        grammar.terNum++;
    }
    //ע����Ҫ���������"#"������
    grammar.terminalChar[grammar.terNum] = '#';
    grammar.terNum++;
}
//���һ���ַ��Ƿ�Ϊ�ս��ַ�,ע�����@Ҳ�����ս��ַ�
bool isTerminal(char var) {
    if ((!isNonTerminal(var)) && (!isEmpty(var))) {
        return true;
    }
    else {
        return false;
    }
}
//���һ���ַ��Ƿ�Ϊ���ս��ַ�
bool isNonTerminal(char var) {
    if (((int)var > 64) && ((int)var < 91)) {
        return true;
    }
    else {
        return false;
    }
}
//���һ���ַ��Ƿ�Ϊ����
bool isEmpty(char var) {
    if ((int)var == 64) {
        return true;
    }
    else {
        return false;
    }
}
//��ȡ����ս��ַ����ڵ�����
int getNonTerminalIndex(char var) {
    int index = 0;
    //��ȡ���ս��ַ����ڵ�����
    for (index; index < grammar.count; index++) {
        if ((int)var == (int)grammar.grammarTable[index][0].front()) {
            break;
        }
    }
    return index;

}
//����i��FIRST���Ƿ��п���
bool hasEmpty(int i) {
    set<char>::iterator it = first.First[i].begin();
    for (it; it != first.First[i].end(); it++) {
        if ((int)*it == 64) {
            return true;
        }
    }
    return false;
}
//�����������ϵĲ�������set(i) = set(i) �� set(j)������set(j)��ȥ������
void calSetUnion(int i, int j) {
    set<char>::iterator it = first.First[j].begin();
    //����п��֣���ȥ����
    if (hasEmpty(j)) {
        for (it; it != first.First[j].end(); it++) {
            if (!isEmpty(*it)) {
                first.First[i].insert(*it);
            }
        }
    }
    else {
        for (it; it != first.First[j].end(); it++) {
            first.First[i].insert(*it);
        }
    }
}
//����calCount
int reloadCalCount() {
    int count = 0;
    for (int i = 0; i < grammar.count; i++) {
        if (first.flag[i] == true) {
            count++;
        }
    }
    first.calCount = count;
    return count;
}
//����FIRST��
void calFIRSTSet() {
    while (reloadCalCount() != grammar.count) {
        //ɨ��ÿһ������ʽ
        for (int i = 0; i < grammar.count; i++) {
            //���û�м���FIRST��
            if (!first.flag[i]) {
                for (int j = 0; j < grammar.countEachRow[i]; j++) {
                    list<char>::iterator it = grammar.grammarTable[i][j].begin();
                    //��ȡ����ʽ�����ַ�
                    it++;
                    //���itû�е��߽粢���Ƿ��ս��ַ����Ҳ����Ѿ�����FIRST������FIRST���п���
                    while (it != grammar.grammarTable[i][j].end() && isNonTerminal(*it) && first.flag[getNonTerminalIndex(*it)] && hasEmpty(getNonTerminalIndex(*it))) {
                        first.nonTerminal[i] = grammar.grammarTable[i][0].front();
                        // first.flag[i] = true;
                        calSetUnion(i, getNonTerminalIndex(*it));
                        it++;
                    }
                    //���it���߽磬˵��ÿ�����ս����FIRST�����Ѿ�������������Ҷ����п���
                    if (it == grammar.grammarTable[i][j].end()) {
                        //�ѿ��ּ���
                        first.First[i].insert('@');
                        first.flag[i] = true;
                        continue;
                    }
                    //����itû�е��߽�
                    else {
                        //���*itΪ�ս��
                        if (isTerminal(*it)) {
                            first.nonTerminal[i] = grammar.grammarTable[i][0].front();
                            first.flag[i] = true;
                            //���ս��ַ����浽FIRST��
                            first.First[i].insert(*it);
                        }
                        //����Ƿ��ս��
                        else if (isNonTerminal(*it)) {
                            //����Ѿ������FIRST�������FIrst������
                            if (first.flag[getNonTerminalIndex(*it)]) {
                                first.nonTerminal[i] = grammar.grammarTable[i][0].front();
                                first.flag[i] = true;
                                calSetUnion(i, getNonTerminalIndex(*it));
                            }
                            //û�м����
                            else {
                                first.flag[i] = false;
                            }
                        }
                        //����ǿ���
                        else {
                            first.nonTerminal[i] = grammar.grammarTable[i][0].front();
                            first.flag[i] = true;
                            //���ս��ַ����浽FIRST��
                            first.First[i].insert(*it);
                        }
                    }
                }
            }
            //�������FIRST��
            else {
                continue;
            }
        }
    }
}
//���first��
void printFIRST() {
    cout << "FIRST�����£�" << endl;
    for (int i = 0; i < grammar.count; i++) {
        cout << "FIRST" << "(" << first.nonTerminal[i] << ")" << "=";
        set<char>::iterator it;
        for (it = first.First[i].begin(); it != first.First[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//��ȡ������ÿһ�����ս���ڲ���ʽ�����������������������У�
void getPosition() {
    for (int i = 0; i < grammar.count; i++) {
        list<char>::iterator it = grammar.grammarTable[i][0].begin();
        for (int j = 0; j < grammar.count; j++) {
            for (int k = 0; k < grammar.countEachRow[j]; k++) {
                list<char>::iterator itp = grammar.grammarTable[j][k].begin();
                itp++;
                for (itp; itp != grammar.grammarTable[j][k].end(); itp++) {
                    if ((int)*it == (int)*itp) {
                        Position pos;
                        pos.x = j;
                        pos.y = k;
                        //������λ��
                        follow.position[i].push_back(pos);
                    }
                }
            }
        }
    }
}
//��FIRST��ȥ�ռ���FOLLOW����i����FOLLOW,i����FIRST��
void calFollowAndFirstUnion(int i, int j) {
    set<char>::iterator it = first.First[j].begin();
    //����п��֣���ȥ����
    if (hasEmpty(j)) {
        for (it; it != first.First[j].end(); it++) {
            if (!isEmpty(*it)) {
                follow.Follow[i].insert(*it);
            }
        }
    }
    else {
        for (it; it != first.First[j].end(); it++) {
            follow.Follow[i].insert(*it);
        }
    }
}
//����FOLLOW����calCount
int reloadFOLLOWCalCount() {
    int count = 0;
    for (int i = 0; i < grammar.count; i++) {
        if (follow.flag[i] == true) {
            count++;
        }
    }
    follow.calCount = count;
    return count;
}
//��������FOLLOW���Ĳ���,��set(i) = set(i) �� set(j)
void calFollowAndFollowUnion(int i, int j) {
    set<char>::iterator it = follow.Follow[j].begin();
    for (it; it != follow.Follow[j].end(); it++) {
        follow.Follow[i].insert(*it);
    }
}
//����FOLLOW��
void calFOLLOWSet() {
    //���ڿ�ʼ����S���轫"#"������FOLLOW��
    follow.Follow[0].insert('#');
    while (reloadFOLLOWCalCount() != grammar.count) {
        for (int i = 0; i < grammar.count; i++) {
            //���û�м���FOLLOW���������
            if (!follow.flag[i]) {
                vector<Position>::iterator it = follow.position[i].begin();
                for (it; it != follow.position[i].end(); it++) {
                    int m = (*it).x;
                    int n = (*it).y;
                    list<char>::iterator  itp = grammar.grammarTable[m][n].begin();
                    //ʹ��ָ�����ַ�
                    itp++;
                    for (itp; itp != grammar.grammarTable[m][n].end(); itp++) {
                        if ((int)(*itp) == (int)grammar.grammarTable[i][0].front()) {
                            itp++;
                            break;
                        }
                    }
                    //itp��ָ���β�������Ƿ��ս����FIRST�����п��֣���������
                    while (itp != grammar.grammarTable[m][n].end() && isNonTerminal(*itp) && hasEmpty(getNonTerminalIndex(*itp))) {
                        int index = getNonTerminalIndex(*itp);
                        follow.nonTerminal[i] = grammar.grammarTable[i][0].front();
                        //�����ս��ȥ���ֵ�FIRST������FOLLOW��
                        calFollowAndFirstUnion(i, index);
                        itp++;
                    }
                    //���itpû��ָ��endָ�룬˵�����ַ�Ϊ�ս��ַ�����ս��ַ������
                    if (itp != grammar.grammarTable[m][n].end()) {
                        if (isTerminal(*itp)) {
                            follow.nonTerminal[i] = grammar.grammarTable[i][0].front();
                            //�����ս��ַ�����FOLLOW��
                            follow.Follow[i].insert(*itp);
                            //����Ѿ�����÷��ս����FOLLOW��
                            follow.flag[i] = true;
                        }
                        else if (isNonTerminal(*itp)) {
                            int index = getNonTerminalIndex(*itp);
                            follow.nonTerminal[i] = grammar.grammarTable[i][0].front();
                            //�����ս��ȥ���ֵ�FIRST������FOLLOW��
                            calFollowAndFirstUnion(i, index);
                            //����Ѿ�����÷��ս����FOLLOW��
                            follow.flag[i] = true;
                        }
                        //����ʲôҲ����
                        else {

                        }
                    }
                    //itpָ��endָ��
                    else {
                        if (!follow.flag[m]) {
                            //���û�м�������false
                            follow.flag[i] = false;
                        }
                        else {
                            follow.nonTerminal[i] = grammar.grammarTable[i][0].front();
                            calFollowAndFollowUnion(i, m);
                            //����Ѿ�����÷��ս����FOLLOW��
                            follow.flag[i] = true;
                        }
                    }
                }
            }
        }
    }
}
//��ȡÿһ�����ս����FOLLOW��
void getFollowSet() {
    getPosition();
    calFOLLOWSet();
}
//��ӡFOLLOW��
void printFOLLOW() {
    cout << "FOLLOW�����£�" << endl;
    for (int i = 0; i < grammar.count; i++) {
        cout << "FOLLOW" << "(" << follow.nonTerminal[i] << ")" << "=";
        set<char>::iterator it;
        for (it = follow.Follow[i].begin(); it != follow.Follow[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//��ȡ�ս����Grammar.terminal[]�е�����
int getTerminalIndex(char var)
{
    for (int i = 0; i < grammar.terNum; i++) {
        if ((int)grammar.terminalChar[i] == (int)var) {
            return i;
        }
    }
    //�����ڷ���-1
    return -1;
}
//������������ʽ��First��,i,jΪ��Ӧ����ʽ������
set<char> buildFirstForOne(int i, int j) {
    //���弯��
    set<char> temp;
    list<char>::iterator it = grammar.grammarTable[i][j].begin();
    it++;
    for (it; it != grammar.grammarTable[i][j].end(); it++) {
        //���û�г��磬�����Ƿ��ս��ַ�������FIRST�����п���
        while (it != grammar.grammarTable[i][j].end() && isNonTerminal(*it) && hasEmpty(getNonTerminalIndex(*it))) {
            int index = getNonTerminalIndex(*it);
            set<char>::iterator itp = first.First[index].begin();
            for (itp; itp != first.First[index].end(); itp++) {
                //������ǿ��������temp����
                if (!isEmpty(*itp)) {
                    temp.insert(*itp);
                }
            }
            it++;
        }
        //û�г���
        if (it != grammar.grammarTable[i][j].end()) {
            //������ս��ַ�����֣�����ս��ַ��FIRST��
            if (isTerminal(*it) || isEmpty(*it)) {
                temp.insert(*it);
                return temp;
            }
            //����Ϊ���ս��
            else {
                int index = getNonTerminalIndex(*it);
                set<char>::iterator itpt = first.First[index].begin();
                for (itpt; itpt != first.First[index].end(); itpt++) {
                    temp.insert(*itpt);
                }
                return temp;
            }
        }
        //������磬���˳�
        else {
            //˵�����Ƿ��ս��ַ����Ҷ����п���
            temp.insert('@');
            return temp;
        }
    }
}
//������ʽ�ַ�תΪ�ַ���,i,jΪ��Ӧ����ʽ������
string charToString(int i, int j) {
    char buf[100] = { 0 };
    int count = 0;
    list<char>::iterator it = grammar.grammarTable[i][j].begin();
    it++;
    for (it; it != grammar.grammarTable[i][j].end(); it++) {
        buf[count] = *it;
        count++;
    }
    buf[count] = '\0';
    string str(buf);
    return str;
}
//����Ԥ�������
void bulidAnalyseTable() {
    bool flag = false;
    //����ÿ�����ս��
    for (int i = 0; i < grammar.count; i++) {
        //����ÿ�����ս��ַ��Ĳ���ʽ
        for (int j = 0; j < grammar.countEachRow[i]; j++) {
            flag = false;
            set<char> firstSet = buildFirstForOne(i, j);
            set<char>::iterator it = firstSet.begin();
            for (it; it != firstSet.end(); it++) {
                //���FIRST�����ڿ��֣����ϱ��
                if (isEmpty(*it)) {
                    flag = true;
                }
                //������Ӧ�Ĳ���ʽ����Ԥ�������
                else {
                    //���ķ��ַ�תΪ�ַ���
                    string str = charToString(i, j);
                    analyseTable[i][getTerminalIndex(*it)] = str;
                }
            }
            //����ʽ��FIRST���к��п���
            if (flag) {
                //��ȡiΪ�����ķ��ս��ַ���FOLLOW��
                set<char>::iterator it = follow.Follow[i].begin();
                for (it; it != follow.Follow[i].end(); it++) {
                    if (isTerminal(*it)) {
                        analyseTable[i][getTerminalIndex(*it)] = (string)"@";
                    }
                }
            }
            //����ʽ��FIRST���в����п���
            else {
                //��ȡiΪ�����ķ��ս��ַ���FOLLOW��
                set<char>::iterator it = follow.Follow[i].begin();
                for (it; it != follow.Follow[i].end(); it++) {
                    analyseTable[i][getTerminalIndex(*it)] = (string)"synch";
                }
            }
        }
    }
}
//��ӡԤ�������
void printAnalyseTable() {
    cout << "Ԥ����������£�" << endl;
    //ռλ��
    cout << setw(10) << " ";
    //ѭ�����ÿλ�ս��
    for (int i = 0; i < grammar.terNum; i++) {
        cout << setw(10) << grammar.terminalChar[i];
    }
    cout << endl;
    //���ÿ��
    for (int i = 0; i < grammar.count; i++) {
        //������ս��ַ�
        cout << setw(10) << grammar.grammarTable[i][0].front();
        //�����Ӧ�Ĳ���ʽ
        for (int j = 0; j < grammar.terNum; j++) {
            cout << setw(10) << analyseTable[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
//��vector�е��ַ�ת��Ϊ�ַ���
string veToString(vector<char>& vec) {
    char buf[N] = { 0 };
    int index = 0;
    vector<char>::iterator it = vec.begin();
    for (it; it != vec.end(); it++) {
        buf[index] = *it;
        index++;
    }
    buf[index] = '\0';
    string str(buf);
    return str;
}
//���ַ�������ѡ���ת��Ϊ�ַ���
string toString(char buf[], int start, int end) {
    char temp[N];
    int index = 0;
    for (start; start <= end; start++) {
        temp[index] = buf[start];
        index++;
    }
    temp[index] = '\0';
    string str(temp);
    return str;
}
//���ĺ��������﷨���з���
void analyseGrammar() {
    cout << "��������������ַ�����";
    string str;
    cin >> str;
    //��������ַ���ת��Ϊ�ַ�����
    char buf[N] = { 0 };
    strcpy_s(buf, str.c_str());
    //�����ַ�����Ŀ
    int count = 0;
    for (int i = 0; buf[i] != 0; i++) {
        count++;
    }
    buf[count++] = '#';
    cout << setw(15) << "����" << setw(15) << "����ջ" << setw(15) << "���봮" << setw(15) << "���ò���ʽ" << setw(15) << "����" << setw(15) << "��ע" << endl;
    //����һ������ջ
    stack<char> analyseStack;
    //��'#'���ķ���ʼ������ջ
    analyseStack.push('#');
    analyseStack.push(grammar.grammarTable[0][0].front());
    vector<char> vec;
    vec.push_back('#');
    vec.push_back(grammar.grammarTable[0][0].front());
    //�ѵ�һ���ַ�����a��
    char a = buf[0];
    //��¼����
    int step = 0;
    cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, 0, count - 1) << setw(15) << " " << setw(15) << "��ʼ��" << setw(15) << " " << endl;
    //buf[]������
    int index = 0;
    bool flag = true;
    while (flag) {
        char ch;
        if (!analyseStack.empty()) {
            ch = analyseStack.top();
            analyseStack.pop();
            vec.pop_back();
        }
        if (isTerminal(ch) && ch != '#') {
            if (ch == a) {

                index++;
                a = buf[index];
                step++;
                cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << " " << setw(15) << (string)"GETNEXT(" + ch + (string)")" << setw(15) << " " << endl;

            }
            else {
                //����
                step++;
                cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << " " << setw(15) << (string)"pop" << setw(15) << "����ջ���ս����������Ų�ƥ�� " << endl;
            }
        }
        else if (ch == '#') {
            if (ch == a) {
                flag = false;
            }
            else {
                //����
                cout << "����";
                return;
            }
        }
        else if (isNonTerminal(ch)) {
            string str = analyseTable[getNonTerminalIndex(ch)][getTerminalIndex(a)];
            //�������ʽ��Ϊ��,�Ҳ�Ϊ����
            if (str != "@" && !str.empty() && str != "synch") {

                int strSize = str.size();
                char temp[N];
                strcpy_s(temp, str.c_str());
                for (int i = strSize - 1; i >= 0; i--) {
                    analyseStack.push(temp[i]);
                    vec.push_back(temp[i]);
                }
                step++;
                cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << str << setw(15) << (string)"pop,push(" + str + (string)")" << setw(15) << " " << endl;
            }
            //���[M,a]Ϊ��,�������������a
            else if (str.empty()) {
                //����
                index++;
                a = buf[index];
                step++;
                cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << " " << setw(15) << " " << setw(15) << "������" << endl;
            }
            else if (str == "synch") {
                //���ջ��Ϊ�ķ���ʼ����,�����������
                if (ch == grammar.grammarTable[0][0].front()) {
                    index++;
                    a = buf[index];
                    //�ķ���ʼ������ջ
                    analyseStack.push(ch);
                    vec.push_back(ch);
                    step++;
                    cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << " " << setw(15) << " " << setw(15) << "������" << endl;
                }
                else {
                    step++;
                    cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << " " << setw(15) << " " << setw(15) << (string)"��,M[" + ch + (string)"," + a + (string)"]=synch" + "," + ch + (string)"�ѵ���ջ" << endl;
                }
            }
            //��Ϊ���֣�ʲôҲ����
            else {
                step++;
                cout << setw(15) << step << setw(15) << veToString(vec) << setw(15) << toString(buf, index, count - 1) << setw(15) << ch + (string)"->" + (string)"@" << setw(15) << " " << setw(15) << "" << endl;
            }
        }
        else {
            //����
            cout << "����";
            return;
        }
    }
}







