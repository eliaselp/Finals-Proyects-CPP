#include "Rock.h"
#include <iostream>
using namespace std;
Rock::Rock(float Duracion, string Autor, int Anio, int Votos, int CantDiscos):Cancion(Duracion,Autor,Anio,Votos,CantDiscos)
{
    //ctor
    this->setNivelAceptacion();
}

Rock::~Rock()
{
    //dtor
}



/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void Rock::setNivelAceptacion(){
    this->NivelAceptacion=((15*this->getVotos())/100);
    return;
}
