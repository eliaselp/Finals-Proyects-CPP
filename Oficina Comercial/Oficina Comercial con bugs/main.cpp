#include <iostream>
#include <fstream>
#include "Planta.h"
#include "Despacho.h"
#include "Usuario.h"
#include "Home.h"
#include "Estado.h"
#include "Extranjero.h"
using namespace std;
Despacho* Servidor;
Planta* Equipo;
Usuario* Host;
Home* HostHome;
Estado* HostEstado;
Extranjero* HostExtranjero;

void SeccionPlantas(int n);
void SeccionUsuario(int n,int c);
int main()
{
    ifstream in;
    in.open("Salva.dat");
    if(!in){
        int CantMaxPlantas;
        int MesActual=1;
        cout<<"[#] Cantidad Maxima de Plantas Permitida: ";
        cin>>CantMaxPlantas;
        do{
            system("cls");
            if(MesActual<1||MesActual>12)cout<<"<<<<<<  ERROR  >>>>>>>"<<endl;
            cout<<"[#] Mes Actual: ";
            cin>>MesActual;
        }while(MesActual<1||MesActual>12);
        Servidor=new Despacho(CantMaxPlantas,MesActual);
    }else{
        int CantMaxPlantas;int MesActual;int CantPlantas;
        in>>CantMaxPlantas>>MesActual>>CantPlantas;
        Servidor=new Despacho(CantMaxPlantas,MesActual);
        for(int i=0;i<CantPlantas;i++){
            int UsuariosMax;in>>UsuariosMax;
            int CantActivos;int CantCola;int CantBaneados;int CantReal;
            in>>CantActivos>>CantCola>>CantBaneados>>CantReal;
            Planta* nuevaPlanta=new Planta(UsuariosMax);
            Servidor->AggPlanta(nuevaPlanta);
            float MN[CantReal];float USD[CantReal];
            for(int j=0;j<CantReal;j++){
                in>>MN[j]>>USD[j];
            }
            Servidor->getPlantas(i+1)->fActivo(CantActivos);
            Servidor->getPlantas(i+1)->fCola(CantCola);
            Servidor->getPlantas(i+1)->fBaneado(CantBaneados);

            for(int j=0;j<CantReal;j++){
                int tipo;in>>tipo;in.ignore();
                if(tipo==1){
                    string Nombre;string Direccion;string Telefono;string Empresa;
                    fflush(stdin);getline(in,Nombre);
                    fflush(stdin);getline(in,Direccion);
                    fflush(stdin);getline(in,Telefono);
                    fflush(stdin);getline(in,Empresa);
                    Estado* aux=new Estado(Nombre,Direccion,Telefono,Empresa);
                    Servidor->getPlantas(i+1)->AggUsuario(aux);
                    int aux2=Servidor->getPlantas(i+1)->getCantActivos()-1;
                    Servidor->getPlantas(i+1)->fActivo(aux2);
                }else if(tipo==2){
                    string Nombre;string Direccion;string Telefono;
                    fflush(stdin);getline(in,Nombre);
                    fflush(stdin);getline(in,Direccion);
                    fflush(stdin);getline(in,Telefono);
                    Extranjero* aux=new Extranjero(Nombre,Direccion,Telefono);
                    Servidor->getPlantas(i+1)->AggUsuario(aux);
                    int aux2=Servidor->getPlantas(i+1)->getCantActivos()-1;
                    Servidor->getPlantas(i+1)->fActivo(aux2);
                }else if(tipo==3){
                    string Nombre; string Direccion; string Telefono;string CI;
                    fflush(stdin);getline(in,Nombre);
                    fflush(stdin);getline(in,Direccion);
                    fflush(stdin);getline(in,Telefono);
                    fflush(stdin);getline(in,CI);
                    Home* aux=new Home(Nombre,Direccion,Telefono,CI);
                    Servidor->getPlantas(i+1)->AggUsuario(aux);
                    int aux2=Servidor->getPlantas(i+1)->getCantActivos()-1;
                    Servidor->getPlantas(i+1)->fActivo(aux2);
                }
                for(int k=0;k<12;k++){
                    float c;in>>c;
                    Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->fConsumo(k,c);
                }
                int NotPay;in>>NotPay;
                Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->setNotPay(NotPay);
                bool Pay;in>>Pay;
                Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->setPay(Pay);
                int Minutos;in>>Minutos;
                Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->setMinutos(Minutos);
                int Categoria;in>>Categoria;
                Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->setCategoria(Categoria);

                Servidor->getPlantas(i+1)->setDepositoMN(j,MN[j]);
                Servidor->getPlantas(i+1)->setDepositoUSD(j,USD[j]);
            }
        }
    }
    int opc;
    do{
        ofstream out;
        out.open("Salva.dat");
        //int CantMaxPlantas,int MesActual,CantPlantas
        out<<Servidor->getCantMaxPlantas()<<" "<<Servidor->getMesActual()<<" "<<Servidor->getCantPlantas()<<"\n";
        for(int i=0;i<Servidor->getCantPlantas();i++){
            //int UsuariosMax
            out<<Servidor->getPlantas(i+1)->getUsuariosMax()<<" "<<Servidor->getPlantas(i+1)->getCantActivos()<<" ";
            out<<Servidor->getPlantas(i+1)->getCantCola()<<" "<<Servidor->getPlantas(i+1)->getCantBaneados()<<" "<<Servidor->getPlantas(i+1)->getCantReal()<<"\n";
            for(int j=0;j<Servidor->getPlantas(i+1)->getCantReal();j++){
                out<<Servidor->getPlantas(i+1)->getDepositoMN(j+1)<<" ";
                out<<Servidor->getPlantas(i+1)->getDepositoUSD(j+1)<<" ";
            }
            for(int j=0;j<Servidor->getPlantas(i+1)->getCantReal();j++){
                if(dynamic_cast<Estado*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1))){
                    out<<"1\n";
                    //string Nombre, string Direccion, string Telefono,string Empresa
                    Estado* aux=dynamic_cast<Estado*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1));
                    out<<aux->getNombre()<<"\n";
                    out<<aux->getDireccion()<<"\n";
                    out<<aux->getTelefono()<<"\n";
                    out<<aux->getEmpresa()<<"\n";
                }else if(dynamic_cast<Extranjero*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1))){
                    out<<"2\n";
                    Extranjero* aux=dynamic_cast<Extranjero*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1));
                    out<<aux->getNombre()<<"\n";
                    out<<aux->getDireccion()<<"\n";
                    out<<aux->getTelefono()<<"\n";
                }else if(dynamic_cast<Home*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1))){
                    out<<"3\n";
                    //string Nombre, string Direccion, string Telefono,string CI
                    Home* aux=dynamic_cast<Home*>(Servidor->getPlantas(i+1)->getTotalUsuarios(j+1));
                    out<<aux->getNombre()<<"\n";
                    out<<aux->getDireccion()<<"\n";
                    out<<aux->getTelefono()<<"\n";
                    out<<aux->getCI()<<"\n";
                }
                for(int k=0;k<12;k++){
                    out<<Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->getConsumo(k+1)<<" ";
                }
                out<<"\n"<<Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->getNotPay()<<" ";
                out<<Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->getPay()<<" ";
                out<<Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->getMinutos()<<" ";
                out<<Servidor->getPlantas(i+1)->getTotalUsuarios(j+1)->getCategoria()<<"\n";
            }
        }
        out.close();
        system("cls");
        cout<<"**************************************************"<<endl;
        cout<<"********    SERVIDOR OFICINA COMERCIAL    ********"<<endl;
        cout<<"**************************************************"<<endl<<endl;
        cout<<"*** MES "<<Servidor->getMesActual()<<" ***"<<endl;
        cout<<"[1] Seccion de Gestion de Plantas"<<endl;
        cout<<"[2] Agregar Planta."<<endl;
        cout<<"[3] Eliminar Planta."<<endl;
        cout<<"[4] Mostrar Datos de Usuarios Baneados."<<endl;
        cout<<"[5] Mostrar Datos de Usuarios por Planta."<<endl;
        cout<<"[6] Mostrar Datos de Usuarios Pasados del Promedio."<<endl;
        cout<<"[7] PROTOCOLO DE CIERRE DE MES."<<endl;
        cout<<"[8] Salir."<<endl<<endl;
        cout<<"[#] OPCION >>>>>>  ";
        cin>>opc;
        system("cls");
        if(opc==1){
            if(Servidor->getCantPlantas()>0){
                Servidor->DataPlantas();
                cout<<"Inserte Numero de Planta: ";int n;cin>>n;
                if(n>0&&n<=Servidor->getCantPlantas())SeccionPlantas(n);
                else cout<<"<<<<<<  ERROR  >>>>>>>"<<endl;
            }else{
                cout<<"[#] No hay plantas Agregadas."<<endl;
            }
        }else if(opc==2){
            if(Servidor->getCantPlantas()<Servidor->getCantMaxPlantas()){
                int UsuariosMax;
                cout<<"[#] Inserte Cantidad maxima de Usuarios Permitida: ";
                cin>>UsuariosMax;
                Equipo=new Planta(UsuariosMax);
                Servidor->AggPlanta(Equipo);
                Equipo=NULL;
            }else{
                cout<<"[#] No hay capacidad para nueva Planta."<<endl;
            }
        }else if(opc==3){
            if(Servidor->getCantPlantas()>0){
                Servidor->DataPlantas();
                int p;
                cout<<"[+] Inserte Numero de la Planta: ";
                cin>>p;
                if(p>0&&p<=Servidor->getCantPlantas())Servidor->EliminarPlanta(p);
                else cout<<"<<<<<<  ERROR  >>>>>>>"<<endl;
            }else{
                cout<<"[#] No hay plantas Agregadas."<<endl;
            }
        }else if(opc==4){
            if(Servidor->getCantPlantas()>0){
                Servidor->DataBaneados();
            }else{
                cout<<"[#] No hay plantas Agregadas."<<endl;
            }
        }else if(opc==5){
            if(Servidor->getCantPlantas()>0){
                for(int i=0;i<Servidor->getCantPlantas();i++){
                    cout<<"*************"<<endl;
                    cout<<"*  Planta  "<<i+1<<"*"<<endl;
                    cout<<"*************"<<endl<<endl;
                    cout<<"*** ACTIVOS ***"<<endl;
                    Servidor->getPlantas(i+1)->DataActivos();
                    cout<<"\n*** EN COLA ***"<<endl;
                    Servidor->getPlantas(i+1)->DataCola();
                    cout<<"\n*** BANEADOS ***"<<endl;
                    Servidor->getPlantas(i+1)->DataBaneados();
                }
            }else{
                cout<<"[#] No hay plantas Agregadas."<<endl;
            }
        }else if(opc==6){
            if(Servidor->getCantPlantas()>0){
                Servidor->MayorPromedio();
            }else{
                cout<<"[#] No hay plantas Agregadas."<<endl;
            }
        }else if(opc==7){
            if(Servidor->getCantPlantas()>0){
                Servidor->setMesActual();
            }else{
                cout<<"[#] No hay Planta disponibles."<<endl;
            }
        }else if(opc==8){
            cout<<"Tengan Piedad. Me quede Calvo"<<endl;
        }else{
            cout<<"<<<<<<  ERROR  >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=8);
    return 0;
}

void SeccionPlantas(int n){
    int opc;
    do{
        system("cls");
        cout<<"******************************************"<<endl;
        cout<<"********    SECCION DE PLANTAS    ********"<<endl;
        cout<<"******************************************"<<endl<<endl;

        cout<<"[1] Agregar Usuario."<<endl;
        cout<<"[2] Eliminar Usuario."<<endl;
        cout<<"[3] Portal Usuarios."<<endl;
        cout<<"[4] Comprobante de Pago Mes Actual"<<endl;
        cout<<"[5] Comprobante Historial de Pago."<<endl;
        cout<<"[6] Usuarios Consumo Mayor del Promedio."<<endl;
        cout<<"[7] Salir."<<endl<<endl;
        cout<<"[#] OPCION >>>>>>  ";
        cin>>opc;
        system("cls");
        if(opc==1){
            if(Servidor->getPlantas(n)->getCantReal()<Servidor->getPlantas(n)->getUsuariosMax()){
                cout<<"[1] Estado."<<endl;
                cout<<"[2] Extranjero."<<endl;
                cout<<"[3] Home."<<endl;
                int c;cin>>c;
                if(c==1){
                    string Nombre;
                    string Direccion;
                    string Telefono;
                    string Empresa;
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                    fflush(stdin);cout<<"[+] Telefono: ";getline(cin,Telefono);
                    fflush(stdin);cout<<"[+] Empresa: ";getline(cin,Empresa);
                    Host=new Estado(Nombre,Direccion,Telefono,Empresa);
                    Servidor->getPlantas(n)->AggUsuario(Host);
                }else if(c==2){
                    string Nombre;
                    string Direccion;
                    string Telefono;
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                    fflush(stdin);cout<<"[+] Telefono: ";getline(cin,Telefono);
                    Host=new Extranjero(Nombre,Direccion,Telefono);
                    Servidor->getPlantas(n)->AggUsuario(Host);
                }else if(c==3){
                    string Nombre;
                    string Direccion;
                    string Telefono;
                    string CI;
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                    fflush(stdin);cout<<"[+] Telefono: ";getline(cin,Telefono);
                    fflush(stdin);cout<<"[+] Identificacion Permanente: ";getline(cin,CI);
                    Host=new Home(Nombre,Direccion,Telefono,CI);
                    Servidor->getPlantas(n)->AggUsuario(Host);
                }else {
                    cout<<"<<<<<  ERROR  >>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Capacidad para nuevo Usuario."<<endl;
            }
        }else if(opc==2){
            if(Servidor->getPlantas(n)->getCantReal()>0){
                Servidor->getPlantas(n)->DataActivos();
                Servidor->getPlantas(n)->DataCola();
                Servidor->getPlantas(n)->DataBaneados();
                cout<<"\n Inserte << INDEXADO >> :";int c;cin>>c;
                if(c>0&&c<=Servidor->getPlantas(n)->getCantReal())
                    Servidor->getPlantas(n)->EliminarUsuario(c);
                else cout<<"<<<<<  ERROR  >>>>>"<<endl;
            }else{
                cout<<"[#] No hay Usuarios registrados."<<endl;
            }
        }else if(opc==3){
            if(Servidor->getPlantas(n)->getCantReal()>0){
                Servidor->getPlantas(n)->DataActivos();
                Servidor->getPlantas(n)->DataCola();
                Servidor->getPlantas(n)->DataBaneados();
                cout<<"[#] Insertar NUMERO de Usuario: ";
                int c;cin>>c;
                if(c>0&&c<=Servidor->getPlantas(n)->getCantReal())SeccionUsuario(n,c);
                else cout<<"<<<<<  ERROR  >>>>>"<<endl;
            }else{
                cout<<"[#] No hay Usuarios en la Planta."<<endl;
            }
        }else if(opc==4){
            if(Servidor->getPlantas(n)->getCantReal()>0){
                string Nombre,Telefono;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] Telefono: ";getline(cin,Telefono);
                Servidor->getPlantas(n)->Comprobante(Nombre,Telefono,Servidor->getMesActual());
            }else cout<<"[#] No hay Usuarios registrados."<<endl;
        }else if(opc==5){
            if(Servidor->getPlantas(n)->getCantReal()>0){
                cout<<"[#] Cantidad de Meses a Buscar: ";int Meses;cin>>Meses;
                string Nombre,Telefono;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] Telefono: ";getline(cin,Telefono);
                Servidor->getPlantas(n)->ComprobantePlus(Nombre,Telefono,Meses,Servidor->getMesActual());
            }else cout<<"[#] No hay Usuarios registrados."<<endl;
        }else if(opc==6){
            if(Servidor->getPlantas(n)->getCantReal()>0){
                if(Servidor->getPlantas(n)->getCantReal()>0){
                    Servidor->getPlantas(n)->UsuariosMaxPromedio(Servidor->getMesActual());
                }else{
                    cout<<"[#] No hay Usuarios registrados."<<endl;
                }
            }else cout<<"[#] No hay Usuarios registrados."<<endl;
        }else if(opc==7){
            cout<<"[#] Que tenga un buen dia"<<endl;
        }else{
            cout<<"<<<<<<   ERROR  >>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=7);
}






void SeccionUsuario(int n,int c){
    system("cls");
    Servidor->getPlantas(n)->getTotalUsuarios(c)->DataUsuario();
    cout<<"\n\n[1] Hacer Llamada."<<endl;
    cout<<"[2] Pagar"<<endl;
    cout<<"[3] Volver."<<endl;
    int opc;
    cout<<"[#] OPCION: ";cin>>opc;
    system("cls");
    if(opc==1){
        if(Servidor->getPlantas(n)->getTotalUsuarios(c)->getCategoria()==1){
            int Minutos;
            cout<<"[#] Inserte Cantidad de Minutos: ";cin>>Minutos;
            if(Minutos>0){
                Minutos+=Servidor->getPlantas(n)->getTotalUsuarios(c)->getMinutos();
                Servidor->getPlantas(n)->getTotalUsuarios(c)->setMinutos(Minutos);
                Servidor->getPlantas(n)->getTotalUsuarios(c)->setConsumo(Servidor->getMesActual());
            }else cout<<"<<<<<  ERROR  >>>>>"<<endl;
        }else cout<<"[#] Usted no tiene acceso al servicio solicitado."<<endl;
    }else if(opc==2){
        if(Servidor->getPlantas(c)->getTotalUsuarios(c)->getPay()==false){
            if(Servidor->getPlantas(c)->getTotalUsuarios(c)->getDeuda(Servidor->getMesActual())>0){
                float Monto;
                float f;
                Servidor->getPlantas(n)->getTotalUsuarios(c)->DataUsuario();
                cout<<"\n[#] Deposito: ";
                if(dynamic_cast<Estado*>(Servidor->getPlantas(n)->getTotalUsuarios(c))||dynamic_cast<Home*>(Servidor->getPlantas(n)->getTotalUsuarios(c))){
                    cout<<Servidor->getPlantas(n)->getDepositoMN(c)<<" CUP";
                    f=Servidor->getPlantas(n)->getDepositoMN(c);
                }else{
                    cout<<Servidor->getPlantas(n)->getDepositoUSD(c)<<" USD";
                    f=Servidor->getPlantas(n)->getDepositoUSD(c);
                }
                cout<<"\n[#] Deuda: "<<Servidor->getPlantas(n)->getTotalUsuarios(c)->getDeuda(Servidor->getMesActual());
                cout<<"\n\n[#] Insertar Monto >>> ";cin>>Monto;
                Monto+=f;
                system("cls");
                if(f>=0){
                    cout<<Monto<<endl;system("pause");
                    Servidor->getPlantas(n)->Pagar(Servidor->getMesActual(),n,Monto);
                }else{
                    cout<<"<<<<<<<   ERROR   >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] Usted no tiene Deuda."<<endl;
            }
        }else{
            cout<<"[#] Usted ya realizo su pago mensual."<<endl;
        }
    }else if(opc==3){
        cout<<"[#] Hasta Pronto."<<endl;
    }else{
        cout<<"<<<<<  ERROR  >>>>>"<<endl;
    }
    return;
}

