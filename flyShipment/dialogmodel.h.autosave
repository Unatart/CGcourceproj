#ifndef DIALOGMODEL_H
#define DIALOGMODEL_H

#include <QDialog>
#include <QString>

#include <iostream>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QIntValidator>

namespace Ui {
class DialogModel;
}

class DialogModel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModel(QWidget *parent = 0);
    ~DialogModel();

    int Lvalue();
    int Hvalue();
    int Wvalue();

private slots:
    void on_acceptButton_clicked();

private:
    Ui::DialogModel *ui;
};

#endif // DIALOGMODEL_H
