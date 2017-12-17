#include "dialogship.h"
#include "ui_dialogship.h"

DialogShip::DialogShip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShip)
{
    ui->setupUi(this);
    ui->lineEdit_l->setValidator(new QIntValidator);
    ui->lineEdit_h->setValidator(new QIntValidator);
    ui->lineEdit_wb->setValidator(new QIntValidator);
    ui->lineEdit_wt->setValidator(new QIntValidator);

}

DialogShip::~DialogShip()
{
    delete ui;
}

int DialogShip::Lvalue() {
    return ui->lineEdit_l->text().toInt();
}

int DialogShip::Hvalue() {
    return ui->lineEdit_h->text().toInt();
}

int DialogShip::Wtvalue() {
    return ui->lineEdit_wt->text().toInt();
}

int DialogShip::Wbvalue() {
    return ui->lineEdit_wb->text().toInt();
}

void DialogShip::on_acceptButton_clicked() {
    close();
}

