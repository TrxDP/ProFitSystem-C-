#include "Actividad.h"

Actividad::Actividad(int _id, string _nombre, string _horario, string _entrenador)
{
    //ctor
    id=_id;
    nombre=_nombre;
    horario=_horario;
    entrenador=_entrenador;

}

Actividad::~Actividad()
{
    //dtor
    cout << "Actividad " << nombre << " eliminada." << endl;
}

int Actividad::getId(){
    return id;
}

string Actividad::getNombre(){
    return nombre;
}

string Actividad::getHorario(){
    return horario;
}

string Actividad::getEntrenador(){
    return entrenador;
}

void Actividad::setId(int _id){
    id=_id;
}

void Actividad::setNombre(string _nombre){
    nombre = _nombre;
}

void Actividad::setHorario(string _horario){
    horario=_horario;
}

void Actividad::setEntrenador(string _entrenador){
    entrenador=_entrenador;
}

void Actividad::setNombre(){
    cout<<"\nIngrese el nombre: ";
    cin>>nombre;
}

void Actividad::setHorario(){
    cout<<"\nIngrese el horario: ";
    cin>>horario;
}

void Actividad::setEntrenador(){
    cout<<"\nIngrese el nombre del entrenador: ";
    cin>>entrenador;
}

// Método para mostrar la información de la actividad
void Actividad::mostrarInformacion(){
    cout << "Actividad: " << nombre << endl;
    cout << "Horario: " << horario << endl;
    cout << "Entrenador: " << entrenador << endl;
}

// Método para modificar la actividad
void Actividad::modificarActividad(string nuevoNombre, string nuevoHorario, string nuevoEntrenador){
    setNombre(nuevoNombre);
    setHorario(nuevoHorario);
    setEntrenador(nuevoEntrenador);
    cout << "Actividad modificada: " << nuevoNombre << endl;
}
