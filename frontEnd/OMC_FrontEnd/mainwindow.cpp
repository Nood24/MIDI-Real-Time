#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <pthread.h>
#include <thread>
#include "hardwareController_Terminal_prototype/HardwareController.h"
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    char * leftSong;
    char * rightSong;
    char * SelectedSong;

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
    ui->song_status->setText("The Current Song is: \n\n");

    font.setPointSize(24);
    ui->playingSongName->setFont(font);

    font.setPointSize(16);
    ui->left_song->setFont(font);
    ui->left_song->setText("Switch Left For: \n\nTemp Song Name!");

    font.setPointSize(16);
    ui->right_song->setFont(font);
    ui->right_song->setText("Switch Right For: \n\nTemp Song Name!");

    font.setPointSize(16);
    ui->play_state->setFont(font);
    ui->play_state->setText("Song Is Currently Playing!\n");

    QPixmap pix3(":/images/images/greenButton.jpg");
    ui->playButton->setPixmap(pix3.scaled(w*1.3,h*1.3,Qt::KeepAspectRatio));

    this->setWindowTitle(
            QApplication::translate("toplevel", "One Man Ceilidh"));

}

void MainWindow::setSongs(char* leftSong, char* rightSong, char* selectedSong){
    cout<< "Hello";
}

void MainWindow::controllerInit()
{
    void *setSongs_pointer setSongs;
    std::thread t1(run, this);
    t1.detach();
    ui->playingSongName->setText(getSong());


}


MainWindow::~MainWindow()
{
    delete ui;
}

