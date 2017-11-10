#include <iostream>
#include <string>
#include "pieza.h"
#include "marine.h"
#include "general.h"

using namespace std;

//==== Prototipo ====//
pieza*** crearMatriz();
void printMatriz(pieza***);
bool validarPos(int*,int*,pieza***);
int terminarJuego(pieza***);

int main(){
  do{
      string player1, player2;
      bool turn=true;
      int x, y;
      pieza*** tablero = crearMatriz();
      cout<<" === Examen_1 ==="<<endl;
      cout<<"Ingrese nombre: ";
      cin>>player1;
      cout<<"Ingrese nombre: ";
      cin>>player2;
      //****Inicio de la simulación*****//
      do{
          if(turn){ //Jugador#1
            cout<<"== Turno jugador "<<player1<<" =="<<endl;
            cout<<"-Ingrese posicion x: ";
            cin>>x;
            cout<<"-Ingrese posicion y: ";
            cin>>y;
            while(validarPos(&x,&y,tablero)){
              cout<<"Ingrese de nuevo x: ";
              cin>>x;
              cout<<"Ingrese de nuevo y: ";
              cin>>y;
            }
            cout<<"-Ingrese nueva posicion de la ficha x :";
            cin>>x;
            cout<<"-Ingrese nueva posicion de la ficha y :";
            cin>>y;
            //ficha = getficha();
          }else{ //Jugador#2
            cout<<"== Turno jugador "<<player2<<" =="<<endl;
            cout<<"-Ingrese posicion x: ";
            cin>>x;
            cout<<"-Ingrese posicion y: ";
            cin>>y;
            while(validarPos(&x,&y,tablero)){
              cout<<"Ingrese de nuevo x: ";
              cin>>x;
              cout<<"Ingrese de nuevo y: ";
              cin>>y;
            }
            cout<<"-Ingrese nueva posicion de la ficha x :";
            cin>>x;
            cout<<"-Ingrese nueva posicion de la ficha y :";
            cin>>y;
          }
      }while(terminarJuego(tablero));
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
        ficha = matriz[i][j];
        if(ficha->getColor()==0){
          contB++;
        }
        if(ficha->getColor()==1){
          contN++;
        }
      }
    }
    if(contN==0){
      return 0; //Return 0, significa que el segundo player ha ganado
    }else if(contB==0){
      return 1; //Return 1, significa que el primer player gano
    }else{
      return 2; //EL juego continua
    }
}

bool validarPos(int*x,int*y,pieza***matriz){
    if(*x<0||*x>8||*y<0||*y>8){
        return false;
    }else{
      if(matriz[*y][*x]==NULL){
        return false;
      }else{
        return true;
      }
    }
}

//====Matriz=====
void printMatriz(pieza***matriz){
    pieza* p;
    cout<<"=============================="<<endl;
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
        p = matriz[i][j];
        if(p->getColor()==0){
          cout<<"|"<<'o'<<"|";
        }else{
          cout<<"|"<<'*'<<"|";
        }
      }
      cout<<endl;
    }
    cout<<"==============================="<<endl;
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
    return matriz;
}
