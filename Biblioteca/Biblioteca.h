#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include "Usuario.h"
#include "Material.h"
#include "Libro.h"
#include "Comun.h"
#include "Infantil.h"
#include "Revista.h"
#include "Pedido.h"
using namespace std;

class Biblioteca
{
    public:
        Biblioteca(int MaxClientes,int MaxMateriales,int MaxPedidos,float MaxPeso);
        virtual ~Biblioteca();
        //----------------------------------------------------------------------
        float getMaxPeso();
        int getMaxClientes();
        int getCantClientes();
        Usuario* getListaClientes(int n);
        int getMaxMateriales();
        int getCantMateriales();
        Material* getListaMateriales(int n);
        int getMaxPedidos();
        int getCantPedidos();
        Pedido* getListaPedidos(int n);
        int getCantHistorico();
        string getArchivoHistorico();
        //---------------------------------------------------------
        void setArchivoHistorico(string Data);
        void setCantHistorico(int CantHistorico);
        //---------------------------------------------------------
        int CantLibros();
        int CantComun();
        int CantInfantil();
        int CantRevista();
        int CantEventuales();
        int CantPrestamoUsuario(string CI);
        int CantMaterialesDisponibles();
        //------------------------------------------------------
        void DataLibros();
        void DataComun();
        void DataInfantil();
        void DataRevista();
        void DataMateriales();

        void DataMateriales(string Codigo);
        void DataPrestamo(string CI);
        void DataEventual();
        void DataClientes();
        //---------------------------------------------------------
        void AggCliente(Usuario* nuevo);
        void EliminarCliente(int n);
        void AggHistorial(int n);

        void AggMaterial(Material* nuevo);
        void EliminarMaterial(int n);

        void setMaxPeso(float MaxPeso);
        void RealizarPedido(int n, int m);
        void HacerEntrega(int n);


    protected:

    private:
        float MaxPeso;

        int MaxClientes;
        int CantClientes;
        Usuario** ListaClientes;

        int CantHistorico;
        string ArchivoHistorico;

        int MaxMateriales;
        int CantMateriales;
        Material** ListaMateriales;

        int MaxPedidos;
        int CantPedidos;
        Pedido** ListaPedidos;

};

#endif // BIBLIOTECA_H
