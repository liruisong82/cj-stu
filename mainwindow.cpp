#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contentwindow.h"
#include "personpage.h"

#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionquti,&QAction::triggered,[=](){
        this->close();
    });

    this->setFixedSize(650,700);//设置大小
    this->setWindowTitle("主页面");//设置标题
    this->setWindowIcon(QIcon(":/abc.jpg"));//左上角图片

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter painter (this);
    QPixmap pix;
    pix.load(":/def.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//拉伸图片

}

void MainWindow::on_pushButton_clicked()
{
    ContentWindow *cw=new ContentWindow;
    cw->con_username=cusername;
    cw->show();
}

void MainWindow::on_pushButton_personpage_clicked()
{
    personpage *pg=new personpage;
    pg->pgname=cusername;
    pg->show();
    pg->init();
}

void MainWindow::init(){
    qDebug()<<cusername;
    QString sql_stu;
    sql_stu="select username as 用户名 ,title as 帖子名,content as 帖子 from content_ ";
    QSqlQueryModel *modelx=new QSqlQueryModel;
    modelx->setQuery(sql_stu);
    ui->tableView->setModel(modelx);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<cusername;
    QString sql_stu;
    sql_stu="select username as 用户名 ,title as 帖子名,content as 帖子 from content_ ";
    QSqlQueryModel *modelx=new QSqlQueryModel;
    modelx->setQuery(sql_stu);
    ui->tableView->setModel(modelx);
}
