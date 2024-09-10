#include "Menus.h"

Menus::Menus()
{
    //ctor
}

Menus::~Menus()
{
    //dtor
}


//El Administrador tiene acceso a todas las funcionalidades de la aplicación, como crear, modificar o eliminar usuarios y actividades, gestionar pagos, ver estadísticas, etc.

void Menus::mostrarMenuAdministrador() {
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


//El Cliente puede reservar actividades, ver sus pagos, modificar su información personal, y gestionar su membresía.


void Menus::mostrarMenuCliente() {
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
void Menus::mostrarMenuEntrenador() {
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
