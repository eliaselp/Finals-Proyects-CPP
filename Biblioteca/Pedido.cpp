#include "Pedido.h"
#include <iostream>
using namespace std;
Pedido::Pedido(Usuario* Cliente, Material* Doc)
{
    this->Cliente=Cliente;
    this->Doc=Doc;
    this->Cliente->PesoAcumulado+=Doc->getPesoAsociado();
    Doc->setPrestado(true);
}

Pedido::~Pedido()
{

}








/************************************************/
/*********** METODOS GETERS ********************/
/*******************************************/
Usuario* Pedido::getCliente(){
    return Cliente;
}
Material* Pedido::getDoc(){
    return Doc;
}


