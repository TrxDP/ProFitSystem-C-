#ifndef MEMBRESIA_H
#define MEMBRESIA_H
#include <iostream>
#include <string>

using namespace std;

// Clase Membresia
class Membresia {
private:
    int idMembresia;          // Identificador único de la membresía
    int idCliente;            // Identificador del cliente
    string tipo;              // Tipo de membresía (Mensual, Anual, VIP, etc.)
    double costo;             // Costo de la membresía
    int duracionDias;         // Duración de la membresía en días
    string fechaInicio;       // Fecha de inicio de la membresía
    string fechaFin;          // Fecha de finalización de la membresía

public:
    // Constructor
    Membresia(int _idMembresia,int _idCliente, string _tipo, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin);
    virtual ~Membresia();

    // Métodos getters
    int getIdMembresia();
    string getTipo();
    double getCosto();
    int getDuracionDias();
    string getFechaInicio();
    string getFechaFin();

    // Métodos setters
    void setTipo(string _tipo);
    void setCosto(double _costo);
    void setDuracionDias(int _duracionDias);
    void setFechaInicio(string _fechaInicio);
    void setFechaFin(string _fechaFin);

    // Método para mostrar la información de la membresía
    void mostrarInformacion();

    // Método para modificar la membresía
    void modificarMembresia(string nuevoTipo, double nuevoCosto, int nuevaDuracion, string nuevaFechaInicio, string nuevaFechaFin);

};

#endif // MEMBRESIA_H
