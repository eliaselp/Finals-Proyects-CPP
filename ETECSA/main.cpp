#include <iostream>
#include "Central.h"

#include "Cliente.h"
#include "Estatal.h"
#include "Residencial.h"

#include "Llamada.h"
#include "Nacional.h"
#include "Internacional.h"
using namespace std;
///////////////////////////////////////////////////////
Central* Planta;

Cliente* Host;
Residencial* HostResidencial;
Estatal* HostEstatal;

Llamada* Salida;
Nacional* SalidaNacional;
Internacional* SalidaInternacional;
//////////////////////////////////////////////////////

void PortalClientes(int n);
int main()
{
    int CantPaises;
    int TeleseleccionProvincial;
    int TeleseleccionInternacional;
    cout<<"[+] Inserte codigo de Teleseleccion INTERPROVINCIAL: ";cin>>TeleseleccionProvincial;
    cout<<"[+] Inserte codigo de Teleseleccion INTERNACIONAL: ";cin>>TeleseleccionInternacional;
    cout<<"[+] Inserte cantidad de Paises disponibles: ";cin>>CantPaises;
    Planta=new Central(CantPaises,TeleseleccionProvincial,TeleseleccionInternacional);
    int opc;
    do{
        system("cls");
        cout<<"**************************************************************"<<endl;
        cout<<"***********  EMPRESA DE TELECOMNICACIONES DE CUBA  ***********"<<endl;
        cout<<"***********               ETECSA.SA                ***********"<<endl;
        cout<<"**************************************************************"<<endl<<endl;


        cout<<"[1] Portal de Cliente."<<endl;
        cout<<"[2] Agregar Nuevo Cliente."<<endl;
        cout<<"[3] Banear Cliente."<<endl;
        cout<<"[4] Activar Cliente."<<endl;
        cout<<"[5] Gestion de Deudas."<<endl;
        cout<<"[6] Cliente Especial."<<endl;
        cout<<"[7] Clientes que usaron Teleseleccion."<<endl;
        cout<<"[8] Salir."<<endl<<endl;
        cout<<"[+] Opcion: ";
        cin>>opc;
        system("cls");
        if(opc==1){
            if(Planta->getCantClientes()>0){
                Planta->DataActivo();
                cout<<"[+] Inserte <<<INDEXADO>>> del Cliente: ----> ";
                int n;cin>>n;
                PortalClientes(n);
            }else{
                cout<<"[#] No hay Clientes Disponibles.";
            }
        }else if(opc==2){
            cout<<"[1] Estatal."<<endl;
            cout<<"[2] Residencial."<<endl;
            cout<<"[#] OPCION: ";int c;cin>>c;
            if(c==1){
                string Nombre;
                string Direccion;
                int CodigoProvincia;
                int Numero;
                bool Arrendada;
                char d;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] Direccion";getline(cin,Direccion);
                fflush(stdin);cout<<"[+] Codigo Provincia: ";cin>>CodigoProvincia;
                fflush(stdin);cout<<"[+] Numero: ";cin>>Numero;
                do{
                    cout<<"[+] Servicio de Arrendandado de Datos S/N: ";cin>>d;
                    if(d=='s'||d=='S')Arrendada=true;
                    else if(d=='n'||d=='N')Arrendada=false;
                }while(d!='s'&& d!='S'&& d=='n'&& d!='N');
                Host=new Estatal(Nombre,Direccion,CodigoProvincia,Numero,Arrendada);
                Planta->AggCliente(Host);
            }else if(c==2){
                string Nombre;
                string Direccion;
                int CodigoProvincia;
                int Numero;
                int CI;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] Direccion";getline(cin,Direccion);
                fflush(stdin);cout<<"[+] Codigo Provincia: ";cin>>CodigoProvincia;
                fflush(stdin);cout<<"[+] Numero: ";cin>>Numero;
                fflush(stdin);cout<<"[+] CI: ";cin>>CI;
                Host=new Residencial(Nombre,Direccion,CodigoProvincia,Numero,CI);
                Planta->AggCliente(Host);
            }else{
                cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
            }
        }else if(opc==3){
            if(Planta->getCantClientes()>0){
                if(Planta->CantActivos()>0){
                    int n;
                    Planta->DataClientes();
                    cout<<"[+] Inserte <<<INDEXADO>>> del Cliente: ----> ";
                    cin>>n;
                    Planta->BanearCliente(n);
                }else{
                    cout<<"[#] No hay cuentas Activas."<<endl;
                }
            }else{
                cout<<"[#] No hay Cuentas Disponibles."<<endl;
            }
        }else if(opc==4){
            if(Planta->getCantClientes()>0){
                if(Planta->CantBaneados()>0){
                    int n;
                    Planta->DataClientes();
                    cout<<"[+] Inserte <<<INDEXADO>>> del Cliente: ----> ";
                    cin>>n;
                    Planta->ActivarCliente(n);
                }else{
                    cout<<"[#] No hay cuentas Baneadas"<<endl;
                }
            }else{
                cout<<"[#] No hay Cuentas Disponibles."<<endl;
            }
        }else if(opc==5){
            if(Planta->getCantClientes()>0){
                int n;
                Planta->DataClientes();
                cout<<"[+] Inserte <<<INDEXADO>>> del Cliente: ----> ";
                cin>>n;
                Planta->Deuda(n);
            }else{
                cout<<"[#] No hay cuentas Baneadas"<<endl;
            }
        }else if(opc==6){
            if(Planta->getCantClientes()>0){
                Planta->ClienteEspecial();
            }else{
                cout<<"[#] No hay cuentas Baneadas"<<endl;
            }
        }else if(opc==7){
            if(Planta->getCantClientes()>0){
                Planta->ListadoClientesTeleseleccion();
            }else{
                cout<<"[#] No hay cuentas Baneadas"<<endl;
            }
        }else if(opc==8){
            cout<<"[#] Que tenga buen dia."<<endl;
        }else{
            cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=8);
    delete Planta;
    return 0;
}




void PortalClientes(int n){
    int opc;
    Host=Planta->getCliente(n);
    cout<<"[1] Realizar Llamada."<<endl;
    bool R=false;
    bool M=false;
    if(dynamic_cast<Residencial*>(Host)){
        R=true;
        HostResidencial=dynamic_cast<Residencial*>(Host);
        cout<<"[2] Activar Servicio de Rastreo."<<endl;
        cout<<"[3] Desactivar Servicio de Rastreo."<<endl;
        cout<<"[4] Solicitar Rastreo."<<endl;
        if(HostResidencial->getMatutino()==true){
            M=true;
            cout<<"[5] Data Matutino Service."<<endl;
            cout<<"[6] Desactivar Matutino Service."<<endl;
        }
    }
    cout<<"[#] Colgar."<<endl<<endl;
    cout<<"[+] Opcion: ";cin>>opc;
    system("cls");
    if(opc==1){
        string call;
        fflush(stdin);
        cout<<"[+] Inserte numero.";getline(cin,call);
        int Diferencial=0;
        int tam=call.size();
        for(int i=0;i<tam;i++){
            if(call[i]=='-')Diferencial++;
        }

        if(Diferencial==0){
            int NumeroReceptor;/*******/
            int pp=call.size()-1;
            for(int i=0;i<tam;i++){
                int x=call[i]-48;
                for(int j=0;j<pp;j++){
                    x=x*10;
                }
                pp--;
                NumeroReceptor+=x;
            }
            int Duracion; /*********/
            cout<<"[+] Duracion: ";cin>>Duracion;
            string Fecha;
            fflush(stdin);
            cout<<"[+] Fecha: ";getline(cin,Fecha);
            int Hora;
            char c;
            int Minuto;
            cout<<"[+] Hora: ";cin>>Hora>>c>>Minuto;
            int CodigoTeleseleccionProvincial=Planta->getTeleseleccionProvincial();
            int CodigoProvinciaReceptor=Host->getCodigoProvincia();
            Salida=new Nacional(Duracion,Host,NumeroReceptor,Hora,Minuto,Fecha,CodigoTeleseleccionProvincial,CodigoProvinciaReceptor);
            Planta->AggLlamada(Salida);
            Salida->getEmisor()->setGasto(Salida->getPrecio());
        }else if(Diferencial==1){
            string Codigo="";
            string Hora="";
            int d;
            for(int i=0;i<tam;i++){
                if(call[i]=='-')d++;
                if(d==0&&call[i]!='-')Codigo+=call[i];
                if(d==1&&call[i]!='-')Hora+=call[i];
            }
            if(Codigo=="077"){
                if(Hora.size()==4){
                    float c=HostResidencial->getGasto();
                    HostResidencial->setGasto(c+1);
                    HostResidencial->setHoraMatutino(Hora);
                }else{
                    cout<<"[#] Su solicitud no se pudo realizar."<<endl;
                }
            }else{
                cout<<"[#] El numero que usted llama no Existe."<<endl;
            }



        }else if(Diferencial==2){
            string Numero="";
            string Teleseleccion="";
            string Provincia="";

            Diferencial=0;
            for(int i=0;i<tam;i++){
                if(call[i]=='-')Diferencial++;
                if(Diferencial==0&&call[i]!='-')Teleseleccion+=call[i];
                if(Diferencial==1&&call[i]!='-')Provincia+=call[i];
                if(Diferencial==2&&call[i]!='-')Numero+=call[i];
            }

            int CodigoTeleseleccionProvincial=0;
            tam=Teleseleccion.size();
            int pp=tam-1;
            for(int i=0;i<tam;i++){
                int x=Teleseleccion[i]-48;
                for(int j=0;j<pp;j++){
                    x=x*10;
                }
                pp--;
                CodigoTeleseleccionProvincial+=x;
            }

            if(Planta->getTeleseleccionProvincial()==CodigoTeleseleccionProvincial){
                int CodigoProvinciaReceptor=0;
                tam=Provincia.size();
                int pp=tam-1;
                for(int i=0;i<tam;i++){
                    int x=Provincia[i]-48;
                    for(int j=0;j<pp;j++){
                        x=x*10;
                    }
                    pp--;
                    CodigoProvinciaReceptor+=x;
                }

                int NumeroReceptor=0;
                tam=Numero.size();
                pp=tam-1;
                for(int i=0;i<tam;i++){
                    int x=Numero[i]-48;
                    for(int j=0;j<pp;j++){
                        x=x*10;
                    }
                    pp--;
                    NumeroReceptor+=x;
                }

                int Duracion;
                cout<<"[+] Duracion: ";cin>>Duracion;
                string Fecha;
                cout<<"[+] Fecha: ";cin>>Fecha;
                int Hora;
                char c;
                int Minuto;
                cout<<"[+] Hora: ";cin>>Hora>>c>>Minuto;
                Salida=new Nacional(Duracion,Host,NumeroReceptor,Hora,Minuto,Fecha,CodigoTeleseleccionProvincial,CodigoProvinciaReceptor);
                Planta->AggLlamada(Salida);
                Salida->getEmisor()->setGasto(Salida->getPrecio());
            }else{
                cout<<"[#] El numero que usted llama no existe."<<endl;
            }
        }else if(Diferencial==3){
            string Teleseleccion="";
            string Pais="";
            string Provincia="";
            string Numero="";
            Diferencial=0;
            for(int i=0;i<tam;i++){
                if(call[i]=='-')Diferencial++;
                if(Diferencial==0&&call[i]!='-')Teleseleccion+=call[i];
                if(Diferencial==1&&call[i]!='-')Pais+=call[i];
                if(Diferencial==2&&call[i]!='-')Provincia+=call[i];
                if(Diferencial==3&&call[i]!='-')Numero+=call[i];
            }
            int CodigoTeleseleccionInternacional=0;
            tam=Teleseleccion.size();
            int pp=tam-1;
            for(int i=0;i<tam;i++){
                int x=Teleseleccion[i]-48;
                for(int j=0;j<pp;j++){
                    x=x*10;
                }
                pp--;
                CodigoTeleseleccionInternacional+=x;
            }


            int CodigoPais=0;
            tam=Pais.size();
            pp=tam-1;
            for(int i=0;i<tam;i++){
                int x=Pais[i]-48;
                for(int j=0;j<pp;j++){
                    x=x*10;
                }
                pp--;
                CodigoPais+=x;
            }
            if(CodigoTeleseleccionInternacional==Planta->getTeleseleccionInternacional()&&Planta->BuscarPais(CodigoPais)==true){
                int CodigoProvinciaReceptor=0;
                tam=Provincia.size();
                pp=tam-1;
                for(int i=0;i<tam;i++){
                    int x=Provincia[i]-48;
                    for(int j=0;j<pp;j++){
                        x=x*10;
                    }
                    pp--;
                    CodigoProvinciaReceptor+=x;
                }

                int NumeroReceptor=0;
                tam=Numero.size();
                pp=tam-1;
                for(int i=0;i<tam;i++){
                    int x=Numero[i]-48;
                    for(int j=0;j<pp;j++){
                        x=x*10;
                    }
                    pp--;
                    NumeroReceptor+=x;
                }
                float Tarifa=Planta->getTarifa(CodigoPais);
                int Duracion;
                cout<<"[#] Duracion: ";cin>>Duracion;
                string Fecha;
                cout<<"[#] Fecha: ";cin>>Fecha;
                int Hora;
                char c;
                int Minuto;
                cout<<"[#] Hora: ";cin>>Hora>>c>>Minuto;
                Salida=new Internacional(Duracion,Host,NumeroReceptor,Hora,Minuto,Fecha,Tarifa,CodigoTeleseleccionInternacional,CodigoPais,CodigoProvinciaReceptor);
                Planta->AggLlamada(Salida);
                Salida->getEmisor()->setGasto(Salida->getPrecio());
            }else{
                cout<<"[#] El numero que usted llama no existe."<<endl;
            }
        }
        Salida=NULL;
        Host=NULL;
    }else if(opc==2&&R==true){
        HostResidencial->setRastreo(true);
    }else if(opc==3&&R==true){
        HostResidencial->setRastreo(false);
    }else if(opc==4&&R==true){
        if(HostResidencial->getRastreo()==true){
            float c=HostResidencial->getGasto();
            HostResidencial->setGasto(c+1);
            Planta->RunRastreo(n);
        }else{
            cout<<"[#] Servicio Desabilitado."<<endl;
        }
    }else if(opc==5&&M==true){
        cout<<"[#] Hora Matutino Service: "<<HostResidencial->getHoraMatutino();
    }else if(opc==6&&M==true){
        HostResidencial->setMatutino(false);
    }
}
