#include <QApplication>
#include <slidesviewer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SlidesViewer main;
    main.show();
    return a.exec();
}
