#include <QApplication>
#include <slidesviewer.h>
#include <controller.h>
#include <model.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SlidesViewer v;
    Controller c;
    Model m;

    c.setModel(&m);
    c.setView(&v);
    v.setController(&c);
    v.show();
    return a.exec();
}
