#include "Administrador.h"
#include"Usuario.h"


Administrador::Administrador(int _id, string _nombre, string _email, string _contrasena,bool _activo):Usuario(_id,_nombre,_email,_contrasena,"Administrador",_activo)
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
    bool activo = true;
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
    return Usuario(_id,nombre,email,contrasena,tipoUsuario,activo);
}



void Administrador::modificarUsuario(int usuarioId, string nuevoNombre, string nuevoEmail,vector<Usuario>& _usuarios){
    for (auto& usuario : _usuarios) {
        if (usuario.getId() == usuarioId) {
            usuario.setNombre(nuevoNombre);
            usuario.setEmail(nuevoEmail);
            cout << "Usuario modificado: " << nuevoNombre << endl;
            return;
        }
    }
}


vector<Usuario> Administrador::eliminarUsuario(int usuarioId,vector<Usuario> _usuarios){
    vector<Usuario> usuarios=_usuarios;
    for (auto& usuairo : usuarios) {
        if (usuairo.getId()== usuarioId) {
            cout << "Usuario eliminado: " << usuairo.getNombre() << endl;
            usuairo.setActivo(false);
            return usuarios;
        }
    }
    cout << "Usuario no encontrado." << endl;
    return _usuarios;
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


