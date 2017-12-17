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
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateSliderBPos(int)));
    setFixedSize(window_size_x, window_size_y);

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

    Model m(model_s.L, model_s.H, model_s.W);
    add_model(m);
    ui->graphicsView->setFocus();

    manager.ship.setColor();
    for (Model& m: manager.model_list) {
        if (m.insideShip(manager.ship) == true) {
            m.setColor(Qt::green);
        } else {
            m.setColor(Qt::red);
        }
    }

    mydrawZBuffer();
}

void MainWindow::add_model(Model &model) {
    QString str = QString("Груз ") + QString::number(manager.num_of_models());

    ui->modelList->addItem(str);
    manager.add_model(model);
    ui->modelList->setCurrentRow(ui->modelList->count() - 1);
    manager.active_object = &(manager.model_list[ui->modelList->currentRow()]);
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
    ui->ship->setChecked(true);

    manager.ship.setColor();

    mydrawZBuffer();
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

    for (Model& m : manager.model_list) {
        for (Polygon& pol : m.polygons) {
            if (manager.check_visible_m(m)) {
                QVector<QPoint> polyvector;
                for (Point& point : pol.points) {
                    polyvector.push_back(manager.camera.to_screen(point));
                }

                QPolygon polygon(polyvector);
                scene.addPolygon(polygon,QPen(Qt::black));
            }
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

void MainWindow::on_ship_toggled(bool checked)
{
    if (checked) {
        manager.active_object = &(manager.ship);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    auto start = std::chrono::high_resolution_clock::now();
    scene.clear();
    ui->graphicsView->setFocus();
    if (manager.active_object != nullptr) {
        Point zero(manager.ship.get_center());
        switch(e->key()) {
//			move
            case Qt::Key_Q :
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.move(0, 0, -move_speed);
                    }
					manager.ship.move(0, 0, -move_speed);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(0, 0, move_speed);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(0, 0, move_speed);
                        }
                    } else {
                        manager.active_object->move(0, 0, move_speed);
                    }
                }
                break;

            case Qt::Key_E:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.move(0, 0, move_speed);
                    }
                    manager.ship.move(0, 0, move_speed);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(0, 0, -move_speed);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(0, 0, -move_speed);
                        }
                    } else {
                        manager.active_object->move(0, 0, -move_speed);
                    }
                }
                break;
            case Qt::Key_W:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list){
                        m.move(0, move_speed, 0);
                    }
                    manager.ship.move(0, move_speed, 0);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(0, -move_speed, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(0, -move_speed, 0);
                        }
                    } else {
                        manager.active_object->move(0, -move_speed, 0);
                    }

                }
                break;
            case Qt::Key_S:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list){
                        m.move(0, -move_speed, 0);
                    }
					manager.ship.move(0, -move_speed, 0);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(0, move_speed, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(0, move_speed, 0);
                        }
                    } else {
                        manager.active_object->move(0, move_speed, 0);
                    }
                }
                break;

            case Qt::Key_A :
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list){
                        m.move(move_speed, 0, 0);
                    }
					manager.ship.move(move_speed, 0, 0);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(-move_speed, 0, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(-move_speed, 0, 0);
                        }
                    } else {
                        manager.active_object->move(-move_speed, 0, 0);
                    }
                }
                break;

            case Qt::Key_D:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list){
                        m.move(-move_speed, 0, 0);
                    }
					manager.ship.move(-move_speed, 0, 0);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.move(move_speed, 0, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->move(move_speed, 0, 0);
                        }
                    } else {
                        manager.active_object->move(move_speed, 0, 0);
                    }
                }
                break;
//			rotate
            case Qt::Key_K:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(0, -rotate_speed, 0, zero);
                    }
					manager.ship.rotate(0, -rotate_speed, 0, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(0, rotate_speed, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(0, rotate_speed, 0);
                        }
                    } else {
                        manager.active_object->rotate(0, rotate_speed, 0);
                    }
                }
                break;
            case Qt::Key_I:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(0, rotate_speed, 0, zero);
                    }
					manager.ship.rotate(0, rotate_speed, 0, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(0, -rotate_speed, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(0, -rotate_speed, 0);
                        }
                    } else {
                        manager.active_object->rotate(0, -rotate_speed, 0);
                    }
                }
                break;
            case Qt::Key_L:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(0, 0, -rotate_speed, zero);
                    }
					manager.ship.rotate(0, 0, -rotate_speed, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(0, 0, rotate_speed);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(0, 0, rotate_speed);
                        }
                    } else {
                        manager.active_object->rotate(0, 0, rotate_speed);
                    }
                }
                break;
            case Qt::Key_J:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(0, 0, rotate_speed, zero);
                    }
					manager.ship.rotate(0, 0, rotate_speed, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(0, 0, -rotate_speed);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(0, 0, -rotate_speed);
                        }
                    } else {
                        manager.active_object->rotate(0, 0, -rotate_speed);
                    }
                }
                break;
            case Qt::Key_O:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(-rotate_speed, 0, 0, zero);
                    }
					manager.ship.rotate(-rotate_speed, 0, 0, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(-rotate_speed, 0, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(-rotate_speed, 0, 0);
                        }
                    } else {
                        manager.active_object->rotate(-rotate_speed, 0, 0);
                    }
                }
                break;
            case Qt::Key_U:
                if (ui->cameraButton->isChecked()) {
                    for (Model& m: manager.model_list) {
                        m.rotate(rotate_speed, 0, 0, zero);
                    }

					manager.ship.rotate(rotate_speed, 0, 0, zero);
                } else {
                    if (ui->models->isChecked() && manager.model_list.size() != 1) {
                        Model curr_model = manager.model_list[ui->modelList->currentRow()];
                        curr_model.rotate(rotate_speed, 0, 0);
                        if (!able_to_move(curr_model)) {
                            manager.active_object->rotate(rotate_speed, 0, 0);
                        }
                    } else {
                        manager.active_object->rotate(rotate_speed, 0, 0);
                    }
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
    }
    manager.ship.setColor();
    for (Model& m: manager.model_list) {
        if (m.insideShip(manager.ship) == true) {
            m.setColor(Qt::green);
        } else {
            m.setColor(Qt::red);
        }
    }
    mydrawZBuffer();

    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << time.count() << std::endl;
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
    for (Model& m: manager.model_list) {
        for (Polygon& polygon : m.polygons) {
            for (unsigned i = 2; i < polygon.points.size(); ++i) {
                Polygon transformed_polygon;
                transformed_polygon.polygon_color = polygon.polygon_color;

                transformed_polygon.points.push_back(polygon.points[0]);
                transformed_polygon.points.push_back(polygon.points[i - 1]);
                transformed_polygon.points.push_back(polygon.points[i]);

                for (Point& point : transformed_polygon.points) {
                    point = manager.camera.to_screen_3d(point);
                }

                transformed_polygon.setup_flatness();

                transformed_polygons.push_back(transformed_polygon);
            }
        }
    }


    for (Polygon& polygon : manager.ship.polygons) {
        if (polygon.polygon_color.alpha() != 0) {
            for (unsigned i = 2; i < polygon.points.size(); ++i) {
                Polygon transformed_polygon;
                transformed_polygon.polygon_color = polygon.polygon_color;

                transformed_polygon.points.push_back(polygon.points[0]);
                transformed_polygon.points.push_back(polygon.points[i - 1]);
                transformed_polygon.points.push_back(polygon.points[i]);

                for (Point& point : transformed_polygon.points) {
                    point = manager.camera.to_screen_3d(point);
                }

                transformed_polygon.setup_flatness();
                transformed_polygons.push_back(transformed_polygon);
            }
        }
    }
}

void MainWindow::on_ModelButton_clicked()
{
    create_model();
}

void MainWindow::on_ShipButton_clicked()
{
    create_ship();
}

void MainWindow::updateSliderBPos(int value) {
    ui->label_2->setText(QString("%1").arg(value));
    move_speed = value;
}


void MainWindow::on_modelList_currentRowChanged(int currentRow)
{
    manager.active_object = &(manager.model_list[currentRow]);
    ui->graphicsView->setFocus();

    ui->models->setChecked(true);
}

void MainWindow::on_modelList_clicked(const QModelIndex &index)
{
    manager.active_object = &(manager.model_list[index.row()]);
    ui->graphicsView->setFocus();

    ui->models->setChecked(true);
}

void MainWindow::on_models_toggled(bool checked)
{
    if (checked) {
        if (manager.model_list.empty()) {
            manager.active_object = nullptr;
        } else {
            manager.active_object = &(manager.model_list[ui->modelList->currentRow()]);
        }
    }
}

bool MainWindow::Inters(float min1, float max1, float min2, float max2) {
    if (min1 > max2)
        return false;
    if (max1 < min2)
        return false;
    return true;
}


bool MainWindow::able_to_move(Model &model) {
    for (int i = 0; i < manager.model_list.size(); i++) {
        if (i != ui->modelList->currentRow()) {
            if (!Inters(model.min_x(), model.max_x(), manager.model_list[i].min_x(), manager.model_list[i].max_x()))
                return false;
            if (!Inters(model.min_y(), model.max_y(), manager.model_list[i].min_y(), manager.model_list[i].max_y()))
                return false;
            if (!Inters(model.min_z(), model.max_z(), manager.model_list[i].min_z(), manager.model_list[i].max_z()))
                return false;
        }
    }
    return true;
}

