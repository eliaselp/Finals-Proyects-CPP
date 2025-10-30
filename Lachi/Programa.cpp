#include "Programa.h"
#include <iostream>
using namespace std;
Programa::Programa(int CantMaxCanciones)
{
    this->CantReal=0;
    this->CantMaxCanciones=CantMaxCanciones;
    this->ListaReproduccion=new Cancion*[this->CantMaxCanciones];
}

Programa::~Programa()
{
    //dtor
}






/*************************************************************************/
/***********   METODOS APILADORES    **************************/
/*******************************************************************/
void Programa::AggCancion(Cancion* nueva){
    this->ListaReproduccion[this->CantReal]=nueva;
    this->CantReal++;
    return;
}

void Programa::EliminarCancion(int n){
    delete this->ListaReproduccion[n-1];
    for(int i=n-1;i<this->CantReal-1;i++){
        this->ListaReproduccion[i]=this->ListaReproduccion[i+1];
    }
    this->ListaReproduccion[this->CantReal]=NULL;
    this->CantReal--;
    return;
}










/*************************************************************************/
/***********   METODOS DATA    **************************/
/*******************************************************************/
void Programa::DataSalsa(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Salsa*>(this->ListaReproduccion[i])){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            Salsa* ptr=dynamic_cast<Salsa*>(this->ListaReproduccion[i]);
            cout<<"[#] Estilo: "<<ptr->getEstilo()<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
        }
    }
    return;
}

void Programa::DataRock(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i])){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
        }
    }
    return;
}


void Programa::DataPop(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Pop*>(this->ListaReproduccion[i])){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            Pop* ptr=dynamic_cast<Pop*>(this->ListaReproduccion[i]);
            cout<<"[#] Acompamiamiento musical: ";
            if(ptr->getAcompMus()==true)cout<<"Si."<<endl;
            else cout<<"No"<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
        }
    }
    return;
}


void Programa::DataListaReproduccion(){
    if(this->CantReal>0){
        for(int i=0;i<this->CantReal;i++){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            if(dynamic_cast<Pop*>(this->ListaReproduccion[i]))cout<<"[#] Genero: POP"<<endl;
            if(dynamic_cast<Rock*>(this->ListaReproduccion[i]))cout<<"[#] Genero: Rock"<<endl;
            if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cout<<"[#] Genero: Salsa"<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
        }
    }else{
        cout<<"[#] Lista de Reproduccion Vacia."<<endl;
    }
    return;
}

void Programa::DataTipo(){
    if(this->CantSalsa()>0){
        cout<<"******************************"<<endl;
        cout<<"******* Genero: Salsa: *******"<<endl;
        cout<<"******************************"<<endl<<endl;
        this->DataSalsa();
    }
    if(this->CantRock()>0){
        cout<<"*****************************"<<endl;
        cout<<"******* Genero: Rock: *******"<<endl;
        cout<<"*****************************"<<endl<<endl;
        this->DataRock();
    }
    if(this->CantPop()>0){
        cout<<"****************************"<<endl;
        cout<<"******* Genero: POP: *******"<<endl;
        cout<<"****************************"<<endl<<endl;
        this->DataPop();
    }
}

/*************************************************************************/
/***********   METODOS CANT    **************************/
/*******************************************************************/

int Programa::CantSalsa(){
    int cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantRock(){
    int cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantPop(){
    int cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Pop*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}






/*************************************************************************/
/***********   METODOS PEDIDOS    **************************/
/*******************************************************************/
void Programa::CancionMaxLarga(){
    float mayor=0;
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaReproduccion[i]->getDuracion()>mayor)mayor=this->ListaReproduccion[i]->getDuracion();
    }
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaReproduccion[i]->getDuracion()==mayor){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
        }
    }
    return;
}




int Programa::CantPopACM(){
    int cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Pop*>(this->ListaReproduccion[i])){
            Pop* ptr=dynamic_cast<Pop*>(this->ListaReproduccion[i]);
            if(ptr->getAcompMus()==true)cant++;
        }
    }
    return cant;
}










void Programa::RockMaxAccepted(){
    float mayor=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i])){
            if(this->ListaReproduccion[i]->getNivelAceptacion()>mayor)mayor=this->ListaReproduccion[i]->getNivelAceptacion();
        }
    }

    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i])){
            if(this->ListaReproduccion[i]->getNivelAceptacion()==mayor){
                cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
                cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}




float Programa::TiempoTotal(){
    float suma=0;
    for(int i=0;i<this->CantReal;i++){
        suma+=this->ListaReproduccion[i]->getDuracion();
    }
    return suma;
}



void Programa::CancionMaxVotos(int Votos){
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaReproduccion[i]->getVotos()>Votos){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
        }
    }
    return;
}




void Programa::CancionMinDuracion(float Duracion){
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaReproduccion[i]->getDuracion()<Duracion){
            cout<<"[#] Numero de Cancion en la lista: "<<i+1<<endl;
            cout<<"[#] Autor: "<<ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
        }
    }
    return;
}
