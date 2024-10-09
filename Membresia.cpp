#include "Membresia.h"

Membresia::Membresia(int _idMembresia,int _idCliente,string _nombre, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin)
{
    //ctor
    idMembresia = _idMembresia;
    idCliente = _idCliente;
    nombre = _nombre;
    costo = _costo;
    duracionDias =_duracionDias;
    fechaInicio = _fechaInicio;
    fechaFin = _fechaFin;
}

Membresia::Membresia(){
   //ctor
    idMembresia = 0;
    idCliente = 0;
    nombre = "-";
    costo = 0.0;
    duracionDias =0;
    fechaInicio = "-";
    fechaFin = "-";
}

Membresia::~Membresia()
{

}



int Membresia::getIdMembresia(){
    return idMembresia;
}

int Membresia::getIdCliente(){
    return idCliente;
}

string Membresia::getNombre(){
    return nombre;
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



void Membresia::setNombre(string _nombre){
    nombre= _nombre;
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


void Membresia::setNombre(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese el nombre de la membresia: ";
    cin>>nombre;
}

void Membresia::setCosto(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese el costo de "<< nombre <<": ";
    cin>>costo;
}

void Membresia::setDuracionDias(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese la duracion: ";
    cin>>duracionDias;
}

void Membresia::setFechaInicio(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese la fecha de inicio (DD/MM/AAAA): ";
    cin>>fechaInicio;
}

void Membresia::setFechaFin(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese la fecha de fin (DD/MM/AAAA): ";
    cin>>fechaFin;
}

void Membresia::mostrarInformacion(){
    cout << "Membresía ID: " << idMembresia << endl;
    cout << "Tipo: " << nombre << endl;
    cout << "Costo: $" << costo << endl;
    cout << "Duración: " << duracionDias << " días" << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de finalización: " << fechaFin << endl;
}

void Membresia::modificarMembresia(string nuevoNombre, double nuevoCosto, int nuevaDuracion, string nuevaFechaInicio, string nuevaFechaFin) {
    setNombre(nuevoNombre);
    setCosto(nuevoCosto);
    setDuracionDias(nuevaDuracion);
    setFechaInicio(nuevaFechaInicio);
    setFechaFin(nuevaFechaFin);
    cout << "Membresía modificada. Nuevo Nombre: " << nuevoNombre
        << ", Nuevo costo: $" << nuevoCosto
        << ", Nueva duración: " << nuevaDuracion << " días"
        << ", Nueva fecha de inicio: " << nuevaFechaInicio
        << ", Nueva fecha de finalización: " << nuevaFechaFin << endl;
}
