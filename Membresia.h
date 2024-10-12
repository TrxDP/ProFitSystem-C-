#ifndef MEMBRESIA_H
#define MEMBRESIA_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <ctime>
#include <iomanip>
#include <sstream>
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
    bool activo;
public:
    map<string,map<string,vector<string>>> todasMembresias;
    map<string,vector<string>> planBasico;
    map<string,vector<string>> planFamiliar;
    map<string,vector<string>> planCorporativo;
    map<string,vector<string>> planPremium;
    vector<string> nombreMembresias = {"Plan Básico","Plan Familiar","Plan Corporativo","Plan Premium"};


    // Constructor
    Membresia(int _idMembresia,int _idCliente, string _nombre, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin, bool _activo);
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
    bool getActivo();

    // Métodos setters
    void setIdMembresia(int _idMembresia);
    void setNombre(string _nombre);
    void setIdCliente(int _idCliente);
    void setCosto(double _costo);
    void setDuracionDias(int _duracionDias);
    void setFechaInicio(string _fechaInicio);
    void setFechaFin(string _fechaFin);
    void setActivo(bool _activo);

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

    //Informacion de membresias
    void infoMembresias();
    void verMembresias(int num);

    //Funcion para operar la fechas
    string sumarDias(int _dias);

};

#endif // MEMBRESIA_H
