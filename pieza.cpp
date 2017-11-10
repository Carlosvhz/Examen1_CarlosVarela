#include "pieza.h"

pieza::pieza(int x, int y, int c){
    posx = x;
    posy = y;
    color = c;
}

pieza::~pieza() {
}

int pieza::getColor(){
  return color;
}
int pieza::getPosx(){
    return posx;
}

int pieza::getPosy(){
    return posy;
}

void pieza::setPosx(int x){
    posx = x;
}
void pieza::setPosy(int y){
    posy = y;
}

bool pieza::validarMov(int,int,pieza***) {
  return false;
}
