/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exit;
    QAction *about;
    QAction *InfoButtons;
    QAction *create_model;
    QAction *create_ship;
    QAction *download_model;
    QAction *download_ship;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ShipButton;
    QPushButton *ModelButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QRadioButton *ship;
    QRadioButton *model;
    QRadioButton *cameraButton;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QCheckBox *DrawBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clearScr;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *Info_menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 664);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        InfoButtons = new QAction(MainWindow);
        InfoButtons->setObjectName(QStringLiteral("InfoButtons"));
        QFont font;
        font.setPointSize(10);
        InfoButtons->setFont(font);
        create_model = new QAction(MainWindow);
        create_model->setObjectName(QStringLiteral("create_model"));
        create_ship = new QAction(MainWindow);
        create_ship->setObjectName(QStringLiteral("create_ship"));
        download_model = new QAction(MainWindow);
        download_model->setObjectName(QStringLiteral("download_model"));
        download_ship = new QAction(MainWindow);
        download_ship->setObjectName(QStringLiteral("download_ship"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(820, 30, 251, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ShipButton = new QPushButton(verticalLayoutWidget);
        ShipButton->setObjectName(QStringLiteral("ShipButton"));
        QFont font1;
        font1.setPointSize(11);
        ShipButton->setFont(font1);

        verticalLayout->addWidget(ShipButton);

        ModelButton = new QPushButton(verticalLayoutWidget);
        ModelButton->setObjectName(QStringLiteral("ModelButton"));
        ModelButton->setFont(font1);

        verticalLayout->addWidget(ModelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        ship = new QRadioButton(verticalLayoutWidget);
        ship->setObjectName(QStringLiteral("ship"));
        ship->setEnabled(true);
        ship->setFont(font1);
        ship->setCheckable(true);

        verticalLayout->addWidget(ship);

        model = new QRadioButton(verticalLayoutWidget);
        model->setObjectName(QStringLiteral("model"));
        model->setEnabled(true);
        model->setFont(font1);

        verticalLayout->addWidget(model);

        cameraButton = new QRadioButton(verticalLayoutWidget);
        cameraButton->setObjectName(QStringLiteral("cameraButton"));
        cameraButton->setEnabled(true);
        cameraButton->setFont(font1);
        cameraButton->setCheckable(true);

        verticalLayout->addWidget(cameraButton);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setStyleSheet(QStringLiteral("selection-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(43, 176, 133, 255), stop:1 rgba(255, 255, 255, 255));"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setSliderPosition(5);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        DrawBox = new QCheckBox(verticalLayoutWidget);
        DrawBox->setObjectName(QStringLiteral("DrawBox"));
        DrawBox->setFont(font1);

        verticalLayout->addWidget(DrawBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        clearScr = new QPushButton(verticalLayoutWidget);
        clearScr->setObjectName(QStringLiteral("clearScr"));
        clearScr->setFont(font1);

        verticalLayout->addWidget(clearScr);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 800, 600));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 21));
        Info_menu = new QMenu(menuBar);
        Info_menu->setObjectName(QStringLiteral("Info_menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(Info_menu->menuAction());
        Info_menu->addAction(InfoButtons);
        Info_menu->addAction(about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\276\320\271 \320\277\321\200\320\276\320\265\320\272\321\202 ", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        InfoButtons->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        create_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        create_ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        download_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        download_ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        ShipButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\204\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        ModelButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\263\321\200\321\203\320\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\321\213\320\271 \320\276\320\261\321\212\320\265\320\272\321\202:", Q_NULLPTR));
        ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        cameraButton->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        DrawBox->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", Q_NULLPTR));
        clearScr->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", Q_NULLPTR));
        Info_menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
