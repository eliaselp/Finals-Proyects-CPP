#include <bits/stdc++.h>
//--------------------------------
#include "Programa.h"
#include "Genero.h"
//---------------------------------
#include "Rock.h"
#include "RockProgresivo.h"
#include "HeavyMetal.h"
#include "BluesRock.h"
//--------------------------------
#include "Salsa.h"
#include "POP.h"
//---------------------------------
using namespace std;
Programa* CMKC;
Genero* Cancion;
Rock* CancionRock;
RockProgresivo* CancionRockProgresivo;
HeavyMetal* CancionHeavyMetal;
BluesRock* CancionBluesRock;
Salsa* CancioSalsa;
POP* CancionPOP;




bool CrearCancion();
int main()
{
    int CantMaxCanciones;
    cout<<"Inserte Cantidad Maxima de Canciones del Programa: ";cin>>CantMaxCanciones;
    CMKC=new Programa(CantMaxCanciones);
    int opc;
    do{
        system("cls");
        cout<<"[1] Agregar Cancion."<<endl;
        cout<<"[2] Eliminar Cancion."<<endl;
        cout<<"[3] Datos de Cancion mas Larga."<<endl;
        cout<<"[4] Cantidad de Pop con ACM."<<endl;
        cout<<"[5] Datos Rock Mayor Aceptacion."<<endl;
        cout<<"[6] Duracion Lista de Reproduccion."<<endl;
        cout<<"[7] Datos Canciones de Mayor Voto (Valor Dado)."<<endl;
        cout<<"[8] Datos Canciones menor Duracion (Valor Dado)."<<endl;
        cout<<"[9] Data Lista de Reproduccion."<<endl;
        cout<<"[10] Salir"<<endl<<endl;
        cout<<"[+] Opcion: ";
        cin>>opc;
        system("cls");

        if(opc==1){
            if(CMKC->getCantCanciones()<CantMaxCanciones){
                if(CrearCancion()==true) CMKC->AggCancion(Cancion);
            }else{
                cout<<"[#] No hay Capacidad para una nueva Cancion."<<endl;
            }
        }
        if(opc==2){
            CMKC->DataReproduccion();
            cout<<"[+] Digite el numero de la Cancion en la Lista: ";
            int del;cin>>del;
            CMKC->EliminarCancion(del);
        }
        if(opc==3){
            if(CMKC->getCantCanciones()>0){
                CMKC->DataMaxDuracion();
            }
        }
        if(opc==4){
            if(CMKC->CantPOP()>0){
                cout<<"[#] Cantidad de Canciones pop con acompaniamiento Musical: "<<CMKC->CantPopACM()<<endl;
            }
        }
        if(opc==5){
            CMKC->DataRockMaxAccepted();
        }
        if(opc==6){
            cout<<"[#] Duracion de Lista de Reproduccion: "<<CMKC->TotalTime()<<endl;
        }
        if(opc==7){
            int Votos;
            cout<<"[+] Inserte numero de votos: ";cin>>Votos;
            CMKC->DataPlusVotos(Votos);
        }
        if(opc==8){
            int Time;
            cout<<"[+] Inserte Duracion a Evaluar: ";
            cin>>Time;
            CMKC->DataListMinTime(Time);
        }
        if(opc==9){
            CMKC->DataReproduccion();
        }

        system("pause");
    }while(opc!=10);
    return 0;
}

bool CrearCancion(){
    int opc;
    do{
        system("cls");
        cout<<"[1] Rock."<<endl;
        cout<<"[2] Salsa."<<endl;
        cout<<"[3] POP."<<endl;
        cout<<"[4] Cancelar"<<endl<<endl;
        cout<<"[+] Opcion: ";
        cin>>opc;
        system("cls");
        if(opc==1){
            int opc2;
            do{
                system("cls");
                cout<<"[1] Heavy Metal"<<endl;
                cout<<"[2] Blues Rock."<<endl;
                cout<<"[3] Rock Progresivo."<<endl;
                cout<<"[4] Salir."<<endl<<endl;
                cout<<"[+] Opcion: ";
                cin>>opc2;
                system("cls");
                if(opc2==1){
                    int Duracion;
                    string Autor;
                    int Anio;
                    int Votos;
                    int CantDiscos;

                    cout<<"[+] Duracion: ";cin>>Duracion;
                    fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
                    cout<<"[+] Anio: ";cin>>Anio;
                    cout<<"[+] Votos: ";cin>>Votos;
                    cout<<"[+] Cantidad de discos: ";cin>>CantDiscos;
                    Cancion=new HeavyMetal(Duracion,Autor,Anio,Votos,CantDiscos);
                }
                if(opc2==2){
                    int Duracion;
                    string Autor;
                    int Anio;
                    int Votos;
                    int CantDiscos;
                    cout<<"[+] Duracion: ";cin>>Duracion;
                    fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
                    cout<<"[+] Anio: ";cin>>Anio;
                    cout<<"[+] Votos: ";cin>>Votos;
                    cout<<"[+] Cantidad de discos: ";cin>>CantDiscos;
                    Cancion=new BluesRock(Duracion,Autor,Anio,Votos,CantDiscos);
                }
                if(opc2==3){
                    int Duracion;
                    string Autor;
                    int Anio;
                    int Votos;
                    int CantDiscos;
                    cout<<"[+] Duracion: ";cin>>Duracion;
                    fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
                    cout<<"[+] Anio: ";cin>>Anio;
                    cout<<"[+] Votos: ";cin>>Votos;
                    cout<<"[+] Cantidad de discos: ";cin>>CantDiscos;
                    Cancion=new RockProgresivo(Duracion,Autor,Anio,Votos,CantDiscos);
                }
            }while(opc<1||opc>4);
        }
        if(opc==2){
            int Duracion;
            string Autor;
            int Anio;
            int Votos;
            int CantDiscos;
            string Estilo;

            cout<<"[+] Duracion: ";cin>>Duracion;
            fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
            cout<<"[+] Anio: ";cin>>Anio;
            cout<<"[+] Votos: ";cin>>Votos;
            cout<<"[+] Cantidad de Discos: ";cin>>CantDiscos;
            fflush(stdin);cout<<"[+] Estilo: ";getline(cin,Estilo);
            Cancion=new Salsa(Duracion,Autor,Anio,Votos,CantDiscos,Estilo);
        }
        if(opc==3){
            int Duracion;
            string Autor;
            int Anio;
            int Votos;
            int CantDiscos;
            bool ACM;
            char c;
            cout<<"[+] Duracion: ";cin>>Duracion;
            fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
            cout<<"[+] Anio: ";cin>>Anio;
            cout<<"[+] Votos: ";cin>>Votos;
            cout<<"[+] Cantidad de Discos: ";cin>>CantDiscos;
            do{
                fflush(stdin);
                cout<<"[+] Acompannamiento Musical S/N: ";cin>>c;
                if(c=='s'||c=='S')ACM=true;
                if(c=='N'||c=='n')ACM=false;

            }while(c!='s'&& c!='S'&& c!='N'&& c!='n');
            Cancion=new POP(Duracion,Autor,Anio,Votos,CantDiscos,ACM);
        }
    }while(opc<1||opc>4);
    if(opc>0&&opc<4)return true;
    else return false;
}
