#include "Administrador.h"
#include"Usuario.h"


Administrador::Administrador(int _id, string _nombre, string _email, string _contrasena):Usuario(_id,_nombre,_email,_contrasena,"Administrador")
{
    //ctor
}

Administrador::~Administrador()
{
    //dtor
    for (auto& usuario : usuarios) {
        delete usuario;
    }
}


void Administrador::crearUsuario(Usuario* nuevoUsuario){
    usuarios.push_back(nuevoUsuario);
    cout << "Usuario creado: " << nuevoUsuario->getNombre() << endl;
}

void Administrador::modificarUsuario(int usuarioId, string nuevoNombre, string nuevoEmail){
    for (auto& usuario : usuarios) {
        if (usuario->getId() == usuarioId) {
            usuario->setNombre(nuevoNombre);
            usuario->setEmail(nuevoEmail);
            cout << "Usuario modificado: " << nuevoNombre << endl;
            return;
        }
    }
}


void Administrador::eliminarUsuario(int usuarioId){
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getId() == usuarioId) {
            cout << "Usuario eliminado: " << (*it)->getNombre() << endl;
            delete *it;
            usuarios.erase(it);
            return;
        }
    }
    cout << "Usuario no encontrado." << endl;
}

void Administrador::gestionarActividades(){
    cout << "Actividades actuales en el gimnasio: " << endl;
    for (const auto& actividad : actividades) {
        cout << "- " << actividad << endl;
    }
    // Aquí podrías agregar lógica para modificar, agregar o eliminar actividades
}

void Administrador::agregarActividad(string nuevaActividad){
    actividades.push_back(nuevaActividad);
    cout << "Nueva actividad agregada: " << nuevaActividad << endl;
}

void Administrador::consultarEstadisticas(){
    cout << "Consultando estadísticas del gimnasio..." << endl;
    // Aquí se implementarían estadísticas como asistencia, usuarios activos, etc.
}


