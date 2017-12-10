#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialogmodel.h"
#include "dialogship.h"

#include <list>
#include "camera.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    zbuffer(screen_size_x, screen_size_y)
{
    ui->setupUi(this);
    setFixedSize(window_size_x, window_size_y);

    ui->model->toggle();
    ui->graphicsView->setFixedSize(screen_size_x, screen_size_y);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene.setSceneRect(-screen_size_x / 2, -screen_size_y / 2,
                       screen_size_x, screen_size_y);
    ui->graphicsView->setScene(&scene);

    pixmap = new QPixmap(screen_size_x, screen_size_y);
    painter = new QPainter(pixmap);

    connect(ui->about, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->InfoButtons, SIGNAL(triggered()), this, SLOT(info_buttons()));
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(close()));

    create_ship();

//    qDebug() << scene.sceneRect();
}

MainWindow::~MainWindow()
{
    delete painter;
    delete pixmap;
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

    manager.model = Model(model_s.L, model_s.H, model_s.W);
    manager.active_object = &(manager.model);

    visualize_model();
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

    manager.ship.createShip(ship_s.L, ship_s.H, ship_s.Wt, ship_s.Wb);
    manager.active_object = &(manager.ship);

    visualize_ship();
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

void MainWindow::visualize_model() {

    for (Polygon& pol : manager.model.polygons) {
        if (manager.check_visible_m()) {
            QVector<QPoint> polyvector;
            for (Point& point : pol.points) {
                polyvector.push_back(manager.camera.to_screen(point));
            }

            QPolygon polygon(polyvector);
            scene.addPolygon(polygon,QPen(Qt::black));
        }
    }
}

void MainWindow::visualize_ship() {

    for (Polygon& pol : manager.ship.polygons) {
        if (manager.check_visible_s()) {
            QVector<QPoint> polyvector;
            for (Point& point : pol.points) {
                polyvector.push_back(manager.camera.to_screen(point));
            }
            QPolygon polygon(polyvector);
            scene.addPolygon(polygon, QPen());
        }
    }
}

void MainWindow::on_clearScr_clicked()
{
    scene.clear();
}

void MainWindow::on_model_toggled(bool checked)
{
    if (checked) {
        manager.active_object = &(manager.model);
        visualize_model();
    }
}

void MainWindow::on_ship_toggled(bool checked)
{
    if (checked) {
        manager.active_object = &(manager.ship);
        visualize_ship();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    scene.clear();
    if (manager.active_object != nullptr && !(ui->moveBox->isChecked())) {
        Point zero(0, 0, 0);
        switch(e->key()) {
//			move
            case Qt::Key_Q :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, -move_speed);
                    manager.ship.move(0, 0, -move_speed);
                } else {
                    manager.active_object->move(0, 0, -move_speed);
                }
                break;

            case Qt::Key_E:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, move_speed);
                    manager.ship.move(0, 0, move_speed);
                } else {
                    manager.active_object->move(0, 0, move_speed);
                }
                break;
            case Qt::Key_W:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, move_speed, 0);
                    manager.ship.move(0, move_speed, 0);
                } else {
                    manager.active_object->move(0, -move_speed, 0);
                }
                break;
            case Qt::Key_S:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, -move_speed, 0);
                    manager.ship.move(0, -move_speed, 0);
                } else {
                    manager.active_object->move(0, move_speed, 0);
                }
                break;

            case Qt::Key_A :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(move_speed, 0, 0);
                    manager.ship.move(move_speed, 0, 0);
                } else {
                    manager.active_object->move(-move_speed, 0, 0);
                }
                break;

            case Qt::Key_D:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(-move_speed, 0, 0);
                    manager.ship.move(-move_speed, 0, 0);
                } else {
                    manager.active_object->move(move_speed, 0, 0);
                }
                break;
//			rotate
            case Qt::Key_K:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, -rotate_speed, 0, zero);
                    manager.ship.rotate(0, -rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, rotate_speed, 0);
                }
                break;
            case Qt::Key_I:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, rotate_speed, 0, zero);
                    manager.ship.rotate(0, rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, -rotate_speed, 0);
                }
                break;
            case Qt::Key_L:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, -rotate_speed, zero);
                    manager.ship.rotate(0, 0, -rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, rotate_speed);
                }
                break;
            case Qt::Key_J:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, rotate_speed, zero);
                    manager.ship.rotate(0, 0, rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, -rotate_speed);
                }
                break;
            case Qt::Key_O:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(-rotate_speed, 0, 0, zero);
                    manager.ship.rotate(-rotate_speed, 0, 0, zero);
                } else {
                    manager.active_object->rotate(-rotate_speed, 0, 0);
                }
                break;
            case Qt::Key_U:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(rotate_speed, 0, 0, zero);
                    manager.ship.rotate(rotate_speed, 0, 0, zero);
                } else {
                    manager.active_object->rotate(rotate_speed, 0, 0);
                }
                break;
//			resize
            case Qt::Key_T:
                manager.active_object->resize(resize_speed);
                break;
            case Qt::Key_Y:
                manager.active_object->resize(1/resize_speed);
                break;
            default:
                break;
        }
    } else if (manager.active_object != nullptr && ui->moveBox->isChecked()) {
        double x = manager.ship.front_vector.get_x();
        double y = manager.ship.front_vector.get_y();
        double z = manager.ship.front_vector.get_z();
        double way = sqrt(x*x + y*y + z*z);
        double speedbyway = move_speed/way;
        switch(e->key()) {
//			move
            case Qt::Key_W:
                    manager.model.move(x * speedbyway, y * speedbyway, z * speedbyway);
                break;
            case Qt::Key_S:
                    manager.model.move(-x * speedbyway, -y * speedbyway, -z * speedbyway);
                break;
        }
    }

    if (manager.model.insideShip(manager.ship) == true) {
        manager.model.setColor(Qt::green);
    } else {
        manager.model.setColor(Qt::red);
    }

    if (ui->DrawBox->isChecked()) {
        mydrawZBuffer();
    } else {
        visualize_model();
        visualize_ship();
    }
}

void MainWindow::mydrawZBuffer() {
    scene.clear();
    pixmap->fill(QColor(234, 238, 242));

    std::list<Polygon> waiting_polygons;
    transform_points_for_zbuffer(waiting_polygons);

    std::list<Polygon> active_polygons;

//    проходимся по каждой строке экрана
    for (int x = 0; x < screen_size_x; ++x) {
         double real_x = x - screen_size_x_half;
//        здесь нужно посмотреть в список ждущих полигонов и если минимальное значение х меньше или равно текущему
//        нужно убрать данный полигон из списка ждущих и добавить его в список активных
        auto it = waiting_polygons.cbegin();
        while (it != waiting_polygons.cend()) {
            double min_x = (*it).min_x();
            if (min_x <= real_x) {
                active_polygons.push_back(*it);
                it = waiting_polygons.erase(it);
            } else {
                ++it;
            }
        }

        std::list<Polygon> active_polygons_y;
        std::list<Polygon> waiting_polygons_y(active_polygons);

//        если список активных полигонов пуст, скипаем цикл
        if (active_polygons.size() > 0) {
            for (int y = 0; y < screen_size_y; ++y) {
                double real_y = y - screen_size_y_half;

                auto it = waiting_polygons_y.cbegin();
                while (it != waiting_polygons_y.cend()) {
                    double min_y = (*it).min_y();
                    if (min_y <= real_y) {
                        active_polygons_y.push_back(*it);
                        it = waiting_polygons_y.erase(it);
                    } else {
                        ++it;
                    }
                }
    //            проходимся по списку активных полигонов и смотрим глубину пикселя для этого полигона, если она меньше,
    //            чем хранящаяся в zbuffer-е, записываем ее туда вместе с цветом
                if (active_polygons_y.size() > 0) {
                    double max_depth = std::numeric_limits<double>::lowest();
                    QColor max_color = QColor(234, 238, 242);

                    for (const Polygon& polygon : active_polygons_y) {
                        double depth = polygon.depth_of_pixel(real_x, real_y);
                        if (depth > max_depth && polygon.in_polygon(real_x, real_y)) {
                            max_depth = depth;
                            max_color = polygon.polygon_color;
                        }
                    }

                    painter->setPen(max_color);
                    painter->drawPoint(x, y);

                    it = active_polygons_y.cbegin();
                    while (it != active_polygons_y.cend()) {
                        double max_y = (*it).max_y();
                        if (max_y <= real_y) {
                            it = active_polygons_y.erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
        }

//        проходимся по списку активных полигонов и смотрим, если максимальный х для полигона равен текущему, то убираем
//        его из списка активных (в список ждущих НЕ добавляем)
        it = active_polygons.cbegin();
        while (it != active_polygons.cend()) {
            double max_x = (*it).max_x();
            if (max_x <= real_x) {
                it = active_polygons.erase(it);
            } else {
                ++it;
            }
        }
    }
    QGraphicsPixmapItem* it = scene.addPixmap(*pixmap);
    it->setPos(-screen_size_x / 2, -screen_size_y / 2);
}

void MainWindow::transform_points_for_zbuffer(std::list<Polygon>& transformed_polygons) {
    for (Polygon& polygon : manager.model.polygons) {
        Polygon transformed_polygon(polygon);
        for (Point& point : transformed_polygon.points) {
            point = manager.camera.to_screen_3d(point);
        }
        transformed_polygons.push_back(transformed_polygon);
    }

    for (Polygon& polygon : manager.ship.polygons) {
        Polygon transformed_polygon(polygon);
        for (Point& point : transformed_polygon.points) {
            point = manager.camera.to_screen_3d(point);
        }
        transformed_polygons.push_back(transformed_polygon);
    }
}



void MainWindow::on_DrawBox_toggled()
{
    mydrawZBuffer();
}

void MainWindow::on_ModelButton_clicked()
{
    create_model();
}
