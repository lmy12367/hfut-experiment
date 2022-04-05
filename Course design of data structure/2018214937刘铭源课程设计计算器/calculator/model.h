#ifndef MODEL_H
#define MODEL_H
#include<String>
#include<Stack>
#include<iostream>
#include<QString>

using namespace std;


class model
{
private:
    QString s1;
public:
    model();
    void get_str(QString s1);
    //QString get();
    QString calculator();
    bool isnumber(char e);

};



#endif // MODEL_H
