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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QRadioButton *model;
    QRadioButton *ship;
    QRadioButton *zbuffer;
    QPushButton *clearScr;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *create_menu;
    QMenu *download_menu;
    QMenu *Info_menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 600);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        InfoButtons = new QAction(MainWindow);
        InfoButtons->setObjectName(QStringLiteral("InfoButtons"));
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
        verticalLayoutWidget->setGeometry(QRect(640, 360, 241, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        model = new QRadioButton(verticalLayoutWidget);
        model->setObjectName(QStringLiteral("model"));

        verticalLayout->addWidget(model);

        ship = new QRadioButton(verticalLayoutWidget);
        ship->setObjectName(QStringLiteral("ship"));

        verticalLayout->addWidget(ship);

        zbuffer = new QRadioButton(verticalLayoutWidget);
        zbuffer->setObjectName(QStringLiteral("zbuffer"));

        verticalLayout->addWidget(zbuffer);

        clearScr = new QPushButton(verticalLayoutWidget);
        clearScr->setObjectName(QStringLiteral("clearScr"));

        verticalLayout->addWidget(clearScr);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 30, 600, 480));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        create_menu = new QMenu(menu);
        create_menu->setObjectName(QStringLiteral("create_menu"));
        download_menu = new QMenu(menu);
        download_menu->setObjectName(QStringLiteral("download_menu"));
        Info_menu = new QMenu(menuBar);
        Info_menu->setObjectName(QStringLiteral("Info_menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(Info_menu->menuAction());
        menu->addAction(create_menu->menuAction());
        menu->addAction(download_menu->menuAction());
        menu->addSeparator();
        menu->addAction(exit);
        create_menu->addAction(create_model);
        create_menu->addAction(create_ship);
        download_menu->addAction(download_model);
        download_menu->addAction(download_ship);
        Info_menu->addAction(InfoButtons);
        Info_menu->addAction(about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        InfoButtons->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        create_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        create_ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        download_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        download_ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        ship->setText(QApplication::translate("MainWindow", "\320\244\321\216\320\267\320\265\320\273\321\217\320\266", Q_NULLPTR));
        zbuffer->setText(QApplication::translate("MainWindow", "Z-\320\261\321\203\321\204\321\204\320\265\321\200", Q_NULLPTR));
        clearScr->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "  \320\234\320\265\320\275\321\216", Q_NULLPTR));
        create_menu->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        download_menu->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", Q_NULLPTR));
        Info_menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
