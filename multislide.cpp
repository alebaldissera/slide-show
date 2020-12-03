#include "multislide.h"

MultiSlide::MultiSlide(bool h): dividedHorizotally(h)
{

}

MultiSlide::~MultiSlide() {
    for(auto i : slides)
        delete i;
}

void MultiSlide::addSlide(Slide *slide){
    slides.push_back(slide);
}

Slide* MultiSlide::removeSlide(u_int index){
    if(index > static_cast<u_int>(slides.size()))
        throw std::out_of_range("Index greater than the number os existing slides");
    auto sl = slides[index];
    slides.erase(slides.begin() + index);
    return sl;
}

bool MultiSlide::isDivideHorizontally() const {
    return dividedHorizotally;
}

const vector<Slide*>& MultiSlide::getSlides() const {return slides;}

u_int MultiSlide::getMaxHeight() const{
    if(isDivideHorizontally()){
        u_int max = 0;
        for(auto sl : slides){
            if(sl->getMaxHeight() > max) max = sl->getMaxHeight();
        }
        return max;
    }else{
        return std::accumulate(
                    slides.begin(), slides.end(), 0,
                    [](int acc, Slide* es) {return acc + es->getMaxHeight(); });
    }
}

u_int MultiSlide::getMaxWidth() const{
    if(isDivideHorizontally()){
        return std::accumulate(
                    slides.begin(), slides.end(), 0,
                    [](int acc, Slide* es) {return acc + es->getMaxWidth(); });
    }else{
        u_int max = 0;
        for(auto sl : slides)
               if(sl->getMaxWidth() > max) max = sl->getMaxWidth();
        return max;
    }
}
