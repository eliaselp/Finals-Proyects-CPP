#include "Carro.h"
#include <iostream>
using namespace std;
Carro::Carro(int Plazas, float VelocidadMax,Motor* motor)
{
    this->Plazas=Plazas;
    this->VelocidadMax=VelocidadMax;
    this->PrecioVenta=0;
    this->siguiente=NULL;
}

Carro::~Carro()
{
    //dtor
}

int Carro::getPlazas(){
    return this->Plazas;
}

float Carro::getVelocidadMax(){
    return this->VelocidadMax;
}

float Carro::getPrecioVenta(){
    return this->PrecioVenta;
}
//************************************************************************
//************************************************************************
void Carro::setPlazas(int Plazas){
    this->Plazas=Plazas;
}
void Carro::setVelocidadMax(float VelocidadMax){
    this->VelocidadMax=VelocidadMax;
}
//************************************************************************
//************************************************************************
