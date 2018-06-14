#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget* widget = new Widget;
    widget->setAttribute( Qt::WA_DeleteOnClose, true );
    widget->resize(600,510);
    widget->show();

    return a.exec();
}
