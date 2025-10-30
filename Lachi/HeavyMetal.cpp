#include "HeavyMetal.h"
#include <iostream>
using namespace std;
HeavyMetal::HeavyMetal(float Duracion, string Autor, int Anio, int Votos, int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->setCostoProduccion();
}

HeavyMetal::~HeavyMetal()
{
    //dtor
}



/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void HeavyMetal::setCostoProduccion(){
    this->Costo=this->getCantDiscos();
    this->Costo+=((30*this->Costo)/100);
    return;
}
