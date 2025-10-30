#ifndef CORRESPONDENCIA_H
#define CORRESPONDENCIA_H
#include <iostream>
using namespace std;
class Correspondencia
{
    public:
        Correspondencia(string Nombre,string Direccion,string Remitente);
        virtual ~Correspondencia();
        //-----------------------------------------------------------
        string getNombre();
        string getDireccion();
        string getRemitente();
        float getCosto();
        //-------------------------------------------------------------
        virtual void setCosto()=0;
        //-------------------------------------------------------------
        virtual void DataCorrespondencia();
    protected:
        float Costo;
    private:
        string Nombre;
        string Direccion;
        string Remitente;
};

#endif // CORRESPONDENCIA_H
