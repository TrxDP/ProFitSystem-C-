#include "Administrador.h"
#include"Usuario.h"


Administrador::Administrador(int _id, string _nombre, string _email, string _contrasena,string _membresia,bool _activo):Usuario(_id,_nombre,_email,_contrasena,"Administrador",_membresia,_activo)
{
    //ctor
}

Administrador::Administrador(){
    id = 0;
    nombre = "-";
    email = "-";
    contrasena = "-";
    tipoUsuario = "-";
    membresia="-";
    activo = false;
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
    return Usuario(_id,nombre,email,contrasena,tipoUsuario,"null",activo);
}



vector<Usuario> Administrador::modificarUsuario(int usuarioId,vector<Usuario> _usuarios,vector<Membresia> _membresias){
    int opcion;
    cout << "\n\t--- Editar Usuario ---\n";
    cout << "\t1. Editar nombre\n";
    cout << "\t2. Editar Membresia\n";
    cout << "\t3. Editar Correo\n";
    cout << "\t4. Editar Contrasena\n";
    cout << "\t0. Salir\n";
    cout << "\tElija una opción: ";
    cin>>opcion;
    if(opcion!=0){
       while(opcion<1 || opcion>4){
            cout << "\nOpcion invalida ";
            cout << "\nIngrese nuevamente la opcion: ";
            cin>>opcion;
        }
        for (auto& usuario : _usuarios) {
            if (usuario.getId() == usuarioId) {
                if(opcion == 1){
                    string nuevoNombre;
                    cout<<"\nIngrese el nuevo nombre: ";
                    cin>>nuevoNombre;
                    usuario.setNombre(nuevoNombre);
                    cout << "\n\t\t---------------- Nombre modificado con exito! -------------- "<< endl;
                    return _usuarios;
                }
                if(opcion == 2){
                    for(auto& dato : _membresias){
                        if(dato.getIdCliente() == usuarioId){
                            usuario.setMembresia(dato.getNombre());
                            cout << "\n\t\t---------------- Membresia modificado con exito! -------------- "<< endl;
                            return _usuarios;
                        }
                    }
                    cout << "\n\t\t---------------- Usuario no tiene membresia activa -------------- "<< endl;
                    return _usuarios;
                }
                if(opcion == 3){
                    string nuevoEmail;
                    cout<<"\nIngrese el nuevo email: ";
                    cin>>nuevoEmail;
                    usuario.setEmail(nuevoEmail);
                    cout << "\n\t\t---------------- Email modificado con exito! -------------- "<< endl;
                    return _usuarios;
                }
                if(opcion == 4){
                    string nuevaContrasena;
                    cout<<"\nIngrese la nueva contrasena: ";
                    cin>>nuevaContrasena;
                    usuario.setContrasena(nuevaContrasena);
                    cout << "\n\t\t---------------- Contrasena modificado con exito! -------------- "<< endl;
                    return _usuarios;
                }

            }
        }
    }
    return _usuarios;

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


