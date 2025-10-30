#include "Empresa.h"
#include <iostream>
using namespace std;
Empresa::Empresa(int MaxExcursiones,int MaxGuias, int MaxVehiculos)
{
    this->MaxExcursiones=MaxExcursiones;
    this->CantExcursiones=0;
    this->ListaExcursiones=new Excursion*[MaxExcursiones];
    this->MaxGuias=MaxGuias;
    this->CantGuias=0;
    this->ListaGuias=new Guia*[MaxGuias];
    this->CantVehiculos=0;
    this->MaxVehiculos=MaxVehiculos;
    this->ListaVehiculos=new Vehiculo*[MaxVehiculos];
    this->Ganancia=0;
    this->totalTuristas=0;
}

Empresa::~Empresa()
{
    //dtor
}


Vehiculo* Empresa::getListaVehiculos(int n){
    return this->ListaVehiculos[n-1];
}
int Empresa::getCantVehiculos(){
    return this->CantVehiculos;
}
int Empresa::getMaxVehiculos(){
    return this->MaxVehiculos;
}
Guia* Empresa::getListaGuias(int n){
    return this->ListaGuias[n-1];
}
int Empresa::getCantGuias(){
    return this->CantGuias;
}
int Empresa::getMaxGuias(){
    return this->MaxGuias;
}
Excursion* Empresa::getListaExcursiones(int n){
    return this->ListaExcursiones[n-1];
}
int Empresa::getCantExcursiones(){
    return this->CantExcursiones;
}
int Empresa::getMaxExcursiones(){
    return this->MaxExcursiones;
}

int Empresa::getTotalTuristas(){
    int f=this->totalTuristas;
    for(int i=0;i<this->CantExcursiones;i++){
        f+=this->ListaExcursiones[i]->getCantRealP();
    }
    return f;
}
float Empresa::getGanancia(){
    float f=this->Ganancia;
    for(int i=0;i<this->CantExcursiones;i++){
        f+=this->ListaExcursiones[i]->PrecioExc();
    }
    return f;
}
/************/

int Empresa::CantExcGuagua(){
    int cont=0;
    if(this->CantExcursiones>0){
        for(int i=0;i<this->CantExcursiones;i++){
            if(dynamic_cast<Guagua*>(this->ListaExcursiones[i]->getTrans()))cont++;
        }
    }
    return cont;
}


/************/
void Empresa::AggVehiculo(Vehiculo* Trans){
    this->ListaVehiculos[this->CantVehiculos]=Trans;
    this->CantVehiculos++;
    return;
}
void Empresa::AggGuia(Guia* guia){
    this->ListaGuias[this->CantGuias]=guia;
    this->CantGuias++;
    return;
}
void Empresa::AggExcursion(Excursion* Paseo){
    this->ListaExcursiones[this->CantExcursiones]=Paseo;
    this->CantExcursiones++;
    return;
}
void Empresa::EliminarVehiculo(int n){
    delete this->ListaVehiculos[n-1];
    this->CantVehiculos--;
    for(int i=n-1;i<this->CantVehiculos;i++){
        this->ListaVehiculos[i]=this->ListaVehiculos[i+1];
    }
    this->ListaExcursiones[this->CantVehiculos]=NULL;
    return;
}
void Empresa::EliminarGuia(int n){
    delete this->ListaGuias[n-1];
    this->CantGuias--;
    for(int i=n-1;i<this->CantGuias;i++){
        this->ListaGuias[i]=this->ListaGuias[i+1];
    }
    this->ListaGuias[this->CantGuias]=NULL;
    return;
}
void Empresa::EliminarExcursion(int n){
    this->Ganancia+=this->ListaExcursiones[n-1]->PrecioExc();
    this->totalTuristas+=this->ListaExcursiones[n-1]->getCantRealP();
    delete this->ListaExcursiones[n-1];
    this->CantExcursiones--;
    for(int i=n-1;i<this->CantExcursiones;i++){
        this->ListaExcursiones[i]=this->ListaExcursiones[i+1];
    }
    this->ListaExcursiones[this->CantExcursiones]=NULL;
    return;
}

void Empresa::Recaudacion(){
    int pos[this->CantExcursiones];
    for(int i=0;i<this->CantExcursiones;i++){
        pos[i]=i;
    }
    for(int i=0;i<this->CantExcursiones;i++){
        for(int j=0;j<this->CantExcursiones-1;j++){
            if(this->ListaExcursiones[j]->PrecioExc()>this->ListaExcursiones[j+1]->PrecioExc()){
                int aux=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=aux;
            }
        }
    }
    for(int i=0;i<this->CantExcursiones;i++){
        cout<<"[#] Numero Excurcion: "<<this->ListaExcursiones[pos[i]]->getNumeroExc()<<endl;
        cout<<"[#] Nombre de Proyecto: "<<this->ListaExcursiones[pos[i]]->getNombreExc()<<endl;
        cout<<"[#] Recaudacion: "<<this->ListaExcursiones[pos[i]]->PrecioExc()<<endl;
        cout<<"***********************************"<<endl<<endl;
    }
    return;
}

void Empresa::DataVehiculos(){
    for(int i=0;i<this->CantVehiculos;i++){
        cout<<"<<<< INDEXADO >>>> ==> "<<i+1<<endl;
        this->ListaVehiculos[i]->Imprimir();
        cout<<"------------------------------"<<endl;
    }
    return;
}
void Empresa::DataGuias(){
    for(int i=0;i<this->CantGuias;i++){
        cout<<"<<<< INDEXADO >>>> ==> "<<i+1<<endl;
        this->ListaGuias[i]->InfoPersonal();
        cout<<"------------------------------"<<endl;
    }
    return;
}

void Empresa::DataExcursiones(){
    for(int i=0;i<this->CantExcursiones;i++){
        cout<<"<<<< INDEXADO >>>> ==> "<<i+1<<endl;
        this->ListaExcursiones[i]->INFO();
        cout<<"------------------------------"<<endl;
    }
    return;
}


void Empresa::DataExcGuagua(){
    if(this->CantExcGuagua()>0){
        for(int i=0;i<this->CantExcursiones;i++){
            if(dynamic_cast<Guagua*>(this->ListaExcursiones[i]->getTrans())){
                this->ListaExcursiones[i]->INFO();
                cout<<"------------------------------"<<endl;
            }
        }
    }
    return;
}

void Empresa::BuscarExcurcion(string Nombre){
    for(int i=0;i<this->CantExcursiones;i++){
        if(this->ListaExcursiones[i]->getNombreExc()==Nombre){
            this->ListaExcursiones[i]->INFO();
        }
    }
    return;
}


int Empresa::CantExcCondicion(){
    int Cant=0;
    for(int i=0;i<this->CantExcursiones;i++){
        if(this->ListaExcursiones[i]->getPrecioxP()<15&&this->ListaExcursiones[i]->getTrans()->getCantAsientos()>50){
            Cant++;
        }
    }
    return Cant;
}


int Empresa::GuiaCantExc(string Nombre){
    bool existe=false;
    for(int i=0;i<this->CantGuias;i++){
        if(this->ListaGuias[i]->getNombre()==Nombre){
            return this->ListaGuias[i]->CantExc;
            existe=true;
        }
    }
    if(existe==false){
        for(int i=0;i<this->CantExcursiones;i++){
            if(this->ListaExcursiones[i]->getguia()!=NULL){
                if(this->ListaExcursiones[i]->getguia()->getNombre()==Nombre)return this->ListaExcursiones[i]->getguia()->CantExc;
            }
        }
    }
    return -1;
}


void Empresa::OrdenExcDir(){
    if(this->CantExcursiones>0){
        int pos[this->CantExcursiones];
        int Cant=0;
        for(int i=0;i<this->CantExcursiones;i++){
            if(this->ListaExcursiones[i]->getguia()!=NULL){
                pos[Cant]=i;
                Cant++;
            }
        }
        for(int i=0;i<Cant;i++){
            for(int j=0;j<Cant-1;j++){
                if(this->ListaExcursiones[j]->PrecioExc()>this->ListaExcursiones[j+1]->PrecioExc()){
                    int aux=pos[j];
                    pos[j]=pos[j+1];
                    pos[j+1]=aux;
                }
            }
        }
        for(int i=0;i<Cant;i++){
            this->ListaExcursiones[pos[i]]->INFO();
            cout<<"----------------------"<<endl;
        }
    }
    return;
}
