#include "Programador.h"
#include <iostream>
using namespace std;
Programador::Programador(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI,int Lenguajes,char Categoria)
:Empleado(Nombre,Edad,Sexo,SalarioBasico,CI)
{
    this->Lenguajes=Lenguajes;
    this->Categoria=Categoria;
    this->setSueldo(0);
}

Programador::~Programador()
{
    //dtor
}


/***** METODOS GETERS *****/
int Programador::getLenguajes(){
    return this->Lenguajes;
}
char Programador::getCategoria(){
    return this->Categoria;
}


/********** METODOS OVERRIDE *******/
void Programador::setSueldo(long PrecioProyecto){
    this->Sueldo=this->getSalarioBasico()+((5*PrecioProyecto)/100)+3*this->Lenguajes;
    return;
}


void Programador::DataEmpleado(){
    Empleado::DataEmpleado();
    cout<<"[#] Cantidad de Lenguajes dominados: "<<this->Lenguajes<<endl;
    cout<<"[#] Categoria: "<<this->Categoria<<endl;
    cout<<"[#] Sueldo: "<<this->Sueldo<<endl;
    return;
}
