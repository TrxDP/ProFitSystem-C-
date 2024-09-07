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


void Entrenador::consultarClientes(){
    cout << "Clientes asignados al entrenador " << nombre << ": " << endl;
    for (const auto& cliente : clientes) {
        cout << cliente << endl;
    }
}


void Entrenador::registrarProgresoCliente(string cliente, string progreso){
    cout << "Registrando progreso para " << cliente << ": " << progreso << endl;
    // Aquí se podría vincular con el objeto Cliente para actualizar su progreso
}


void Entrenador::consultarActividades(){
    cout << "Actividades que el entrenador puede impartir:" << endl;
    cout << "1. Pesas\n2. Cardio\n3. Yoga\n";  // Ejemplo de actividades
}

void Entrenador::visualizarHorarios(){
    cout << "Horarios del entrenador " << nombre << ": " << endl;
    for (const auto& horario : horarios) {
        cout << horario << endl;
    }
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

