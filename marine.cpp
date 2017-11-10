#include "marine.h"

marine::marine(int x, int y, int c):pieza(x,y,c){
}

marine::~marine(){
}

//marine::marine()
bool marine::validarMov(int x, int y, pieza***matriz, bool turno){
    if(turno){ //Si es jugador 1
      if(x<0||x>8||y<0||y>8){
        return false;
      }else if(y>getPosy()){
        return false;
      }else{
        if(getPosx()==x||getPosy()==y||(getPosx()==x&&getPosy()==y)){
          return false;
        }else if(dynamic_cast<pieza*>(matriz[y][x])){
          return false;
        }else{
          return true;
        }
      }
    }else{ //Si es jugador 2
      if(x<0||x>8||y<0||y>8){
        return false;
      }else if(y<getPosy()){
        return false;
      }else{
        if(getPosx()==x||getPosy()==y||(getPosx()==x&&getPosy()==y)){
          return false;
        }else if(dynamic_cast<pieza*>(matriz[y][x])){
          return false;
        }else{
          return true;
        }
      }
    }
}

void marine::hacerMov(pieza* ficha,int x,int y ,pieza*** matriz, bool turno){
    pieza* fichaEliminar;
    if(turno){  //Si turno es true, es jugador 1 el que hace el movimiento
      for(int i=ficha->getPosy(); i<y;i++){
        for(int j=ficha->getPosx(); j<x; j++){
            if(dynamic_cast<pieza*>(matriz[y][x])){
                fichaEliminar = matriz[y][x];
                fichaEliminar->setPosx(-1);
                fichaEliminar->setPosy(-1);
            }
        }
      }
    }else{  //Si es false es el jugador 2
      for(int i=ficha->getPosy(); i>y;i--){
        for(int j=ficha->getPosx(); j>x; j--){
            if(dynamic_cast<pieza*>(matriz[y][x])){
                fichaEliminar = matriz[y][x];
                fichaEliminar->setPosx(-1);
                fichaEliminar->setPosy(-1);
            }
        }
      }
    }
}
