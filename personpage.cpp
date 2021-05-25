#include "personpage.h"
#include "ui_personpage.h"
#include <QDebug>
#include <QDialog>
#include<QSqlQueryModel>


personpage::personpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::personpage)
{
    ui->setupUi(this);
}

personpage::~personpage()
{
    delete ui;
}

void personpage::on_pushButton_mycon_clicked()
{
    QDialog dlg;
    dlg.resize(300,300);
    dlg.exec();
}

void personpage::init()
{
    qDebug()<<pgname;
    QString sql2;
    sql2="select username from user where username='"+pgname+"'";
    QSqlQueryModel *model2=new QSqlQueryModel;
    model2->setQuery(sql2);
    ui->tableView_2->setModel(model2);

    QString sql;
    sql="select username as 用户名 ,title as 帖子名,content as 帖子 from content_  where username='"+pgname+"'";
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(sql);
    ui->tableView->setModel(model);


}
