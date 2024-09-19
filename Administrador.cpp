#include "Administrador.h"
#include"Usuario.h"


Administrador::Administrador(int _id, string _nombre, string _email, string _contrasena):Usuario(_id,_nombre,_email,_contrasena,"Administrador")
{
    //ctor
}

Administrador::Administrador(){
    id = 0;
    nombre = "-";
    email = "-";
    contrasena = "-";
    tipoUsuario = "-";
}

Administrador::~Administrador()
{
    //dtor
}
bool Administrador::getActivo() {
    return activo;
}

void Administrador::setActivo(bool _activo) {
        activo = _activo;
}


Usuario Administrador::crearUsuario(int _id){
    string roles[3]={"Cliente", "Entrenador","Administrador"};
    int opc;
    string nombre,email,contrasena,tipoUsuario;
    cout<<"\n\t\t\tIngrese el nombre: ";
    cin>>nombre;
    cout<<"\n\t\t\tIngrese el email: ";
    cin>>email;
    cout<<"\n\t\t\tIngrese el contrasena: ";
    cin>>contrasena;
    cout<<"\n\t\t\tRoles";
    for(int i = 0;i<3;i++){
        cout<<"\n\t\t\t"<<(i+1)<<") "<<roles[i];
    }
    cout<<"\n\t\t\tSeleccione el rol:";
    cin>>opc;
    if(opc==1){tipoUsuario=roles[0];}
    if(opc==2){tipoUsuario=roles[1];}
    if(opc==3){tipoUsuario=roles[2];}
    cout << "\n\t\t\tUsuario creado: " << nombre << endl;
    return Usuario(_id,nombre,email,contrasena,tipoUsuario);
}



void Administrador::modificarUsuario(int usuarioId, string nuevoNombre, string nuevoEmail){
    for (auto& usuario : usuarios) {
        if (usuario.getId() == usuarioId) {
            usuario.setNombre(nuevoNombre);
            usuario.setEmail(nuevoEmail);
            cout << "Usuario modificado: " << nuevoNombre << endl;
            return;
        }
    }
}


void Administrador::eliminarUsuario(int usuarioId){
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it).getId() == usuarioId) {
            cout << "Usuario eliminado: " << (*it).getNombre() << endl;
            usuarios.erase(it);
            return;
        }
    }
    cout << "Usuario no encontrado." << endl;
}

void Administrador::gestionarActividades(){
    cout << "Actividades actuales en el gimnasio: " << endl;
    for (const auto& actividad : actividades) {
        cout << "- " << actividad << endl;
    }
    // Aquí podrías agregar lógica para modificar, agregar o eliminar actividades
}

void Administrador::agregarActividad(string nuevaActividad){
    actividades.push_back(nuevaActividad);
    cout << "Nueva actividad agregada: " << nuevaActividad << endl;
}

void Administrador::consultarEstadisticas(){
    cout << "Consultando estadísticas del gimnasio..." << endl;
    // Aquí se implementarían estadísticas como asistencia, usuarios activos, etc.
}


