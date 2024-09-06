#include "Cliente.h"
#include"Usuario.h"

Cliente::Cliente(int _id, string _nombre, string _email, string _contrasena)
{
    //ctor
    Usuario(_id,_nombre,_email,_contrasena,"Cliente");
}

Cliente::~Cliente()
{
    //dtor
}
