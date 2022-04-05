#include "mainwindow.h"
#include <QApplication>
#include<model.h>
#include<iostream>
#include<QString>
#include<Stack>
#include<String>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
