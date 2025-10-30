#include "Planta.h"
#include <bits/stdc++.h>
using namespace std;
Planta::Planta()
{
    this->AlmacenCarros=NULL;
    this->AlmacenMotores=NULL;
    this->Ganancia=0;
    this->CantCarros=0;
    this->CantMotores=0;
}

Planta::~Planta()
{
    //dtor
}

//*********************************************************************
//*********************************************************************
void Planta::AggCarro(Carro* nuevo){
    if(this->AlmacenCarros==NULL){
        nuevo->siguiente=NULL;
    }else{
        nuevo->siguiente=this->AlmacenCarros;
    }
    this->AlmacenCarros=nuevo;
    this->CantCarros++;
}
//*********************************************************************
//*********************************************************************
void Planta::AggMotor(Motor* nuevo){
    if(this->AlmacenMotores==NULL){
        nuevo->siguiente=NULL;
    }else{
        nuevo->siguiente=this->AlmacenMotores;
    }
    this->AlmacenMotores=nuevo;
    this->CantMotores++;
    cout<<"[+] El MOTOR ha sido Agregado."<<endl;
}
//*********************************************************************
//*********************************************************************
void Planta::EliminarMotor(int n){
    if(n<=this->CantMotores){
        Motor* aux=this->AlmacenMotores;
        Motor*aux2=NULL;
        for(int i=2;i<=n;i++){
            aux2=aux;
            aux=aux->siguiente;
        }
        if(aux2==NULL){
            this->AlmacenMotores=aux->siguiente;
        }else{
            aux2->siguiente=aux->siguiente;
        }
        this->CantMotores--;
    }
    return;
}
//*********************************************************************
//*********************************************************************
void Planta::VenderCarro(int n){
    if(n<=this->CantCarros){
        Carro* aux=this->AlmacenCarros;
        Carro*aux2=NULL;
        for(int i=2;i<=n;i++){
            aux2=aux;
            aux=aux->siguiente;
        }
        this->Ganancia+=aux->getPrecioVenta();
        if(aux2==NULL){
            this->AlmacenCarros=aux->siguiente;
        }else{
            aux2->siguiente=aux->siguiente;
        }
        delete aux;
    }
    return;
}
//*********************************************************************
//*********************************************************************
void Planta::DesmantelarCarro(int n){
    Carro* aux=this->AlmacenCarros;
    Carro*aux2=NULL;
    for(int i=2;i<=n;i++){
        aux2=aux;
        aux=aux->siguiente;
    }

    aux->motor->setCantRegreso();
    if(dynamic_cast<Trabajo*>(aux->motor)){
        aux->motor->setArtesanal();
    }
    this->AggMotor(aux->motor);
    aux->motor=NULL;

    if(aux2==NULL){
        this->AlmacenCarros=aux->siguiente;
    }else{
        aux2->siguiente=aux->siguiente;
    }
    delete aux;
    return;
}
//*********************************************************************
//*********************************************************************
int Planta::getCantCarros(){
    return this->CantCarros;
}
int Planta::getCantMotores(){
    return this->CantMotores;
}
float Planta::getGanancia(){
    return this->Ganancia;
}
Motor* Planta::getMotor(int n){
    Motor* aux=this->AlmacenMotores;
    for(int i=1;i<n;i++){
        aux=aux->siguiente;
    }
    return aux;
}

void Planta::DataFormula(){
    int i=1;
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Formula*>(aux)){
            cout<<"Numero de VEHICULO: "<<i;
            aux->FichaTecnica();
            cout<<"-------------------------------"<<endl;
        }
        i++;
        aux=aux->siguiente;
    }
    return;
}
void Planta::DataLujo(){
    int i=1;
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Lujo*>(aux)){
            cout<<"Numero de VEHICULO: "<<i;
            aux->FichaTecnica();
        }
        cout<<"-------------------------------"<<endl;
        i++;
        aux=aux->siguiente;
    }
    return;
}
void Planta::DataSport(){
    int i=1;
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Sport*>(aux)){
            cout<<"Numero de VEHICULO: "<<i;
            aux->FichaTecnica();
        }
        cout<<"-------------------------------"<<endl;
        i++;
        aux=aux->siguiente;
    }
    return;
}
void Planta::DataBus(){
    int i=1;
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Bus*>(aux)){
            cout<<"Numero de VEHICULO: "<<i;
            aux->FichaTecnica();
        }
        cout<<"-------------------------------"<<endl;
        i++;
        aux=aux->siguiente;
    }
    return;
}
//*********************************************************************
//*********************************************************************
int Planta::CantTrabajo(){
    int cant=0;
    Motor*aux=this->AlmacenMotores;
    while(aux!=NULL){
        if(dynamic_cast<Trabajo*>(aux))cant++;
    }
    return cant;
}

int Planta::CantFuerza(){
    int cant=0;
    Motor*aux=this->AlmacenMotores;
    while(aux!=NULL){
        if(dynamic_cast<Fuerza*>(aux))cant++;
    }
    return cant;
}

int Planta::CantAlta(){
    int cant=0;
    Motor*aux=this->AlmacenMotores;
    while(aux!=NULL){
        if(dynamic_cast<Alta*>(aux))cant++;
    }
    return cant;
}
int Planta::CantTrabajoArtesanal(){
    int cant=0;
    Motor* aux=this->AlmacenMotores;
    while(aux!=NULL){
        if(dynamic_cast<Trabajo*>(aux)){
            if(aux->getArtesanal()==true){
                cant++;
            }
        }
    }
    return cant;
}

void Planta::getDataTrabajoArtesanal(){
    Motor* aux=this->AlmacenMotores;
    int i=1;
    while(aux!=NULL){
        if(dynamic_cast<Trabajo*>(aux)){
            if(aux->getArtesanal()==true){
                cout<<"[#] Numero de MOTOR: "<<i;
                aux->FichaTecnica();
            }
        }
    }
    return;
}
//*********************************************************************
//*********************************************************************
int Planta::CantBus(){
    int cant=0;
    Carro*aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Bus*>(aux))cant++;
    }
    return cant;
}
int Planta::CantFormula(){
    int cant=0;
    Carro*aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Formula*>(aux))cant++;
    }
    return cant;
}
int Planta::CantLujo(){
    int cant=0;
    Carro*aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Lujo*>(aux))cant++;
    }
    return cant;
}
int Planta::CantSport(){
    int cant=0;
    Carro*aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Sport*>(aux))cant++;
    }
    return cant;
}
//*********************************************************************
//*********************************************************************
void Planta::MotoresFuerza(){
    cout<<"************************************************************\n\n\n";
    cout<<"[#] Motores de Fuerza: \n";
    Motor*aux=this->AlmacenMotores;
    int i=1;
    while(aux!=NULL){
        if(dynamic_cast<Fuerza*>(aux)){
            cout<<"[#] MOTOR NUMERO: ["<<i<<"]: \n";
            aux->FichaTecnica();
        }
        i++;
        aux=aux->siguiente;
        cout<<"\n-------------\n";
    }
    return;
}
void Planta::MotoresAlta(){
    cout<<"*************************************************************\n\n";
    cout<<"[#] Motores de Alta: \n";
    Motor*aux=this->AlmacenMotores;
    int i=1;
    while(aux!=NULL){
        if(dynamic_cast<Alta*>(aux)){
            cout<<"[#] MOTOR NUMERO: ["<<i<<"]: "<<endl;
            aux->FichaTecnica();
        }
        i++;
        aux=aux->siguiente;
        cout<<"\n-------------\n";
    }
}
void Planta::MotoresTrabajo(){
    cout<<"*************************************************************\n\n";
    cout<<"[#] Motores de Trabajo: \n";
    int i=1;
    Motor* aux=this->AlmacenMotores;
    while(aux!=NULL){
        if(dynamic_cast<Trabajo*>(aux)){
            cout<<"[#] MOTOR NUMERO: ["<<i<<"]: "<<endl;
            aux->FichaTecnica();
        }
        i++;
        aux=aux->siguiente;
        cout<<"\n-------------\n";
    }
}
void Planta::DataMotores(){
    MotoresFuerza();
    MotoresAlta();
    MotoresTrabajo();
    return;
}
//*********************************************************************
//*********************************************************************

void Planta::CarrosMaxVelocidad(){
    Carro*aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(aux->getVelocidadMax()>150)aux->FichaTecnica();
        cout<<"\n************************************************************************\n\n";
        aux=aux->siguiente;
    }
    return;
}
//*********************************************************************
//*********************************************************************
void Planta::BusMayor(){
    int mayor=0;
    Carro* bus;
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(dynamic_cast<Bus*>(aux)){
            if(aux->getCantPuertas()>mayor){
                mayor=aux->getCantPuertas();
                bus=aux;
            }
        }
        aux=aux->siguiente;
    }
    bus->FichaTecnica();
    return;
}
//*********************************************************************
//*********************************************************************
void Planta::DataAlmacenCarros(){
    Carro* aux=this->AlmacenCarros;
    int i=1;
    while(aux!=NULL){
        cout<<"[#] Numero de Vehiculo: "<<i;
        aux->FichaTecnica();
        cout<<"\n**********************************************************************\n\n";
        i++;
        aux=aux->siguiente;
    }
    return;
}
//*********************************************************************
//*********************************************************************
void Planta::CarrosMotoresReensablados(){
    Carro* aux=this->AlmacenCarros;
    while(aux!=NULL){
        if(aux->motor->getCantRegreso()>0){
            aux->FichaTecnica();
            cout<<"[+] Descuento motor Reensamblado: "<<aux->motor->getCantRegreso()*100;
            cout<<"\n**********************************************************************\n\n";
        }
        aux=aux->siguiente;
    }
}
//*********************************************************************
//*********************************************************************
float Planta::CumplimientoMotores(int cant){
    float c=(this->CantMotores*100)/cant;
    return c;
}

float Planta::CumplimientoCarros(int cant){
    float c=(this->CantCarros*100)/cant;
    return c;
}
//*********************************************************************
//*********************************************************************
