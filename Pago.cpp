#include "Pago.h"

Pago::Pago(int _idPago, string _cliente, double _monto, string _metodoPago, string _fecha)
{
    //ctor
}

Pago::~Pago()
{
    //dtor
    cout << "Pago ID " << idPago << " eliminado." << endl;
}

int Pago::getIdPago(){
   return idPago;
}

string Pago::getCliente(){
    return cliente;
}

double Pago::getMonto(){
    return monto;
}

string Pago::getMetodoPago(){
    return metodoPago;
}

string Pago::getFecha(){
    return fecha;
}

void Pago::setIdPago(int _idPago){
    idPago=_idPago;
}

void Pago::setMonto(double _monto){
    monto=_monto;
}

void Pago::setMetodoPago(string _metodoPago){
    metodoPago=_metodoPago;
}

void Pago::setFecha(string _fecha){
    fecha=_fecha;
}

// Método para mostrar la información del pago
void Pago::mostrarInformacion(){
    cout << "Pago ID: " << idPago << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Método de Pago: " << metodoPago << endl;
    cout << "Fecha: " << fecha << endl;
}


// Método para modificar el pago
void Pago::modificarPago(double nuevoMonto, string nuevoMetodoPago, string nuevaFecha) {
    setMonto(nuevoMonto);
    setMetodoPago(nuevoMetodoPago);
    setFecha(nuevaFecha);
    cout << "Pago modificado. Nuevo monto: $" << nuevoMonto
            << ", Nuevo método de pago: " << nuevoMetodoPago
            << ", Nueva fecha: " << nuevaFecha << endl;
}
