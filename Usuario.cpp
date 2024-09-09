#include "Usuario.h"


Usuario::Usuario(int _id, string _nombre,string _email, string _contrasena, string _tipoUsuario){
    id = _id;
    nombre = _nombre;
    email = _email;
    contrasena = _contrasena;
    tipoUsuario = _tipoUsuario;
}

Usuario::Usuario()
{
    id = 0;
    nombre = "-";
    email = "-";
    contrasena = "-";
    tipoUsuario = "-";
}

Usuario::~Usuario()
{
    //dtor
}


// Inicializacion de los getters
int Usuario::getId(){
    return id;
}

string Usuario::getNombre(){
    return nombre;
}

string Usuario::getEmail(){
    return email;
}

string Usuario::getContrasena(){
    return contrasena;
}

string Usuario::getTipoUsuario(){
    return tipoUsuario;
}




// Inicializacion de los setters

void Usuario::setId(int _id){
    id = _id;
}

void Usuario::setNombre(string _nombre){
    nombre = _nombre;
}

void Usuario::setEmail(string _email){
    email= _email;
}

void Usuario::setContrasena(string _contrasena){
    contrasena=_contrasena;
}

void Usuario::setTipoUsuario(string _tipoUsuario){
    tipoUsuario= _tipoUsuario;
}

void Usuario::setId(){
    cout<<"\nIngrese el id: ";
    cin>>id;
}

void Usuario::setNombre(){
    cout<<"\nIngrese el nombre: ";
    cin>>nombre;
}

void Usuario::setEmail(){
    cout<<"\nIngrese el email: ";
    cin>>email;
}

void Usuario::setContrasena(){
    cout<<"\nIngrese la contraseña: ";
    cin>>contrasena;
}

void Usuario::setTipoUsuario(){
    cout<<"\nIngrese el tipo de usuario: ";
    cin>>tipoUsuario;
}

void Usuario::modificarPerfil(){
    cout << "Modificar perfil de " << nombre << endl;
    cout << "Nuevo nombre: ";
    cin >> nombre;
    cout << "Nuevo email: ";
    cin >> email;
}

void Usuario::mostrarInformacion(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Rango: "<<tipoUsuario<<endl;
}


void Usuario::desactivar() {
    activo = false;
    cout << "Usuario " << nombre << " desactivado." << endl;
}

bool Usuario::login(string _email, string _contrasena) {
    return (email == _email && contrasena == _contrasena && activo);
}
