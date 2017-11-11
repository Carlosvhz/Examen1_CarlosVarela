#pragma once

class pieza{

  private:
    int posx;
    int posy;
    int color;  //Color = 1 (Negro) Color = 0 (Blanco)

  public:
    pieza(int,int,int);
    virtual ~pieza();
	//**Get**//
    int getPosx();
    int getPosy();
    int getColor();
    //**Set**//
    void setPosx(int);
    void setPosy(int);

    bool validarMov(int,int,pieza***,bool);
};
