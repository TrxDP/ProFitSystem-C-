


#include <iostream>
#include<vector>
#include "Usuario.h"
#include "Autenticacion.h"
#include "Administrador.h"
#include "Cliente.h"
#include "Entrenador.h"

using namespace std;

vector<string> especializaciones = {"Yoga","Pesas","Piscina"};

int main()
{
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
        cout << "Hello world!" << endl;
    }
    return 0;
}
