#include "Entrenador.h"

Entrenador::Entrenador(int _id, string _nombre, string _email, string _contrasena,vector<string> _especializaciones, int _experiencia)
{
    //ctor
    Usuario(_id,_nombre,_email,_contrasena,"Entrenador");
    especializaciones = _especializaciones;
    experiencia = _experiencia;
}

Entrenador::~Entrenador()
{
    //dtor

}
// Métodos getters
vector<string> Entrenador::getEspecializaciones(){
    return especializaciones;
}

vector<string> Entrenador::getActividades(){
    return actividades;
}

// Métodos setters
void Entrenador::setEspecializaciones(vector<string>& _especializaciones){
    especializaciones=_especializaciones;
}

void Entrenador::setExperiencia(int _experiencia){
    experiencia=_experiencia;
}



void Entrenador::registrarProgresoCliente(string cliente, string progreso){
    cout << "Registrando progreso para " << cliente << ": " << progreso << endl;
    // Aquí se podría vincular con el objeto Cliente para actualizar su progreso
}


void Entrenador::consultarActividades(){
    cout << "Actividades que el entrenador puede impartir:" << endl;
    cout << "1. Pesas\n2. Cardio\n3. Yoga\n";  // Ejemplo de actividades
}


void Entrenador::agregarEspecializacion(string especializacion) {
    especializaciones.push_back(especializacion);
    cout << "Especialización '" << especializacion << "' agregada al entrenador " << getNombre() << endl;
}

void Entrenador::agregarHorario(Horario horario){
    horarios.push_back(horario);
    cout << "Horario agregado para el entrenador " << getNombre() << " el día " << horario.getDia() << " de " << horario.getHoraInicio() << " a " << horario.getHoraFin() << "." << endl;
}

void Entrenador::agregarActividad(string actividad){
    actividades.push_back(actividad);
    cout << "Actividad '" << actividad << "' agregada al entrenador " << getNombre() << endl;
}
void Entrenador::mostrarInformacion(){
    Usuario::mostrarInformacion();
    cout << "Especializaciones: " << endl;
    for (const string& especializacion : especializaciones) {
        cout << "- " << especializacion << endl;
    }
    cout << "Experiencia: " << experiencia << " años" << endl;
    cout << "Actividades que imparte: " << endl;
    for (const string& actividad : actividades) {
        cout << "- " << actividad << endl;
    }
}
void Entrenador::eliminarEspecializacion(string especializacion) {
    for (auto it = especializaciones.begin(); it != especializaciones.end(); ++it) {
        if (*it == especializacion) {
            especializaciones.erase(it);
            cout << "Especialización '" << especializacion << "' eliminada del entrenador " << getNombre() << endl;
            return;
        }
    }
    cout << "Especialización '" << especializacion << "' no encontrada." << endl;
}
void Entrenador::eliminarActividad(string actividad) {
    for (auto it = actividades.begin(); it != actividades.end(); ++it) {
        if (*it == actividad) {
            actividades.erase(it);
            cout << "Actividad '" << actividad << "' eliminada del entrenador " << getNombre() << endl;
            return;
        }
    }
    cout << "Actividad '" << actividad << "' no encontrada." << endl;
}

void Entrenador::agregarCliente(Cliente cliente) {
    clientes.push_back(cliente);
    cout << "Cliente " << cliente.getNombre() << " agregado al entrenador " << getNombre() << "." << endl;
}

void Entrenador::mostrarHorarios(){
    cout << "Horarios del entrenador " << getNombre() << ":" << endl;
    for (Horario& horario : horarios) {
        horario.mostrarHorario();
    }
}

void Entrenador::mostrarClientes(){
    cout << "Clientes del entrenador " << getNombre() << ":" << endl;
    for (Cliente& cliente : clientes) {
        cliente.mostrarInformacion();
    }
}

void Entrenador::cancelarSesion(string cliente, string dia, string horaInicio) {
    for (Horario& horario : horarios) {
        if (horario.getDia() == dia && horario.getHoraInicio() == horaInicio) {
            horario.eliminarCliente(cliente);
            return;
        }
    }
    cout << "No se encontró el horario especificado para la cancelación." << endl;
}
