#pragma once
#include "pieza.h"
class general : public pieza{
  public:
    general(int,int,int);
    ~general();
    bool validarMov(int,int,pieza***);
};
