#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <string>

using namespace std;

// Clase Reserva
class Reserva {
private:
    int idReserva;             // Identificador único de la reserva
    string cliente;            // Nombre del cliente que realiza la reserva
    string actividad;          // Nombre de la actividad reservada
    string fecha;              // Fecha de la reserva

public:
    // Constructor
    Reserva(int _idReserva, string _cliente, string _actividad, string _fecha);
    virtual ~Reserva();


    // Métodos getters
    int getIdReserva();
    string getCliente();
    string getActividad();
    string getFecha();


    void mostrarInformacion();
    void modificarReserva(string nuevaActividad, string nuevaFecha);

};


#endif // RESERVA_H
