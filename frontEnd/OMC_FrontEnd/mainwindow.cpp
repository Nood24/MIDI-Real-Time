#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
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
    ui->song_status->setText("The Current Song is: \n\n\nTemp Song Name!");

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

MainWindow::~MainWindow()
{
    delete ui;
}

