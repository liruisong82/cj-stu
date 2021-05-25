#ifndef CONTENTWINDOW_H
#define CONTENTWINDOW_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class ContentWindow;
}

class ContentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContentWindow(QWidget *parent = 0);
    ~ContentWindow();

    QString con_username;
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ContentWindow *ui;
};

#endif // CONTENTWINDOW_H
