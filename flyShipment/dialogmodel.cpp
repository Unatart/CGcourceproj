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
//    int L = (ui->lineEdit_L->text().toInt());
//    int H = (ui->lineEdit_H->text().toInt());
//    int W = (ui->lineEdit_W->text().toInt());


//    QString fileName = QFileDialog::getSaveFileName(this,
//                       tr("Save ship"), "",
//                       tr("Txt file (*.txt);;All Files (*)"));


//    QFile outFile(fileName);
//    outFile.open(QIODevice::WriteOnly | QIODevice::Text);

//    if(!outFile.isOpen()){
//        std::cerr <<  "Error, unable to open file";
//    }

//    QTextStream outStream(&outFile);
//    outStream << L;
//    outStream << " ";
//    outStream << H;
//    outStream << " ";
//    outStream << W;
//    outStream << "\n";

//    outFile.close();

    close();
}

void DialogModel::on_backButton_clicked()
{
    close();
}
