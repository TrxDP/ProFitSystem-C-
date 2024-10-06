#include "Membresia.h"

Membresia::Membresia(int _idMembresia,int _idCliente,string _tipo, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin)
{
    //ctor

}

Membresia::~Membresia()
{
    //dtor
    cout << "Membresía ID " << idMembresia << " eliminada." << endl;
}



int Membresia::getIdMembresia(){
    return idMembresia;
}

int Membresia::getIdCliente(){
    return idCliente;
}

string Membresia::getTipo(){
    return tipo;
}

double Membresia::getCosto(){
    return costo;
}

int Membresia::getDuracionDias(){
    return duracionDias;
}

string Membresia::getFechaInicio(){
    return fechaInicio;
}

string Membresia::getFechaFin(){
    return fechaFin;
}

void Membresia::setTipo(string _tipo){
    tipo= _tipo;
}

void Membresia::setIdCliente(int _idCliente){
    idCliente = _idCliente;
}
void Membresia::setCosto(double _costo){
    costo= _costo;
}

void Membresia::setDuracionDias(int _duracionDias){
    duracionDias= _duracionDias;
}

void Membresia::setFechaInicio(string _fechaInicio){
    fechaInicio= _fechaInicio;
}

void Membresia::setFechaFin(string _fechaFin){
    fechaFin= _fechaFin;
}


void Membresia::mostrarInformacion(){
    cout << "Membresía ID: " << idMembresia << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Costo: $" << costo << endl;
    cout << "Duración: " << duracionDias << " días" << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de finalización: " << fechaFin << endl;
}

void Membresia::modificarMembresia(string nuevoTipo, double nuevoCosto, int nuevaDuracion, string nuevaFechaInicio, string nuevaFechaFin) {
    setTipo(nuevoTipo);
    setCosto(nuevoCosto);
    setDuracionDias(nuevaDuracion);
    setFechaInicio(nuevaFechaInicio);
    setFechaFin(nuevaFechaFin);
    cout << "Membresía modificada. Nuevo tipo: " << nuevoTipo
        << ", Nuevo costo: $" << nuevoCosto
        << ", Nueva duración: " << nuevaDuracion << " días"
        << ", Nueva fecha de inicio: " << nuevaFechaInicio
        << ", Nueva fecha de finalización: " << nuevaFechaFin << endl;
}
