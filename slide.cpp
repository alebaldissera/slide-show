#include "slide.h"

bool Slide::isHorizontal() const
{
    return getMaxWidth() > getMaxHeight();
}
