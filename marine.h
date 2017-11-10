#pragma once

#include "pieza.h"
class marine: public pieza{
  public:
    marine(int,int,int);
    ~marine();
    bool validarMov(int,int,pieza***,bool);
    void hacerMov(pieza*,int,int,pieza***,bool);
};
