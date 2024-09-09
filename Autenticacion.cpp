#include "Autenticacion.h"

Autenticacion::Autenticacion(vector<Usuario*> _usuariosRegistrados)
{
    //ctor
    usuariosRegistrados = _usuariosRegistrados;
}

Autenticacion::~Autenticacion()
{
    //dtor
}

Usuario* Autenticacion::iniciarSesion(string email, string contrasena) {
    for (auto& usuario : usuariosRegistrados) {
        if (usuario->getEmail() == email && usuario->getContrasena() == contrasena) {
            cout << "Inicio de sesión exitoso. Bienvenido, " << usuario->getNombre() << "!" << endl;
            return usuario;
        }
    }
    cout << "Credenciales incorrectas." << endl;
    return nullptr;
}
