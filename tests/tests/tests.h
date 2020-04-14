#ifndef TESTS_H
#define TESTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tests; }
QT_END_NAMESPACE

class tests : public QMainWindow
{
    Q_OBJECT

public:
    tests(QWidget *parent = nullptr);
    ~tests();

private:
    Ui::tests *ui;
};
#endif // TESTS_H
