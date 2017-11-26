#include "dialogship.h"
#include "ui_dialogship.h"

DialogShip::DialogShip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShip)
{
    ui->setupUi(this);
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
    int L = (ui->lineEdit_l->text().toInt());
    int H = (ui->lineEdit_h->text().toInt());
    int Wt = (ui->lineEdit_wt->text().toInt());
    int Wb = (ui->lineEdit_wb->text().toInt());


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
//    outStream << Wt;
//    outStream << " ";
//    outStream << Wb;
//    outStream << " ";
//    outStream << "\n";

//    outFile.close();

    close();
}

void DialogShip::on_backButton_clicked() {
    close();
}
