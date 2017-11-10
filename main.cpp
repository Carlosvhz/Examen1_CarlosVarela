#include <iostream>
#include <string>

#include "pieza.h"
#include "marine.h"
//#include "general.h"

using namespace std;

//==== Prototipo ====//
pieza*** crearMatriz();
void printMatriz(pieza***);
int main(){
  do{
      pieza ficha;
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
            while(x<0||x>8||y<0||y>8){
              cout<<"Ingrese de nuevo x: ";
            }
            //ficha = getficha();
          }else{ //Jugador#2
            cout<<"== Turno jugador "<<player2<<" =="<<endl;
            cout<<"-Ingrese posicion x: ";
            cin>>x;
            cout<<"-Ingrese posicion y: ";
            cin>>y;
            while(x<0||x>8||y<0||y>8){
              cout<<"Ingrese de nuevo x: ";
            }
          }
      }while();
      cout<<"==========================="
        endl<<"¿Volver a intentarlo?[s]: ";
      cin>>resp;
  }while(resp=='s');
  return 0;
}

/*bool terminarJuego(pieza*** matriz){
    int contB=0, contN=0;
    for(){
      for(){

      }
    }
}*/

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
    for (int i = 0; i <8 count; i++) {
        matriz[i] = new pieza*[8];
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        matriz[i][j] = NULL;
      }
    }
    return matriz;
}
