#include "Reserva.h"

Reserva::Reserva(int _idReserva, string _cliente, string _actividad, string _fecha)
{
    //ctor
    idReserva= _idReserva;
    cliente= _cliente;
    actividad=_actividad;
    fecha=_fecha;
}

Reserva::~Reserva()
{
    //dtor
    cout << "Reserva ID " << idReserva << " eliminada." << endl;
}

int Reserva::getIdReserva(){
    return idReserva;
}

string Reserva::getCliente(){
    return cliente;
}

string Reserva::getActividad(){
    return actividad;
}

string Reserva::getFecha(){
    return fecha;
}

// Método para mostrar la información de la reserva
void Reserva::mostrarInformacion(){
    cout << "Reserva ID: " << idReserva << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "Actividad: " << actividad << endl;
    cout << "Fecha: " << fecha << endl;
}

// Método para modificar la reserva
void Reserva::modificarReserva(string nuevaActividad, string nuevaFecha){
    actividad = nuevaActividad;
    fecha = nuevaFecha;
    cout << "Reserva modificada. Nueva actividad: " << actividad << ", nueva fecha: " << fecha << endl;
}
