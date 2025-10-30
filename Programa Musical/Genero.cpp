#include "Genero.h"
#include <iostream>
using namespace std;
Genero::Genero(int Duracion,string Autor,int Anio,int Votos,int CantDiscos)
{
    this->Duracion=Duracion;
    this->Autor=Autor;
    this->Anio=Anio;
    this->Votos=Votos;
    this->CantDiscos=CantDiscos;
}

Genero::~Genero()
{
    //dtor
}


/*****************************************************************************************************/
/******************  METODOS GETERS    ***********************************************************/
/********************************************************************************************************/

int Genero::getDuracion(){
    return this->Duracion;
}
string Genero::getAutor(){
    return this->Autor;
}
int Genero::getAnio(){
    return this->Anio;
}
int Genero::getVotos(){
    return this->Votos;
}
int Genero::getCantDiscos(){
    return this->CantDiscos;
}
float Genero::getLevel_Accepted(){
    return this->Level_Accepted;
}
float Genero::getCostoProduccion(){
    return this->CostoProduccion;
}


/*****************************************************************************************************/
/******************  METODOS SETERS    ***********************************************************/
/********************************************************************************************************/
void Genero::setDuracion(int Duracion){
    this->Duracion=Duracion;
    return;
}
void Genero::setAutor(string Autor){
    this->Autor=Autor;
    return;
}
void Genero::setAnio(int Anio){
    this->Anio=Anio;
    return;
}
void Genero::setVotos(int Votos){
    this->Votos=Votos;
    return;
}
void Genero::setCantDiscos(int CantDiscos){
    this->CantDiscos=CantDiscos;
    return;
}


