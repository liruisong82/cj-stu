#ifndef STULOGIN_H
#define STULOGIN_H

#include "mainwindow.h"
#include "contentwindow.h"

#include <QMainWindow>

namespace Ui {
class STUlogin;
}

class STUlogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit STUlogin(QWidget *parent = 0);
    ~STUlogin();

private slots:
    void on_pushButton_zhuce_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::STUlogin *ui;
    MainWindow *user;
    ContentWindow *CONTUSERNAME;
    QString inputName;
};

#endif // STULOGIN_H
