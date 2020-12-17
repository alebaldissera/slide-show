#ifndef SLIDESCREEN_H
#define SLIDESCREEN_H

#include <QWidget>
#include <QProgressBar>
#include <QFrame>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include <slide.h>
#include <monoslide.h>
#include <multislide.h>

class SlideScreen : public QWidget
{
    Q_OBJECT
private:
    QFrame *frame;
    QProgressBar *progresso;

    void showSlideRecursive(Slide *slide, QBoxLayout *layout, double scale = 1);
    void clearLayout(QLayout *layout);

public:
    explicit SlideScreen(QWidget *parent = nullptr);
    void showSlide(Slide *slide);
    void updateProgressBar(u_int current, u_int limit);
};

#endif // SLIDESCREEN_H
