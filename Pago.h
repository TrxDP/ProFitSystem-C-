#ifndef PAGO_H
#define PAGO_H
#include <iostream>
#include <string>

using namespace std;

// Clase Pago
class Pago {
private:
    int idPago;              // Identificador único del pago
    string cliente;          // Cliente que realizó el pago
    double monto;            // Monto del pago
    string metodoPago;       // Método de pago (tarjeta, efectivo, etc.)
    string fecha;            // Fecha del pago

public:
    // Constructor
    Pago(int _idPago, string _cliente, double _monto, string _metodoPago, string _fecha);
    virtual ~Pago();


    // Métodos getters
    int getIdPago();
    string getCliente();
    double getMonto();
    string getMetodoPago();
    string getFecha();

    // Métodos setters
    void setIdPago(int _idPago);
    void setMonto(double _monto);
    void setMetodoPago(string _metodoPago);
    void setFecha(string _fecha);


    void mostrarInformacion();


    void modificarPago(double nuevoMonto, string nuevoMetodoPago, string nuevaFecha);
};


#endif // PAGO_H
