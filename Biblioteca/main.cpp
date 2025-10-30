#include <fstream>
#include <iostream>
#include "Biblioteca.h"
#include "Material.h"
#include "Libro.h"
#include "Comun.h"
#include "Infantil.h"
#include "Revista.h"
#include "Usuario.h"
//--------------------------------------
Biblioteca* Marti;
Material* Doc;
Usuario* Cliente;

using namespace std;
void SeccionUsuario(int n);
int main()
{
    ifstream in;
    in.open("Salva.txt");
    if(!in){
        int MaxClientes;
        int MaxMateriales;
        int MaxPedidos;
        float MaxPeso;

        cout<<"[+] Maximo de Clientes Permitidos: ";cin>>MaxClientes;
        cout<<"[+] Maximo de Materiales Permitidos: ";cin>>MaxMateriales;
        cout<<"[+] Maximo de Pedidos Permitidos en Biblioteca: ";cin>>MaxPedidos;
        cout<<"[+] Maximo Peso Acumulado por Clientes: ";cin>>MaxPeso;
        Marti=new Biblioteca(MaxClientes,MaxMateriales,MaxPedidos,MaxPeso);
    }else{
        int MaxClientes;int MaxMateriales;int MaxPedidos;float MaxPeso;
        in>>MaxClientes>>MaxMateriales>>MaxPedidos>>MaxPeso;
        int CantClientes,CantMateriales,CantPedidos,CantHistorico;
        in>>CantClientes>>CantMateriales>>CantPedidos>>CantHistorico;in.ignore();
        Marti=new Biblioteca(MaxClientes,MaxMateriales,MaxPedidos,MaxPeso);
        Marti->setCantHistorico(CantHistorico);
        for(int i=0;i<CantClientes;i++){
            string Nombre;string CI;string Direccion;string Tipo;string FechaVencimiento="";float PesoAcumulado;
            fflush(stdin);getline(in,Nombre);
            fflush(stdin);getline(in,CI);
            fflush(stdin);getline(in,Direccion);
            fflush(stdin);getline(in,Tipo);
            if(Tipo=="EVENTUAL"){fflush(stdin);getline(in,FechaVencimiento);}
            in>>PesoAcumulado;
            Usuario* nuevo=new Usuario(Nombre,CI,Direccion,Tipo,FechaVencimiento);
            nuevo->PesoAcumulado=PesoAcumulado;
            Marti->AggCliente(nuevo);
            nuevo=NULL;
        }
        for(int i=0;i<Marti->getCantMateriales();i++){
            int tipo;in>>tipo;in.ignore();
            if(tipo==1){
                string Titulo;string Codigo;int AnioIngreso;int MesesPublicacion;string Pais;
                fflush(stdin);getline(in,Titulo);
                fflush(stdin);getline(in,Codigo);
                fflush(stdin);cin>>AnioIngreso;
                fflush(stdin);cin>>MesesPublicacion;in.ignore();
                fflush(stdin);getline(in,Pais);
                Revista* aux=new Revista(Titulo,Codigo,AnioIngreso,MesesPublicacion,Pais);
                Marti->AggMaterial(aux);
            }else if(tipo==2){
                string Titulo;string Codigo;int AnioIngreso;string Autor;string Genero;int AnioPublicacion;
                fflush(stdin);getline(in,Titulo);
                fflush(stdin);getline(in,Codigo);
                fflush(stdin);cin>>AnioIngreso;in.ignore();
                fflush(stdin);getline(in,Autor);
                fflush(stdin);getline(in,Genero);
                fflush(stdin);cin>>AnioPublicacion;in.ignore();
                Comun* aux=new Comun(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion);
                Marti->AggMaterial(aux);
            }else if(tipo==3){
                string Titulo;string Codigo;int AnioIngreso;string Autor;string Genero;int AnioPublicacion;bool Fotos;int Mayor;int Menor;
                fflush(stdin);getline(in,Titulo);
                fflush(stdin);getline(in,Codigo);
                fflush(stdin);cin>>AnioIngreso;in.ignore();
                fflush(stdin);getline(in,Autor);
                fflush(stdin);getline(in,Genero);
                fflush(stdin);cin>>AnioPublicacion;
                in>>Fotos>>Mayor>>Menor;in.ignore();
                Infantil* aux=new Infantil(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion,Fotos,Mayor,Menor);
                Marti->AggMaterial(aux);
            }
        }
        for(int i=0;i<Marti->getCantPedidos();i++){
            int ClientNum;
            int DocNum;
            in>>ClientNum>>DocNum;
            Marti->RealizarPedido(ClientNum,DocNum);
        }
        string DataHistorial="";
        string Temp;
        while(getline(in,Temp)){
            DataHistorial+=Temp;
        }
        Marti->setArchivoHistorico(DataHistorial);
    }
    in.close();
    int opc;
    do{
        system("cls");
        cout<<"*****************************************"<<endl;
        cout<<"*****     BIBLIOTECA JOSE MARTI     *****"<<endl;
        cout<<"*****************************************"<<endl<<endl;
        cout<<"[1] Agregar Material."<<endl;
        cout<<"[2] Eliminar Material"<<endl;
        cout<<"[3] Agregar Usuario."<<endl;
        cout<<"[4] Eliminar Usuario."<<endl;
        cout<<"[5] Agregar Usuario Eventual al Archivo Historico."<<endl;
        cout<<"[6] Mostrar Archivo Historico."<<endl;
        cout<<"[7] Reestablecer Peso Acumulado Maximo."<<endl;
        cout<<"[8] Mostrar Datos de un Material."<<endl;
        cout<<"[9] Mostrar Pedido de Usuario."<<endl;
        cout<<"[10] PORTAL DE USUARIO."<<endl;
        cout<<"[11] Salir."<<endl<<endl;
        cout<<"[#] OPCION >>>>> ==>  ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Marti->getCantMateriales()<Marti->getMaxMateriales()){
                int m;
                cout<<"[1] Libro"<<endl;
                cout<<"[2] Revista."<<endl<<endl;
                cout<<"[#] OPCION >>>>> ==>  ";cin>>m;
                system("cls");
                if(m==1){
                    int l;
                    cout<<"[1] Para Adultos."<<endl;
                    cout<<"[2] Infantil."<<endl<<endl;
                    cout<<"[#] OPCION >>>>> ==>  ";cin>>l;
                    system("cls");
                    if(l==1){
                        string Titulo;
                        string Codigo;
                        int AnioIngreso;
                        string Autor;
                        string Genero;
                        int AnioPublicacion;
                        fflush(stdin);cout<<"[+] Titulo: ";getline(cin,Titulo);
                        fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                        fflush(stdin);cout<<"[+] Anios de Ingresado: ";cin>>AnioIngreso;
                        fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
                        fflush(stdin);cout<<"[+] Genero: ";getline(cin,Genero);
                        fflush(stdin);cout<<"[+] Anios de Publicado: ";cin>>AnioPublicacion;
                        Doc=new Comun(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion);
                        Marti->AggMaterial(Doc);
                        Doc=NULL;
                    }else if(l==2){
                        string Titulo;
                        string Codigo;
                        int AnioIngreso;
                        string Autor;
                        string Genero;
                        int AnioPublicacion;
                        bool Fotos;
                        int Mayor;
                        int Menor;
                        fflush(stdin);cout<<"[+] Titulo: ";getline(cin,Titulo);
                        fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                        fflush(stdin);cout<<"[+] Anios de Ingresado: ";cin>>AnioIngreso;
                        fflush(stdin);cout<<"[+] Autor: ";getline(cin,Autor);
                        fflush(stdin);cout<<"[+] Genero: ";getline(cin,Genero);
                        fflush(stdin);cout<<"[+] Anios de Publicado: ";cin>>AnioPublicacion;
                        char c='n';
                        do{
                            system("cls");
                            if(c!='s'&&c!='S'&&c!='n'&&c!='N')cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                            fflush(stdin);cout<<"[+] Tiene Imagenes?  S/N: ";cin>>c;
                            if(c=='s'||c=='S')Fotos=true;
                            else if(c=='n'||c=='N')Fotos=false;
                        }while(c!='s'&&c!='S'&&c!='n'&&c!='N');
                        cout<<"[+] Rango de Edad: "<<endl;
                        cout<<"[+] Edad Minima: ";cin>>Mayor;
                        cout<<"[+] Edad Maxima: ";cin>>Menor;
                        Doc=new Infantil(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion,Fotos,Mayor,Menor);
                        Marti->AggMaterial(Doc);
                        Doc=NULL;
                    }else{
                        cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                    }
                }else if(m==2){
                    string Titulo;
                    string Codigo;
                    int AnioIngreso;
                    int MesesPublicacion;
                    string Pais;
                    fflush(stdin);cout<<"[+] Titulo: ";getline(cin,Titulo);
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Anios de Ingresado: ";cin>>AnioIngreso;
                    fflush(stdin);cout<<"[+] Meses de Publicado: ";cin>>MesesPublicacion;
                    fflush(stdin);cout<<"[+] Pais: ";getline(cin,Pais);fflush(stdin);
                    Doc=new Revista(Titulo,Codigo,AnioIngreso,MesesPublicacion,Pais);
                    Marti->AggMaterial(Doc);
                    Doc=NULL;
                }else{
                    cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                }
            }
        }else if(opc==2){
            if(Marti->getCantMateriales()>0){
                int n;
                Marti->DataMateriales();
                cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>n;
                if(n<1||n>Marti->getCantMateriales())cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                else{
                    Marti->EliminarMaterial(n);
                }
            }else{
                cout<<"[#] No hay Materiaes Registrados."<<endl;
            }
        }else if(opc==3){
            if(Marti->getCantClientes()<Marti->getMaxClientes()){
                string Nombre;
                string CI;
                string Direccion;
                string Tipo;
                string FechaVencimiento;
                fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                fflush(stdin);cout<<"[+] CI: ";getline(cin,CI);
                fflush(stdin);cout<<"[+] Direccion: ";getline(cin,Direccion);
                int n;
                do{
                    system("cls");
                    if(n<1||n>2)cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                    cout<<"[+] Tipo:   [1] Permanente.        [2] Eventual."<<endl;
                    cout<<"[#] OPCION >>>>> ==>  ";cin>>n;
                    if(n==1)Tipo="PERMANENTE";
                    else if(n==2)Tipo="EVENTUAL";
                }while(n<1||n>2);
                fflush(stdin);cout<<"[+] Fecha de Vencimiento.";getline(cin,FechaVencimiento);
                Cliente=new Usuario(Nombre,CI,Direccion,Tipo,FechaVencimiento);
                Marti->AggCliente(Cliente);
                Cliente=NULL;
            }else{
                cout<<"[#] No hay Capacidad para nuevo Cliente."<<endl;
            }
        }else if(opc==4){
            if(Marti->getCantClientes()>0){
                int n=1;
                Marti->DataClientes();
                cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>n;
                if(n<1||n>Marti->getCantClientes())cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                else Marti->EliminarCliente(n);
            }else{
                cout<<"[#] No hay Usuarios Registrados."<<endl;
            }
        }else if(opc==5){
            if(Marti->getCantClientes()>0){
                if(Marti->CantEventuales()>0){
                    int n=1;
                    Marti->DataEventual();
                    cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>n;
                    if(n<1||n>Marti->getCantClientes())cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                    else Marti->AggHistorial(n);
                }else{
                    cout<<"[#] No hay Clientes Eventuales."<<endl;
                }
            }else{
                cout<<"[#] No hay Usuarios Registrados."<<endl;
            }
        }else if(opc==6){
            if(Marti->getCantHistorico()>0){
                if(Marti->getCantHistorico()>0){
                    cout<<Marti->getArchivoHistorico();
                }else{
                    cout<<"[#] No hay Clientes en el Archivo Historico."<<endl;
                }
            }else{
                cout<<"[#] No hay Usuarios Registrados."<<endl;
            }
        }else if(opc==7){
            cout<<"[+] Nuevo Peso Acumulado Maximo Permitido: ";
            float MaxPeso;cin>>MaxPeso;
            Marti->setMaxPeso(MaxPeso);
        }else if(opc==8){
            if(Marti->getCantMateriales()>0){
                string Codigo;
                fflush(stdin);cout<<"[+] Inserte Codigo del Material: ";getline(cin,Codigo);
                Marti->DataMateriales(Codigo);
            }else{
                cout<<"[#] No hay Materiales Registrados."<<endl;
            }
        }else if(opc==9){
            if(Marti->getCantClientes()>0){
                string CI;
                fflush(stdin);cout<<"[+] Inserte CI del Cliente: ";getline(cin,CI);
                Marti->DataPrestamo(CI);
            }else{
                cout<<"[#] No hay Usuarios Registrados."<<endl;
            }
        }else if(opc==10){
            if(Marti->getCantClientes()>0){
                int n;
                do{
                    system("cls");
                    Marti->DataClientes();
                    if(n<1||n>Marti->getCantClientes())cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                    cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>n;
                }while(n<1||n>Marti->getCantClientes());
                SeccionUsuario(n);
            }else{
                cout<<"[#] No hay Usuarios Registrados."<<endl;
            }
        }else if(opc==11){
            cout<<"********************************"<<endl;
            cout<<"*******     GOOD BYE     *******"<<endl;
            cout<<"********************************"<<endl<<endl;
        }else{
            cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=11);
    /**int MaxClientes,int MaxMateriales,int MaxPedidos,float MaxPeso**/
    ofstream out;
    out.open("Salva.txt");
    out<<Marti->getMaxClientes()<<" "<<Marti->getMaxMateriales()<<" "<<Marti->getMaxPedidos()<<" "<<Marti->getMaxPeso()<<"\n";
    out<<Marti->getCantClientes()<<" "<<Marti->getCantMateriales()<<" "<<Marti->getCantPedidos()<<"\n";
    out<<Marti->getCantHistorico()<<"\n";
    for(int i=0;i<Marti->getCantClientes();i++){
        //string Nombre,string CI,string Direccion,string Tipo,string FechaVencimiento,pesoAcumulado
        out<<Marti->getListaClientes(i+1)->getNombre()<<"\n";
        out<<Marti->getListaClientes(i+1)->getCI()<<"\n";
        out<<Marti->getListaClientes(i+1)->getDireccion()<<"\n";
        out<<Marti->getListaClientes(i+1)->getTipo()<<"\n";
        if(Marti->getListaClientes(i+1)->getTipo()=="EVENTUAL")out<<Marti->getListaClientes(i+1)->getFechaVencimiento()<<"\n";
        out<<Marti->getListaClientes(i+1)->PesoAcumulado<<"\n";
    }

    for(int i=0;i<Marti->getCantMateriales();i++){
        if(dynamic_cast<Revista*>(Marti->getListaMateriales(i+1))){
            out<<"1\n";
            //string Titulo,string Codigo,int AnioIngreso,int MesesPublicacion,string Pais
            Revista* aux=dynamic_cast<Revista*>(Marti->getListaMateriales(i+1));
            out<<aux->getTitulo()<<"\n"<<aux->getCodigo()<<"\n"<<aux->getAnioIngreso()<<"\n"<<aux->getMesesPublicacion()<<"\n"<<aux->getPais()<<"\n";
        }else if(dynamic_cast<Comun*>(Marti->getListaMateriales(i+1))){
            out<<"2\n";
            //string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion
            Comun* aux=dynamic_cast<Comun*>(Marti->getListaMateriales(i+1));
            out<<aux->getTitulo()<<"\n"<<aux->getCodigo()<<"\n"<<aux->getAnioIngreso()<<"\n"<<aux->getAutor()<<"\n"<<aux->getGenero()<<"\n"<<aux->getAnioPublicacion()<<"\n";
        }else if(dynamic_cast<Infantil*>(Marti->getListaMateriales(i+1))){
            out<<"3\n";
            //string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion,bool Fotos,int Mayor,int Menor
            Infantil* aux=dynamic_cast<Infantil*>(Marti->getListaMateriales(i+1));
            out<<aux->getTitulo()<<"\n"<<aux->getCodigo()<<"\n"<<aux->getAnioIngreso()<<"\n"<<aux->getAutor()<<"\n"<<aux->getGenero()<<"\n"<<aux->getAnioPublicacion()<<"\n";
            out<<aux->getFotos()<<" "<<aux->getMayor()<<" "<<aux->getMenor()<<"\n";
        }
    }

    for(int i=0;i<Marti->getCantPedidos();i++){
        int ClientNum;
        for(int j=0;j<Marti->getCantClientes();j++){
            if(Marti->getListaPedidos(i+1)->getCliente()->getCI()==Marti->getListaClientes(j+1)->getCI())ClientNum=j+1;
        }

        int DocNum;
        for(int j=0;j<Marti->getCantMateriales();j++){
            if(Marti->getListaPedidos(i+1)->getDoc()->getCodigo()==Marti->getListaMateriales(j+1)->getCodigo())DocNum=j+1;
        }
        out<<ClientNum<<" "<<DocNum<<"\n";
    }
    out<<Marti->getArchivoHistorico()<<"\n";
    out.close();
    delete Marti;
    return 0;
}


void SeccionUsuario(int n){
    int opc;
    do{
        system("cls");
        cout<<"[1] Realizar Pedido."<<endl;
        cout<<"[2] Entregar Material."<<endl;
        cout<<"[3] Ver Mi Prestamo."<<endl;
        cout<<"[4] Volver. "<<endl<<endl;
        cout<<"[#] OPCION >>>>> ==>  ";cin>>opc;
        if(opc==1){
            if(Marti->getCantMateriales()>0){
                if(Marti->CantMaterialesDisponibles()>0){
                    int m=1;
                    do{
                        Marti->DataMateriales();
                        if(m<1||m>Marti->getCantMateriales())cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                        cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>m;
                    }while(m<1||m>Marti->getCantMateriales());
                    Marti->RealizarPedido(n,m);
                }else{
                    cout<<"[#] No hay materiales Disponibles."<<endl;
                }
            }else{
                cout<<"Biblioteca Vacia."<<endl;
            }
        }else if(opc==2){
            if(Marti->CantPrestamoUsuario(Marti->getListaClientes(n)->getCI())>0){
                int p;
                bool Confirm=true;
                do{
                    system("cls");
                    Marti->DataPrestamo(Marti->getListaClientes(n)->getCI());
                    if(Confirm==false)cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
                    cout<<"[+] Inserte << INDEXADO >>  ==>> ";cin>>p;
                    if(p<1||p>Marti->getCantPedidos()){
                        if(Marti->getListaPedidos(p)->getCliente()->getCI()==Marti->getListaClientes(n)->getCI())Confirm=true;
                    }
                }while(Confirm==false);
                Marti->HacerEntrega(p);
            }else{
                cout<<"[#] El cliente no ha realizado Pedidos."<<endl;
            }
        }else if(opc==3){
            Marti->DataPrestamo(Marti->getListaClientes(n)->getCI());
        }else{
            cout<<"<<<<<<<    ERROR    >>>>>>>"<<endl;
        }
        system("pause");
    }while(opc!=4);
}
