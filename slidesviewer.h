#ifndef SLIDESVIEWER_H
#define SLIDESVIEWER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFrame>
#include <QProgressBar>
#include <QDialog>
#include <QFileDialog>
#include <QInputDialog>

#include <slide.h>
#include <monoslide.h>
#include <multislide.h>
#include <slidecreator.h>

#include <slidescreen.h>

#include <utility>
#include <string>

class SlidesViewer : public QWidget
{
    Q_OBJECT
private:
    QMenuBar *createMenu();
    SlideScreen *screen;

public:
    explicit SlidesViewer(QWidget *parent = nullptr);

    void showWarning(const QString &message);
    QString showAddDialog();
    int showRemoveDialog();
    std::pair<int, int> showMergeDialog();

    void showSlide(Slide *slide, u_int value, u_int limit);

signals:

};

#endif // SLIDESVIEWER_H
