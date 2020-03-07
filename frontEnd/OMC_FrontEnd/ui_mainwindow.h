/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *OMC_logo;
    QVBoxLayout *verticalLayout;
    QLabel *song_status;
    QLabel *label;
    QLabel *OMC_logo_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OMC_logo = new QLabel(centralwidget);
        OMC_logo->setObjectName(QStringLiteral("OMC_logo"));
        OMC_logo->setMinimumSize(QSize(191, 191));
        OMC_logo->setMaximumSize(QSize(191, 191));
        OMC_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/images/OneManCeilidh.jpg")));

        horizontalLayout->addWidget(OMC_logo, 0, Qt::AlignLeft|Qt::AlignTop);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        song_status = new QLabel(centralwidget);
        song_status->setObjectName(QStringLiteral("song_status"));

        verticalLayout->addWidget(song_status, 0, Qt::AlignHCenter|Qt::AlignTop);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        OMC_logo_2 = new QLabel(centralwidget);
        OMC_logo_2->setObjectName(QStringLiteral("OMC_logo_2"));
        OMC_logo_2->setMinimumSize(QSize(191, 191));
        OMC_logo_2->setMaximumSize(QSize(191, 538));
        OMC_logo_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/OneManCeilidh2.jpg")));

        horizontalLayout->addWidget(OMC_logo_2, 0, Qt::AlignRight|Qt::AlignTop);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        OMC_logo->setText(QString());
        song_status->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label->setText(QString());
        OMC_logo_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
