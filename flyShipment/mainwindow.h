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

#include <limits>

#include <QDialog>
#include <QDebug>
#include <QColorDialog>
#include <QGraphicsPixmapItem>

#include <chrono>
#include <iostream>

#include "ship.h"
#include "model.h"
#include "manager.h"
#include "zbuffer.h"

const double resize_speed = 1.1;

const int window_size_x = 1080;
const int window_size_y = 665;

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

    void add_model(Model& model);

    void mydrawZBuffer();

    void keyPressEvent(QKeyEvent*);



    void on_clearScr_clicked();

    void on_ship_toggled(bool checked);

    void on_ModelButton_clicked();

    void on_ShipButton_clicked();

    void on_modelList_currentRowChanged(int currentRow);

    void on_modelList_clicked(const QModelIndex &index);

    void on_models_toggled(bool checked);


    bool Inters(float min1, float max1, float min2, float max2);

    bool able_to_move(Model &model);

    void updateSliderBPos(int value);

    void on_delButton_clicked();

private:
    Ui::MainWindow* ui;

    QGraphicsScene scene;
    QPixmap* pixmap;
    QPainter* painter;

    Manager manager;

    sizes model_s;
    ship_sizes ship_s;

    ZBuffer zbuffer;
    double move_speed = 5;
    double rotate_speed = 0.1;

    void transform_points_for_zbuffer(std::list<Polygon> &transformed_polygons);
};

#endif // MAINWINDOW_H
