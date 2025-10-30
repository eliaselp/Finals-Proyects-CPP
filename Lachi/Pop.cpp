#include "Pop.h"
#include <iostream>
using namespace std;
Pop::Pop(float Duracion, string Autor, int Anio, int Votos, int CantDiscos,bool AcompMus):Cancion(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->AcompMus=AcompMus;
    this->setNivelAceptacion();
    this->setCostoProduccion();
}

Pop::~Pop()
{
    //dtor
}





/********************************************************************/
/***********METODOS GETERS**********************/
/*******************************************************/
bool Pop::getAcompMus(){
    return this->AcompMus;
}






/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void Pop::setNivelAceptacion(){
    this->NivelAceptacion=((25*this->getVotos())/100);
    return;
}

void Pop::setCostoProduccion(){
    this->Costo=this->getCantDiscos();
    if(this->AcompMus==true){
        this->Costo+=((25*this->Costo)/100);
    }
    return;
}
