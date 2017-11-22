#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"

#include <QDialog>

#include "dialogmodel.h"
#include "dialogship.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->about, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->InfoButtons, SIGNAL(triggered()), this, SLOT(info_buttons()));
    connect(ui->create_model, SIGNAL(triggered()), this, SLOT(create_model()));
    connect(ui->create_ship, SIGNAL(triggered()), this, SLOT(create_ship()));
    connect(ui->download_model, SIGNAL(triggered()), this, SLOT(load_model()));
    connect(ui->download_ship, SIGNAL(triggered()), this, SLOT(load_ship()));
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::info_buttons() {
    QMessageBox::information(this, "Help", "Some text");
}

void MainWindow::about() {
    QMessageBox::information(this, "Help", "Some text");
}

void MainWindow::create_model() {
    DialogModel dmodel;
    dmodel.exec();

    if ((dmodel.Lvalue() != 0) && (dmodel.Wvalue() != 0) && (dmodel.Hvalue() != 0) ) {
        model_s.L = dmodel.Lvalue();
        model_s.H = dmodel.Hvalue();
        model_s.W = dmodel.Wvalue();
    }


    model.createModel(model_s.L, model_s.H, model_s.W);

}

void MainWindow::create_ship() {
    DialogShip dship;
    dship.exec();

    if ((dship.Lvalue() != 0) && (dship.Wbvalue() != 0) && (dship.Hvalue() != 0) && (dship.Wtvalue() != 0)) {
        ship_s.H = dship.Hvalue();
        ship_s.L = dship.Lvalue();
        ship_s.Wb = dship.Wbvalue();
        ship_s.Wt = dship.Wtvalue();
    }

    plane.createShip(ship_s.L, ship_s.H, ship_s.Wt, ship_s.Wb);
}

void MainWindow::load_model() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Выберите файл"), tr(""), tr("*.txt"));
    if (file_path.isEmpty()) {
        return;
    }

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Невозможно открыть файл"), file.errorString());
        return;
    }

    QTextStream in(&file);

    while (in.status() == QTextStream::Ok) {

        float l, w, h;
        in >> l >> h >> w;

        model_s.H = h;
        model_s.L = l;
        model_s.W = w;
    }

    file.close();
}

void MainWindow::load_ship() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Выберите файл"), tr(""), tr("*.txt"));
    if (file_path.isEmpty()) {
        return;
    }

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Невозможно открыть файл"), file.errorString());
        return;
    }

    QTextStream in(&file);

    while (in.status() == QTextStream::Ok) {

        float l, wb, h, wt;
        in >> l >> h >> wt >> wb;

        ship_s.L = l;
        ship_s.H = h;
        ship_s.Wt = wt;
        ship_s.Wb = wb;

    }

    file.close();
}

void MainWindow::on_model_clicked()
{

}

void MainWindow::on_camera_clicked()
{

}

void MainWindow::on_ship_clicked()
{

}

void MainWindow::on_paint_clicked()
{

}

void MainWindow::on_clearScr_clicked()
{

}


