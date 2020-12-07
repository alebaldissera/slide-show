#ifndef SLIDECREATOR_H
#define SLIDECREATOR_H

#include <string>
#include <utility>
#include <monoslide.h>
#include <multislide.h>

class SlideCreator
{
private:
    static std::pair<int, int> getImageSize(const string& path);
public:
    /**
      * @brief factory per la creazioen di MonoSlide
      * @param path : path della slide
      * @return la slide che rappresenta i parametri
      * @throw std::runtime_error
      */
    static MonoSlide* createSlide(string& path);

    /**
      * @brief factory per la composizione di slide composte
      * @param firstSlide : prima slide da aggiungere
      * @param sencondSlide : seconda slide da aggiungere
      * @return la MultiSlide contenente le slide di input
      */
    static MultiSlide* composeSlide(Slide* firstSlide, Slide* secondSlide, bool horizontal = true);
};

#endif // SLIDECREATOR_H
