#ifndef MULTSLIDE_H
#define MULTSLIDE_H

#include"slide.h"
#include<string>
#include<vector>
#include<stdexcept>
#include<numeric>
#include<algorithm>

using std::string;
using std::vector;

class MultiSlide:public Slide
{
private:
    bool dividedHorizotally;
    vector<Slide*> slides;

public:
    MultiSlide(bool h);
    ~MultiSlide() override;

    /**
      * @brief aggiunge una slide
      * @param slide: puntatore alla slide da aggiungere
      */
    void addSlide(Slide* slide);

    /**
      * @brief rimuove la index-esima slide dalla slide corrente
      * @param index: indice della slide corrente
      * @return riferimento alla slide rimossa
      * @throws std::out_of_range: e index > numero di slides
      */
    Slide* removeSlide(u_int index);

    /**
      * @brief specifica se la slide corrente è divisa verticale o orrizzontale
      * @return true sse è divisa orrizzontalmente
      */
    bool isDivideHorizontally() const;

    /**
      * @brief getter per le slide che compongono la corrente
      * @return vector delle slide contenute
      */
    const vector<Slide*>& getSlides() const;

    /**
      * @brief getMaxHeight restituisce l'altezza massima della slide
      * @return u_int altezza della slide
      */
    u_int getMaxHeight() const override;

    /**
      * @brief getMaxWidth restituisce la larghezza massima della slide
      * @return u_int larghezza della slide
      */
    u_int getMaxWidth() const override;
};

#endif // MULTSLIDE_H
