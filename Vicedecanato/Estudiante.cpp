#include "Estudiante.h"
#include <iostream>
using namespace std;
Estudiante::Estudiante(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                       string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera)
{
    this->Nombre=Nombre;
    this->Apellido=Apellido;
    this->CI=CI;
    this->Grupo=Grupo;
    this->Anio=Anio;
    this->Proyecto=Proyecto;
    this->NombreProyecto=NombreProyecto;
    this->CantAsignaturas=CantAsignaturas;
    this->AyudaFinanciera=AyudaFinanciera;
    this->Asignaturas=new Asignatura*[this->CantAsignaturas];
    for(int i=0;i<this->CantAsignaturas;i++){
        system("cls");
        string Nombre;
        float NotaFinal;
        int Anio;
        int Semestre;
        fflush(stdin);cout<<"[+] Asignatura: ";getline(cin,Nombre);
        fflush(stdin);cout<<"[+] Nota Final: ";cin>>NotaFinal;
        cout<<"[+] Anio: ";cin>>Anio;
        cout<<"[+] Semestre: ";cin>>Semestre;
        Asignatura* nueva=new Asignatura(Nombre,NotaFinal,Anio,Semestre);
        this->Asignaturas[i]=nueva;
    }
}

Estudiante::~Estudiante()
{
    //dtor
}



string Estudiante::getNombre(){
    return this->Nombre;
}
string Estudiante::getApellido(){
    return this->Apellido;
}
string Estudiante::getCI(){
    return this->CI;
}
string Estudiante::getGrupo(){
    return this->Grupo;
}
int Estudiante::getAnio(){
    return this->Anio;
}
bool Estudiante::getProyecto(){
    return this->Proyecto;
}
string Estudiante::getNombreProyecto(){
    return this->NombreProyecto;
}
Asignatura* Estudiante::getAsignaturas(int n){
    return this->Asignaturas[n-1];
}
int Estudiante::getCantAsignaturas(){
    return this->CantAsignaturas;
}
bool Estudiante::getAyudaFinanciera(){
    return this->AyudaFinanciera;
}
float Estudiante::getEstipendio(){
    return this->Estipendio;
}



//----------------------------------------
void Estudiante::DataEstudiante(){
    cout<<"[#] Nombres y Apellidos: "<<this->Nombre<<" "<<this->Apellido<<endl;
    cout<<"[#] CI: "<<this->CI<<endl;
    cout<<"[#] Grupo: "<<this->Grupo<<endl;
    cout<<"[#] Anio: "<<this->Anio<<endl;
    if(this->Proyecto==true){
        cout<<"[#] Proyecto: "<<this->NombreProyecto<<endl;
    }
    cout<<"[#] Cantidad de Asignaturas: "<<this->CantAsignaturas<<endl;
    return;
}
