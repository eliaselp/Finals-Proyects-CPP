#include <iostream>
#include <fstream>
#include "Acueducto.h"
#include "Deposito.h"
#include "Tanque.h"
#include "Cisterna.h"
#include "Simple.h"
#include "Compuesta.h"
#include "Equipo.h"
#include "Turbina.h"
#include "Bomba.h"
using namespace std;

Acueducto* Empresa;

int main()
{
    ifstream in;
    in.open("Salva.txt");
    if(!in){
        int CantMaxDepositos; int CantMaxEquipos;
        cout<<"[#] Cantidad Maxima de Depositos: ";cin>>CantMaxDepositos;
        cout<<"[#] Cantidad Maxima de Equipos: ";cin>>CantMaxEquipos;
        Empresa=new Acueducto(CantMaxDepositos,CantMaxEquipos);
    }else{
        int CantMaxDepositos; int CantMaxEquipos;
        in>>CantMaxDepositos>>CantMaxEquipos;
        int CantDepositos,CantEquipos;
        in>>CantDepositos>>CantEquipos;
        Empresa=new Acueducto(CantMaxDepositos,CantMaxEquipos);
        for(int i=0;i<CantDepositos;i++){
            int tipo;in>>tipo;in.ignore();
            if(tipo==1){
                float Capacidad;string Estado;string TipoAbasto;string Material;
                fflush(stdin);in>>Capacidad;in.ignore();
                fflush(stdin);getline(in,Estado);
                fflush(stdin);getline(in,TipoAbasto);
                fflush(stdin);getline(in,Material);
                Tanque*aux=new Tanque(Capacidad,Estado,TipoAbasto,Material);
                Empresa->AggDeposito(aux);
            }else if(tipo==2){
                float Capacidad;string Estado;string TipoAbasto;string Forma;
                fflush(stdin);in>>Capacidad;in.ignore();
                fflush(stdin);getline(in,Estado);
                fflush(stdin);getline(in,TipoAbasto);
                fflush(stdin);getline(in,Forma);
                Simple *aux=new Simple(Capacidad,Estado,TipoAbasto,Forma);
                Empresa->AggDeposito(aux);
            }else if(tipo==3){
                float Capacidad;string Estado;string TipoAbasto;int CantCompartimientos;
                fflush(stdin);in>>Capacidad;in.ignore();
                fflush(stdin);getline(in,Estado);
                fflush(stdin);getline(in,TipoAbasto);
                fflush(stdin);in>>CantCompartimientos;in.ignore();
                Compuesta *aux=new Compuesta(Capacidad,Estado,TipoAbasto,CantCompartimientos);
                Empresa->AggDeposito(aux);
            }
        }
        for(int i=0;i<CantEquipos;i++){
            int Tipo;in>>Tipo;in.ignore();
            if(Tipo==1){
                string Estado;float Regimen;float Tiempo;
                fflush(stdin);getline(in,Estado);
                fflush(stdin);in>>Regimen;
                fflush(stdin);in>>Tiempo;in.ignore();
                Bomba* aux=new Bomba(Estado,Regimen,Tiempo);
                Empresa->AggEquipo(aux);
            }else if(Tipo==2){
                string Estado;float Regimen;float Fuerza;
                fflush(stdin);getline(in,Estado);
                fflush(stdin);in>>Regimen;
                fflush(stdin);in>>Fuerza;in.ignore();
                Turbina* aux=new Turbina(Estado,Regimen,Fuerza);
                Empresa->AggEquipo(aux);
            }
        }
    }
    in.close();
    int opc;
    do{
        system("cls");
        cout<<"###########################\n";
        cout<<"####     ACUEDUCTO     ####\n";
        cout<<"###########################\n\n\n";
        cout<<"[1] Agregar Deposito."<<endl;
        cout<<"[2] Eliminar Deposito."<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"[3] Agregar Equipo."<<endl;
        cout<<"[4] Eliminar Equipo."<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"[5] Data de Depositos #Estado  #Tipo_de_Abasto."<<endl;
        cout<<"[6] Capacidad Depositos Ordenadas por tipo."<<endl;
        cout<<"[7] Cantidad de Equipos y Depositos Disponibles"<<endl;
        cout<<"[8] Mayor Regimen de Bombeo por tipo."<<endl;
        cout<<"[9] Tiempo Promedio de Bombeo de Bombas Buen Estado"<<endl;
        cout<<"[10] Estado de Turbinas de Mayor Fuerza."<<endl;
        cout<<"[11] Capacidad Total Especificada."<<endl;
        cout<<"[12] Salir."<<endl<<endl<<endl;
        cout<<"[#] OPCION ===>> ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Empresa->getCantDepositos()<Empresa->getCantMaxDepositos()){
                int d;
                cout<<"[1] Tanque."<<endl;
                cout<<"[2] Cisterna."<<endl<<endl;
                cout<<"[#] ==>> ";cin>>d;
                system("cls");
                if(d==1){
                    float Capacidad;string Estado;string TipoAbasto;string Material;
                    cout<<"[#] Capacidad: ";
                    fflush(stdin);cin>>Capacidad;
                    int e=1;
                    do{
                        system("cls");
                        if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                        cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                        cout<<"# ==>> ";
                        cin>>e;
                    }while(e<1||e>3);
                    if(e==1)Estado="Bien";
                    else if(e==2)Estado="Regular";
                    else if(e==3)Estado="Mal";
                    cout<<"[#] Tipo de Abasto: ";fflush(stdin);getline(cin,TipoAbasto);

                    int m=1;
                    do{
                        system("cls");
                        if(m<1||m>3)cout<<"### ERROR ###"<<endl;
                        cout<<"[#] Material:   <1>Fibrocemento.   <2>Metal.   <3>Plastico."<<endl;
                        cout<<"# ==>> ";
                        cin>>m;
                    }while(m<1||m>3);
                    if(m==1)Material="Fibrocemento";
                    else if(m==2)Material="Metal";
                    else if(m==3)Material="Plastico";
                    Tanque* aux=new Tanque(Capacidad,Estado,TipoAbasto,Material);
                    Empresa->AggDeposito(aux);
                }else if(d==2){
                    int c;
                    cout<<"[1] Simple."<<endl;
                    cout<<"[2] Compuesta."<<endl<<endl;
                    cout<<"[#] ===>> ";cin>>c;
                    if(c==1){
                        float Capacidad;string Estado;string TipoAbasto;string Forma;
                        cout<<"[#] Capacidad: ";
                        fflush(stdin);cin>>Capacidad;
                        int e=1;
                        do{
                            system("cls");
                            if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                            cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                            cout<<"# ==>> ";
                            cin>>e;
                        }while(e<1||e>3);
                        if(e==1)Estado="Bien";
                        else if(e==2)Estado="Regular";
                        else if(e==3)Estado="Mal";
                        cout<<"[#] Tipo de Abasto: ";fflush(stdin);getline(cin,TipoAbasto);
                        int f=1;
                        do{
                            system("cls");
                            if(f<1||f>3)cout<<"### ERROR ###"<<endl;
                            cout<<"[#] Forma:   <1>Cubica.   <2>Cilindrica."<<endl;
                            cout<<"# ==>> ";
                            cin>>f;
                        }while(f<1||f>2);
                        if(f==1)Forma="Bien";
                        else if(f==2)Forma="Regular";
                        else if(f==3)Forma="Mal";
                        Simple* aux=new Simple(Capacidad,Estado,TipoAbasto,Forma);
                        Empresa->AggDeposito(aux);
                    }else if(c==2){
                        float Capacidad;string Estado;string TipoAbasto;int CantCompartimientos;
                        cout<<"[#] Capacidad: ";
                        fflush(stdin);cin>>Capacidad;
                        int e=1;
                        do{
                            system("cls");
                            if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                            cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                            cout<<"# ==>> ";
                            cin>>e;
                        }while(e<1||e>3);
                        if(e==1)Estado="Bien";
                        else if(e==2)Estado="Regular";
                        else if(e==3)Estado="Mal";
                        cout<<"[#] Tipo de Abasto: ";fflush(stdin);getline(cin,TipoAbasto);
                        cout<<"[#] Cantidad de Compartimientos: ";cin>>CantCompartimientos;
                        Compuesta* aux=new Compuesta(Capacidad,Estado,TipoAbasto,CantCompartimientos);
                        Empresa->AggDeposito(aux);
                    }else cout<<"### ERROR ###"<<endl;
                }else cout<<"### ERROR ###"<<endl;
            }else cout<<"[#] No hay Capacidad para nuevo Deposito."<<endl;
        }else if(opc==2){
            if(Empresa->getCantDepositos()>0){
                cout<<Empresa->DataDeposito();
                cout<<"\n[#] <<INDEXADO>> ==>> ";int n;cin>>n;
                if(n>0&&n<=Empresa->getCantDepositos()){
                    Empresa->EliminarDeposito(n);
                }else cout<<"### ERROR ###"<<endl;
            }else cout<<"[#] No hay Depositos Registrados."<<endl;
        }else if(opc==3){
            if(Empresa->getCantEquipos()<Empresa->getCantMaxEquipos()){
                cout<<"[1] Bomba."<<endl;
                cout<<"[2] Turbina."<<endl;
                cout<<"[#] ==>> ";int t;cin>>t;
                if(t==1){
                    string Estado;float Regimen;float Tiempo;
                    int e=1;
                    do{
                        system("cls");
                        if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                        cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                        cout<<"# ==>> ";
                        cin>>e;
                    }while(e<1||e>3);
                    if(e==1)Estado="Bien";
                    else if(e==2)Estado="Regular";
                    else if(e==3)Estado="Mal";
                    cout<<"[#] Regimen: ";cin>>Regimen;
                    cout<<"[#] Tiempo: ";cin>>Tiempo;
                    Bomba* aux=new Bomba(Estado,Regimen,Tiempo);
                    Empresa->AggEquipo(aux);
                }else if(t==2){
                    string Estado;float Regimen;float Fuerza;
                    int e=1;
                    do{
                        system("cls");
                        if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                        cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                        cout<<"# ==>> ";
                        cin>>e;
                    }while(e<1||e>3);
                    if(e==1)Estado="Bien";
                    else if(e==2)Estado="Regular";
                    else if(e==3)Estado="Mal";
                    cout<<"[#] Regimen: ";cin>>Regimen;
                    cout<<"[#] Fuerza: ";cin>>Fuerza;
                    Turbina* aux=new Turbina(Estado,Regimen,Fuerza);
                    Empresa->AggEquipo(aux);
                }else cout<<"### ERROR ###"<<endl;
            }else cout<<"[#] No hay Capacidad para nuevo Equipo."<<endl;
        }else if(opc==4){
            if(Empresa->getCantEquipos()>0){
                cout<<Empresa->DataEquipo();
                cout<<"\n[#] <<INDEXADO>> ==>> ";int n;cin>>n;
                if(n>0&&n<=Empresa->getCantEquipos()){
                    Empresa->EliminarEquipo(n);
                }else cout<<"### ERROR ###"<<endl;
            }else cout<<"[#] No hay Equipos Registrados."<<endl;
        }else if(opc==5){
            if(Empresa->getCantDepositos()>0){
                string Estado,TipoAbasto;
                int e=1;
                do{
                    system("cls");
                    if(e<1||e>3)cout<<"### ERROR ###"<<endl;
                    cout<<"[#] Estado:   <1>Bien.   <2>Regular.   <3>Mal."<<endl;
                    cout<<"# ==>> ";
                    cin>>e;
                }while(e<1||e>3);
                cout<<"[#] Tipo de Abasto: ";fflush(stdin);getline(cin,TipoAbasto);
                Empresa->InfoDeposito(e,TipoAbasto);
            }else cout<<"[#] No hay Depositos Registrados."<<endl;
        }else if(opc==6){
            if(Empresa->getCantDepositos()>0){
                Empresa->InfoOrdenMaterial();
            }else cout<<"[#] No hay Depositos Registrados."<<endl;
        }else if(opc==7){
            cout<<"[#] Depositos Disponibles: "<<Empresa->getCantDepositos()<<endl;
            cout<<"[#] Equipos Disponibles: "<<Empresa->getCantEquipos()<<endl;
        }else if(opc==8){
            if(Empresa->getCantEquipos()>0){
                Empresa->EquipoMaxRegimen();
            }else cout<<"[#] No hay Equipos disponibles."<<endl;
        }else if(opc==9){
            if(Empresa->getCantEquipos()>0){
                cout<<"[#] Tiempo promedio de Bombas en Buen Estado: "<<Empresa->TiempoPromedioBombaBuenas()<<endl;
            }else cout<<"[#] No hay Equipos disponibles."<<endl;
        }else if(opc==10){
            if(Empresa->CantTurbina()>0){
                Empresa->EstadoTurbinaMaxFuerza();
            }else cout<<"[#] No hay Turbinas Registradas."<<endl;
        }else if(opc==11){
            cout<<"[1] Cisterna Simple."<<endl;
            cout<<"[2] Cisterna Compuesta."<<endl<<endl;
            cout<<"# ===>> ";int n;cin>>n;
            system("cls");
            if(n==1){
                string Forma;fflush(stdin);getline(cin,Forma);
                cout<<"[#] Capacidad Total: "<<Empresa->CapacidadTotalCisternas(Forma);
            }else if(n==2){
                int CantCompartimiento;
                cout<<"[#] Cantidad de Compartimientos: ";cin>>CantCompartimiento;
                Empresa->CapacidadTotalCisternas(CantCompartimiento);
            }else cout<<"### ERROR ###"<<endl;
        }else if(opc==12){
            cout<<"[#] Hasta Pronto.\n";
        }else cout<<"### ERROR ###"<<endl;
        system("pause");
    }while(opc!=12);

    ofstream out;
    out.open("Salva.txt");
    //int CantMaxDepositos, int CantMaxEquipos
    out<<Empresa->getCantMaxDepositos()<<" "<<Empresa->getCantMaxEquipos()<<"\n";
    out<<Empresa->getCantDepositos()<<" "<<Empresa->getCantEquipos()<<"\n";
    for(int i=0;i<Empresa->getCantDepositos();i++){
        if(dynamic_cast<Tanque*>(Empresa->getListaDepositos(i+1))){
            //float Capacidad,string Estado,string TipoAbasto,string Material
            out<<"1\n";
            out<<Empresa->getListaDepositos(i+1)->getCapacidad()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getEstado()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getTipoAbasto()<<"\n";
            Tanque*aux=dynamic_cast<Tanque*>(Empresa->getListaDepositos(i+1));
            out<<aux->getMaterial()<<"\n";
        }else if(dynamic_cast<Simple*>(Empresa->getListaDepositos(i+1))){
            //float Capacidad,string Estado,string TipoAbasto,string Forma
            out<<"2\n";
            out<<Empresa->getListaDepositos(i+1)->getCapacidad()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getEstado()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getTipoAbasto()<<"\n";
            Simple *aux=dynamic_cast<Simple*>(Empresa->getListaDepositos(i+1));
            out<<aux->getForma()<<"\n";
        }else if(dynamic_cast<Compuesta*>(Empresa->getListaDepositos(i+1))){
            out<<"3\n";
            //float Capacidad,string Estado,string TipoAbasto,int CantCompartimientos
            out<<Empresa->getListaDepositos(i+1)->getCapacidad()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getEstado()<<"\n";
            out<<Empresa->getListaDepositos(i+1)->getTipoAbasto()<<"\n";
            Compuesta *aux=dynamic_cast<Compuesta*>(Empresa->getListaDepositos(i+1));
            out<<aux->getCantCompartimientos()<<"\n";
        }
    }

    for(int i=0;i<Empresa->getCantEquipos();i++){
        if(dynamic_cast<Bomba*>(Empresa->getListaEquipos(i+1))){
            out<<"1\n";
            //string Estado,float Regimen,float Tiempo
            out<<Empresa->getListaEquipos(i+1)->getEstado()<<"\n";
            out<<Empresa->getListaEquipos(i+1)->getRegimen()<<"\n";
            Bomba* aux=dynamic_cast<Bomba*>(Empresa->getListaEquipos(i+1));
            out<<aux->getTiempo()<<"\n";
        }else if(dynamic_cast<Turbina*>(Empresa->getListaEquipos(i+1))){
            out<<"2\n";
            //string Estado,float Regimen,float Fuerza
            out<<Empresa->getListaEquipos(i+1)->getEstado()<<"\n";
            out<<Empresa->getListaEquipos(i+1)->getRegimen()<<"\n";
            Turbina* aux=dynamic_cast<Turbina*>(Empresa->getListaEquipos(i+1));
            out<<aux->getFuerza()<<"\n";
        }
    }
    out.close();
    delete Empresa;
    return 0;
}
