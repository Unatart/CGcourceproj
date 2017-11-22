#ifndef DIALOGSHIP_H
#define DIALOGSHIP_H

#include <QDialog>

#include <iostream>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QString>

namespace Ui {
class DialogShip;
}

class DialogShip : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShip(QWidget *parent = 0);
    ~DialogShip();

    int Lvalue();
    int Hvalue();
    int Wtvalue();
    int Wbvalue();

private slots:
    void on_acceptButton_clicked();

    void on_backButton_clicked();

private:
    Ui::DialogShip *ui;
};

#endif // DIALOGSHIP_H
