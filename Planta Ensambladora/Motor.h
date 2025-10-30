#ifndef MOTOR_H
#define MOTOR_H
#include<iostream>
using namespace std;
class Motor
{
    public:
        Motor(string Codigo, string FechaSalida, string Especialista);
        virtual ~Motor();
        string getCodigo();
        string getFechaSalida();
        string getEspecialista();
        int getCantRegreso();
        virtual bool getArtesanal(){return false;};
        //-------------------------------------------------------------------
        void setCantRegreso();
        virtual void setArtesanal(){};
        //-------------------------------------------------------------------
        virtual void FichaTecnica();
        virtual float Costo()=0;
        Motor* siguiente;
    protected:

    private:
        string Codigo;
        string FechaSalida;
        string Especialista;
        int CantRegreso;
};

#endif // MOTOR_H
