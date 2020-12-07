#include "model.h"

Model::Model(): slideshow(new SlideShow) {}

Model::~Model()
{
    delete slideshow;
}

void Model::addNewSlide(std::string &path) const
{
    slideshow->addSlide(SlideCreator::createSlide(path));
}

void Model::mergeSlides(u_int firstSlide, u_int secondSlide) const
{
    if(slideshow->getSize() <= firstSlide)
        throw std::out_of_range("First index out of range");
    if(slideshow->getSize() <= secondSlide)
        throw std::out_of_range("Second index out of range");

    if(secondSlide > firstSlide)
        std::swap(firstSlide, secondSlide);

    Slide* f, *s;
    s = slideshow->removeSlide(secondSlide);

    if(firstSlide != secondSlide)
        f = slideshow->removeSlide(firstSlide);
    else
        f = s;

    slideshow->insertSlide(SlideCreator::composeSlide(f, s, f->getMaxWidth() + s->getMaxWidth() <= f->getMaxHeight() + s->getMaxHeight()), firstSlide);
}

void Model::removeSlide(u_int index) const
{
    if(slideshow->getSize() <= index)
        throw std::out_of_range("Index out of range");
    slideshow->removeSlide(index);
}

void Model::nextSlide() const
{
    slideshow->next();
}

void Model::previousSlide() const
{
    slideshow->previous();
}

void Model::restartSlideShow() const
{
    slideshow->goToStart();
}

void Model::endSlideShow() const
{
    slideshow->goToEnd();
}

Slide *Model::getSlide() const
{
    return slideshow->getSlide(slideshow->getCurrentSlide());
}

u_int Model::getCurrent() const
{
    return slideshow->getCurrentSlide();
}

u_int Model::getSlideShowSize() const
{
    return slideshow->getSize();
}


