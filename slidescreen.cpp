#include "slidescreen.h"

SlideScreen::SlideScreen(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *main = new QVBoxLayout(this);
    setLayout(main);
    QVBoxLayout *centrale = new QVBoxLayout(this);
    centrale->setSpacing(0);
    frame = new QFrame(this);
    centrale->addWidget(frame);
    QHBoxLayout *image = new QHBoxLayout(frame);
    frame->setLayout(image);
    frame->layout()->setSpacing(0);
    frame->layout()->setMargin(0);
    frame->layout()->setAlignment(Qt::AlignCenter);
    frame->setMinimumSize(800, 600);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    progresso = new QProgressBar(this);
    centrale->addWidget(progresso);

    progresso->setRange(0,0);
    progresso->setValue(0);
    progresso->setFormat("%v / %m");

    main->addLayout(centrale);
}

void SlideScreen::showSlide(Slide *slide)
{
    //ripulore il layout già presente
    clearLayout(frame->layout());
    //se la slide è multi ed è divisa verticalmente usermo un layout verticale
    // altrimenti useremo un layout orrizontale
    MultiSlide *s = dynamic_cast<MultiSlide*>(slide);
    if(s && s->isDivideHorizontally())
        frame->setLayout(new QHBoxLayout);
    else
        frame->setLayout(new QVBoxLayout);
    if(slide)
        showSlideRecursive(slide, static_cast<QBoxLayout*>(frame->layout()));
    else
        frame->layout()->addWidget(new QLabel(this));
}

void SlideScreen::updateProgressBar(u_int current, u_int limit)
{
    progresso->setRange(0, limit);
    progresso->setValue(current);
    progresso->show();
}

void SlideScreen::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))){
        if(item->layout())
            clearLayout(item->layout());
        if(item->widget())
            delete item->widget();
        delete item;
    }
}

void SlideScreen::showSlideRecursive(Slide *slide, QBoxLayout *layout, double scale)
{
    MonoSlide *s = dynamic_cast<MonoSlide*>(slide);
    if(s){
        QPixmap pic = QPixmap(QString::fromStdString(s->getPath()));
        QLabel *lab = new QLabel(this);
        lab->setPixmap(pic.scaled(s->getMaxWidth() * scale, s->getMaxHeight() * scale));
        lab->setMaximumSize(QSize(s->getMaxWidth() * scale, s->getMaxHeight() * scale));
        layout->addWidget(lab);
    }else {
        MultiSlide *ms = dynamic_cast<MultiSlide*>(slide);
        if(ms){
            QBoxLayout *topL;
            if(ms->isDivideHorizontally())
                topL = new QHBoxLayout();
            else
                topL = new QVBoxLayout();

            layout->addLayout(topL);
            topL->setSpacing(0);
            topL->setContentsMargins(0, 0, 0, 0);

            for(auto sl : ms->getSlides()){
                showSlideRecursive(sl, topL, scale / ms->getSlides().size() * 1.7);
            }
        }
    }
}
