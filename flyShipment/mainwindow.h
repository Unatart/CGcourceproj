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
#include "manager.h"

const double move_speed = 5;
const double rotate_speed = 0.1;
const double resize_speed = 1.1;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void visualize_model();
    void visualize_ship();


public slots:
    void info_buttons();
    void about();

private slots:
    void load_model();

    void load_ship();

    void create_model();

    void create_ship();

    void on_clearScr_clicked();
    
    void on_model_toggled(bool checked);

    void on_ship_toggled(bool checked);

    void on_camera_toggled(bool checked);

    void keyPressEvent(QKeyEvent*);

private:
    Ui::MainWindow* ui;

    QGraphicsScene scene;
    QPixmap* pixmap;
    QPainter* painter;

    Manager manager;

    sizes model_s;
    ship_sizes ship_s;


};

#endif // MAINWINDOW_H
