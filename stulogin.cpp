#include "stulogin.h"
#include "ui_stulogin.h"
#include "personpage.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>


STUlogin::STUlogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::STUlogin)
{
    ui->setupUi(this);
    user=new MainWindow;

}

STUlogin::~STUlogin()
{
    delete ui;
}


void STUlogin::on_pushButton_zhuce_clicked()
{
 QString sql1,sql2;
 QString sql3;
 inputName=ui->lineEdit_username->text();
 QString inputPassword=ui->lineEdit_password->text();
 QSqlQueryModel *model1=new QSqlQueryModel;
 QSqlQueryModel *model2=new QSqlQueryModel;
 sql1="select count(*) from user where username='"+inputName+"'";
 model1->setQuery(sql1);
 QModelIndex index1=model1->index(0,0);
 if(index1.data()==0)
 {
     QMessageBox::about(NULL,"提示","用户注册成功");
     sql3="insert into user(username,password) values('"+inputName+"','"+inputPassword+"')";
     QSqlQueryModel *model=new QSqlQueryModel;
     model->setQuery(sql3);
 }
 else if(index1.data()!=0)
 {
     QMessageBox::about(NULL,"提示","用户已经存在");
 }
}



void STUlogin::on_pushButton_login_clicked()
{
    QString sql1,sql2;
    QString sql3;

    QString inputName=ui->lineEdit_username->text();
    QString inputPassword=ui->lineEdit_password->text();
    QSqlQueryModel *model1=new QSqlQueryModel;
    QSqlQueryModel *model2=new QSqlQueryModel;
    sql1="select count (*) from user where username='"+inputName+"'";
    model1->setQuery(sql1);
    QModelIndex index1=model1->index(0,0);
    sql2="select password from user where username ='"+inputName+"'";
    model2->setQuery(sql2);
    QModelIndex index2=model2->index(0,0);

    if(index1.data()!=0&&inputPassword==index2.data())
        {
            QMessageBox::about(NULL,"提示","用户登录成功");
            //sql3="insert into student(name,password) values('"+inputName+"','"+inputPassword+"')";
            //QSqlQueryModel *model=new QSqlQueryModel;
            //model->setQuery(sql3);

            user->cusername=inputName;//将登陆的学生信息读取出来
            user->show();
            user->init();
        }
        else
        {
            QMessageBox::about(NULL,"提示","用户名或密码错误");

        }

}




