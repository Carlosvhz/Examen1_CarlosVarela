#include <iostream>
#include <string>
#include "pieza.h"
#include "marine.h"
#include "general.h"

using namespace std;

//==== Prototipo ====//
pieza*** crearMatriz();
void printMatriz(pieza***);
bool validarPos(string,pieza***,bool);
int terminarJuego(pieza***);
int posiciones(char);
pieza* tomarficha(string,pieza***);

int main(){
  do{
      string player1, player2, inicial;
      string posterminal;
      int x,y;
      bool turn=true;
      pieza* ficha;
      pieza*** tablero = crearMatriz();
      cout<<" === Examen_1 ==="<<endl;
      cout<<"Ingrese nombre: ";
      cin>>player1;
      cout<<"Ingrese nombre: ";
      cin>>player2;
      //****Inicio de la simulación*****//
      do{
        printMatriz(tablero);
          if(turn==true){ //Jugador#1
            cout<<"== Turno jugador "<<player1<<" =="<<endl;
            cout<<"-Ingrese posicion inicial: ";
            cin>>inicial;
            while(inicial.length()!=2||validarPos(inicial,tablero,turn)){
              cout<<"Ingrese de nuevo: ";
              cin>>inicial;
            }
            ficha = tomarficha(inicial,tablero);
            //tablero[ficha->getPosy()][ficha->getPosx()] = NULL;
            cout<<"-Ingrese posicion final: ";
            cin>>posterminal;
            x = posiciones(posterminal[0]);
            y = posiciones(posterminal[1]);
            while(ficha->validarMov(x,y,tablero,turn)){
              cout<<"Ingrese de nuevo: ";
              cin>>posterminal;
            }
            //-----
            turn =false;
          }else if(turn==false){ //Jugador#2
            cout<<"== Turno jugador "<<player2<<" =="<<endl;
            cout<<"-Ingrese posicion inicial: ";
            cin>>inicial;
            while(inicial.length()!=2||validarPos(inicial,tablero,turn)){
              cout<<"Ingrese de nuevo: ";
              cin>>inicial;
            }
            ficha = tomarficha(inicial,tablero);
            //tablero[ficha->getPosy()][ficha->getPosx()] = NULL;
            cout<<"-Ingrese posicion final:";
            cin>>posterminal;
            x = posiciones(posterminal[0]);
            y = posiciones(posterminal[1]);
            while(ficha->validarMov(x,y,tablero,turn)){
              cout<<"Ingrese de nuevo: ";
              cin>>posterminal;
            }

            //--------
            turn=true;
          }
      }while(/*terminarJuego(tablero)==2*/true);
      cout<<"==========================="<<
        endl<<"¿Volver a intentarlo?[s]: ";

  }while(true);
  return 0;
}

int terminarJuego(pieza*** matriz){
    int contB=0, contN=0;  //Contador de fichas negras y blancas
    pieza *ficha;
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
        if(matriz[i][j]!=NULL){
          ficha = matriz[i][j];
          if(ficha->getColor()==0){
            contB++;
          }
          if(ficha->getColor()==1){
            contN++;
          }
        }

      }
    }
    delete ficha;
    if(contN==0){
      return 0; //Return 0, significa que el segundo player ha ganado
    }else if(contB==0){
      return 1; //Return 1, significa que el primer player gano
    }else{
      return 2; //EL juego continua
    }
}

int posiciones(char posicion){
    switch(posicion){
      case 'a':{
        return 0;
      }
        break;
      case 'b':{
        return 1;
      }
        break;
      case 'c':{
        return 2;
      }
        break;
      case 'd':{
        return 3;
      }
        break;
      case 'e':{
        return 4;
      }
        break;
      case 'f':{
        return 5;
      }
        break;
      case 'g':{
        return 6;
      }
        break;
      case 'h':{
        return 7;
      }
        break;
      default:{
        return posicion-48;
      }
    }
}

bool validarPos(string pos,pieza***matriz, bool turno){
    pieza* ficha;
    int x = posiciones(pos[0]);
    int y = (posiciones(pos[1])-8)*-1 ;
    if(x<0||x>8||y<0||y>8){
        return true;
    }
    if(matriz[y][x]==NULL){
      return true;
    }
    if(turno){ //Jugador 1
      if(dynamic_cast<pieza*>(matriz[y][x])){ //Por si hay una ficha
        ficha = matriz[y][x];
        if(ficha->getColor()==0){ //Si es una ficha blanca
          return false;
        }else{
          return true;
        }
      }
    }else{ //Jugador 2
      if(dynamic_cast<pieza*>(matriz[y][x])){
        ficha = matriz[y][x];
        if(ficha->getColor()==1){ //Si es una ficha negra
          return false;
        }else{
          return true;
        }
      }
    }
}

pieza* tomarficha(string posicion,  pieza***matriz){
    pieza* f;
    int x = posiciones(posicion[0]);
    int y = posiciones(posicion[1]);
    f = matriz[y][x];
    return f;
}

//====Matriz=====
void printMatriz(pieza***matriz){
    pieza* p;
    cout<<"==========================="<<endl;
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
        if(matriz[i][j]==NULL){
          cout<<"| |";
        }else{
          p = matriz[i][j];
          if(p->getColor()==0){
            cout<<"|"<<'o'<<"|";
          }else{
            cout<<"|"<<'*'<<"|";
          }
        }
      }
      cout<<endl;
    }
    cout<<"============================"<<endl;
}

pieza*** crearMatriz(){
    pieza*** matriz = new pieza**[8];
    for (int i = 0; i <8 ; i++) {
        matriz[i] = new pieza*[8];
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        matriz[i][j] = NULL;
      }
    }
    matriz[0][1] = new marine(1,0,1);
    matriz[0][3] = new marine(3,0,1);
    matriz[0][5] = new marine(5,0,1);
    matriz[0][7] = new marine(7,0,1);
    matriz[1][0] = new marine(0,1,1);
    matriz[1][2] = new marine(2,1,1);
    matriz[1][4] = new marine(4,1,1);
    matriz[1][6] = new marine(6,1,1);
    matriz[2][1] = new marine(1,2,1);
    matriz[2][3] = new marine(3,2,1);
    matriz[2][5] = new marine(5,2,1);
    matriz[2][7] = new marine(7,2,1);
    matriz[5][0] = new marine(0,5,0);
    matriz[5][2] = new marine(2,5,0);
    matriz[5][4] = new marine(4,5,0);
    matriz[5][6] = new marine(6,5,0);
    matriz[6][1] = new marine(1,6,0);
    matriz[6][3] = new marine(3,6,0);
    matriz[6][5] = new marine(5,6,0);
    matriz[6][7] = new marine(7,6,0);
    matriz[7][0] = new marine(0,7,0);
    matriz[7][2] = new marine(2,7,0);
    matriz[7][4] = new marine(4,7,0);
    matriz[7][6] = new marine(6,7,0);
    return matriz;
}
