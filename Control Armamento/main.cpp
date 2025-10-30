#include <iostream>
#include "Policia.h"
#include "Arma.h"
#include "Fuego.h"
#include "Blanca.h"
using namespace std;
Policia* Estacion;
Arma* Armamento;
Fuego* ArmaFuego;
Blanca* ArmaBlanca;
int main()
{
    int PlantillaFuego;
    int PlantillaBlanca;
    cout<<"[+] Plantilla de Armamento de Fuego: ";cin>>PlantillaFuego;
    cout<<"[+] Plantilla de Arma Blanca: ";cin>>PlantillaBlanca;
    Estacion=new Policia(PlantillaFuego,PlantillaBlanca);
    int opc;
    do{
        system("cls");
        cout<<"***********************************************"<<endl;
        cout<<"**********    Estacion de Policia    **********"<<endl;
        cout<<"***********************************************"<<endl<<endl;
        cout<<"[1] Agregar Arma."<<endl;
        cout<<"[2] Eliminar Arma."<<endl;
        cout<<"[3] Completamiento por Tipo"<<endl;
        cout<<"[4] Perdidas Por Tipo"<<endl;
        cout<<"[5] Reservas por Tipo."<<endl;
        cout<<"[6] Tipo Armamento Mayor Perdida"<<endl;
        cout<<"[7] Tipo Armamento Mayor Reserva"<<endl;
        cout<<"[8] Tipo Armamento menos Completamiento."<<endl;
        cout<<"[9] Buscar tipo de Arma."<<endl;
        cout<<"[10] Gestion de Estado de Arma"<<endl;
        cout<<"[11] Peso de Perdida de Arma."<<endl;
        cout<<"[12] Utilidad de Arma."<<endl;
        cout<<"[13] Cantidad de Armas por Tipo."<<endl;
        cout<<"[14] Fichero."<<endl;
        cout<<"[15] Salir."<<endl<<endl;
        cout<<"[+] OPCION: ";cin>>opc;
        system("cls");
        if(opc==1){
            cout<<"[1] Fuego."<<endl;
            cout<<"[2] Blanca."<<endl;
            cout<<"[#]>>>>> ";int n;cin>>n;
            if(n==1){
                if(Estacion->getCantFuego()<Estacion->getPlantillaFuego()){
                    int NoInventario;
                    cout<<"[+] Numero de Inventario: ";cin>>NoInventario;
                    string Estado;
                    int d;
                    do{
                        system("cls");
                        cout<<"[#] ESTADO >>> [1]->Uso [2]->Perdida [3]->Reserva"<<endl;
                        cout<<">>>> ";cin>>d;
                        if(d==1)Estado="USO";
                        else if(d==2)Estado="PERDIDA";
                        else if(d==3)Estado="RESERVA";
                        else cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
                        system("pause");
                    }while(d>3||d<1);
                    string Tipo;
                    do{
                        system("cls");
                        cout<<"[#] TIPO >>> [1]->Pistola [2]->Escopeta"<<endl;
                        cout<<">>>> ";cin>>d;
                        if(d==1)Tipo="PISTOLA";
                        else if(d==2)Tipo="ESCOPETA";
                        else cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
                        system("pause");
                    }while(d>2||d<1);
                    system("cls");
                    float ValorArma;
                    cout<<"[+] Valor del Arma: ";cin>>ValorArma;
                    float Calibre;
                    cout<<"[+] Calibre: ";cin>>Calibre;
                    bool Cargador;
                    int CantBalas;
                    char c;
                    do{
                        cout<<"[+] Cargador S/N: ";cin>>c;
                        if(c=='s'||c=='S'){
                            Cargador=true;
                            cout<<"[+] Cantidad de balas del Cargador: ";
                            cin>>CantBalas;
                        }else if(c=='n'||c=='N'){
                            Cargador=false;
                            CantBalas=0;
                        }else{
                            cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
                        }
                    }while(c!='n'&&c!='N'&&c!='s'&&c!='S');
                    int AlcanceMax;
                    cout<<"[+] Alcance Maximo: ";cin>>AlcanceMax;
                    float LongitudCannon;
                    cout<<"[+] Longitud del Cannon: ";cin>>LongitudCannon;
                    Armamento=new Fuego(NoInventario,Estado,Tipo,ValorArma,Calibre,Cargador,CantBalas,AlcanceMax,LongitudCannon);
                    Estacion->AggArma(Armamento);
                }else{
                    cout<<"[#] La Plantilla esta Completa."<<endl;
                }
            }else if(n==2){
                if(Estacion->getCantBlanca()<Estacion->getPlantillaBlanca()){
                    int NoInventario;
                    cout<<"[+] Numero de Inventario: ";cin>>NoInventario;
                    string Estado;
                    int d;
                    do{
                        system("cls");
                        cout<<"[#] ESTADO >>> [1]->Uso [2]->Perdida [3]->Reserva"<<endl;
                        cout<<">>>> ";cin>>d;
                        if(d==1)Estado="USO";
                        else if(d==2)Estado="PERDIDA";
                        else if(d==3)Estado="RESERVA";
                        else cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
                        system("pause");
                    }while(d>3||d<1);
                    string Tipo;
                    do{
                        system("cls");
                        cout<<"[#] TIPO >>> [1]->Cuchillo [2]->Bayoneta [3]->Machete"<<endl;
                        cout<<">>>> ";cin>>d;
                        if(d==1)Tipo="CUCHILLO";
                        else if(d==2)Tipo="BAYONETA";
                        else if(d==3)Tipo="MACHETE";
                        else cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
                        system("pause");
                    }while(d>3||d<1);
                    system("cls");
                    float ValorArma;
                    cout<<"[+] Valor del Arma: ";cin>>ValorArma;
                    string Material;
                    fflush(stdin);cout<<"[+] Material: ";getline(cin,Material);
                    float ValorMaterial;
                    cout<<"[+] Valor del Material: ";cin>>ValorMaterial;
                    int Peligrosidad;
                    cout<<"[#] Peligrosidad: ";
                    cin>>Peligrosidad;
                    Armamento=new Blanca(NoInventario,Estado,Tipo,ValorArma,Material,ValorMaterial,Peligrosidad);
                    Estacion->AggArma(Armamento);
                }else{
                    cout<<"[#] La Plantilla esta Completa."<<endl;
                }
            }else{
                cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
            }
        }else if(opc==2){
            if(Estacion->getCantBlanca()+Estacion->getCantFuego()>0){
                Estacion->DataArmas();
                cout<<"[#] Inserte Indexado >>>> ";
                int n;cin>>n;
                Estacion->EliminarArma(n);
            }else{
                cout<<"[#] No hay Armas Disponibles."<<endl;
            }
        }else if(opc==3){
            Estacion->Completamiento();
        }else if(opc==4){
            if(Estacion->getCantReal()>0){
                Estacion->PerdidaTipo();
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==5){
            if(Estacion->getCantReal()>0){
                Estacion->ReservaTipo();
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==6){
            if(Estacion->getCantReal()>0){
                Estacion->TipoMayorPerdida();
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==7){
            if(Estacion->getCantReal()>0){
                Estacion->TipoMayorReserva();
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==8){
            if(Estacion->getCantReal()>0){
                Estacion->MinCompletamiento();
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==9){
            if(Estacion->getCantReal()>0){
                string tipo;
                cout<<"[+] Inserte Tipo de Arma: ";
                fflush(stdin);getline(cin,tipo);
                if(Estacion->BuscarTipoArma(tipo)==true){
                    cout<<"[#] Si existe."<<endl;
                }else{
                    cout<<"[#] No existe."<<endl;
                }
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==10){
            cout<<"[#] Inserte el numero de inventario";
            int Inventario;cin>>Inventario;
            cout<<"[#] "<<Estacion->GestionEstado(Inventario)<<endl;
        }else if(opc==11){
            if(Estacion->getCantReal()>0){
                Estacion->DataArmas();
                cout<<"[#] <<<IDENTADO>>>  --->> ";
                int n;cin>>n;
                cout<<"[#] Peso de Perdida: "<<Estacion->GestionPerdida(n)<<endl;
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==12){
            if(Estacion->getCantReal()>0){
                Estacion->DataArmas();
                cout<<"[#] <<<IDENTADO>>>  --->> ";
                int n;cin>>n;
                cout<<"[#] Utilidad: "<<Estacion->GestionUtilidad(n)<<endl;
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==13){
            if(Estacion->getCantReal()>0){
                cout<<"[+] Armas de Fuego: "<<Estacion->getCantFuego()<<endl;
                cout<<"[+] Armas Blanca: "<<Estacion->getCantBlanca()<<endl;
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==14){
            if(Estacion->getCantReal()>0){
                cout<<"[#] TENGA PIEDAD."<<endl;
            }else{
                cout<<"[#] No hay Armamento Registrado."<<endl;
            }
        }else if(opc==15){
            cout<<"[#] Que tenga buen dia."<<endl;
        }else{
            cout<<"<<<<<<<   ERROR    >>>>>>>"<<endl;
        }

        system("pause");
    }while(opc!=15);
    return 0;
}
