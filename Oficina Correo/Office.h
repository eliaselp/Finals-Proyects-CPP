#ifndef OFFICE_H
#define OFFICE_H
#include <iostream>
#include "Correspondencia.h"
#include "Carta.h"
#include "Telegrama.h"
#include "Bulto.h"
using namespace std;

class Office
{
    public:
        Office(int MaxBuzon);
        virtual ~Office();
    //-----------------------------------------------------------
        Correspondencia* getBuzon(int n);
        int getCantBuzon();
        int getMaxBuzon();
        float getGanancia();
    //------------------------------------------------------------
    void setGanancia();
    //-------------------------------------------------------------
        int CantCarta();
        int CantTelegrama();
        int CantBulto();
    //------------------------------------------------------------
        void AggCorrespondencia(Correspondencia* nueva);
        void DespacharCorrespondencia();
        void EntregaPersonal(string Nombre, string Direccion);
        int TelegramaMaxPalabra(int n);
        int CartasRemitente(string Remitente);
        void MaxCorrespondencia();
        void TelegramaOrdenRemitente();
        void FinDia();
    protected:

    private:
        Correspondencia** Buzon;
        int CantBuzon;
        int MaxBuzon;
        float Ganancia;

};

#endif // OFFICE_H
