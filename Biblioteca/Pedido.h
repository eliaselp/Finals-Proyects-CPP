#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include "Usuario.h"
#include "Material.h"
using namespace std;

class Pedido
{
    public:
        Pedido(Usuario* Cliente, Material* Doc);
        virtual ~Pedido();
        //------------------------------------------------
        Usuario* getCliente();
        Material* getDoc();
        //------------------------------------------------
    protected:

    private:
        Usuario* Cliente;
        Material* Doc;
};

#endif // PEDIDO_H
