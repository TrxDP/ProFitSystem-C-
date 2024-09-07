#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include<iostream>

using namespace std;


class Actividad
{
    public:
        Actividad(int _id, string _nombre, string _horario, string _entrenador);
        virtual ~Actividad();


        // Métodos getters y setters
        int getId();
        string getNombre();
        string getHorario();
        string getEntrenador();



        void setId(int _id);
        void setNombre(string _nombre);
        void setHorario(string _horario);
        void setEntrenador(string _entrenador);


        void setNombre();
        void setHorario();
        void setEntrenador();

        //

        void mostrarInformacion();
        void modificarActividad(string nuevoNombre, string nuevoHorario, string nuevoEntrenador);


    protected:

    private:
        int id;                 // ID de la actividad
        string nombre;          // Nombre de la actividad
        string horario;         // Horario en que se imparte la actividad
        string entrenador;      // Nombre del entrenador asignado

};

#endif // ACTIVIDAD_H
