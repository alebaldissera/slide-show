#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), autoMode(false), timer(new QTimer())
{
    connect(timer, SIGNAL(timeout()), this, SLOT(next()));
}

void Controller::setModel(Model *m)
{
    model = m;
}

void Controller::setView(SlidesViewer *v)
{
    view = v;
}

Controller::~Controller()
{
    delete timer;
}

void Controller::setAutoMode(bool mode)
{
    if(mode != autoMode){
        autoMode = mode;
        if(mode){
            timer->start(2000);
        }else{
            timer->stop();
        }
    }
}

void Controller::showSlide() const
{
    try{
        view->showSlide(model->getSlide(), model->getCurrent() + 1, model->getSlideShowSize());
    }catch(std::out_of_range e){
        view->showSlide(0,0,0);
    }
}

void Controller::next()const
{
    model->nextSlide();
    showSlide();
}

void Controller::previous()const
{
    model->previousSlide();
    showSlide();
}

void Controller::begin()const
{

    model->restartSlideShow();
    showSlide();
}

void Controller::end()const
{
    model->endSlideShow();
    showSlide();
}

void Controller::add() const
{
    try{
        string path = view->showAddDialog().toStdString();
        model->addNewSlide(path);
    }catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
    begin();
}

void Controller::remove() const
{
    try{
        u_int index = view->showRemoveDialog();
        model->removeSlide(index - 1);
    }catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
    begin();
}

void Controller::merge() const
{
    try{
        auto indexs = view->showMergeDialog();
        model->mergeSlides(indexs.first, indexs.second);
        showSlide();
    } catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
    begin();
}

void Controller::autoplay()
{
    setAutoMode(!autoMode);
}
