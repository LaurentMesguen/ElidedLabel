#include "elidedlabel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElidedLabel label ("This some text to test the ElidedLabel class");
    label.show();
    return a.exec();
}
