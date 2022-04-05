#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<iostream>
#include<model.h>
#include<QDialog>
#include<QMainWindow>

using namespace std;


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    //void get_btn_0();

    void on_btn_0_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_left_clicked();
    void on_btn_right_clicked();
    void on_btn_sum_clicked();
    void on_btn_or_clicked();
    void on_btn_mis_clicked();
    void on_btn_mul_clicked();
    void on_btn_plus_clicked();
    void on_btn_clear_clicked();
    void on_btn_jin_clicked();
    void on_btn_and_clicked();
    void on_btn_div_clicked();
    void on_btn_sub_clicked();

private:
    Ui::MainWindow *ui;
    model * model1;
    QString temp1;
    QString temp2;
};

#endif // MAINWINDOW_H
