


#include <iostream>
#include<vector>
#include<string.h>
#include<string>


#include "Autenticacion.h"
#include "Administrador.h"
#include "BaseDatos.h"
#include "Cliente.h"
#include "Entrenador.h"
#include "Sistema.h"
#include "Usuario.h"

using namespace std;


//variables globales
//vector<Usuario> usuarios;

Usuario usuarioLogueado;

//Inicializacion de funciones
void mostrarMenuCliente();
void mostrarMenuEntrenador();
void mostrarMenuAdministrador();


//Inicializando clases
BaseDatos objBd;
Sistema objSys;

vector<string> especializaciones = {"Yoga","Pesas","Piscina"};

//El Cliente puede reservar actividades, ver sus pagos, modificar su información personal, y gestionar su membresía.
void mostrarMenuCliente(){
    int opcion;
    do {
        cout << "\n--- Menu Cliente ---\n";
        cout << "1. Ver Actividades\n";
        cout << "2. Reservar Actividad\n";
        cout << "3. Consultar Membresía\n";
        cout << "4. Ver Pagos\n";
        cout << "5. Modificar Información Personal\n";
        cout << "6. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llamar función para ver actividades
                break;
            case 2:
                // Llamar función para reservar actividad
                break;
            case 3:
                // Llamar función para consultar membresía
                break;
            case 4:
                // Llamar función para ver pagos
                break;
            case 5:
                // Llamar función para modificar info personal
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);
}

//El Entrenador puede gestionar sus horarios, clientes, actividades y ver el progreso de sus clientes.
void mostrarMenuEntrenador() {
    int opcion;
    do {
        cout << "\n--- Menu Entrenador ---\n";
        cout << "1. Ver Horarios\n";
        cout << "2. Gestionar Clientes\n";
        cout << "3. Ver Progreso de Clientes\n";
        cout << "4. Modificar Actividades\n";
        cout << "5. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llamar función para ver horarios
                break;
            case 2:
                // Llamar función para gestionar clientes
                break;
            case 3:
                // Llamar función para ver progreso de clientes
                break;
            case 4:
                // Llamar función para modificar actividades
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);
}

//El Administrador tiene acceso a todas las funcionalidades de la aplicación, como crear, modificar o eliminar usuarios y actividades, gestionar pagos, ver estadísticas, etc.
void mostrarMenuAdministrador() {
    int opcion;
    do {
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Crear Usuario\n";
        cout << "2. Modificar Usuario\n";
        cout << "3. Eliminar Usuario\n";
        cout << "4. Gestionar Actividades\n";
        cout << "5. Consultar Estadísticas\n";
        cout << "6. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llamar función para crear usuario

                break;
            case 2:
                // Llamar función para modificar usuario

                break;
            case 3:
                // Llamar función para eliminar usuario

                break;
            case 4:
                // Llamar función para gestionar actividades

                break;
            case 5:
                // Llamar función para consultar estadísticas
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);
}


Usuario login(){
    string email,contrasena;
    /*
    // Crear usuarios de ejemplo
    Administrador admin(1, "Admin", "admin@gym.com", "1234");
    Cliente cliente(2, "Juan", "juan@gym.com", "abcd");
    Entrenador entrenador(3, "Carlos", "carlos@gym.com", "5678",especializaciones,10);
    */

    // Sistema de autenticación
    Autenticacion sistemaAuth(objSys.getUsuarios());

    cout<<"\n\t\t\tEmail: ";
    cin>>email;
    cout<<"\n\t\t\tContraseña: ";
    cin>>contrasena;


    // Prueba de inicio de sesión
    Usuario _usuarioLogueado = sistemaAuth.iniciarSesion(email, contrasena);

    if (usuarioLogueado.getId() != 0) {
        // Mostrar menú basado en el tipo de usuario
        return _usuarioLogueado;
    }
}


void mostrarMenuPorUsuario(Usuario usuario) {

    if (usuario.getTipoUsuario() == "Administrador") {
        mostrarMenuAdministrador();
    } else if (usuario.getTipoUsuario() == "Cliente") {
        mostrarMenuCliente();
    } else if (usuario.getTipoUsuario() == "Entrenador") {
        mostrarMenuEntrenador();
    } else {
        cout << "Tipo de usuario no reconocido.\n";
    }
}


void inicio(){
    int opc;
    do{
        system("cls");
        cout<<"\n\t\t\t------------------------------";
        cout<<"\n\t\t\t-------- ProFitSystem --------";
        cout<<"\n\t\t\t------------------------------";
        cout<<"\n\t\t\t1) Iniciar Sesion.";
        cout<<"\n\t\t\t2) Acerca De ProFitSystem.";
        cout<<"\n\t\t\t3) Programadores.";
        cout<<"\n\t\t\t4) Salir.";
        cout<<"\n\t\t\tIngrese la opcion: ";
        cin>> opc;
        switch(opc){
            case 1:
                usuarioLogueado=login();
                mostrarMenuPorUsuario(usuarioLogueado);
                break;
            case 2:
                objSys.verUsuarios(objSys.getUsuarios());
                system("pause");
                break;
            case 3:
                system("pause");
                break;
            case 4:
                cout<<"\t\t\t\nSaliendo...";                break;
            default:
                cout<<"\t\t\t\nOpcion invalida.";
                break;
        }
    }while(opc != 4);

}
void cargarBaseDatos(){
    objSys.setUsuarios(objBd.leerUsuariosBlockNotas());
}

int main()
{
    cargarBaseDatos();
    //mostrarMenuPorUsuario(login());
    inicio();

    return 0;
}
