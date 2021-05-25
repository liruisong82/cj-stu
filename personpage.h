#ifndef PERSONPAGE_H
#define PERSONPAGE_H

#include <QMainWindow>
#include <QDialog>

namespace Ui {
class personpage;
}

class personpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit personpage(QWidget *parent = 0);
    ~personpage();
    void init();
    QString pgname;


private slots:
    void on_pushButton_mycon_clicked();

private:
    Ui::personpage *ui;
};

#endif // PERSONPAGE_H
