#include "general.h"

general::general(int x, int y, int c):pieza(x,y,c){

}

general::~general(){
}

bool general::validarMov(int x, int y, pieza***matriz){
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
