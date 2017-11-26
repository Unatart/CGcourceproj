#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialogmodel.h"
#include "dialogship.h"

#include "camera.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bufferMatrix = new double*[900];
    for(int i = 0;i < 900; i++) {
        bufferMatrix[i] = new double[600];
    }
    ui->setupUi(this);
    setFixedSize(900, 600);
    ui->model->toggle();
    ui->graphicsView->setFixedSize(screen_size_x, screen_size_y);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene.setSceneRect(-screen_size_x / 2, -screen_size_y / 2, screen_size_x, screen_size_y);

    pixmap = new QPixmap(screen_size_x, screen_size_y);
    painter = new QPainter(pixmap);

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
    for (int i = 0; i < 900; i++){
        delete bufferMatrix[i];
    }
    delete bufferMatrix;
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

    manager.model.createModel(model_s.L, model_s.H, model_s.W);
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
    scene.clear();

    for (ModelPolygon& pol : manager.model.model) {
        if (manager.check_visible_m()) {
            QVector<QPoint> polyvector;
            for (Edge& edge : pol.mpolygon) {
                polyvector.push_back(manager.camera.to_screen(edge.begin));
            }

            QPolygon polygon(polyvector);
            scene.addPolygon(polygon,QPen());
        }
    }
}

void MainWindow::visualize_ship() {    

    for (ShipPolygon& pol : manager.ship.ship) {
        if (manager.check_visible_s()) {
            QVector<QPoint> polyvector;
            for (Edge& edge : pol.spolygon) {
                polyvector.push_back(manager.camera.to_screen_s(edge.begin));
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
        visualize_model();
    }
}

void MainWindow::on_ship_toggled(bool checked)
{
    if (checked) {
        visualize_ship();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (manager.active_object != nullptr) {
        Point zero(0, 0, 0);
        switch(e->key()) {
//			move
            case Qt::Key_Q :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, -move_speed);
                } else {
                    manager.active_object->move(0, 0, -move_speed);
                }
                break;

            case Qt::Key_E:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, move_speed);
                } else {
                    manager.active_object->move(0, 0, move_speed);
                }
                break;
            case Qt::Key_W:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, move_speed, 0);
                } else {
                    manager.active_object->move(0, -move_speed, 0);
                }
                break;
            case Qt::Key_S:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, -move_speed, 0);
                } else {
                    manager.active_object->move(0, move_speed, 0);
                }
                break;

            case Qt::Key_A :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(move_speed, 0, 0);
                } else {
                    manager.active_object->move(-move_speed, 0, 0);
                }
                break;

            case Qt::Key_D:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(-move_speed, 0, 0);
                } else {
                    manager.active_object->move(move_speed, 0, 0);
                }
                break;
//			rotate
            case Qt::Key_K:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, -rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, rotate_speed, 0);
                }
                break;
            case Qt::Key_I:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, -rotate_speed, 0);
                }
                break;
            case Qt::Key_L:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, -rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, rotate_speed);
                }
                break;
            case Qt::Key_J:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, -rotate_speed);
                }
                break;
            case Qt::Key_O:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(-rotate_speed, 0, 0, zero);
                } else {
                    manager.active_object->rotate(-rotate_speed, 0, 0);
                }
                break;
            case Qt::Key_U:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(rotate_speed, 0, 0, zero);
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
    }
    if (ui->model->isChecked()) {
        visualize_model();
        drawZBuffer();
    }
}

void MainWindow::drawZBuffer() {
    for (int i = 0; i < 900; i++)
        for (int j = 0; j < 600; j++)
            bufferMatrix[i][j] = std::numeric_limits<double>::max();

    for (ModelPolygon& modelpol : manager.model.model) { // для каждого полигона в теле
        std::vector<Point> trianglePol1;
        std::vector<Point> trianglePol2;

        // грани из 2 точек переводим в 4 точки полигона
        Point point_array[4];
        int i = 0;
        for (Edge& edge: modelpol.mpolygon) {
            point_array[i] = edge.begin;
            i++;
        }

        trianglePol1.push_back(point_array[0]);
        trianglePol1.push_back(point_array[1]);
        trianglePol1.push_back(point_array[2]);

        trianglePol2.push_back(point_array[0]);
        trianglePol2.push_back(point_array[2]);
        trianglePol2.push_back(point_array[3]);

        rasterCompareAndDraw(trianglePol1);
        rasterCompareAndDraw(trianglePol2);

        trianglePol1.clear();
        trianglePol2.clear();
    }
}

void MainWindow::rasterCompareAndDraw(std::vector<Point> pol) {


    Point p1, p2, p3;
    int xa, xb, za, zb;
    double z;

    // compare points by y-values
    if (pol[0].get_y() > pol[1].get_y())
    {
        if (pol[0].get_y() > pol[2].get_y())
        {
            p3 = pol[0];
            if (pol[1].get_y() > pol[2].get_y())
            {
                p1 = pol[2];
                p2 = pol[1];
            }
            else
            {
                p2 = pol[2];
                p1 = pol[1];
            }
        }
        else
        {
            p1 = pol[1];
            p2 = pol[0];
            p3 = pol[2];
        }
    }
    else
    {
        if (pol[1].get_y() > pol[2].get_y())
        {
            p3 = pol[1];
            if (pol[0].get_y() > pol[2].get_y())
            {
                p1 = pol[2];
                p2 = pol[0];
            }
            else
            {
                p2 = pol[2];
                p1 = pol[0];
            }
        }
        else
        {
            p1 = pol[0];
            p2 = pol[1];
            p3 = pol[2];
        }
    }

    //треугольник вырождается в прямую
    if (p1.get_y() == p3.get_y())
    {
//        ignore this triangle
    }
    // верхние вершины нах-ся на одной высоте(рассматриваем 1 треугольник)
    else if (p1.get_y() == p2.get_y())
    {
        for (int y = p2.get_y(); y < p3.get_y(); y ++)

        {
            xa = p2.get_x() + (p3.get_x() - p2.get_x())*(y - p2.get_y())/(p3.get_y() - p2.get_y());
            xb = p1.get_x() + (p3.get_x() - p1.get_x())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            za = p2.get_z() + (p3.get_z() - p2.get_z())*(y - p2.get_y())/(p3.get_y() - p2.get_y());
            zb = p1.get_z() + (p3.get_z() - p1.get_z())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            int x1 = std::min(xa, xb);
            int x2 = std::max(xa, xb);
            if (x1 == x2)
            {
                int x = x1;
                z = std::min(std::min(p1.get_z(), p2.get_z()), p3.get_z());

                if (z < bufferMatrix[x+450][y+300])
                {
                    QPoint point;
                    Point p;
                    p.set(x,y,z);
                    point = manager.camera.to_screen(p);
                    scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                    bufferMatrix[point.x()+450][point.y()+300] = z;
                }
            }
            else
            {
                for (int x = x1; x < x2; x ++)
                {
                    z = za + (zb - za)*(x - xa)/(xb - xa);
                    if (z < bufferMatrix[x+450][y+300])
                    {
                        QPoint point;
                        Point p;
                        p.set(x,y,z);
                        point = manager.camera.to_screen(p);
                        scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                        bufferMatrix[point.x()+450][point.y()+300] = z;
                    }
                }
            }
        }
    }
    // делим треугольник на 2 треугольника и рассматриваем каждый из них
    else
    {
        for (int y = p1.get_y(); y < p2.get_y(); y ++)
        {
            xa = p1.get_x() + (p2.get_x() - p1.get_x())*(y - p1.get_y())/(p2.get_y() - p1.get_y());
            xb = p1.get_x() + (p3.get_x() - p1.get_x())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            za = p1.get_z() + (p2.get_z() - p1.get_z())*(y - p1.get_y())/(p2.get_y() - p1.get_y());
            zb = p1.get_z() + (p3.get_z() - p1.get_z())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            int x1 = std::min(xa, xb);
            int x2 = std::max(xa, xb);
            if (x1 == x2)
            {
                int x = x1;
                z = std::min(std::min(p1.get_z(), p2.get_z()), p3.get_z());
                if (z < bufferMatrix[x+450][y+300])
                {
                    QPoint point;
                    Point p;
                    p.set(x,y,z);
                    point = manager.camera.to_screen(p);
                    scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                    bufferMatrix[point.x()+450][point.y()+300] = z;
                }
            }
            else
            {
                for (int x = x1; x < x2; x ++)
                {
                    z = za + (zb - za)*(x - xa)/(xb - xa);
                    if (z < bufferMatrix[x+450][y+300])
                    {
                        QPoint point;
                        Point p;
                        p.set(x,y,z);
                        point = manager.camera.to_screen(p);
                        scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                        bufferMatrix[point.x()+450][point.y()+300] = z;
                    }
                }
            }
        }

        for (int y = p2.get_y(); y < p3.get_y(); y ++)
        {
            xa = p2.get_x() + (p3.get_x() - p2.get_x())*(y - p2.get_y())/(p3.get_y() - p2.get_y());
            xb = p1.get_x() + (p3.get_x() - p1.get_x())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            za = p2.get_z() + (p3.get_z() - p2.get_z())*(y - p2.get_y())/(p3.get_y() - p2.get_y());
            zb = p1.get_z() + (p3.get_z() - p1.get_z())*(y - p1.get_y())/(p3.get_y() - p1.get_y());
            int x1 = std::min(xa, xb);
            int x2 = std::max(xa, xb);
            if (x1 == x2)
            {
                int x = x1;
                z = std::min(std::min(p1.get_z(), p2.get_z()), p3.get_z());
                if (z < bufferMatrix[x+450][y+300])
                {
                    QPoint point;
                    Point p;
                    p.set(x,y,z);
                    point = manager.camera.to_screen(p);
                    scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                    bufferMatrix[point.x()+450][point.y()+300] = z;
                }
            }
            else
            {
                for (int x = x1; x < x2; x ++)
                {
                    z = za + (zb - za)*(x - xa)/(xb - xa);
                    if (z < bufferMatrix[x+450][y+300])
                    {
                        QPoint point;
                        Point p;
                        p.set(x,y,z);
                        point = manager.camera.to_screen(p);
                        scene.addRect(point.x(), point.y(), 1, 1, QPen(Qt::blue));
                        bufferMatrix[point.x()+450][point.y()+300] = z;
                    }
                }
            }
        }
    }
}

void MainWindow::on_zbuffer_toggled(bool checked)
{
    drawZBuffer();
}
