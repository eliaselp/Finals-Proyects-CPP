#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario(string Nombre, string Direccion, string Telefono)
{
    this->Nombre=Nombre;
    this->Direccion=Direccion;
    this->Telefono=Telefono;

    this->Consumo=new float[12];
    for(int i=0;i<12;i++){
        this->Consumo[i]=0;
    }
    this->NotPay=0;
    this->Pay=false;
    this->Minutos=0;
    this->Categoria=1;
}

Usuario::~Usuario()
{
    //dtor
}



/***************************************************************************/
/******************  METODOS GETERS   ******************************/
/***************************************************************************/
float Usuario::getConsumo(int n){
    return this->Consumo[n-1];
}
int Usuario::getNotPay(){
    return this->NotPay;
}
bool Usuario::getPay(){
    return this->Pay;
}
int Usuario::getMinutos(){
    return this->Minutos;
}
string Usuario::getNombre(){
    return this->Nombre;
}
string Usuario::getDireccion(){
    return this->Direccion;
}
string Usuario::getTelefono(){
    return this->Telefono;
}
int Usuario::getCategoria(){
    return this->Categoria;
}
float Usuario::getDeuda(int Mes){
    Mes--;
    float Suma=0;
    if(this->Pay==false){
        for(int i=Mes;i>=Mes-this->NotPay;i--){
            Suma+=this->Consumo[i];
        }
        if(this->Categoria==3)Suma+=((10*Suma)/100);
    }
    return Suma;
}

void Usuario::fConsumo(int M,float C){
    this->Consumo[M]=C;
    return;
}


/***************************************************************************/
/******************  METODOS SETERS   ******************************/
/***************************************************************************/
void Usuario::setMinutos(int Minutos){
    this->Minutos=Minutos;
    return;
}
void Usuario::setPay(bool Pay){
    this->Pay=Pay;
    return;
}
void Usuario::setNotPay(int n){
    this->NotPay=n;
    return;
}
void Usuario::setCategoria(int n){
    this->Categoria=n;
    return;
}






/***************************************************************************/
/******************  METODOS VIRTUAL   ******************************/
/***************************************************************************/
void Usuario::DataUsuario(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    cout<<"[#] Direccion: "<<this->Direccion<<endl;
    cout<<"[#] Telefono: "<<this->Telefono<<endl;
    return;
};
