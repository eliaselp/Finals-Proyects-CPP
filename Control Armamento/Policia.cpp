#include "Policia.h"
#include <iostream>
using namespace std;
Policia::Policia(int PlantillaFuego,int PlantillaBlanca)
{
    this->PlantillaBlanca=PlantillaBlanca;
    this->PlantillaFuego=PlantillaFuego;
    this->CantBlanca=0;
    this->CantFuego=0;
    this->CantReal=0;
    this->CantMax=PlantillaBlanca+PlantillaFuego;
    this->ListaArmas=new Arma*[CantMax];
}

Policia::~Policia()
{
    //dtor
}






/***********************************************************************/
/**************   METODOS GETERS    **********************************/
/***********************************************************************/
int Policia::getPlantillaFuego(){
    return this->PlantillaFuego;
}
int Policia::getPlantillaBlanca(){
    return this->PlantillaBlanca;
}
int Policia::getCantFuego(){
    return this->CantFuego;
}
int Policia::getCantBlanca(){
    return this->CantBlanca;
}
int Policia::getCantReal(){
    return this->CantReal;
}
Arma* Policia::getListaArmas(int n){
    n--;
    return this->ListaArmas[n];
}





void Policia::AggArma(Arma* nueva){
    this->ListaArmas[this->CantReal]=nueva;
    if(dynamic_cast<Fuego*>(nueva))this->CantFuego++;
    else if(dynamic_cast<Blanca*>(nueva))this->CantBlanca++;
    this->CantReal++;
    return;
}

void Policia::EliminarArma(int n){
    if(n<=this->CantReal&&n>0){
        if(dynamic_cast<Fuego*>(this->getListaArmas(n)))this->CantFuego--;
        else if(dynamic_cast<Blanca*>(this->getListaArmas(n)))this->CantBlanca--;
        n--;
        delete this->ListaArmas[n];
        this->CantReal--;
        for(int i=n;i<this->CantReal;i++){
            this->ListaArmas[i]=this->ListaArmas[i+1];
        }
        this->ListaArmas[this->CantReal]=NULL;

    }else{
        cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
    }
    return;
}


void Policia::DataFuego(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Fuego*>(this->ListaArmas[i])){
            cout<<"<<<< INDEXADO >>>> ----> "<<i+1<<endl;
            this->ListaArmas[i]->DataArma();
            cout<<"---------------------------------------"<<endl;
        }
    }
    return;
}
void Policia::DataBlanca(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i])){
            cout<<"<<<< INDEXADO >>>> ----> "<<i+1<<endl;
            this->ListaArmas[i]->DataArma();
            cout<<"---------------------------------------"<<endl;
        }
    }
    return;
}
void Policia::DataArmas(){
    if(this->CantBlanca>0){
        cout<<"Armas Blancas"<<endl;
        this->DataBlanca();
    }
    if(this->CantFuego>0){
        cout<<"Armas Fuego"<<endl;
        this->DataFuego();
    }
}




void Policia::Completamiento(){
    cout<<"[#] Plantilla Armas de Fuego: "<<this->PlantillaFuego<<endl;
    cout<<"Cantidad Registrada: "<<this->CantFuego<<endl;
    float p=((100*this->CantFuego)/this->PlantillaFuego);
    cout<<"[#] Porcentaje de Completamiento: "<<p<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"[#] Plantilla Armas Blanca: "<<this->PlantillaBlanca<<endl;
    cout<<"Cantidad Registrada: "<<this->CantBlanca<<endl;
    p=((100*this->CantBlanca)/this->PlantillaBlanca);
    cout<<"[#] Porcentaje de Completamiento: "<<p<<endl;
    return;
}

void Policia::PerdidaTipo(){
    cout<<"[#] Perdidas Armas de Fuego: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Fuego*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="PERDIDA"){
                this->ListaArmas[i]->DataArma();
            }
        }
    }
    cout<<"------------------------------------------------"<<endl;
    cout<<"[#] Perdidas Armas de Fuego: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="PERDIDA"){
                this->ListaArmas[i]->DataArma();
            }
        }
    }
}
void Policia::ReservaTipo(){
    cout<<"[#] RESERVA Armas de Fuego: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Fuego*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="RESERVA"){
                this->ListaArmas[i]->DataArma();
            }
        }
    }
    cout<<"------------------------------------------------"<<endl;
    cout<<"[#] RESERVA Armas Blanca: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="RESERVA"){
                this->ListaArmas[i]->DataArma();
            }
        }
    }
}

void Policia::TipoMayorPerdida(){
    float PF=0,PB=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Fuego*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="PERDIDA"){
                PF++;
            }
        }
    }
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="PERDIDA"){
                PB++;
            }
        }
    }
    if(PB>PF){
        cout<<"[#] Perdida Mayor: Armas Blanca"<<endl;
    }else if(PB<PF){
        cout<<"[#] Perdida Mayor: Armas de Fuego."<<endl;
    }else{
        cout<<"[#] Perdidas Iguales."<<endl;
    }
}

void Policia::TipoMayorReserva(){
    float RF=0,RB=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Fuego*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="RESERVA"){
                RF++;
            }
        }
    }
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i])){
            if(this->ListaArmas[i]->getEstado()=="RESERVA"){
                RB++;
            }
        }
    }
    if(RB>RF){
        cout<<"[#] RESERVA Mayor: Armas Blanca"<<endl;
    }else if(RB<RF){
        cout<<"[#] RESERVA Mayor: Armas de Fuego."<<endl;
    }else{
        cout<<"[#] Perdidas Iguales."<<endl;
    }
}

void Policia::MinCompletamiento(){
    float CF=((100*this->CantFuego)/this->PlantillaFuego);
    float CB=((100*this->CantBlanca)/this->PlantillaBlanca);
    if(CB>CF){
        cout<<"[#] COMPLETAMIENTO Mayor: Armas Blanca"<<endl;
    }else if(CB<CF){
        cout<<"[#] COMPLETAMIENTO Mayor: Armas de Fuego."<<endl;
    }else{
        cout<<"[#] COMPLETAMIENTO Igual."<<endl;
    }
}

bool Policia::BuscarTipoArma(string Type){
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaArmas[i]->getTipo()==Type)return true;
    }
    return false;
}

string Policia::GestionEstado(int Inventario){
    bool existe=false;
    int pos;
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaArmas[i]->getNoInventario()==Inventario){
            existe=true;
            pos = i;
        }
    }
    if(existe==true)return this->ListaArmas[pos]->getEstado();
    else return "El arma no esta Registrada.";
}


float Policia::GestionPerdida(int n){
    return this->getListaArmas(n)->getPesoPerdida();
}

float Policia::GestionUtilidad(int n){
    return this->getListaArmas(n)->getUtilidad();
}

void Policia::ArmaUSO(){
    int CF=0,CB=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Blanca*>(this->ListaArmas[i]))CB++;
        if(dynamic_cast<Fuego*>(this->ListaArmas[i]))CF++;
    }
    cout<<"[#] Cantidad de Arma de FUEGO: "<<CF<<endl;
    cout<<"[#] Cantidad de Arma Blanca: "<<CB<<endl;
    return;
}
