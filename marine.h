#pragma once

#include "pieza.h"
class marine: public pieza{
  public:
    marine(int,int,int);
    ~marine();
    bool validarMov(int,int,pieza***);
};
