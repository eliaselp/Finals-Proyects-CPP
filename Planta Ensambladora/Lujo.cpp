#include "Lujo.h"

Lujo::Lujo(int Plazas, float VelocidadMax, float CostoTapiceria, Trabajo* motor):Carro(Plazas,VelocidadMax,motor)
{
    this->CostoTapiceria=CostoTapiceria;
    this->motor=motor;

}

Lujo::~Lujo()
{
    //dtor
}
//************************************************************************
//************************************************************************
float Lujo::getCostoTapiceria(){
    return this->CostoTapiceria;
}

//************************************************************************
//************************************************************************
void Lujo::setCostoTapiceria(float CostoTapiceria){
    this->CostoTapiceria=CostoTapiceria;
}
void Lujo::setMotor(Trabajo* motor){
    this->motor=motor;
}

//************************************************************************
//************************************************************************
void Lujo::FichaTecnica(){
    this->motor->FichaTecnica();
    cout<<"[+] Plazas: "<<this->getPlazas()<<endl;
    cout<<"[+] Vehiculo maxima del Vehiculo: "<<this->getVelocidadMax()<<endl;
    cout<<"[+] Costo de Tapiceria: "<<this->CostoTapiceria<<endl;
    cout<<"[+] Precio de Venta: "<<this->PrecioVenta<<endl;
    return;
}

void Lujo::setPrecioVenta(){
    this->PrecioVenta=(this->CostoTapiceria+this->motor->Costo())*10;
    return;
}
