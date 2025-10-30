#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>

using namespace std;

class Empleado
{
    public:
        bool Asociado;
        Empleado(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI);
        virtual ~Empleado();
        //----------------------------------------------------------
        string getNombre();
        int getEdad();
        string getSexo();
        float getSalarioBasico();
        bool getAsociado();
        float getSueldo();
        string getCI();
        //---------------------------------------------------------------
        virtual void setSueldo(long PrecioProyecto)=0;
        virtual void DataEmpleado();
    protected:
        float Sueldo;
    private:
        string Nombre;
        int Edad;
        string Sexo;
        string CI;
        float SalarioBasico;

};

#endif // EMPLEADO_H
