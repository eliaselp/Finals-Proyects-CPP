#ifndef ARMA_H
#define ARMA_H
#include <iostream>
using namespace std;

class Arma
{
    public:
        Arma(int NoInventario,string Estado,string Tipo,float ValorArma);
        virtual ~Arma();
        //----------------------------------------------------------------
        float getUtilidad();
        float getPesoPerdida();
        int getNoInventario();
        string getEstado();
        string getTipo();
        float getValorArma();
        //-----------------------------------------
        virtual void DataArma();
        //----------------------------------------
    protected:
        float Utilidad;
        float PesoPerdida;
        virtual void setPesoPerdida()=0;
        virtual void setUtilidad()=0;

    private:
        int NoInventario;
        string Estado;/** USO-PERDIDA-RESERVA*/
        string Tipo;
        float ValorArma;
};

#endif // ARMA_H
