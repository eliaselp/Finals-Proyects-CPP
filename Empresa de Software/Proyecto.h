#ifndef PROYECTO_H
#define PROYECTO_H
#include <iostream>
using namespace std;
class Proyecto
{
    public:
        bool Asignado;
        Proyecto(string Nombre,string Descripcion,int Tiempo,long Precio);
        virtual ~Proyecto();
        //------------------------------------------
        string getNombre();
        string getDescripcion();
        int getTiempo();
        long getPrecio();

        //-------------------------------------------
        virtual void DataProyecto();
    protected:

    private:
        string Nombre;
        string Descripcion;
        int Tiempo;
        long Precio;
};

#endif // PROYECTO_H
