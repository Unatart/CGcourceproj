#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QFileDialog>
#include <QTextStream>

#include "ship.h"
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void info_buttons();
    void about();

private slots:
    void load_model();

    void load_ship();

    void create_model();

    void create_ship();

    void on_clear_scene_button_clicked();

    void on_model_clicked();

    void on_camera_clicked();

    void on_paint_clicked();

    void on_clearScr_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    Model model;
    Ship plane;

    sizes model_s;
    ship_sizes ship_s;


};

#endif // MAINWINDOW_H
