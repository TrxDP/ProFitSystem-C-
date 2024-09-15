


#include <iostream>
#include<vector>
#include "Usuario.h"
#include "Autenticacion.h"
#include "Administrador.h"
#include "Cliente.h"
#include "Entrenador.h"
#include "Menus.h"

using namespace std;

//Inicializando clases

Menus objMenu;

vector<string> especializaciones = {"Yoga","Pesas","Piscina"};
Usuario* login(){
    // Crear usuarios de ejemplo
    Administrador admin(1, "Admin", "admin@gym.com", "1234");
    Cliente cliente(2, "Juan", "juan@gym.com", "abcd");
    Entrenador entrenador(3, "Carlos", "carlos@gym.com", "5678",especializaciones,10);

    // Vector de usuarios registrados
    vector<Usuario*> usuarios = {&admin,&cliente,&entrenador};

    // Sistema de autenticación
    Autenticacion sistemaAuth(usuarios);

    // Prueba de inicio de sesión
    Usuario* usuarioLogueado = sistemaAuth.iniciarSesion("juan@gym.com", "abcd");

    if (usuarioLogueado != nullptr) {
        // Mostrar menú basado en el tipo de usuario
        // Aquí podríamos implementar un menú dinámico
        return usuarioLogueado;
    }
}

void mostrarMenuPorUsuario(Usuario* usuario) {

    if (usuario->getTipoUsuario() == "Administrador") {
        objMenu.mostrarMenuAdministrador();
    } else if (usuario->getTipoUsuario() == "Cliente") {
        objMenu.mostrarMenuCliente();
    } else if (usuario->getTipoUsuario() == "Entrenador") {
        objMenu.mostrarMenuEntrenador();
    } else {
        cout << "Tipo de usuario no reconocido.\n";
    }
}
int main()
{
    mostrarMenuPorUsuario(login());
    return 0;
}
