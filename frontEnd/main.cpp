#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.showMaximized();
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "One Man Ceilidh"));
    return app.exec();
}
