#include "Entrenador.h"

Entrenador::Entrenador(int _id, string _nombre, string _email, string _contrasena)
{
    //ctor
    Usuario(_id,_nombre,_email,_contrasena,"Entrenador");
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

void Entrenador::asignarEntrenamiento(string cliente, string plan){
    entrenamientos[cliente] = plan;
    cout << "Entrenamiento asignado a " << cliente << ": " << plan << endl;
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

void Entrenador::agregarHorario(string horario){
    horarios.push_back(horario);
    cout << "Horario agregado: " << horario << endl;
}
