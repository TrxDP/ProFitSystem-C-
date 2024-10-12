


#include<iostream>
#include<vector>
#include<string.h>
#include<string>

#include "Autenticacion.h"
#include "Administrador.h"
#include "BaseDatos.h"
#include "Cliente.h"
#include "Entrenador.h"
#include "Membresia.h"
#include "Sistema.h"
#include "Usuario.h"

using namespace std;


//variables globales
//vector<Usuario> usuarios;

Usuario usuarioLogueado;


//Test
void test();

//Inicializacion de funciones

void mostrarMenuCliente();
void mostrarMenuEntrenador();
void mostrarMenuAdministrador();
void menuMembresia();

//------------------ inicializacion de funciones de la base de datos ----------------------
void cargarBaseDatos();
void updateUsuarios(Usuario _usuario);
void escribirBaseDatos();
void cargarBaseDatosMembresias();
void updateMembresias(Membresia _membresia);



//crear la membresia
Membresia crearMembresias();

//Inicializando clases
BaseDatos objBd;
Sistema objSys;
Administrador objAdmin;

vector<string> especializaciones = {"Yoga","Pesas","Piscina"};

void test(){

}


Membresia crearMembresias(){
    Membresia nuevaMembresia;
    if(usuarioLogueado.getTipoUsuario()=="Administrador"){
        int codigo;
        nuevaMembresia.setIdMembresia(objSys.getIdMembresias()); // recibe el id guardado en la clase sistema
        cout<<"\n\t-------------------------";
        cout<<"\nIngrese el codigo del cliente: ";
        cin>>codigo;
        Usuario user = objSys.getUsuario(codigo);
        if(user.getId()!=0){
            nuevaMembresia.setIdCliente(user.getId());
        }else{nuevaMembresia.setIdCliente(0);}
        nuevaMembresia.setNombre();
        nuevaMembresia.setDuracionDias();
        nuevaMembresia.setCosto();
        nuevaMembresia.setFechaInicio(objSys.fechaHora());
        nuevaMembresia.setFechaFin();
        nuevaMembresia.setActivo(true);
        updateMembresias(nuevaMembresia);
        return nuevaMembresia;
    }else{
        nuevaMembresia.setIdMembresia(objSys.getIdMembresias());
        nuevaMembresia.setIdCliente(usuarioLogueado.getId());
        nuevaMembresia.setNombre();
        nuevaMembresia.setDuracionDias();
        nuevaMembresia.setCosto();
        nuevaMembresia.setFechaInicio(objSys.fechaHora());
        nuevaMembresia.setFechaFin();
        nuevaMembresia.setActivo(true);
        updateMembresias(nuevaMembresia);
        return nuevaMembresia;
    }
}

//Esta funcion sirve para establecer  la membresia que quiera pagar el cliente
void menuMembresia(){
    int opcion;
    if(usuarioLogueado.getTipoUsuario()=="Administrador"){
        do{
            //CRUD para las membresias
            cout << "\n\t--- Menu Membresias ---\n";
            cout << "\t1. Informacion de Membresias\n";
            cout << "\t2. Editar Membresias\n";
            cout << "\t3. Eliminar Membresias\n";
            cout << "\t4. Ver Todas Las Membresias\n";
            cout << "\t5. Crear membresia\n";
            cout << "\t0. Salir\n";
            cout << "\tElija una opción: ";
            cin >> opcion;
            switch(opcion){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    objSys.verMembresias(usuarioLogueado,objSys.getMembresias(),objSys.getUsuarios());
                    break;
                case 5:
                    crearMembresias();
                    break;
                case 0:
                    break;
                default:
                    cout << "\tOpción no válida, intente de nuevo.\n";
                    break;
            }
        }while(opcion!=0);
    }else{
        do{
            cout << "\n\t--- Menu Membresias ---\n";
            cout << "\t1. Infomacion de  Membresias\n";
            cout << "\t2. crear Membresia\n";
            cout << "\t3. Actualizar Membresia\n";
            cout << "\t4. Mi Membresia\n";
            cout << "\t0. Salir\n";
            cout << "\tElija una opción: ";
            cin >> opcion;
            switch(opcion){
                case 1:
                    break;
                case 2:
                    if(usuarioLogueado.getMembresia()== "null"){
                            crearMembresias();
                    }else{
                        cout<<"\n\t --------------- Ya cuentas con membresia! ---------------------";
                        }
                    break;
                case 3:

                    break;
                case 4:
                    objSys.verMembresias(usuarioLogueado,objSys.getMembresias(),objSys.getUsuarios());
                    break;
                case 0:
                    break;
                default:
                    cout << "\tOpción no válida, intente de nuevo.\n";
                    break;
            }
        }while(opcion!=0);
    }
}

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
                menuMembresia();
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
    int _id;
    string _nombre,email,contrasena;
    Usuario _nuevoUsuario;
    do {
        cout << "\n\t--- Menu Administrador ---\n";
        cout << "\t1. Crear Usuario\n";
        cout << "\t2. Mostrar Usuarios\n";
        cout << "\t3. Modificar Usuario\n";
        cout << "\t4. Eliminar Usuario\n";
        cout << "\t5. Gestionar Actividades\n";
        cout << "\t6. Consultar Estadísticas\n";
        cout << "\t7. CRUD Membresias\n";
        cout << "\t8. Salir\n";
        cout << "\tElija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llamar función para crear usuario
                _nuevoUsuario = objAdmin.crearUsuario(objSys.getId());
                updateUsuarios(_nuevoUsuario);
                break;
            case 2:

                    objSys.verUsuarios(objSys.getUsuarios());
                break;
            case 3:
                // Llamar función para modificar usuario
                cout<<"\n\t\t\tIngrese el id: ";
                cin>>_id;
                objSys.setUsuarios(objAdmin.modificarUsuario(_id,objSys.getUsuarios(),objSys.getMembresias()));
                objBd.actualizarUsuariosBlockNotas(objSys.getUsuarios());
                break;
            case 4:
                // Llamar función para eliminar usuario
                cout<<"\n\t\t\tIngrese el id: ";
                cin>>_id;
                objSys.setUsuarios(objAdmin.eliminarUsuario(_id,objSys.getUsuarios()));
                escribirBaseDatos();
                break;
            case 5:
                // Llamar función para gestionar actividades
                break;
            case 6:
                // Llamar función para consultar estadísticas
                break;
            case 7:
                menuMembresia();
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 8);
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
    return _usuarioLogueado;
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
    cargarBaseDatos();
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
                if (usuarioLogueado.getId() != 0) {
                    mostrarMenuPorUsuario(usuarioLogueado);
                }else{
                    system("pause");
                }
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
    escribirBaseDatos();
}


//---------------------------- Implimentacion de la base de datos ----------------------------


void cargarBaseDatos(){
    objSys.setUsuarios(objBd.leerUsuariosBlockNotas());
    objSys.setId(objBd.leerIdBlockNotas());
    cargarBaseDatosMembresias();

}

void updateUsuarios(Usuario _usuario){
    objSys.pushUsuarios(_usuario);
    escribirBaseDatos();
    objSys.idAumento();
    objBd.actualizarIdBlockNotas(objSys.getId());
}

void escribirBaseDatos(){
    objBd.actualizarUsuariosBlockNotas(objSys.getUsuarios());
}

void cargarBaseDatosMembresias(){
    objSys.setMembresias(objBd.leerMembresiasBlockNotas());
    objSys.setIdMembresias(objBd.leerIdMembresiasBlockNotas());
}


void updateMembresias(Membresia _membresia){
    objSys.pushMembresias(_membresia);
    objBd.escribirMembresiasBlockNotas(objSys.getMembresias());
    objSys.idMembresiasAumento();
    objBd.escribirIdMembresiasBlockNotas(objSys.getIdMembresias());
    vector<Usuario> _usuarios = objSys.getUsuarios();
    for(auto& user : _usuarios){
        if(user.getId() == _membresia.getIdCliente()){
            user.setMembresia(_membresia.getNombre());
            objSys.setUsuarios(_usuarios);
            objBd.actualizarUsuariosBlockNotas(objSys.getUsuarios());
            cout<<"\n\t --------------- Membresia creada con exito! ---------------------";
        }
    }
}


int main()
{
    inicio();
    //test();
    return 0;
}
