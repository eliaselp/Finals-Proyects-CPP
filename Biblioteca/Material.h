#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
using namespace std;

class Material
{
    public:
        int Prestamos;
        Material(string Titulo,string Codigo,int AnioIngreso);
        virtual ~Material();
        //-------------------------------------------------------
        string getTitulo();
        string getCodigo();
        int getAnioIngreso();
        int getPrestamos();
        bool getPrestado();
        float getFactorEstancia();
        float getPesoAsociado();
        //-----------------------------------------------------------
        virtual void DataMaterial();
        virtual void setFactorEstancia()=0;
        void setPesoAsociado();
        void setPrestado(bool Prestado);

    protected:
        float PesoAsociado;
        float FactorEstancia;
    private:
        string Titulo;
        string Codigo;
        int AnioIngreso;
        bool Prestado;
};

#endif // MATERIAL_H
