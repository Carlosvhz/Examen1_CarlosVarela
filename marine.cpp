#include "marine.h"

marine::marine(int x, int y, int c):pieza(x,y,c){
}

marine::~marine(){
}

//marine::marine()
bool marine::validarMov(int x, int y, pieza***matriz){
    if(x<0||x>8||y<0||y>8){
      return false;
    }else if(y<getPosy){

    }else{
      if(getPosx()==x||getPosy()==y||(getPosx()==x&&getPosy()==y)){
        return false;
      }else if(dynamic_cast<pieza>(matriz[y][x])){
        return false;
      }else{

      }
    }
}
