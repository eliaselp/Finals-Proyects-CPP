#include "Empresa.h"
#include <iostream>
Empresa::Empresa(int MaxProyectos,int MaxEquipos,int MaxEmpleados)
{
    this->MaxProyectos=MaxProyectos;
    this->MaxEquipos=MaxEquipos;
    this->MaxEmpleados=MaxEmpleados;
    this->CantProyectos=0;
    this->CantEquipos=0;
    this->CantEmpleados=0;
    this->ListaProyectos=new Proyecto*[MaxProyectos];
    this->ListaEquipos=new Equipo*[MaxEquipos];
    this->ListaEmpleados=new Empleado*[MaxEmpleados];
}

Empresa::~Empresa()
{
    //dtor
}


/************ METODOS GETERS *********/
Proyecto* Empresa::getListaProyectos(int n){
    return this->ListaProyectos[n-1];
}
int Empresa::getMaxProyectos(){
    return this->MaxProyectos;
}
int Empresa::getCantProyectos(){
    return this->CantProyectos;
}
Empleado* Empresa::getListaEmpleados(int n){
    return this->ListaEmpleados[n-1];
}
int Empresa::getMaxEmpleados(){
    return this->MaxEmpleados;
}
int Empresa::getCantEmpleados(){
    return this->CantEmpleados;
}
Equipo* Empresa::getListaEquipos(int n){
    return this->ListaEquipos[n-1];
}
int Empresa::getMaxEquipos(){
    return this->MaxEquipos;
}
int Empresa::getCantEquipos(){
    return this->CantEquipos;
}



/******  METODOS CANTS  ***********/
int Empresa::CantProgramadores(){
    int Cant=0;
    for(int i=0;i<this->CantEmpleados;i++){
        if(dynamic_cast<Programador*>(this->ListaEmpleados[i]))
            if(this->ListaEmpleados[i]->Asociado==false)Cant++;
    }
    return Cant;
}
int Empresa::CantLideres(){
    int Cant=0;
    for(int i=0;i<this->CantEmpleados;i++){
        if(dynamic_cast<Lider*>(this->ListaEmpleados[i]))
            if(this->ListaEmpleados[i]->Asociado==false)Cant++;
    }
    return Cant;
}
int Empresa::CantMultimedia(){
    int Cant=0;
    for(int i=0;i<this->CantProyectos;i++){
        if(dynamic_cast<Multimedia*>(this->ListaProyectos[i]))
            if(this->ListaProyectos[i]->Asignado==false)Cant++;
    }
    return Cant;
}
int Empresa::CantEmpresarial(){
    int Cant=0;
    for(int i=0;i<this->CantProyectos;i++){
        if(dynamic_cast<Empresarial*>(this->ListaProyectos[i])){
            if(this->ListaProyectos[i]->Asignado==false){
                Cant++;
            }
        }
    }
    return Cant;
}
int Empresa::CantTotalEmpresarial(){
    int Cant=0;
    for(int i=0;i<this->CantProyectos;i++){
        if(dynamic_cast<Empresarial*>(this->ListaProyectos[i]))Cant++;
    }
    return Cant;
}
int Empresa::CantTotalMultimedia(){
    int Cant=0;
    for(int i=0;i<this->CantProyectos;i++){
        if(dynamic_cast<Multimedia*>(this->ListaProyectos[i]))Cant++;
    }
    return Cant;
}



/**********  METODOS DATA ***********/
void Empresa::DataEmpleado(){
    if(this->CantProgramadores()>0){
        cout<<"***** PROGRAMADORES *****"<<endl<<endl;
        this->DataProgramadores();
    }
    if(this->CantLideres()>0){
        cout<<"***** LIDERES DE PROYECTO *****"<<endl<<endl;
        this->DataLideres();
    }
}
void Empresa::DataProgramadores(){
    if(this->CantProgramadores()>0){
        for(int i=0;i<this->CantEmpleados;i++){
            if(dynamic_cast<Programador*>(this->ListaEmpleados[i])){
                if(this->ListaEmpleados[i]->Asociado==false){
                    cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
                    this->ListaEmpleados[i]->DataEmpleado();
                    cout<<"------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Empresa::DataLideres(){
    if(this->CantLideres()>0){
        for(int i=0;i<this->CantEmpleados;i++){
            if(dynamic_cast<Lider*>(this->ListaEmpleados[i])){
                if(this->ListaEmpleados[i]->Asociado==false){
                    cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
                    this->ListaEmpleados[i]->DataEmpleado();
                    cout<<"------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Empresa::DataProyectos(){
    if(this->CantMultimedia()>0){
        cout<<"***** PROYECTOS MULTIMEDIA *****"<<endl;
        this->DataMultimedia();
    }
    if(this->CantEmpresarial()>0){
        cout<<"***** PROYECTOS EMPRESARIALES *****"<<endl;
        this->DataEmpresarial();
    }
    return;
}
void Empresa::DataAllProyecto(){
    for(int i=0;i<this->CantProyectos;i++){
        cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
        this->ListaProyectos[i]->DataProyecto();
        cout<<"---------------------------------------"<<endl;
    }
    return;
}
void Empresa::DataMultimedia(){
    if(this->CantMultimedia()>0){
        for(int i=0;i<this->CantProyectos;i++){
            if(dynamic_cast<Multimedia*>(this->ListaProyectos[i])){
                if(this->ListaProyectos[i]->Asignado==false){
                    cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
                    this->ListaProyectos[i]->DataProyecto();
                    cout<<"------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Empresa::DataEmpresarial(){
    if(this->CantEmpresarial()>0){
        for(int i=0;i<this->CantProyectos;i++){
            if(dynamic_cast<Empresarial*>(this->ListaProyectos[i])){
                if(this->ListaProyectos[i]->Asignado==false){
                    cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
                    this->ListaProyectos[i]->DataProyecto();
                    cout<<"------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}


/********** METODOS APILADORES  ********/
void Empresa::AggEquipo(Equipo* nuevo){
    this->ListaEquipos[this->CantEquipos]=nuevo;
    this->CantEquipos++;
}
void Empresa::AggEmpleado(Empleado* nuevo){
    this->ListaEmpleados[this->CantEmpleados]=nuevo;
    this->CantEmpleados++;
}
void Empresa::AggProyecto(Proyecto* nuevo){
    this->ListaProyectos[this->CantProyectos]=nuevo;
    this->CantProyectos++;
}
void Empresa::CambiarProgramador(int n1,int p,int n2){
    if(n1>0&&n1<=this->CantEquipos){
        if(n2>0&&n2<=this->CantEquipos){
            if(n2!=n1){
                if(this->ListaEquipos[n2-1]->getCantProgramadores()<this->ListaEquipos[n2-1]->getMaxProgramadores()){
                    Programador* aux=this->ListaEquipos[n1-1]->getProgramadores(p);
                    this->ListaEquipos[n1-1]->QuitarProgramador(p);
                    this->ListaEquipos[n2-1]->AggProgramador(aux);
                }else{
                    cout<<"[#] No hay Capacidad en el segundo equipo."<<endl;
                }
            }else{
                cout<<"[#] No se pudo realizar la Opercion."<<endl;
            }
        }else{
            cout<<"[#] El segundo equipo no existe."<<endl;
        }
    }else{
        cout<<"[#] El primer equipo no existe."<<endl;
    }
        return;
}
void Empresa::ProyectoMinTime(){
    if(this->CantProyectos>0){
        int menor=9999999;
        for(int i=0;i<this->CantProyectos;i++){
            if(this->ListaProyectos[i]->getTiempo()<menor){
                menor=this->ListaProyectos[i]->getTiempo();
            }
        }
        cout<<"**************  PROYECTOS REALIZACION MAS RAPIDA  **************"<<endl;
        for(int i=0;i<this->CantProyectos;i++){
            if(this->ListaProyectos[i]->getTiempo()==menor){
                this->ListaProyectos[i]->DataProyecto();
                cout<<"---------------------------------------------"<<endl;
            }
        }
    }else{
        cout<<"[#] No hay PROYECTOS Disponibles."<<endl;
    }
    return;
}
float Empresa::TotalSueldo(){
    float Suma=0;
    for(int i=0;i<this->CantEmpleados;i++){
        Suma+=this->ListaEmpleados[i]->getSueldo();
    }
    return Suma;
}
void Empresa::EmpleadoMaxSueldo(){
    float Mayor=0;
    for(int i=0;i<this->CantEmpleados;i++){
        if(this->ListaEmpleados[i]->getSueldo()>Mayor)
            Mayor=this->ListaEmpleados[i]->getSueldo();
    }
    cout<<"***** CLIENTES DE MAYOR SUELDO *****"<<endl;
    for(int i=0;i<this->CantEmpleados;i++){
        if(this->ListaEmpleados[i]->getSueldo()==Mayor){
            this->ListaEmpleados[i]->DataEmpleado();
            cout<<"-------------------------------------------------"<<endl;
        }
    }
    return;
}
void Empresa::ProyectoProgramador(string CI){
    bool existe=false;
    int pos;
    for(int i=0;i<this->CantEmpleados;i++){
        if(this->ListaEmpleados[i]->getCI()==CI){
            existe=true;
            pos=i;
        }
    }
    if(existe==true){
        if(this->ListaEmpleados[pos]->Asociado==true){
            if(dynamic_cast<Lider*>(this->ListaEmpleados[pos])){
                for(int i=0;i<this->CantEquipos;i++){
                    if(this->ListaEquipos[i]->getJefe()->getCI()==CI){
                        this->ListaEquipos[i]->getPincha()->DataProyecto();
                        return;
                    }
                }
            }else{
                for(int i=0;i<this->CantEquipos;i++){
                    for(int j=0;j<this->ListaEquipos[i]->getCantProgramadores();j++){
                        if(this->ListaEquipos[i]->getProgramadores(j+1)->getCI()==CI){
                            this->ListaEquipos[i]->getPincha()->DataProyecto();
                            return;
                        }
                    }
                }
            }
        }else{
            cout<<"[#] El Empleado no esta asociado a ningun curso."<<endl;
        }
    }else{
        cout<<"[#] El Empleado no existe."<<endl;
    }
    return;
}
void Empresa::DataProgramadoresProyecto(int n){
    Proyecto* aux=this->getListaProyectos(n);
    if(aux->Asignado==true){
        int pos;
        for(int i=0;i<this->CantEquipos;i++){
            if(this->ListaEquipos[i]->getPincha()==aux){
                pos=i;
            }
        }
        for(int i=0;i<this->ListaEquipos[pos]->getCantProgramadores();i++){
            this->ListaEquipos[pos]->getProgramadores(i+1)->DataEmpleado();
            cout<<"------------------------------------------------"<<endl;
        }
    }else{
        cout<<"[#] El Proyecto no ha sido Asignado."<<endl;
    }
}
