#ifndef SLIDE_H
#define SLIDE_H

typedef unsigned int u_int ;

class Slide
{
public:

    virtual ~Slide() = default;

    /**
      * @brief getMaxHeight restituisce l'altezza massima della slide
      * @return u_int
      */

    virtual u_int getMaxHeight() const = 0;

    /**
      * @brief getMaxWidth  Restituisce la larghezza massima della slide
      * @return u_int   restituisce la larghezza della slide
      */

    virtual u_int getMaxWidth() const = 0;

    /**
      * @brief isHorizontal Restituisce true se la slide è orrizzontale
      * @return bool true sse slide orrizzontale
      */
    bool isHorizontal() const;

};

#endif // SLIDE_H
