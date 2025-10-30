#ifndef PLANTA_H
#define PLANTA_H
#include<iostream>
#include "Usuario.h"
#include "Estado.h"
#include "Home.h"
#include "Extranjero.h"
using namespace std;

class Planta
{
    public:
        Planta(int UsuariosMax);
        virtual ~Planta();
        //-----------------------------------------------------
        void PoliticaCambio(int MesActual);
        void Pagar(int MesActual,int n,float F);
        //-----------------------------------------------------
        int getCantActivos();
        int getCantCola();
        int getCantBaneados();
        Usuario* getTotalUsuarios(int n);
        float getDepositoMN(int n);
        float getDepositoUSD(int n);
        int getUsuariosMax();
        int getCantReal();
        //-------------------------------------------------------------------------------------
        void fActivo(int n);
        void fCola(int n);
        void fBaneado(int n);

        //-------------------------------------------------------------------------------------
        void AggUsuario(Usuario* nuevo);

        //-----------------------

        void EliminarUsuario(int n);
        //-----------------------------------------------------------------------------------------------
        void setDepositoMN(int Usser,float Gasto);
        void setDepositoUSD(int Usser,float Gasto);
        //-----------------------------------------------------------------------------------------------
        void DataUsuario();
        void DataEstado(int n);
        void DataHome(int n);
        void DataExtranjero(int n);
        void DataPlanta();
        //-----------------------
        void DataBaneados();
        void DataActivos();
        void DataCola();
        //----------------------------------------------------------------------------------------
        int CantEstado(int n);
        int CantHome(int n);
        int CantExtranjero(int n);
        //-----------------------------------------------------------------------------------------
        void Comprobante(string Nombre,string Telefono,int mes);
        void ComprobantePlus(string Nombre,string Telefono,int Cants,int MesActual);
        void UsuariosMaxPromedio(int MesActual);
    protected:
        float setPromedio(int MesActual);
    private:
        int CantActivos;
        int CantCola;
        int CantBaneados;
        Usuario**TotalUsuarios;
        float* DepositoMN;
        float* DepositoUSD;
        int UsuariosMax;
        int CantReal;
        float* Promedio;
};

#endif // PLANTA_H
