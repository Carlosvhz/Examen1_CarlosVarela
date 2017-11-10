#include "pieza.h"

pieza::pieza(int x, int y){
    posx = x;
    posy = y;
}

int pieza::getPosx(){
    return posx;
}

int getPosy(){
    return posy;
}

void setPosx(int x){
    posx = x;
}
void setPosy(int y){
    posy = y;
}
