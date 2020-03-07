#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/OneManCeilidh.jpg");
    int w = this->width();
    int h = ui->OMC_logo->height();
    ui->OMC_logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/images/images/OneManCeilidh2.jpg");
    int w_2 = ui->OMC_logo_2->width();
    int h_2 = ui->OMC_logo_2->height();
    ui->OMC_logo_2->setPixmap(pix2.scaled(w_2,h_2,Qt::KeepAspectRatio));

    this->setWindowTitle(
            QApplication::translate("toplevel", "One Man Ceilidh"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

