#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <slide.h>
#include <stdexcept>
#include <vector>

class SlideShow
{
private:
    u_int currentSlide;
    std::vector<Slide*> slides;

public:
    SlideShow();
    ~SlideShow();

    /**
      * @brief inserisce slide in posizione finale
      * @param slide : slide da inserire
      */
    void addSlide(Slide* slide);

    /**
      * @brief inserisce alla posizione index, oppure alla fine se index > numero di slide correntemente inserite
      * @param slide : slide da inserire
      * @param index : indice da cui inserire la slide
      */
    void insertSlide(Slide* slide, u_int index);

    /**
      * @brief rimuve la index-esima slide dalla slideshow
      * @param index : indice della slide da rimuovere
      * @return puntatore alla slide rimossa
      * @throw out_of_range se index > numero di slide correntemente nella slideshow
      */
    Slide* removeSlide(u_int index);

    /**
     * @brief getter per l'indice della slide corrente
     * @return l'indice per la slide corrente
     */
    u_int getCurrentSlide() const;

    /**
      * @brief getter per una slide specifica
      * @param index : indice della slide desiderata
      * @return la slide desiderata
      * @throw out_of_range se index > numero di slide correntemente nella slideshow
      */
    Slide *getSlide(u_int index) const;

    /**
      * @brief getSize getter per la dimesione della slideshow
      * @return u_int la dimensione dello slideshow
      */
    u_int getSize() const;

    /**
      * @brief torna indietro di una slide
      */
    void previous();

    /**
      * @brief avanza di una slide
      */
    void next();

    /**
      * @brief vai all'inizio della slideshow
      */
    void goToStart();

    /**
      * @brief vai alla fine della slideshow
      */
    void goToEnd();
};

#endif // SLIDESHOW_H
