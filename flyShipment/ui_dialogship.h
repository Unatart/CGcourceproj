/********************************************************************************
** Form generated from reading UI file 'dialogship.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSHIP_H
#define UI_DIALOGSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogShip
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *length;
    QLineEdit *lineEdit_l;
    QHBoxLayout *horizontalLayout_2;
    QLabel *height;
    QLineEdit *lineEdit_h;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *bottom_w;
    QLineEdit *lineEdit_wb;
    QHBoxLayout *horizontalLayout_3;
    QLabel *top_w;
    QLineEdit *lineEdit_wt;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer;
    QPushButton *acceptButton;
    QPushButton *backButton;

    void setupUi(QDialog *DialogShip)
    {
        if (DialogShip->objectName().isEmpty())
            DialogShip->setObjectName(QStringLiteral("DialogShip"));
        DialogShip->resize(381, 373);
        verticalLayoutWidget = new QWidget(DialogShip);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 311, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        length = new QLabel(verticalLayoutWidget);
        length->setObjectName(QStringLiteral("length"));

        horizontalLayout->addWidget(length);

        lineEdit_l = new QLineEdit(verticalLayoutWidget);
        lineEdit_l->setObjectName(QStringLiteral("lineEdit_l"));

        horizontalLayout->addWidget(lineEdit_l);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        height = new QLabel(verticalLayoutWidget);
        height->setObjectName(QStringLiteral("height"));

        horizontalLayout_2->addWidget(height);

        lineEdit_h = new QLineEdit(verticalLayoutWidget);
        lineEdit_h->setObjectName(QStringLiteral("lineEdit_h"));

        horizontalLayout_2->addWidget(lineEdit_h);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        bottom_w = new QLabel(verticalLayoutWidget);
        bottom_w->setObjectName(QStringLiteral("bottom_w"));

        horizontalLayout_6->addWidget(bottom_w);

        lineEdit_wb = new QLineEdit(verticalLayoutWidget);
        lineEdit_wb->setObjectName(QStringLiteral("lineEdit_wb"));

        horizontalLayout_6->addWidget(lineEdit_wb);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        top_w = new QLabel(verticalLayoutWidget);
        top_w->setObjectName(QStringLiteral("top_w"));

        horizontalLayout_3->addWidget(top_w);

        lineEdit_wt = new QLineEdit(verticalLayoutWidget);
        lineEdit_wt->setObjectName(QStringLiteral("lineEdit_wt"));

        horizontalLayout_3->addWidget(lineEdit_wt);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        acceptButton = new QPushButton(verticalLayoutWidget);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        verticalLayout->addWidget(acceptButton);

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName(QStringLiteral("backButton"));

        verticalLayout->addWidget(backButton);


        retranslateUi(DialogShip);

        QMetaObject::connectSlotsByName(DialogShip);
    } // setupUi

    void retranslateUi(QDialog *DialogShip)
    {
        DialogShip->setWindowTitle(QApplication::translate("DialogShip", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogShip", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\321\213 \321\204\321\216\320\267\320\265\320\273\321\217\320\266\320\260 :", Q_NULLPTR));
        length->setText(QApplication::translate("DialogShip", "\320\224\320\273\320\270\320\275\320\260", Q_NULLPTR));
        height->setText(QApplication::translate("DialogShip", "\320\222\321\213\321\201\320\276\321\202\320\260", Q_NULLPTR));
        bottom_w->setText(QApplication::translate("DialogShip", "\320\250\320\270\321\200\320\270\320\275\320\260 \320\262\320\265\321\200\321\205. \320\276\321\201\320\275.", Q_NULLPTR));
        top_w->setText(QApplication::translate("DialogShip", "\320\250\320\270\321\200\320\270\320\275\320\260 \320\275\320\270\320\266\320\275. \320\276\321\201\320\275.", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("DialogShip", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
        backButton->setText(QApplication::translate("DialogShip", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogShip: public Ui_DialogShip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSHIP_H
