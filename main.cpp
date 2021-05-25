#include "mainwindow.h"
#include "STUlogin.h"
#include "stulogin.h"
#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>
#include <QSqlQuery>

bool opendatabase();

int main(int argc, char *argv[])
{
    opendatabase();
    QApplication a(argc, argv);
    STUlogin w;
    w.show();

    return a.exec();
}
bool opendatabase()
{
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("content.db");//release用
    if(mydb.open())
    {
        //qDebug()<<"open success";
        QSqlQuery query;
       // QString create_user = "create table user_ (username varchar(50) primary key, password varchar(50))";
        QString create_cont = "create table content_ (title varchar(500) primary key, username varchar(50) ,content varchar(4000),foreign key(username)references user(username))";

        QString create_user = "create table user (id int primary key, username varchar(50), password varchar(50))";
//        QString create_con = "create table content (ID int primary key, username varchar(50) , title varchar(500),content varchar(4000),foreign key(username)references user(username))";

        query.prepare(create_user);
        query.prepare(create_cont);

        if(!query.exec())
        {
            qDebug() << "Error: Fail to create table.";
        }
        else
        {
            qDebug() << "Table created!";
        }
        return true;
    }
    else
    {
        qDebug()<<"open failed";
        return false;
    }


}


