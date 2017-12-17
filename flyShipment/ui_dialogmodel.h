/********************************************************************************
** Form generated from reading UI file 'dialogmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODEL_H
#define UI_DIALOGMODEL_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogModel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_L;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_W;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_H;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *acceptButton;

    void setupUi(QDialog *DialogModel)
    {
        if (DialogModel->objectName().isEmpty())
            DialogModel->setObjectName(QStringLiteral("DialogModel"));
        DialogModel->resize(335, 249);
        verticalLayoutWidget = new QWidget(DialogModel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 291, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_L = new QLineEdit(verticalLayoutWidget);
        lineEdit_L->setObjectName(QStringLiteral("lineEdit_L"));

        horizontalLayout->addWidget(lineEdit_L);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_W = new QLineEdit(verticalLayoutWidget);
        lineEdit_W->setObjectName(QStringLiteral("lineEdit_W"));

        horizontalLayout_2->addWidget(lineEdit_W);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_H = new QLineEdit(verticalLayoutWidget);
        lineEdit_H->setObjectName(QStringLiteral("lineEdit_H"));

        horizontalLayout_3->addWidget(lineEdit_H);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayoutWidget_4 = new QWidget(DialogModel);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(60, 160, 211, 71));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        acceptButton = new QPushButton(horizontalLayoutWidget_4);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        horizontalLayout_4->addWidget(acceptButton);


        retranslateUi(DialogModel);

        QMetaObject::connectSlotsByName(DialogModel);
    } // setupUi

    void retranslateUi(QDialog *DialogModel)
    {
        DialogModel->setWindowTitle(QApplication::translate("DialogModel", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\321\213 \320\274\320\276\320\264\320\265\320\273\320\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogModel", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\321\213 \320\274\320\276\320\264\320\265\320\273\320\270 :", Q_NULLPTR));
        label->setText(QApplication::translate("DialogModel", "\320\224\320\273\320\270\320\275\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogModel", "\320\250\320\270\321\200\320\270\320\275\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogModel", "\320\222\321\213\321\201\320\276\321\202\320\260", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("DialogModel", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogModel: public Ui_DialogModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODEL_H
