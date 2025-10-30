#include "Sport.h"
#include <iostream>
using namespace std;
Sport::Sport(int Plazas, float VelocidadMax,int CantVelocidades, bool CambioUniversal, Trabajo* motor):Carro(Plazas,VelocidadMax,motor)
{
    this->CantVelocidades=CantVelocidades;
    this->CambioUniversal=CambioUniversal;
    this->motor=motor;
    this->setPrecioVenta();
}

Sport::~Sport()
{
    //dtor
}
//************************************************************************
//************************************************************************
int Sport::getCantVelocidades(){
    return this->CantVelocidades;
}
bool Sport::getCambioUniversal(){
    return this->CambioUniversal;
}
//************************************************************************
//************************************************************************
void Sport::setCantVelocidades(int CantVelocidades){
    this->CantVelocidades=CantVelocidades;
    return;
}
void Sport::setCambioUniversal(bool CambioUniversal){
    this->CambioUniversal=CambioUniversal;
    return;
}
void Sport::setMotor(Trabajo* motor){
    this->motor=motor;
}
//************************************************************************
//************************************************************************
void Sport::setPrecioVenta(){
    this->PrecioVenta=(this->CantVelocidades*2)+this->motor->Costo();
    if(this->CambioUniversal==true){
        this->PrecioVenta+=1000;
    }
    return;
}
void Sport::FichaTecnica(){
    this->motor->FichaTecnica();
    cout<<"[+] Plazas: "<<this->getPlazas()<<endl;
    cout<<"[+] Velocidad Maxima del Vehiculo: "<<this->getVelocidadMax()<<endl;
    cout<<"[+] Cantidad de Velocidades: "<<this->getCantVelocidades()<<endl;
    cout<<"[+] Cambio Universal: ";
    if(this->CambioUniversal==true)cout<<"Si"<<endl;
    else cout<<"No"<<endl;
    cout<<"[+] Precio de Venta: "<<this->PrecioVenta<<endl;
}
