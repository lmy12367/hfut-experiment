//#endif
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<iostream>
#include<model.h>
#include<QDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->temp1="";
    this->temp2="";
    ui->setupUi(this);
    model1=new model();
   this ->setWindowOpacity(0.7);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_0_clicked()
{
    if(this->temp1!="")
    {
        this->temp1 += this->ui->btn_0->text();
        this->temp2+=this->ui->btn_0->text();
        this->ui->label->setText(this->temp1);
    }
}

void MainWindow::on_btn_1_clicked()
{
    this->temp1 += this->ui->btn_1->text();
    this->temp2 += this->ui->btn_1->text();
    this->ui->label->setText(this->temp1);
}
void MainWindow::on_btn_2_clicked()
{
    this->temp1 += this->ui->btn_2->text();
    this->temp2 += this->ui->btn_2->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_3_clicked()
{
    this->temp1 += this->ui->btn_3->text();
    this->temp2 += this->ui->btn_3->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_4_clicked()
{
    this->temp1 += this->ui->btn_4->text();
    this->temp2 += this->ui->btn_4->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_5_clicked()
{
    this->temp1 += this->ui->btn_5->text();
    this->temp2 += this->ui->btn_5->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_6_clicked()
{
    this->temp1 += this->ui->btn_6->text();
    this->temp2 += this->ui->btn_6->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_7_clicked()
{
    this->temp1 += this->ui->btn_7->text();
    this->temp2 += this->ui->btn_7->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_8_clicked()
{
    this->temp1 += this->ui->btn_8->text();
    this->temp2 += this->ui->btn_8->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_9_clicked()
{
    this->temp1 += this->ui->btn_9->text();
    this->temp2 += this->ui->btn_9->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_left_clicked()
{
    this->temp1 += this->ui->btn_left->text();
    this->temp2 += this->ui->btn_left->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_right_clicked()
{
    this->temp1 += this->ui->btn_right->text();
    this->temp2 += this->ui->btn_right->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_sum_clicked()
{
    this->model1->get_str(this->temp2);
    QString p=this->model1->calculator();
    this->temp1=p;
    this->temp2=p;
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_or_clicked()
{
    this->temp1+="||";
    this->temp2+='|';
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_mis_clicked()
{
    this->temp1 += this->ui->btn_mis->text();
    this->temp2 += this->ui->btn_mis->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_mul_clicked()
{
    this->temp1 += this->ui->btn_mul->text();
    this->temp2 += this->ui->btn_mul->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_plus_clicked()
{
    this->temp1 += this->ui->btn_plus->text();
    this->temp2 += this->ui->btn_plus->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_clear_clicked()
{
    this->temp1="";
    this->temp2="";
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_jin_clicked()
{
    this->temp1 += this->ui->btn_jin->text();
    this->temp2 += this->ui->btn_jin->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_and_clicked()
{
    this->temp1 += "&&";
    this->temp2 += '&';
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_div_clicked()
{
    this->temp1 += this->ui->btn_div->text();
    this->temp2 += this->ui->btn_div->text();
    this->ui->label->setText(this->temp1);
}

void MainWindow::on_btn_sub_clicked()
{
    this->temp1 += this->ui->btn_sub->text();
    this->temp2 += this->ui->btn_sub->text();
    this->ui->label->setText(this->temp1);
}
