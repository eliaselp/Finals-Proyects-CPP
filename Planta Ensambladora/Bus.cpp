#include "Bus.h"
#include <iostream>
using namespace std;
Bus::Bus(float VelocidadMax, int CantPuertas,Fuerza* motor):Carro(0,VelocidadMax,motor)
{
    this->CantPuertas=CantPuertas;
    this->motor=motor;
    int c=(this->motor->getCaballosFuerza()/10);
    this->setPlazas(c);
    this->getPrecioVenta();
}

Bus::~Bus()
{
    //dtor
}
//************************************************************************
//************************************************************************
int Bus::getCantPuertas(){
    return this->CantPuertas;
}
//************************************************************************
//************************************************************************
void Bus::setMotor(Fuerza* motor){
    this->motor=motor;
}
//************************************************************************
//************************************************************************
void Bus::FichaTecnica(){
    this->motor->FichaTecnica();
    cout<<"[+] Plazas: "<<this->getPlazas();
    cout<<"[+] Velocidad Maxima del Vehiculo: "<<this->getVelocidadMax();
    cout<<"[+] Cantidad de Puertas: "<<this->CantPuertas;
    cout<<"[+] Precio de Venta: "<<this->PrecioVenta<<endl;
}
void Bus::setPrecioVenta(){
    this->PrecioVenta=((this->CantPuertas*1.5)+this->motor->Costo())*3;
}
