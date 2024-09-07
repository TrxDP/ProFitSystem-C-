#ifndef HORARIO_H
#define HORARIO_H
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Horario {
private:
    string dia;           // Día de la semana (Ej: Lunes, Martes, etc.)
    string horaInicio;    // Hora de inicio (formato 24h, Ej: "09:00")
    string horaFin;       // Hora de fin (formato 24h, Ej: "10:00")
    vector<string> clientes;  // Lista de nombres de los clientes que tienen citas

public:
    // Constructor
    Horario(string _dia, string _horaInicio, string _horaFin);
    virtual ~Horario();

    // Métodos getters
    string getDia();
    string getHoraInicio();
    string getHoraFin();
    vector<string> getClientes();

    // Método para agregar un cliente al horario
    void agregarCliente(string cliente);

    // Método para mostrar el horario con los clientes asignados
    void mostrarHorario();
    void eliminarCliente(string cliente);
};

#endif // HORARIO_H
