#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkmoney();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::inputmoney(int i){
    money += i;
    checkmoney();
    ui->lcdMoney->display(money);
}
void Widget::checkmoney()
{
    ui->pbYul->setEnabled(money>=250);
    ui->pbCoffee->setEnabled(money>=200);
    ui->pbTea->setEnabled(money>=100);
    ui->pbReset->setEnabled(money>0);
}

void Widget::on_pbReset_clicked()
{
    ui->lcdMoney->display(money);

    int pb500 = money/500;
    QString str_pb500 = QString::number(pb500);
    money %= 500;
    int pb100 = money/100;
    QString str_pb100 = QString::number(pb100);
    money %= 100;
    int pb50 = money/50;
    QString str_pb50 = QString::number(pb50);
    money %= 50;
    int pb10 = money/10;
    QString str_pb10 = QString::number(pb10);
    money %= 10;

    QMessageBox::information(this,tr("Return left money!"),tr("500  : ")+str_pb500+tr(" 100 : ")+str_pb100+tr(" 50 : ")+str_pb50+tr(" 10 : ")+str_pb10);
    checkmoney();
    ui->lcdMoney->display(money);
}

void Widget::on_pb500_clicked()
{
    inputmoney(500);
}

void Widget::on_pb100_clicked()
{
    inputmoney(100);
}

void Widget::on_pb50_clicked()
{
    inputmoney(50);
}

void Widget::on_pb10_clicked()
{
    inputmoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    inputmoney(-200);
}

void Widget::on_pbTea_clicked()
{
    inputmoney(-100);
}

void Widget::on_pbYul_clicked()
{
    inputmoney(-250);
}
