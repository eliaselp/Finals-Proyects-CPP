#ifndef TANQUE_H
#define TANQUE_H
#include <iostream>
#include "Deposito.h"
using namespace std;

class Tanque:public Deposito
{
    public:
        Tanque(float Capacidad,string Estado,string TipoAbasto,string Material);
        virtual ~Tanque();
        //----------------------------------
        string getMaterial();
        //-------------------------------
        string DataDeposito()override;
    protected:

    private:
        string Material;
        /** Plastico..Metal...FibroCemento**/

};

#endif // TANQUE_H
