#include "Cadena.h"
#include <iostream>
using namespace std;
Cadena::Cadena(int CantMaxAlmacenes)
{
    this->CantMaxAlmacenes=CantMaxAlmacenes;
    this->ListadoAlmacenes=new Almacen*[CantMaxAlmacenes];
    this->CantAlmacenes=0;
}

Cadena::~Cadena()
{
    //dtor
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
int Cadena::getCantAlmacenes(){
    return this->CantAlmacenes;
}
int Cadena::getCantMaxAlmacenes(){
    return this->CantMaxAlmacenes;
}
Almacen* Cadena::getListadoAlmacenes(int n){
    if(n>0&&n<=this->CantAlmacenes){
        return this->ListadoAlmacenes[n-1];
    }else{
        cout<<"[#] Opcion INVALIDA."<<endl;
    }
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void Cadena::AggAlmacen(Almacen* nuevo){
    if(this->CantAlmacenes<this->CantMaxAlmacenes){
        this->ListadoAlmacenes[this->CantAlmacenes]=nuevo;
        this->CantAlmacenes++;
    }else{
        cout<<"[#] No hay espacio para un nuevo Almacen: ";
    }
}
void Cadena::DataAlmacenes(){
    for(int i=0;i<this->CantAlmacenes;i++){
        cout<<"Almacen numero: "<<i+1<<endl;
        if(this->ListadoAlmacenes[i]->getCantProductos()>0){
            this->ListadoAlmacenes[i]->DataNacional();
            cout<<"\n";
            this->ListadoAlmacenes[i]->DataInternacional();
        }else{
            cout<<"[#] El Almacen no tiene Productos."<<endl;
        }
        cout<<"************************************************************************************"<<endl;
        cout<<"************************************************************************************"<<endl;
    }
    return;
}



void Cadena::ProductoMaxVendido(){
    if(this->CantAlmacenes>0){
        for(int i=0;i<this->CantAlmacenes;i++){
            cout<<"[#] Almacen "<<i+1<<": "<<endl;
            this->ListadoAlmacenes[i]->ProductoMaxVendido();
            cout<<"---------------------------------------------"<<endl;
        }
    }else{
        cout<<"[#] La cadena no tiene Almacenes."<<endl;
    }
}
void Cadena::ProductoMinVendido(){
    if(this->CantAlmacenes>0){
        for(int i=0;i<this->CantAlmacenes;i++){
            cout<<"[] Almacen "<<i+1<<": "<<endl;
            this->ListadoAlmacenes[i]->ProductoMinVendido();
            cout<<"---------------------------------------------"<<endl;
        }
    }else{
        cout<<"[#] La cadena no tiene Almacenes."<<endl;
    }
}



void Cadena::ProductosAlmacenes(){
    for(int i=0;i<this->CantAlmacenes;i++){
        cout<<"Almacen numero: "<<i+1<<endl;
        for(int j=0;j<this->ListadoAlmacenes[i]->getCantProductos();i++){
            cout<<"[+] Producto: "<<this->ListadoAlmacenes[i]->ListaProductos[j]->getNombre()<<endl;
        }
        cout<<"************************************************************************************"<<endl;
        cout<<"************************************************************************************"<<endl;
    }
    return;
}


void Cadena::AlmacenMaxGanancia(){
    float Mayor;
    for(int i=0;i<this->CantAlmacenes;i++){
        if(this->ListadoAlmacenes[i]->getGanancia()>Mayor){
            Mayor=ListadoAlmacenes[i]->getGanancia();
        }
    }
    cout<<"Almacen con mayor ganancia:\n";
    for(int i=0;i<this->CantAlmacenes;i++){
        if(this->ListadoAlmacenes[i]->getGanancia()==Mayor){
            cout<<"Almacen numero: "<<i+1<<endl;
        }
    }
    return;
}

float Cadena::GananciaNeta(){
    if(this->CantAlmacenes>0){
        float Suma=0;
        for(int i=0;i<this->CantAlmacenes;i++){
            Suma+=this->ListadoAlmacenes[i]->getGanancia();
        }
        return Suma;
    }else{
        return 0;
    }
}
