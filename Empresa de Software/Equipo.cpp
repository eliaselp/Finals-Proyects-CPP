#include "Equipo.h"

Equipo::Equipo(int MaxProgramadores,Lider* Jefe,Proyecto* Pincha)
{
    this->MaxProgramadores=MaxProgramadores;
    this->Pincha=Pincha;
    this->Pincha->Asignado=true;
    this->Jefe=Jefe;
    this->Jefe->setSueldo(this->Pincha->getPrecio());
    this->Programadores=new Programador*[MaxProgramadores];
    this->CantProgramadores=0;
}

Equipo::~Equipo()
{
    //dtor
}



/*********   METODOS GETERS ***********/
Programador* Equipo::getProgramadores(int n){
    return this->Programadores[n-1];
}
int Equipo::getCantProgramadores(){
    return this->CantProgramadores;
}
int Equipo::getMaxProgramadores(){
    return this->MaxProgramadores;
}
Lider* Equipo::getJefe(){
    return this->Jefe;
}
Proyecto* Equipo::getPincha(){
    return this->Pincha;
}



/******************** METODOS APILDORES  ***************/
void Equipo::AggProgramador(Programador* nuevo){
    this->Programadores[this->CantProgramadores]=nuevo;
    nuevo->setSueldo(this->Pincha->getPrecio());
    nuevo->Asociado=true;
    this->CantProgramadores++;
}



void Equipo::QuitarProgramador(int n){
    this->Programadores[n-1]->Asociado=false;
    this->Programadores[n-1]->setSueldo(0);
    this->Programadores[n-1]=NULL;
    for(int i=0;i<this->CantProgramadores-1;i++){
        this->Programadores[i]=this->Programadores[i+1];
    }
    this->Programadores[CantProgramadores-1]=NULL;
    this->CantProgramadores--;
    return;
}
