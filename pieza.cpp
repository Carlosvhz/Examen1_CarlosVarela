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

bool pieza::validarMov(int x,int y,pieza***matriz,bool turno) {
  y=(y-8)*-1;
  if(turno){ //Si es jugador 1
    if(x<0||x>8||y<0||y>8){
      return true;
    }else if(y>getPosy()){
      return true;
    }else{
      if(getPosx()==x||getPosy()==y){
        return true;
      }else if(dynamic_cast<pieza*>(matriz[y][x])){
        return true;
      }else{
      /*  setPosx(x);
        setPosy(y);
        matriz[y][x]=this;*/
        return false;
      }
    }
  }else{ //Si es jugador 2
    if(x<0||x>8||y<0||y>8){
      return true;
    }else if(y<getPosy()){
      return true;
    }else{
      if(getPosx()==x||getPosy()==y){
        return true;
      }else if(dynamic_cast<pieza*>(matriz[y][x])){
        return true;
      }else{
        /*setPosx(x);
        setPosy(y);
        matriz[y][x]=this;*/
        return false;
      }
    }
  }
}
