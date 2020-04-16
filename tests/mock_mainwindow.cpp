#include "mock_mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <pthread.h>
#include <thread>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


}


void MainWindow::set_play_button(bool playButtonState, bool text_red){
    }



void MainWindow::set_songs(string leftSong, string rightSong, string selectedSong){

}


MainWindow::~MainWindow()
{

    delete ui;
}

