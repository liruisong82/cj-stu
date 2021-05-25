#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QSqlDatabase>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void init();
    QString cusername;



private slots:
    void on_pushButton_clicked();

    void on_pushButton_personpage_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model1;
    QStandardItemModel *model2;

};

#endif // MAINWINDOW_H
