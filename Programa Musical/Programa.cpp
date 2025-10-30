#include "Programa.h"
#include <iostream>
using namespace std;
Programa::Programa(int CantMaxCanciones)
{
    this->ListaReproduccion=new Genero*[CantMaxCanciones];
    this->CantCanciones=0;
}

Programa::~Programa()
{
    //dtor
}


/*****************************************************************************************************************/
/*********** METODOS GETERS *************************************************************************************/
/**********************************************************************************/

int Programa::getCantCanciones(){
    return this->CantCanciones;
}






/*****************************************************************************************************************/
/*********** METODOS DATA *************************************************************************************/
/**********************************************************************************/
void Programa::DataReproduccion(){
    if(this->CantCanciones>0){
        if(CantRockProgresivo()>0){
            cout<<"[#] GENERO ROCK PROGRESIVO."<<endl;
            DataRockProgresivo();
            cout<<"*************************************************************************************"<<endl;
            cout<<"*************************************************************************************"<<endl;
        }
        if(CantHeavyMetal()>0){
            cout<<"[#] GENERO HEAVY METAL."<<endl;
            DataHeavyMetal();
            cout<<"*************************************************************************************"<<endl;
            cout<<"*************************************************************************************"<<endl;
        }
        if(CantBluesRock()>0){
            cout<<"[#] GENERO BLUES ROCK."<<endl;
            DataBluesRock();
            cout<<"*************************************************************************************"<<endl;
            cout<<"*************************************************************************************"<<endl;
        }
        if(CantPOP()>0){
            cout<<"[#] GENERO POP."<<endl;
            DataPOP();
            cout<<"*************************************************************************************"<<endl;
            cout<<"*************************************************************************************"<<endl;
        }
        if(CantSalsa()>0){
            cout<<"[#] GENERO SALSA."<<endl;
            DataSalsa();
            cout<<"*************************************************************************************"<<endl;
            cout<<"*************************************************************************************"<<endl;
        }
    }else{
        cout<<"[#] Lista de Reproduccion Vacia."<<endl;
    }


}
void Programa::DataRockProgresivo(){
    if(this->CantRockProgresivo()>0){
        for(int i=0;i<this->CantCanciones;i++){
            if(dynamic_cast<RockProgresivo*>(this->ListaReproduccion[i])){
                cout<<"[#] Numero de Cancion en la Lista. "<<i+1<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Genero: Rock Progresivo."<<endl;
                cout<<"[#] Tiempor de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Programa::DataHeavyMetal(){
    if(this->CantHeavyMetal()>0){
        for(int i=0;i<this->CantCanciones;i++){
            if(dynamic_cast<HeavyMetal*>(this->ListaReproduccion[i])){
                cout<<"[#] Numero de Cancion en la Lista. "<<i+1<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Genero: HeavyMetal."<<endl;
                cout<<"[#] Tiempor de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}

void Programa::DataBluesRock(){
    if(this->CantBluesRock()>0){
        for(int i=0;i<this->CantCanciones;i++){
            if(dynamic_cast<BluesRock*>(this->ListaReproduccion[i])){
                cout<<"[#] Numero de Cancion en la Lista. "<<i+1<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Genero: BluesRock."<<endl;
                cout<<"[#] Tiempor de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Programa::DataPOP(){
    if(this->CantPOP()>0){
        for(int i=0;i<this->CantCanciones;i++){
            if(dynamic_cast<POP*>(this->ListaReproduccion[i])){
                cout<<"[#] Numero de Cancion en la Lista. "<<i+1<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Genero: POP."<<endl;
                POP* pvr=dynamic_cast<POP*>(this->ListaReproduccion[i]);
                cout<<"Acompannamiento Musical: ";
                if(pvr->getACM()==true)cout<<"Si."<<endl;
                else cout<<"No."<<endl;
                cout<<"[#] Tiempor de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Programa::DataSalsa(){
    if(this->CantSalsa()>0){
        for(int i=0;i<this->CantCanciones;i++){
            if(dynamic_cast<Salsa*>(this->ListaReproduccion[i])){
                cout<<"[#] Numero de Cancion en la Lista. "<<i+1<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Genero: Salsa."<<endl;
                Salsa* pvr=dynamic_cast<Salsa*>(this->ListaReproduccion[i]);
                cout<<"[#] Estilo: "<<pvr->getEstilo();
                cout<<"[#] Tiempor de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
            }
        }
    }
    return;
}

/*****************************************************************************************************************/
/*********** METODOS CANT *************************************************************************************/
/**********************************************************************************/
int Programa::CantRockProgresivo(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<RockProgresivo*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantHeavyMetal(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<HeavyMetal*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantBluesRock(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<BluesRock*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantPOP(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<POP*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}
int Programa::CantSalsa(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cant++;
    }
    return cant;
}




//-----------------------------------------------------------------
void Programa::AggCancion(Genero* nuevo){
    this->ListaReproduccion[this->CantCanciones]=nuevo;
    this->CantCanciones++;
    return;
}


void Programa::EliminarCancion(int n){
    delete this->ListaReproduccion[n-1];
    for(int i=n-1;i<this->CantCanciones-1;i++){
        this->ListaReproduccion[i]=this->ListaReproduccion[i+1];
    }
    this->ListaReproduccion[this->CantCanciones]=NULL;
    this->CantCanciones--;
    return;
}
void Programa::DataMaxDuracion(){
    int Mayor=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(this->ListaReproduccion[i]->getDuracion()>Mayor)Mayor=this->ListaReproduccion[i]->getDuracion();
    }

    for(int i=0;i<this->CantCanciones;i++){
        if(this->ListaReproduccion[i]->getDuracion()==Mayor){
            cout<<"[#] Genero: ";
            if(dynamic_cast<POP*>(this->ListaReproduccion[i]))cout<<"POP."<<endl;
            if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cout<<"Salsa."<<endl;
            if(dynamic_cast<Rock*>(this->ListaReproduccion[i]))cout<<"Rock."<<endl;
            cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Tiempo de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
        }
    }
    return;
}
int Programa::CantPopACM(){
    int cant=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<POP*>(this->ListaReproduccion[i])){
            POP* ptr=dynamic_cast<POP*>(this->ListaReproduccion[i]);
            if(ptr->getACM()==true)cant++;
        }
    }
    return cant;
}

void Programa::DataRockMaxAccepted(){
    float Mayor=0;
    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i])){
            if(this->ListaReproduccion[i]->getLevel_Accepted()>Mayor)Mayor=this->ListaReproduccion[i]->getLevel_Accepted();
        }
    }

    for(int i=0;i<this->CantCanciones;i++){
        if(dynamic_cast<Rock*>(this->ListaReproduccion[i])){
            if(this->ListaReproduccion[i]->getLevel_Accepted()==Mayor){
                cout<<"[#] Genero: ";
                if(dynamic_cast<BluesRock*>(this->ListaReproduccion[i]))cout<<"Blues Rock."<<endl;
                if(dynamic_cast<RockProgresivo*>(this->ListaReproduccion[i]))cout<<"Rock Progresivo."<<endl;
                if(dynamic_cast<HeavyMetal*>(this->ListaReproduccion[i]))cout<<"Heavy Metal."<<endl;
                cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
                cout<<"[#] Tiempo de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
                cout<<"[#] Nivel de Aceptacion: "<<this->ListaReproduccion[i]->getLevel_Accepted()<<endl;
            }
        }
    }
}
int Programa::TotalTime(){
    int TOTA=0;
    for(int i=0;i<this->CantCanciones;i++){
        TOTA+=this->ListaReproduccion[i]->getDuracion();
    }
    return TOTA;
}

void Programa::DataPlusVotos(int n){
    for(int i=0;i<this->CantCanciones;i++){
        if(this->ListaReproduccion[i]->getVotos()>n){
            if(dynamic_cast<POP*>(this->ListaReproduccion[i]))cout<<"[#] POP."<<endl;
            if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cout<<"[#] Salsa."<<endl;
            if(dynamic_cast<Rock*>(this->ListaReproduccion[i]))cout<<"[#] Rock."<<endl;
            cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Tiempo de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
            cout<<"[#] Cantidad de Votos: "<<this->ListaReproduccion[i]->getVotos()<<endl;
        }
    }
    return;
}

void Programa::DataListMinTime(int time){
    for(int i=0;i<this->CantCanciones;i++){
        if(this->ListaReproduccion[i]->getDuracion()<time){
            cout<<"Genero: ";
            if(dynamic_cast<POP*>(this->ListaReproduccion[i]))cout<<"[#] POP."<<endl;
            if(dynamic_cast<Salsa*>(this->ListaReproduccion[i]))cout<<"[#] Salsa."<<endl;
            if(dynamic_cast<Rock*>(this->ListaReproduccion[i]))cout<<"[#] Rock."<<endl;
            cout<<"[#] Autor: "<<this->ListaReproduccion[i]->getAutor()<<endl;
            cout<<"[#] Tiempo de Duracion: "<<this->ListaReproduccion[i]->getDuracion()<<endl;
        }
    }
    return;
}
