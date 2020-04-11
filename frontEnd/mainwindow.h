#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void controllerInit();
    void set_songs(string leftSong, string rightSong, string selectedSong);
    void set_play_button(bool playButtonState, bool text_red=false);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
