#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;

class Usuario
{
    public:
        Usuario(string Nombre, string Direccion, string Telefono);
        virtual ~Usuario();
        ////////////////////////////////////////////////////////
        float getConsumo(int n);
        int getNotPay();
        bool getPay();
        int getMinutos();
        string getNombre();
        string getDireccion();
        string getTelefono();
        int getCategoria();
        float getDeuda(int Mes);
        /////////////////////////////////////////////////////////
        void setMinutos(int Minutos);
        void setPay(bool Pay);
        void setNotPay(int n);
        void setCategoria(int n);
        //////////////////////////////////////////////////////////
        virtual void DataUsuario();
        virtual void setConsumo(int Mes)=0;
        void fConsumo(int M,float C);
    protected:
        float* Consumo;/***/
        int NotPay;/**/
        bool Pay;/**/
        int Minutos;/**/
    private:
        string Nombre;
        string Direccion;
        string Telefono;
        int Categoria;
};

#endif // USUARIO_H
