#include "Horario.h"

Horario::Horario(string _dia, string _horaInicio, string _horaFin)
{
    //ctor

}

Horario::~Horario()
{
    //dtor
}


string Horario::getDia(){
    return dia;
}

string Horario::getHoraInicio(){
    return horaInicio;
}

string Horario::getHoraFin(){
    return horaFin;
}

vector<string> Horario::getClientes(){
    return clientes;
}


void Horario::agregarCliente(string cliente){
    clientes.push_back(cliente);
    cout << "Cliente " << cliente << " ha reservado el horario de " << horaInicio << " a " << horaFin << " el " << dia << "." << endl;
}

void Horario::mostrarHorario(){
    cout << "Día: " << dia << " | Horario: " << horaInicio << " - " << horaFin << endl;
    cout << "Clientes asignados: " << endl;
    for (const string& cliente : clientes) {
        cout << "- " << cliente << endl;
    }
}

// Método para eliminar un cliente del horario
void Horario::eliminarCliente(string cliente) {
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (*it == cliente) {
            clientes.erase(it);
            cout << "Cliente " << cliente << " ha cancelado la sesión de " << horaInicio << " a " << horaFin << " el " << dia << "." << endl;
            return;
        }
    }
    cout << "Cliente " << cliente << " no encontrado en el horario de " << horaInicio << " a " << horaFin << " el " << dia << "." << endl;
}
