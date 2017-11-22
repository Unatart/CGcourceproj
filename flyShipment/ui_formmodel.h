/********************************************************************************
** Form generated from reading UI file 'formmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMODEL_H
#define UI_FORMMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormModel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *Length;
    QLineEdit *lineEdit_L;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Width;
    QLineEdit *lineEdit_W;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Height;
    QLineEdit *lineEdit_H;
    QSpacerItem *verticalSpacer;
    QPushButton *acceptButton;

    void setupUi(QWidget *FormModel)
    {
        if (FormModel->objectName().isEmpty())
            FormModel->setObjectName(QStringLiteral("FormModel"));
        FormModel->resize(292, 296);
        verticalLayoutWidget = new QWidget(FormModel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 231, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Length = new QLabel(verticalLayoutWidget);
        Length->setObjectName(QStringLiteral("Length"));

        horizontalLayout->addWidget(Length);

        lineEdit_L = new QLineEdit(verticalLayoutWidget);
        lineEdit_L->setObjectName(QStringLiteral("lineEdit_L"));

        horizontalLayout->addWidget(lineEdit_L);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Width = new QLabel(verticalLayoutWidget);
        Width->setObjectName(QStringLiteral("Width"));

        horizontalLayout_2->addWidget(Width);

        lineEdit_W = new QLineEdit(verticalLayoutWidget);
        lineEdit_W->setObjectName(QStringLiteral("lineEdit_W"));

        horizontalLayout_2->addWidget(lineEdit_W);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Height = new QLabel(verticalLayoutWidget);
        Height->setObjectName(QStringLiteral("Height"));

        horizontalLayout_3->addWidget(Height);

        lineEdit_H = new QLineEdit(verticalLayoutWidget);
        lineEdit_H->setObjectName(QStringLiteral("lineEdit_H"));

        horizontalLayout_3->addWidget(lineEdit_H);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        acceptButton = new QPushButton(verticalLayoutWidget);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        verticalLayout->addWidget(acceptButton);


        retranslateUi(FormModel);

        QMetaObject::connectSlotsByName(FormModel);
    } // setupUi

    void retranslateUi(QWidget *FormModel)
    {
        FormModel->setWindowTitle(QApplication::translate("FormModel", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("FormModel", "Enter sizes:", Q_NULLPTR));
        Length->setText(QApplication::translate("FormModel", "Length", Q_NULLPTR));
        Width->setText(QApplication::translate("FormModel", "Width", Q_NULLPTR));
        Height->setText(QApplication::translate("FormModel", "Height", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("FormModel", "Accept", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormModel: public Ui_FormModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMODEL_H
