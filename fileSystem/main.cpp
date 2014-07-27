#include "myfilesyster.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyFileSyster w;
    w.show();

    return a.exec();
}
