#ifndef MODEL_H
#define MODEL_H

#include <slideshow.h>
#include <slide.h>
#include <slidecreator.h>
#include <string>
#include <utility>

using std::string;
typedef unsigned int u_int ;

class Model
{
private:
    SlideShow* slideshow;

public:
    Model();
    ~Model();

    /**
      * @brief addNewSlide  Aggiunge al modello una slide
      * @param path         Path in cui si trova l'immagine da aggiungere
      */
    void addNewSlide(string& path) const;

    /**
      * @brief mergeSlides  Compone due slide in un'unica slide multipla
      * @param firstIndex   Indice della prima slide
      * @param secondIndex  Indice della seconda slide
      * @throw std::out_of_range    se gli indici non rispettano il numero di slides
      */
    void mergeSlides(u_int firstSlide, u_int secondSlide) const;

    /**
      * @brief removeSlide  Rimuove una slide
      * @param index        Indice della slide da rimuovere
      * @throw  std::out_of_range   se l'indice non è tra le slide indicate
      */
    void removeSlide(u_int index) const;

    /**
      * @brief nextSlide    Va aventi di una slide
      */
    void nextSlide() const;

    /**
      * @brief previousSlide    Va indietro di una slide
      */
    void previousSlide() const;

    /**
      * @brief restartSlideShow Ritorna all'inizio della slideshow
      */
    void restartSlideShow() const;

    /**
      * @brief endSlideShow Va alla fine della slideshow
      */
    void endSlideShow() const;

    /**
      * @brief getSlide     Restituisce la slide corrente
      * @return Slide*
      */

    Slide *getSlide() const;

    /**
      * @brief getCurrent   Restituisce l'indece della slide corrente
      * @return u_int       Indice della slide
      */
    u_int getCurrent() const;

    /**
      * @brief getSlideShowSize Restituisce la dimensione della slideshow
      * @return u_int           Dimensione della slideshow
      */
    u_int getSlideShowSize() const;
};

#endif // MODEL_H
