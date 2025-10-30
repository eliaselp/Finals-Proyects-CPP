#include "Vicedecanato.h"
#include <iostream>
using namespace std;
Vicedecanato::Vicedecanato(int MaxEstudiantes)
{
    this->MaxEstudiantes=MaxEstudiantes;
    this->ListaEstudiantes=new Estudiante*[this->MaxEstudiantes];
    this->CantEstudiantes=0;
}

Vicedecanato::~Vicedecanato()
{
    //dtor
}


Estudiante* Vicedecanato::getListaEstudiantes(int n){
    return this->ListaEstudiantes[n-1];
}
int Vicedecanato::getCantEstudiantes(){
    return this->CantEstudiantes;
}
int Vicedecanato::getMaxEstudiantes(){
    return this->MaxEstudiantes;
}
//----------------------------------------------------
int Vicedecanato::CantComun(){
    int Cant=0;
    for(int i=0;i<this->CantEstudiantes;i++){
        if(dynamic_cast<Comun*>(this->ListaEstudiantes[i]))Cant++;
    }
    return Cant;
}
int Vicedecanato::CantEspecial(){
    int Cant=0;
    for(int i=0;i<this->CantEstudiantes;i++){
        if(dynamic_cast<Especial*>(this->ListaEstudiantes[i]))Cant++;
    }
    return Cant;
}
int Vicedecanato::CantAyudante(){
    int Cant=0;
    for(int i=0;i<this->CantEstudiantes;i++){
        if(dynamic_cast<Ayudante*>(this->ListaEstudiantes[i]))Cant++;
    }
    return Cant;
}





//-------------------------------------------------------
void Vicedecanato::DataEstudiantes(){
    this->DataComun();
    this->DataAyudante();
    this->DataEspecial();
    return;
}
void Vicedecanato::DataComun(){
    if(CantComun()>0){
        cout<<"*****  ESTUDIANTES COMUNES  *****"<<endl;
        for(int i=0;i<this->CantEstudiantes;i++){
            if(dynamic_cast<Comun*>(this->ListaEstudiantes[i])){
                cout<<"<<<<<<<  INDEXADO  >>>>>>>"<<endl;
                this->ListaEstudiantes[i]->DataEstudiante();
                cout<<"------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Vicedecanato::DataAyudante(){
    if(CantAyudante()>0){
        cout<<"*****  ALUMNOS AYUDANTES  *****"<<endl;
        for(int i=0;i<this->CantEstudiantes;i++){
            if(dynamic_cast<Ayudante*>(this->ListaEstudiantes[i])){
                cout<<"<<<<<<<  INDEXADO  >>>>>>>"<<endl;
                this->ListaEstudiantes[i]->DataEstudiante();
                cout<<"------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Vicedecanato::DataEspecial(){
    if(CantEspecial()>0){
        cout<<"*****  ESTUDIANTES LICENCIA ESPECIAL  *****"<<endl;
        for(int i=0;i<this->CantEstudiantes;i++){
            if(dynamic_cast<Especial*>(this->ListaEstudiantes[i])){
                cout<<"<<<<<<<  INDEXADO  >>>>>>>"<<endl;
                this->ListaEstudiantes[i]->DataEstudiante();
                cout<<"------------------------------------"<<endl;
            }
        }
    }
    return;
}






void Vicedecanato::AggEstudiante(Estudiante* nuevo){
    this->ListaEstudiantes[this->CantEstudiantes]=nuevo;
    this->CantEstudiantes++;
    return;
}
string Vicedecanato::GrupoEstudiante(string CI){
    bool Existe=false;
    int pos;
    for(int i=0;i<this->CantEstudiantes;i++){
        if(this->ListaEstudiantes[i]->getCI()==CI){
            Existe=true;
            pos=i;
        }
    }
    if(Existe==true){
        return this->ListaEstudiantes[pos]->getGrupo();
    }else{
        cout<<"[#] El estudiante no esta Matriculado."<<endl;
    }
    return "";
}

float Vicedecanato::Promedio(string Nombre){
    int pos;
    bool Existe=false;
    for(int i=0;i<this->CantEstudiantes;i++){
        if(this->ListaEstudiantes[i]->getNombre()==Nombre){
            pos=i;
            Existe=true;
        }
    }
    float Suma=0;
    if(Existe==true){
        for(int i=0;i<this->ListaEstudiantes[pos]->getCantAsignaturas();i++){
            Suma+=this->ListaEstudiantes[pos]->getAsignaturas(i+1)->getNotaFinal();
        }
        Suma=Suma/this->ListaEstudiantes[pos]->getCantAsignaturas();
    }
    return Suma;
}
void Vicedecanato::DiplomaOro(){
    for(int i=0;i<this->CantEstudiantes;i++){
        float Suma=0;
        for(int j=0;j<this->ListaEstudiantes[i]->getCantAsignaturas();j++){
            Suma+=this->ListaEstudiantes[i]->getAsignaturas(j+1)->getNotaFinal();
        }
        Suma=Suma/this->ListaEstudiantes[i]->getCantAsignaturas();
        if(Suma>=4.75){
            this->ListaEstudiantes[i]->DataEstudiante();
            cout<<"------------------------------------------"<<endl;
        }
    }
}
void Vicedecanato::Escalafon(){
    Estudiante**aux=new Estudiante*[this->CantEstudiantes];
    float Promedios[this->CantEstudiantes];
    for(int i=0;i<this->CantEstudiantes;i++){
        aux[i]=this->ListaEstudiantes[i];
        float Suma=0;
        for(int j=0;j<this->ListaEstudiantes[i]->getCantAsignaturas();j++){
            Suma+=this->ListaEstudiantes[i]->getAsignaturas(j+1)->getNotaFinal();
        }
        Suma=Suma/this->ListaEstudiantes[i]->getCantAsignaturas();
        Promedios[i]=Suma;
    }

    for(int i=0;i<this->CantEstudiantes;i++){
        for(int j=0;j<this->CantEstudiantes-1;j++){
            if(Promedios[j]<Promedios[j+1]){
                float p=Promedios[j];
                Promedios[j]=Promedios[j+1];
                Promedios[j+1]=p;
                Estudiante* aux2=aux[j];
                aux[j]=aux[j+1];
                aux[j+1]=aux2;
            }
        }
    }

    for(int i=0;i<this->CantEstudiantes;i++){
        cout<<"[#] Nombre: "<<this->ListaEstudiantes[i]->getNombre()<<" "<<this->ListaEstudiantes[i]->getApellido();
        cout<<"  ===>>>  "<<Promedios[i];
        cout<<"---------------------------------------------------"<<endl;
    }
    return;
}


