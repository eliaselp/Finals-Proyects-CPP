#include "Cancion.h"
#include <iostream>
using namespace std;
Cancion::Cancion(float Duracion, string Autor, int Anio, int Votos, int CantDiscos)
{
    this->Duracion=Duracion;
    this->Autor=Autor;
    this->Anio=Anio;
    this->Votos=Votos;
    this->CantDiscos=CantDiscos;
    this->Costo=0;
    this->NivelAceptacion=0;
}

Cancion::~Cancion()
{
    //dtor
}


/********************************************************************/
/***********METODOS GETERS**********************/
/*******************************************************/
float Cancion::getDuracion(){
    return this->Duracion;
}
string Cancion::getAutor(){
    return this->Autor;
}
int Cancion::getAnio(){
    return this->Anio;
}
int Cancion::getVotos(){
    return this->Votos;
}
int Cancion::getCantDiscos(){
    return this->CantDiscos;
}
float Cancion::getCostoProduccion(){
    return this->Costo;
}
float Cancion::getNivelAceptacion(){
    return this->NivelAceptacion;
}
