#include <bits/stdc++.h>
#include "Office.h"
#include "Correspondencia.h"
#include "Telegrama.h"
#include "Carta.h"
#include "Bulto.h"
using namespace std;

Correspondencia* Salida;
Telegrama* TelegramaSalida;
Carta* CartaSalida;
Bulto* BultoSalida;




int main()
{
    int MaxBuzon;
    cout<<"#>>>> Inserte Capacidad del Buzon: ";
    cin>>MaxBuzon;
    Office* Oficina=new Office(MaxBuzon);

    int opc;
    do{
        system("cls");
        cout<<"********************************************************"<<endl;
        cout<<"*****************  OFICINA DE CORREOS  *****************"<<endl;
        cout<<"********************************************************"<<endl<<endl;

        cout<<"[1] Agregar Nueva Correspondencia."<<endl;
        cout<<"[2] Despachar Correspondencia."<<endl;
        cout<<"[3] Entrega Personal."<<endl;
        cout<<"[4] Cant Telegramas Max Plabras (Valor Dado)."<<endl;
        cout<<"[5] Cartas Por Remitente."<<endl;
        cout<<"[6] Correspondencia mas Recibida"<<endl;
        cout<<"[7] Telegrama Ordenado Remitente"<<endl;
        cout<<"[8] Protocolo de Cierre de Dia."<<endl;
        cout<<"[9] Salir. "<<endl<<endl;
        cout<<"[+] Opcion: ";
        cin>>opc;
        system("cls");
        if(opc==1){
            if(Oficina->getCantBuzon()<Oficina->getMaxBuzon()){
                cout<<"[1] Telegrama."<<endl;
                cout<<"[2] Carta."<<endl;
                cout<<"[3] Bulto Postal."<<endl<<endl;
                int NC;
                cout<<"[+] Opcion: ";cin>>NC;
                if(NC>0&&NC<4){
                    string Nombre;
                    string Direccion;
                    string Remitente;
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                    fflush(stdin);cout<<"[+] Remitente: ";getline(cin,Remitente);
                    if(NC==1){
                        int CantPalabras;
                        float Impuesto;
                        cout<<"[+] Cantidad de Palabras: ";cin>>CantPalabras;
                        cout<<"[+] Impuesto: ";cin>>Impuesto;
                        Salida=new Telegrama(Nombre,Direccion,Remitente,CantPalabras,Impuesto);
                        Oficina->AggCorrespondencia(Salida);
                        Salida=NULL;
                    }else if(NC==2){
                        bool Ext;
                        char C;
                        string Fecha;
                        fflush(stdin);cout<<"[+] Fecha: ";getline(cin,Fecha);
                        do{
                            cout<<"[+] Proveniente del Exterior? S/N: ";cin>>C;
                            if(C=='s'||C=='S')Ext=true;
                            else if(C=='N'||C=='n')Ext=false;
                        }while(C!='s'&& C!='S'&& C!='N'&& C!='n');
                        Salida=new Carta(Nombre,Direccion,Remitente,Fecha,Ext);
                        Oficina->AggCorrespondencia(Salida);
                    }else if(NC==3){
                        float Peso;
                        int Urgencia;
                        cout<<"[+] Peso: ";cin>>Peso;
                        cout<<"[+] Urgencia: [1] Urgente <<<<<>>>> [2] Media.  <<<<<>>>>  [3] Indiferente."<<endl;
                        cout<<"[#] >>>>>>>  ";cin>>Urgencia;
                        Salida=new Bulto(Nombre,Direccion,Remitente,Peso,Urgencia);
                        Oficina->AggCorrespondencia(Salida);
                    }else{
                        cout<<"[#] Opcion Invalida."<<endl;
                    }
                }
            }else{
                cout<<"[#] Buzon Lleno. Vuelva mas tarde"<<endl;
            }
        }else if(opc==2){
            if(Oficina->getCantBuzon()>0){
                Oficina->DespacharCorrespondencia();
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==3){
            if(Oficina->getCantBuzon()>0){
                string Nombre;
                string Direccion;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                Oficina->EntregaPersonal(Nombre,Direccion);
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==4){
            if(Oficina->getCantBuzon()>0){
                if(Oficina->CantTelegrama()>0){
                    int Palabras;
                    cout<<"[+] Inserte Cantidad de Palabras: ";cin>>Palabras;
                    cout<<"Cantidad: "<<Oficina->TelegramaMaxPalabra(Palabras)<<endl;
                }else{
                    cout<<"[#] No hay Telegramas en el Buzon."<<endl;
                }
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==5){
            if(Oficina->getCantBuzon()>0){
                if(Oficina->CantCarta()>0){
                    string Nombre;
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    cout<<"Cantidad de Cartas: "<<Oficina->CartasRemitente(Nombre)<<endl;
                }else{
                    cout<<"[#] No hay Cartas en el buzon."<<endl;
                }
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==6){
            if(Oficina->getCantBuzon()>0){
                Oficina->MaxCorrespondencia();
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==7){
            if(Oficina->getCantBuzon()>0){
                if(Oficina->CantTelegrama()>0){
                    Oficina->TelegramaOrdenRemitente();
                }else{
                    cout<<"[#] No hay Telegramas en el Buzon."<<endl;
                }
            }else{
                cout<<"[#] >>> Buzon Vacio."<<endl;
            }
        }else if(opc==8){
            Oficina->FinDia();
        }else if(opc==9){
            cout<<"[#] >>>> Que tenga buen dia."<<endl;
        }else{
            cout<<"[#] Opcion Invalida."<<endl;
        }

        system("pause");
    }while(opc!=8);
    return 0;
}
