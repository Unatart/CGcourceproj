#include "dialogmodel.h"
#include "ui_dialogmodel.h"

DialogModel::DialogModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModel)
{
    ui->setupUi(this);
    ui->lineEdit_L->setValidator(new QIntValidator);
    ui->lineEdit_H->setValidator(new QIntValidator);
    ui->lineEdit_W->setValidator(new QIntValidator);
}

DialogModel::~DialogModel()
{
    delete ui;
}

int DialogModel::Lvalue() {
    return ui->lineEdit_L->text().toInt();
}

int DialogModel::Hvalue() {
    return ui->lineEdit_H->text().toInt();
}

int DialogModel::Wvalue() {
    return ui->lineEdit_W->text().toInt();
}

void DialogModel::on_acceptButton_clicked()
{
    close();
}
