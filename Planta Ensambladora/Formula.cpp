#include "Formula.h"
#include <iostream>
using namespace std;
Formula::Formula(float VelocidadMax,Alta* motor,float PesoCarroceria):Carro(1,VelocidadMax,motor)
{
    this->motor=motor;
    this->PesoCarroceria=PesoCarroceria;
    this->setPrecioVenta();
}

Formula::~Formula()
{
    //dtor
}

//************************************************************************
//************************************************************************
float Formula::getPesoCarroceria(){
    return this->PesoCarroceria;
}

//************************************************************************
//************************************************************************
void Formula::setPesoCarroceria(float PesoCarroceria){
    this->PesoCarroceria=PesoCarroceria;
    return;
}
void Formula::setMotor(Alta* motor){
    this->motor=motor;
    return;
}
//************************************************************************
//************************************************************************
void Formula::setPrecioVenta(){
    this->PrecioVenta=(1/this->PesoCarroceria)+(this->motor->Costo());
}

void Formula::FichaTecnica(){
    this->motor->FichaTecnica();
    cout<<"[+] Plazas: "<<this->getPlazas()<<endl;
    cout<<"[+] Velocidad Maxima: "<<this->getVelocidadMax()<<endl;
    cout<<"[+] Peso de Carroceria: "<<this->getPesoCarroceria();
    cout<<"[+] Precio de Venta: "<<this->PrecioVenta<<endl;
    return;
}
