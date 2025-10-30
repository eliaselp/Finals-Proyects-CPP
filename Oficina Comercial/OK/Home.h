#ifndef HOME_H
#define HOME_H
#include <iostream>
#include "Usuario.h"
using namespace std;

class Home:public Usuario
{
    public:
        Home(string Nombre, string Direccion, string Telefono,string CI);
        virtual ~Home();
        //---------------------------------------------------------------------
        string getCI();
        //-----------------------------------------------------------------------
        void DataUsuario()override;
        void setConsumo(int Mes)override;
    protected:

    private:
        string CI;
};

#endif // HOME_H
