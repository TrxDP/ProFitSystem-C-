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
    string nombre;            // Nombre de membresía (VIP, etc.)
    double costo;             // Costo de la membresía
    int duracionDias;         // Duración de la membresía en días
    string fechaInicio;       // Fecha de inicio de la membresía
    string fechaFin;          // Fecha de finalización de la membresía

public:
    // Constructor
    Membresia(int _idMembresia,int _idCliente, string _nombre, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin);
    Membresia();//Sobrecarga de constructor
    virtual ~Membresia();

    // Métodos getters
    int getIdMembresia();
    int getIdCliente();
    string getNombre();
    double getCosto();
    int getDuracionDias();
    string getFechaInicio();
    string getFechaFin();

    // Métodos setters
    void setNombre(string _nombre);
    void setIdCliente(int _idCliente);
    void setCosto(double _costo);
    void setDuracionDias(int _duracionDias);
    void setFechaInicio(string _fechaInicio);
    void setFechaFin(string _fechaFin);

    //Sobrecarga de setters
    void setNombre();
    void setCosto();
    void setDuracionDias();
    void setFechaInicio();
    void setFechaFin();

    // Método para mostrar la información de la membresía
    void mostrarInformacion();

    // Método para modificar la membresía
    void modificarMembresia(string nuevoNombre, double nuevoCosto, int nuevaDuracion, string nuevaFechaInicio, string nuevaFechaFin);

};

#endif // MEMBRESIA_H
