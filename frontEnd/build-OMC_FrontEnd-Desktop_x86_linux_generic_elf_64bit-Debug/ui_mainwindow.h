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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *OMC_logo;
    QSpacerItem *verticalSpacer_2;
    QLabel *leftShift;
    QLabel *left_song;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *song_status;
    QLabel *playingSongName;
    QLabel *play_state;
    QLabel *playButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *OMC_logo_2;
    QSpacerItem *verticalSpacer;
    QLabel *rightShift;
    QLabel *right_song;
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        OMC_logo = new QLabel(centralwidget);
        OMC_logo->setObjectName(QStringLiteral("OMC_logo"));
        OMC_logo->setMinimumSize(QSize(191, 191));
        OMC_logo->setMaximumSize(QSize(191, 191));
        OMC_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/images/OneManCeilidh.jpg")));

        verticalLayout_2->addWidget(OMC_logo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        leftShift = new QLabel(centralwidget);
        leftShift->setObjectName(QStringLiteral("leftShift"));

        verticalLayout_2->addWidget(leftShift, 0, Qt::AlignLeft|Qt::AlignBottom);

        left_song = new QLabel(centralwidget);
        left_song->setObjectName(QStringLiteral("left_song"));

        verticalLayout_2->addWidget(left_song, 0, Qt::AlignLeft|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        song_status = new QLabel(centralwidget);
        song_status->setObjectName(QStringLiteral("song_status"));

        verticalLayout_4->addWidget(song_status, 0, Qt::AlignHCenter);

        playingSongName = new QLabel(centralwidget);
        playingSongName->setObjectName(QStringLiteral("playingSongName"));

        verticalLayout_4->addWidget(playingSongName, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(verticalLayout_4);

        play_state = new QLabel(centralwidget);
        play_state->setObjectName(QStringLiteral("play_state"));

        verticalLayout->addWidget(play_state, 0, Qt::AlignHCenter|Qt::AlignBottom);

        playButton = new QLabel(centralwidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout->addWidget(playButton, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        OMC_logo_2 = new QLabel(centralwidget);
        OMC_logo_2->setObjectName(QStringLiteral("OMC_logo_2"));
        OMC_logo_2->setMinimumSize(QSize(191, 191));
        OMC_logo_2->setMaximumSize(QSize(191, 538));
        OMC_logo_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/OneManCeilidh2.jpg")));

        verticalLayout_3->addWidget(OMC_logo_2, 0, Qt::AlignRight|Qt::AlignTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        rightShift = new QLabel(centralwidget);
        rightShift->setObjectName(QStringLiteral("rightShift"));

        verticalLayout_3->addWidget(rightShift, 0, Qt::AlignRight|Qt::AlignBottom);

        right_song = new QLabel(centralwidget);
        right_song->setObjectName(QStringLiteral("right_song"));

        verticalLayout_3->addWidget(right_song, 0, Qt::AlignRight|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_3);

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
        leftShift->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        left_song->setText(QApplication::translate("MainWindow", "left Song", Q_NULLPTR));
        song_status->setText(QApplication::translate("MainWindow", "What Song is playig", Q_NULLPTR));
        playingSongName->setText(QApplication::translate("MainWindow", "Song Playing Name", Q_NULLPTR));
        play_state->setText(QApplication::translate("MainWindow", "Song is Playing", Q_NULLPTR));
        playButton->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        OMC_logo_2->setText(QString());
        rightShift->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        right_song->setText(QApplication::translate("MainWindow", "Right Song", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
