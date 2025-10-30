#include <iostream>
#include "Empresa.h"
#include "Proyecto.h"
#include "Multimedia.h"
#include "Empresarial.h"
#include "Empleado.h"
#include "Programador.h"
#include "Lider.h"
#include "Equipo.h"
using namespace std;
Empresa* DESOFT;
Proyecto* Trabajo;
Multimedia* TrabajoMultimedia;
Empresarial* TrabajoEmpresarial;
Empleado* Usser;
Programador* UsserProgramador;
Lider* UsserAdmin;
Equipo* Bulto;

void GestionEquipos(int n);
int main()
{
    int MaxProyectos,MaxEquipos,MaxEmpleados;
    cout<<"[+] MAXIMO DE PROYECTOS PERMITIDOS: "<<endl;
    cin>>MaxProyectos;
    cout<<"[+] MAXIMO DE EQUIPOS PERMITIDOS: "<<endl;
    cin>>MaxEquipos;
    cout<<"[+] MAXIMO DE EMPLEADOS PERMITIDOS: "<<endl;
    cin>>MaxEmpleados;
    DESOFT=new Empresa(MaxProyectos,MaxEquipos,MaxEmpleados);
    int opc;
    do{
        system("cls");
        cout<<"*************************************"<<endl;
        cout<<"***      EMPRESA DE SOFTWARE      ***"<<endl;
        cout<<"*************************************"<<endl<<endl;
        cout<<"[1] Agregar Proyecto."<<endl;
        cout<<"[2] Agregar Empleado."<<endl;
        cout<<"[3] Crear Equipo de Trabajo."<<endl;
        cout<<"[4] Trasladar Programador."<<endl;
        cout<<"[5] Cantidad de Proyectos por tipo."<<endl;
        cout<<"[6] Proyecto de Realizacion mas Rapida."<<endl;
        cout<<"[7] Nomina de pago total."<<endl;
        cout<<"[8] Trabajador(es) Mayor Sueldo."<<endl;
        cout<<"[9] Proyecto Asignado a un Programador."<<endl;
        cout<<"[10] Programadores de un Proyecto."<<endl;
        cout<<"[11] SECCION DE GESTION DE EQUIPOS."<<endl;
        cout<<"[12] Fichero."<<endl;
        cout<<"[13] Salir."<<endl<<endl;
        cout<<"[#] OPCION >>>>>  ";cin>>opc;
        system("cls");

        if(opc==1){
            if(DESOFT->getCantProyectos()<DESOFT->getMaxProyectos()){
                int p;
                cout<<"[1] Multimedia."<<endl;
                cout<<"[2] Empresarial."<<endl<<endl;
                cout<<"[#] OPCION >>>>>  ";cin>>p;
                if(p==1){
                    string Nombre;
                    string Descripcion;
                    int Tiempo;
                    long Precio;
                    string Desarrollo;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[#] Descripcion: ";getline(cin,Descripcion);
                    fflush(stdin);cout<<"[#] Tiempo: ";cin>>Tiempo;
                    fflush(stdin);cout<<"[#] Precio: ";cin>>Precio;
                    int d=1;
                    do{
                        system("cls");
                        if(d<1||d>2)cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        cout<<"[+] Desarrollo ==>>>>     [1] Flash       [2]Director.";cin>>d;
                    }while(d<1||d>2);
                    if(d==1)Desarrollo="FLASH";
                    else if(d==2)Desarrollo="DIRECTOR";
                    Trabajo=new Multimedia(Nombre,Descripcion,Tiempo,Precio,Desarrollo);
                    DESOFT->AggProyecto(Trabajo);
                    Trabajo=NULL;
                }else if(p==2){
                    string Nombre;
                    string Descripcion;
                    int Tiempo;
                    long Precio;
                    string Arquitectura;
                    string BD;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[#] Descripcion: ";getline(cin,Descripcion);
                    fflush(stdin);cout<<"[#] Tiempo: ";cin>>Tiempo;
                    fflush(stdin);cout<<"[#] Precio: ";cin>>Precio;
                    int d=1;
                    do{
                        system("cls");
                        if(d<1||d>2)cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        fflush(stdin);cout<<"[#] Arquitectura ==>>>>     [1] Distribuida       [2]Cliente-Servidor."<<endl;
                        cin>>d;
                    }while(d<1||d>2);
                    if(d==1)Arquitectura="DISTRIBUIDA";
                    else if(d==2)Arquitectura="CLIENTE-SERVIDOR";
                    fflush(stdin);cout<<"[#] Tipo de Base de Datos: ";getline(cin,BD);
                    Trabajo=new Empresarial(Nombre,Descripcion,Tiempo,Precio,Arquitectura,BD);
                    DESOFT->AggProyecto(Trabajo);
                    Trabajo=NULL;
                }else{
                    cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Capacidad para un nuevo Proyecto."<<endl;
            }
        }else if(opc==2){
            if(DESOFT->getCantEmpleados()<DESOFT->getMaxEmpleados()){
                int p;
                cout<<"[1] Lider."<<endl;
                cout<<"[2] Programador"<<endl<<endl;
                cout<<"[#] OPCION >>>>>  ";cin>>p;
                if(p==1){
                    string Nombre;
                    int Edad;
                    string Sexo;
                    float SalarioBasico;
                    string CI;
                    int Anios;
                    int CantProyectos;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[#] Edad: ";cin>>Edad;
                    fflush(stdin);cout<<"[#] Sexo: ";getline(cin,Sexo);
                    fflush(stdin);cout<<"[#] Salario Basico: ";cin>>SalarioBasico;
                    fflush(stdin);cout<<"[#] Carnet de Identidad: ";getline(cin,CI);
                    fflush(stdin);cout<<"[#] Anios de Experiencia: ";cin>>Anios;
                    fflush(stdin);cout<<"[#] Cantidad de Proyectos dirigidos: ";cin>>CantProyectos;
                    Usser=new Lider(Nombre,Edad,Sexo,SalarioBasico,CI,Anios,CantProyectos);
                    DESOFT->AggEmpleado(Usser);
                    Usser=NULL;
                }else if(p==2){
                    string Nombre;
                    int Edad;
                    string Sexo;
                    float SalarioBasico;
                    string CI;
                    int Lenguajes;
                    char Categoria='A';
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[#] Edad: ";cin>>Edad;
                    fflush(stdin);cout<<"[#] Sexo: ";getline(cin,Sexo);
                    fflush(stdin);cout<<"[#] Salario Basico: ";cin>>SalarioBasico;
                    fflush(stdin);cout<<"[#] Carnet de Identidad: ";getline(cin,CI);
                    fflush(stdin);cout<<"[#] Cantidad de Lenguajes que Domina: ";cin>>Lenguajes;
                    do{
                        system("cls");
                        if(Categoria!='A'&&Categoria!='B'&&Categoria!='C')cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        fflush(stdin);cout<<"[#] Categoria: <A>  <B>  <C> ==> ";cin>>Categoria;
                    }while(Categoria!='A'&&Categoria!='B'&&Categoria!='C');
                    Usser=new Programador(Nombre,Edad,Sexo,SalarioBasico,CI,Lenguajes,Categoria);
                    DESOFT->AggEmpleado(Usser);
                    Usser=NULL;
                }else{
                    cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Capacidad para un nuevo Empleado."<<endl;
            }
        }else if(opc==3){
            if(DESOFT->CantLideres()>0){
                if(DESOFT->getCantProyectos()>0){
                    bool accepted=false;
                    int p;
                    int l=1;
                    do{
                        system("cls");
                        DESOFT->DataLideres();
                        if(accepted==true)cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        cout<<"Seleccione un Lider."<<endl;
                        cout<<"<<<< INDEXADO >>>> ==> ";cin>>l;
                        if(l>0&&l<=DESOFT->getCantEmpleados()){
                            if(dynamic_cast<Lider*>(DESOFT->getListaEmpleados(l))){
                                if(DESOFT->getListaEmpleados(l)->Asociado==false)accepted=true;
                            }
                        }
                        system("cls");
                    }while(accepted!=true);
                    accepted=false;
                    do{
                        system("cls");
                        DESOFT->DataProyectos();
                        if(accepted==true)cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        cout<<"Seleccione un Proyecto."<<endl;
                        cout<<"<<<< INDEXADO >>>> ==> ";cin>>p;
                        if(p>0&&p<=DESOFT->getCantProyectos()){
                            if(DESOFT->getListaProyectos(p)->Asignado==false){
                                accepted=true;
                            }
                        }
                        system("cls");
                    }while(accepted!=true);
                    int m=1;
                    do{
                        system("cls");
                        if(m>DESOFT->getMaxEmpleados()||m<1)cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        cout<<"[#] Cantidad Maxima de Empleados en el Equipo: ";cin>>m;
                    }while(m>DESOFT->getMaxEmpleados()||m<1);

                    UsserAdmin=dynamic_cast<Lider*>(DESOFT->getListaEmpleados(l));
                    UsserAdmin->Asociado=true;
                    DESOFT->getListaProyectos(p)->Asignado=true;
                    Bulto=new Equipo(m,UsserAdmin,DESOFT->getListaProyectos(p));
                    DESOFT->AggEquipo(Bulto);


                    Bulto=NULL;
                    UsserAdmin=NULL;
                    UsserProgramador=NULL;
                }else{
                    cout<<"[#] No hay Proyectos Disponibles."<<endl;
                }
            }else{
                cout<<"[#] No hay Lideres Disponibles."<<endl;
            }
        }else if(opc==4){
            if(DESOFT->getCantEquipos()>=2){
                int n1=1;
                int n2=1;
                int p=1;
                system("cls");
                for(int i=0;i<DESOFT->getCantEquipos();i++){
                    cout<<"[#] Equipo "<<i+1<<": ";
                    cout<<DESOFT->getListaEquipos(i+1)->getPincha()->getNombre()<<endl;
                    cout<<"--------------------------------------------------"<<endl;
                }
                cout<<"[#] Inserte numero de Equipo de Salida: ";cin>>n1;
                if(n1<1||n1>DESOFT->getCantEquipos())cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                else{
                    system("cls");
                    if(DESOFT->getListaEquipos(n1)->getCantProgramadores()>0){
                        system("cls");
                        for(int i=0;i<DESOFT->getListaEquipos(n1)->getCantProgramadores();i++){
                            cout<<"<<<< INDEXADO >>>>  ==> "<<i+1<<endl;
                            DESOFT->getListaEquipos(n1)->getProgramadores(i+1)->DataEmpleado();
                            cout<<"-----------------------------------------------------"<<endl;
                        }
                        cout<<"[#] Inserte << Indexado >> ==> ";cin>>p;
                        if(p<1||p>DESOFT->getListaEquipos(n1)->getCantProgramadores())
                            cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                        else{
                            system("cls");
                            for(int i=0;i<DESOFT->getCantEquipos();i++){
                                if(i!=n1-1){
                                    cout<<"[#] Equipo "<<i+1<<": ";
                                    cout<<DESOFT->getListaEquipos(i+1)->getPincha()->getNombre()<<endl;
                                    cout<<"--------------------------------------------------"<<endl;
                                }
                            }
                            cout<<"[#] Inserte Numero de equipo de Llegada ==> ";cin>>n2;
                            if(n2>=1&&n2<=DESOFT->getCantEquipos()&&n1!=n2){
                                system("cls");
                                DESOFT->CambiarProgramador(n1,p,n2);
                            }else{
                                cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                            }
                        }
                    }else{
                        cout<<"[#] No hay Programadores Disponibles."<<endl;
                    }
                }
            }else{
                cout<<"[#] No se puede realizar esta operacion."<<endl;
            }
        }else if(opc==5){
            cout<<"[#] Proyectos Empresariales: "<<DESOFT->CantTotalEmpresarial()<<endl;
            cout<<"[#] Proyectos Multimedia: "<<DESOFT->CantTotalMultimedia()<<endl;
        }else if(opc==6){
            if(DESOFT->getCantProyectos()>0){
                DESOFT->ProyectoMinTime();
            }else{
                cout<<"[#] No hay Proyectos disponibles."<<endl;
            }
        }else if(opc==7){
            if(DESOFT->getCantEmpleados()>0){
                cout<<"[#] Pago total: "<<DESOFT->TotalSueldo()<<"$"<<endl;
            }else{
                cout<<"[#] No hay Clientes Disponibles."<<endl;
            }
        }else if(opc==8){
            if(DESOFT->getCantEmpleados()>0){
                DESOFT->EmpleadoMaxSueldo();
            }else{
                cout<<"[#] No hay Clientes Disponibles."<<endl;
            }
        }else if(opc==9){
            if(DESOFT->getCantEmpleados()>0){
                string CI;
                cout<<"[#] Carnet de Identidad: ";
                fflush(stdin);getline(cin,CI);
                DESOFT->ProyectoProgramador(CI);
            }else{
                cout<<"[#] No hay Clientes Disponibles."<<endl;
            }
        }else if(opc==10){
            if(DESOFT->getCantProyectos()>0){
                int n=1;
                do{
                    DESOFT->DataAllProyecto();
                    if(n<1||n>DESOFT->getCantProyectos())
                        cout<<"<<<<<<    ERROR    >>>>>>>"<<endl;
                    cout<<"[#] Inserte << Indexado >> ==> ";cin>>n;
                }while(n<1||n>DESOFT->getCantProyectos());
                if(DESOFT->getListaProyectos(n)->Asignado==true){
                    int pos;
                    for(int i=0;i<DESOFT->getCantEquipos();i++){
                        if(DESOFT->getListaEquipos(i+1)->getPincha()==DESOFT->getListaProyectos(n)){
                            pos=i;
                        }
                    }
                    cout<<"***** LIDER  *****"<<endl;
                    DESOFT->getListaEquipos(n)->getJefe()->DataEmpleado();
                    cout<<endl<<"***** PROGRAMADORES *****"<<endl;
                    for(int i=0;i<DESOFT->getListaEquipos(n)->getCantProgramadores();i++){
                        DESOFT->getListaEquipos(pos+1)->getProgramadores(i+1)->DataEmpleado();
                        cout<<"-----------------------------------------------------"<<endl;
                    }
                }else{
                    cout<<"[#] El proyecto no esta Asignado"<<endl;
                }
            }else{
                cout<<"[#] No hay Proyectos Disponibles."<<endl;
            }
        }else if(opc==11){
            if(DESOFT->getCantEquipos()>0){
                int n;
                for(int i=0;i<DESOFT->getCantEquipos();i++){
                    cout<<"EQUIPO => ["<<i+1<<"]  >>>> ";
                    cout<<DESOFT->getListaEquipos(i+1)->getPincha()->getNombre()<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                }
                cout<<"[#] Inserte << Indexado >> ==> ";cin>>n;
                if(n<1||n>DESOFT->getCantEquipos())cout<<"<<<<<<    ERROR    >>>>>>>"<<endl;
                else GestionEquipos(n);
            }else{
                cout<<"[#] No hay Equipos Registrados."<<endl;
            }
        }else if(opc==12){
            cout<<"[#] INCISO DE FICHEROS."<<endl;
        }else if(opc==13){
            cout<<"[#] Que tenga buen dia."<<endl;
        }else{
            cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
        }

        system("pause");
    }while(opc!=13);

    delete DESOFT;
    return 0;
}

void GestionEquipos(int n){
    int opc;
    do{
        system("cls");
        cout<<"[1] Agregar Programador."<<endl;
        cout<<"[2] Desvincular Programador."<<endl;
        cout<<"[3] Volver."<<endl<<endl;
        cout<<"[#] OPCION >>>>>  ";cin>>opc;
        system("cls");
        if(opc==1){
            if(DESOFT->CantProgramadores()>0){
                int p;
                DESOFT->DataProgramadores();
                cout<<"[+] Seleccione un Programador."<<endl;
                cout<<"[#] Inserte << Indexado >> ==> ";cin>>p;
                if(p>=1||p<=DESOFT->getCantEmpleados()){
                    if(dynamic_cast<Programador*>(DESOFT->getListaEmpleados(p))){
                        if(DESOFT->getListaEmpleados(p)->Asociado==false){
                            Programador* aux=dynamic_cast<Programador*>(DESOFT->getListaEmpleados(p));
                            DESOFT->getListaEquipos(n)->AggProgramador(aux);
                        }else{
                            cout<<"[#] El programador ya esta asociado a un proyecto."<<endl;
                        }
                    }else{
                        cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                    }
                }else{
                    cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Programadores Disponibles."<<endl;
            }
        }else if(opc==2){
            if(DESOFT->getListaEquipos(n)->getCantProgramadores()>0){
                for(int i=0;i<DESOFT->getListaEquipos(n)->getCantProgramadores();i++){
                    cout<<"<<<< INDEXADO >>>>  ---->>> "<<i+1<<endl;
                    DESOFT->getListaEquipos(n)->getProgramadores(i+1)->DataEmpleado();
                    cout<<"-------------------------------------------------"<<endl;
                }
                int p;
                cout<<"[+] Seleccione un Programador."<<endl;
                cout<<"[#] Inserte << Indexado >> ==> ";cin>>p;
                if(p<1||p>DESOFT->getListaEquipos(n)->getCantProgramadores())
                    cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                else{
                    DESOFT->getListaEquipos(n)->QuitarProgramador(p);
                }
            }else{
                cout<<"[#] No hay Programadores Vinculados a este Equipo."<<endl;
            }
        }else if(opc==3){
            cout<<"[#] Hasta la proxima."<<endl;
        }else{
            cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=3);
}
