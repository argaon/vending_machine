#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

volatile int leMoney = 0;

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
    QString strlem = ui->leMoney->text();
    leMoney = strlem.toInt()+i;
    checkmoney();
    strlem = QString::number(leMoney);
    ui->leMoney->setText(strlem);

}
void Widget::checkmoney()
{
    if(leMoney>=250)
        ui->pbYul->setEnabled(true);
    if(leMoney>=200)
        ui->pbCoffee->setEnabled(true);
    if(leMoney>=100)
        ui->pbTea->setEnabled(true);
    if(leMoney<250)
        ui->pbYul->setEnabled(false);
    if(leMoney<200)
        ui->pbCoffee->setEnabled(false);
    if(leMoney<100)
        ui->pbTea->setEnabled(false);
}

void Widget::on_pbReset_clicked()
{

    QString strlem = ui->leMoney->text();
    leMoney = strlem.toInt();

    int pb500 = leMoney/500;
    QString str_pb500 = QString::number(pb500);
    leMoney = leMoney%500;
    int pb100 = leMoney/100;
    QString str_pb100 = QString::number(pb100);
    leMoney = leMoney%100;
    int pb50 = leMoney/50;
    QString str_pb50 = QString::number(pb50);
    leMoney = leMoney%50;
    int pb10 = leMoney/10;
    QString str_pb10 = QString::number(pb10);
    leMoney = leMoney%10;

    QMessageBox::information(this,tr("Return left money!"),tr("500  : ")+str_pb500+tr(" 100 : ")+str_pb100+tr(" 50 : ")+str_pb50+tr(" 10 : ")+str_pb10);
    strlem = QString::number(leMoney);
    checkmoney();
    ui->leMoney->setText(strlem);
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
