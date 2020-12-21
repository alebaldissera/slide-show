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

class Controller;

class SlidesViewer : public QWidget
{
    Q_OBJECT
private:
    QMenuBar *createMenu();
    SlideScreen *screen;

    Controller *controller;

    QAction *inizio;
    QAction *precedente;
    QAction *successivo;
    QAction *fine;
    QAction *autoplay;

    QAction *aggiungi;
    QAction *rimuovi;
    QAction *unisci;

    QPushButton *inizioB;
    QPushButton *precedenteB;
    QPushButton *successivoB;
    QPushButton *fineB;
    QPushButton *autoplayB;


public:
    explicit SlidesViewer(QWidget *parent = nullptr);

    void showWarning(const QString &message);
    QString showAddDialog();
    int showRemoveDialog();
    std::pair<int, int> showMergeDialog();

    void showSlide(Slide *slide, u_int value, u_int limit);

    void setController(Controller *c);

signals:

};

#endif // SLIDESVIEWER_H
