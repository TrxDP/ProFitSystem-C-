#ifndef AUTENTICACION_H
#define AUTENTICACION_H
#include <iostream>
#include <vector>
#include "Usuario.h"
using namespace std;

class Autenticacion {
private:
    vector<Usuario> usuariosRegistrados;  // Lista de usuarios registrados
    Usuario* usuarioActual; // Usuario actualmente autenticado

public:
    Autenticacion(vector<Usuario> _usuariosRegistrados);
    virtual ~Autenticacion();

    //get usuario
    Usuario* getUsuarioActual();

    Usuario iniciarSesion(string email, string contrasena);
    // Método para cerrar sesión
    void cerrarSesion();


};

#endif // AUTENTICACION_H
