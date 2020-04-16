#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <pthread.h>
#include <thread>
#include "hardwareController_Terminal_prototype/TerminalController.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QPixmap pix(":/images/images/OneManCeilidh.jpg");
    int w = ui->OMC_logo->width();
    int h = ui->OMC_logo->height();
    ui->OMC_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/images/images/OneManCeilidh2.jpg");
    ui->OMC_logo_2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

    QFont font = ui->song_status->font();
    font.setPointSize(24);
    ui->song_status->setFont(font);
    ui->song_status->setText("The Current Song is: \n");
    ui->song_status->setAlignment(Qt::AlignCenter);

    font.setPointSize(24);
    ui->playingSongName->setFont(font);
    ui->playingSongName->setAlignment(Qt::AlignCenter);

    font.setPointSize(16);
    ui->leftShift->setFont(font);
    ui->leftShift->setText("Switch Left For:\n");
    ui->leftShift->setFixedWidth(w*1.1);
    ui->leftShift->setAlignment(Qt::AlignCenter);

    font.setPointSize(16);
    ui->left_song->setFont(font);
    ui->left_song->setFixedWidth(w*1.1);
    ui->left_song->setAlignment(Qt::AlignCenter);
    ui->left_song->setText("Switch Left For: \n\nTemp Song Name!");

    font.setPointSize(16);
    ui->rightShift->setFont(font);
    ui->rightShift->setText("Switch Right For:\n");
    ui->rightShift->setFixedWidth(w*1.1);
    ui->rightShift->setAlignment(Qt::AlignCenter);

    font.setPointSize(16);
    ui->right_song->setFont(font);
    ui->right_song->setFixedWidth(w*1.1);
    ui->right_song->setAlignment(Qt::AlignCenter);
    ui->right_song->setText("Switch Right For: \n\nTemp Song Name!");

    font.setPointSize(16);
    ui->play_state->setFont(font);
    ui->play_state->setText("Song Is Currently Playing!\n");

    QPixmap pix3(":/images/images/greenButton.jpg");
    ui->playButton->setPixmap(pix3.scaled(w*1.3,h*1.3,Qt::KeepAspectRatio));

    this->setWindowTitle(
            QApplication::translate("toplevel", "One Man Ceilidh"));

}
    

void MainWindow::set_play_button(bool playButtonState, bool text_red){
    int w = ui->OMC_logo->width();
    int h = ui->OMC_logo->height();
    if (playButtonState){
        QPixmap pix3(":/images/images/greenButton.jpg");
        ui->playButton->setPixmap(pix3.scaled(w*1.3,h*1.3,Qt::KeepAspectRatio));
        ui->play_state->setText("Song Is Currently Playing!\n");
    }
    else{
        QPixmap pix3(":/images/images/redButton.jpg");
        ui->playButton->setPixmap(pix3.scaled(w*1.3,h*1.3,Qt::KeepAspectRatio));
        ui->play_state->setText("Song Is Currently Paused!\n");
    }

    QPalette pal = palette();
    
    if (text_red){
        pal.setColor(QPalette::Background, Qt::white);
        pal.setColor(QPalette::WindowText, Qt::red);
    }
    else{
        pal.setColor(QPalette::Background, Qt::white);
        pal.setColor(QPalette::WindowText, Qt::black);
    }
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();

}

void MainWindow::set_songs(string leftSong, string selectedSong, string rightSong){
    ui->right_song->setText(QString::fromStdString(rightSong));
    ui->left_song->setText(QString::fromStdString(leftSong));
    cout << "selectsong:"<<selectedSong<<endl;
    ui->playingSongName->setText(QString::fromStdString(selectedSong));
}



MainWindow::~MainWindow()
{
    delete ui;
    QApplication::quit();
}

