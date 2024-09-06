#include "Cliente.h"
#include"Usuario.h"

Cliente::Cliente(int _id, string _nombre, string _email, string _contrasena)
{
    //ctor
    Usuario(_id,_nombre,_email,_contrasena,"Cliente");
}

Cliente::~Cliente()
{
    //dtor
}


void Cliente::verPerfil(){
    cout << "Perfil del cliente: " << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "Actividades inscritas: ";
    for (const auto& actividad : actividades) {
        cout << actividad << " ";
    }
    cout << endl;
}

void Cliente::consultarActividades(){
    cout << "Actividades disponibles para inscribirse:" << endl;
    // Aquí se mostrarían actividades disponibles desde el sistema
    // En este ejemplo sólo es demostrativo
    cout << "1. Yoga\n2. Spinning\n3. Boxeo" << endl;
}

void Cliente::registrarAsistencia(){
    cout << "Registrando asistencia para el cliente: " << nombre << endl;
    // Lógica para registrar la asistencia en la actividad actual
}

void Cliente::visualizarProgreso(){
    cout << "Progreso del cliente " << nombre << ": " << endl;
    for (const auto& log : progreso) {
        cout << log << endl;
    }
}

void Cliente::reservarClase(string clase){
    cout << "Reservando la clase " << clase << " para " << nombre << endl;
    actividades.push_back(clase);  // Agregar la clase a la lista de actividades del cliente
}
