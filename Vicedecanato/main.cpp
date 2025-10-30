#include <iostream>
#include "Vicedecanato.h"
#include "Ayudante.h"
#include "Comun.h"
#include "Especial.h"
#include "Estudiante.h"
#include "Asignatura.h"

using namespace std;

Vicedecanato* Juan;
Estudiante* Alumno;
Ayudante* AlumnoAyudante;
Comun* AlumnoComun;
Especial* AlumnoEspecial;
Asignatura* Suspensa;

int main()
{
    int MaxEstudiantes;
    cout<<"[#] Maximos Estudiantes Permitidas: ";cin>>MaxEstudiantes;
    Juan=new Vicedecanato(MaxEstudiantes);
    int opc;
    do{
        system("cls");
        cout<<"************************"<<endl;
        cout<<"**    VICEDECANATO    **"<<endl;
        cout<<"**     FACULTAD 2     **"<<endl;
        cout<<"************************"<<endl<<endl;
        cout<<"[1] Agregar Estudiante."<<endl;
        cout<<"[2] Buscar Estudiante (CI)"<<endl;
        cout<<"[3] Promedio Estudiante (Nombre)"<<endl;
        cout<<"[4] Datos de Estudiante (Nombre)."<<endl;
        cout<<"[5] Listado Posibles Diplomas de ORO."<<endl;
        cout<<"[6] Escalafon."<<endl;
        cout<<"[7] Salir."<<endl<<endl;
        cout<<"[#] OPCION ===>>>> ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Juan->getCantEstudiantes()<Juan->getMaxEstudiantes()){
                int e;
                cout<<"[1] ALUMNO COMUN."<<endl;
                cout<<"[2] ALUMNO AYUDANTE."<<endl;
                cout<<"[3] ALUMNO ESPECIAL."<<endl<<endl;
                cout<<"[#] OPCION ===>>>> ";cin>>e;
                if(e==1){
                    string Nombre;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    string Apellido;
                    fflush(stdin);cout<<"[#] Apellidos: ";getline(cin,Apellido);
                    string CI;
                    fflush(stdin);cout<<"[#] CI: ";getline(cin,CI);
                    string Grupo;
                    fflush(stdin);cout<<"[#] Grupo: ";getline(cin,Grupo);
                    int Anio;
                    fflush(stdin);cout<<"[#] Anio: ";cin>>Anio;
                    bool Proyecto;
                    string NombreProyecto;
                    char c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Proyecto S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')Proyecto=true;
                    else if(c=='N'||c=='n')Proyecto=false;
                    if(Proyecto==true){
                        fflush(stdin);cout<<"[#] Nombre de Proyecto: ";getline(cin,NombreProyecto);
                    }else{
                        Proyecto="";
                    }
                    int CantAsignaturas;
                    cout<<"[#] Cantidad de Asignaturas.";cin>>CantAsignaturas;

                    bool AyudaFinanciera;
                    c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Ayuda Financiera S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')AyudaFinanciera=true;
                    else if(c=='N'||c=='n')AyudaFinanciera=false;
                    Alumno=new Comun(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera);
                    Juan->AggEstudiante(Alumno);
                    Alumno=NULL;
                }else if(e==2){
                    string Nombre;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    string Apellido;
                    fflush(stdin);cout<<"[#] Apellidos: ";getline(cin,Apellido);
                    string CI;
                    fflush(stdin);cout<<"[#] CI: ";getline(cin,CI);
                    string Grupo;
                    fflush(stdin);cout<<"[#] Grupo: ";getline(cin,Grupo);
                    int Anio;
                    fflush(stdin);cout<<"[#] Anio: ";cin>>Anio;
                    bool Proyecto;
                    string NombreProyecto;
                    char c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Proyecto S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')Proyecto=true;
                    else if(c=='N'||c=='n')Proyecto=false;
                    if(Proyecto==true){
                        fflush(stdin);cout<<"[#] Nombre de Proyecto: ";getline(cin,NombreProyecto);
                    }else{
                        Proyecto="";
                    }
                    int CantAsignaturas;
                    cout<<"[#] Cantidad de Asignaturas.";cin>>CantAsignaturas;

                    bool AyudaFinanciera;
                    c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Ayuda Financiera S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')AyudaFinanciera=true;
                    else if(c=='N'||c=='n')AyudaFinanciera=false;
                    int AniosImpartidos;
                    cout<<"[+] Anios Impartidos: ";cin>>AniosImpartidos;
                    int CantAsignaturasImpartidas;
                    cout<<"[+] Cantidad de Asignaturas Impartidas: ";cin>>CantAsignaturasImpartidas;
                    Alumno=new Ayudante(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera,AniosImpartidos,CantAsignaturasImpartidas);
                    Juan->AggEstudiante(Alumno);
                    Alumno=NULL;
                }else if(e==3){
                    string Nombre;
                    fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
                    string Apellido;
                    fflush(stdin);cout<<"[#] Apellidos: ";getline(cin,Apellido);
                    string CI;
                    fflush(stdin);cout<<"[#] CI: ";getline(cin,CI);
                    string Grupo;
                    fflush(stdin);cout<<"[#] Grupo: ";getline(cin,Grupo);
                    int Anio;
                    fflush(stdin);cout<<"[#] Anio: ";cin>>Anio;
                    bool Proyecto;
                    string NombreProyecto;
                    char c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Proyecto S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')Proyecto=true;
                    else if(c=='N'||c=='n')Proyecto=false;
                    if(Proyecto==true){
                        fflush(stdin);cout<<"[#] Nombre de Proyecto: ";getline(cin,NombreProyecto);
                    }else{
                        Proyecto="";
                    }
                    int CantAsignaturas;
                    cout<<"[#] Cantidad de Asignaturas.";cin>>CantAsignaturas;

                    bool AyudaFinanciera;
                    c='s';
                    do{
                        system("cls");
                        if(c!='N'&&c!='n'&&c!='s'&&c!='S')cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                        cout<<"[#] Ayuda Financiera S/N: ";
                        cin>>c;
                    }while(c!='N'&&c!='n'&&c!='s'&&c!='S');
                    if(c=='s'||c=='S')AyudaFinanciera=true;
                    else if(c=='N'||c=='n')AyudaFinanciera=false;
                    int AnioRepetido;
                    cout<<"[+] Anio Repetido: ";cin>>AnioRepetido;
                    //Asignatura
                    string NombreAsig;
                    float NotaFinal;
                    int Semestre;
                    fflush(stdin);cout<<"[+] Asignatura: ";getline(cin,NombreAsig);
                    fflush(stdin);cout<<"[+] Nota Final: ";cin>>NotaFinal;
                    cout<<"[+] Semestre: ";cin>>Semestre;
                    Suspensa=new Asignatura(NombreAsig,NotaFinal,Anio,Semestre);
                    Alumno=new Especial(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera,AnioRepetido,Suspensa);
                    Juan->AggEstudiante(Alumno);
                    Alumno=NULL;
                    Suspensa=NULL;
                }else{
                    cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Disponiblidad para una nueva Matricula."<<endl;
            }
        }else if(opc==2){
            if(Juan->getCantEstudiantes()>0){
                string CI;
                fflush(stdin);cout<<"[+] Inserte Carnet de Identidad: ";getline(cin,CI);
                cout<<"Grupo: "<<Juan->GrupoEstudiante(CI)<<endl;
            }else{
                cout<<"[#] No hay Estudiantes Registrados."<<endl;
            }
        }else if(opc==3){
            if(Juan->getCantEstudiantes()>0){
                string Nombre;
                fflush(stdin);cout<<"[+] Inserte Nombre: ";getline(cin,Nombre);
                cout<<"[#] Promedio: "<<Juan->Promedio(Nombre);
            }else{
                cout<<"[#] No hay Estudiantes Registrados."<<endl;
            }
        }else if(opc==4){
            if(Juan->getCantEstudiantes()>0){
                string Nombre;
                fflush(stdin);cout<<"[+] Inserte Nombre: ";getline(cin,Nombre);
                for(int i=0;i<Juan->getCantEstudiantes();i++){
                    if(Juan->getListaEstudiantes(i+1)->getNombre()==Nombre){
                        if(dynamic_cast<Comun*>(Juan->getListaEstudiantes(i+1)))cout<<"[#] Tipo: Estudiante Comun."<<endl;
                        if(dynamic_cast<Ayudante*>(Juan->getListaEstudiantes(i+1)))cout<<"[#] Tipo: Alumno Ayudante."<<endl;
                        if(dynamic_cast<Especial*>(Juan->getListaEstudiantes(i+1)))cout<<"[#] Tipo: Alumno de Licencia Especial."<<endl;
                        Juan->getListaEstudiantes(i+1)->DataEstudiante();
                    }
                }
            }else{
                cout<<"[#] No hay Estudiantes Registrados."<<endl;
            }
        }else if(opc==5){
            if(Juan->getCantEstudiantes()>0){
                Juan->DiplomaOro();
            }else{
                cout<<"[#] No hay Estudiantes Registrados."<<endl;
            }
        }else if(opc==6){
            if(Juan->getCantEstudiantes()>0){
                Juan->Escalafon();
            }else{
                cout<<"[#] No hay Estudiantes Registrados."<<endl;
            }
        }else if(opc==7){
            cout<<"[#] Hasta Pronto."<<endl;
        }else{
            cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=7);
    return 0;
}
