#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <slidesviewer.h>
#include <model.h>
#include <QTimer>
#include <utility>

class Controller : public QObject
{
    Q_OBJECT
private:

    bool autoMode;
    QTimer *timer;

    SlidesViewer *view;
    Model *model;

    void showSlide()const;

public:
    explicit Controller(QObject *parent = nullptr);
    void setModel(Model* m);
    void setView(SlidesViewer *v);
    ~Controller();
    void setAutoMode(bool mode);

signals:

public slots:
    void next()const;
    void previous()const;
    void begin()const;
    void end()const;

    void add() const;
    void remove() const;
    void merge() const;
    void autoplay();
};

#endif // CONTROLLER_H
