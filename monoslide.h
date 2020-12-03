#ifndef MONOSLIDE_H
#define MONOSLIDE_H

#include <string>
#include "slide.h"
using std::string;

class MonoSlide: public Slide
{
private:
    string image_path;
    u_int max_width;
    u_int max_height;

public:
    MonoSlide(const string& path, u_int max_w, u_int max_h);
    ~MonoSlide() override = default;

    /**
      * @brief getPath getter per il path della slide
      * @return il path della slide
      */
   string getPath() const;

   /**
     * @brief getMaxHeight Restituisce l'altezza massima della slide
     * @return u_int Altezza massima della slide
     */
   u_int getMaxHeight() const override;

   /**
     * @brief getMaxWidth Restituisce la lunghezza massima della slide
     * @return u_int Lunghezza massima della slide
     */
   u_int getMaxWidth() const override;


};

#endif // MONOSLIDE_H
