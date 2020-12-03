#include "monoslide.h"

MonoSlide::MonoSlide(const string& path, u_int max_w, u_int max_h): image_path(path), max_width(max_w), max_height(max_h)
{

}

u_int MonoSlide::getMaxHeight() const {
    return max_height;
}

u_int MonoSlide::getMaxWidth() const {
    return max_width;
}
