#ifndef MOTOR_H
#define MOTOR_H
#include <iostream>
using namespace std;

class Motor
{
    public:
        Motor(string Codigo,string FechaSalida,string Especialista);
        virtual ~Motor();
        //----------------------------------------------
        string getCodigo();
        string getFechaSalida();
        string getEspecialista();
        int getRegreso();
        float getPrecioCosto();
        void pushRegreso();
        //-------------------------------------------------
        virtual string FichaTecnica();
        virtual void setPrecioCosto()=0;

    protected:
        float PrecioCosto;
    private:
        string Codigo;
        string FechaSalida;
        string Especialista;
        int Regreso;
};

#endif // MOTOR_H
