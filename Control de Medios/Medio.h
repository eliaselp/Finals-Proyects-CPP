#ifndef MEDIO_H
#define MEDIO_H
#include <iostream>
using namespace std;

class Medio
{
    public:
        Medio(string Inventario,float CostoUnitario,string Estado);
        virtual ~Medio();
        /***********/
        string getInventario();
        float getCostoUnitario();
        string getEstado();
        float getCostoReal();
        string getTipo();

        /***********/
        virtual void setCostoReal()=0;
        virtual void INFO();
    protected:
        float CostoReal;
        string Tipo;
    private:
        string Inventario;
        float CostoUnitario;
        string Estado;
};

#endif // MEDIO_H
