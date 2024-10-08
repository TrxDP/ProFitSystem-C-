#include "Autenticacion.h"

Autenticacion::Autenticacion(vector<Usuario> _usuariosRegistrados)
{
    //ctor
    usuariosRegistrados = _usuariosRegistrados;
}

Autenticacion::~Autenticacion()
{
    //dtor
}

Usuario Autenticacion::iniciarSesion(string email, string contrasena) {
    for (auto& usuario : usuariosRegistrados) {
        if ((usuario.getEmail() == email && usuario.getContrasena() == contrasena)&& usuario.getActivo() == true) {
            cout << "Inicio de sesión exitoso. Bienvenido, " << usuario.getNombre() << "!" << endl;
            return usuario;
        }
    }
    cout << "\n\t\t\tCredenciales incorrectas." << endl;
    return Usuario(); //Si el inicio de sesion fue malo me retorna un usuario por defecto
}

Usuario* Autenticacion::getUsuarioActual() {
        return usuarioActual;
}

void Autenticacion::cerrarSesion(){
    if (usuarioActual) {
        cout << "Cerrando sesión del usuario: " << usuarioActual->getEmail() << endl;
        usuarioActual = nullptr;
    } else {
        cout << "No hay un usuario actualmente autenticado." << endl;
    }
}
