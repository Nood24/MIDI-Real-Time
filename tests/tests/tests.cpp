#include "tests.h"
#include "./ui_tests.h"

tests::tests(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tests)
{
    ui->setupUi(this);
}

tests::~tests()
{
    delete ui;
}

