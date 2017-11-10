#ifndef PIEZA_H
#define PIEZA_H

class pieza{

  private:
    int posx;
    int posy;
    int color;  //Color = 1 (Negro) Color = 0 (Blanco)

  public:
    pieza(int,int);
    //**Get**//
    int getPosx();
    int getPosy();
    int getColor();
    //**Set**//
    void setPosx(int);
    void setPosy(int);

    virtual bool validarMov(int,int,pieza***);
};

#endif