#ifndef AUTENTICACION_H
#define AUTENTICACION_H
#include <iostream>
#include <vector>
#include "Usuario.h"
using namespace std;

class Autenticacion {
private:
    vector<Usuario*> usuariosRegistrados;

public:
    Autenticacion(vector<Usuario*> _usuariosRegistrados);
    virtual ~Autenticacion();

    Usuario* iniciarSesion(string email, string contrasena);
};

#endif // AUTENTICACION_H
