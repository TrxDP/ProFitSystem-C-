#include "Sistema.h"
#include <string>

Sistema::Sistema()
{
    //ctor
    usuarios;
    id = 0;
    idFacturas= 0;
}

Sistema::~Sistema()
{
    //dtor
}

vector<Usuario> Sistema::getUsuarios(){
    return usuarios;
}

/*
vector<Usuario*> Sistema::getCopiaUsuarios(){
    return usuarioscopia;
}
*/
int Sistema::getId(){
    return id;
}
int Sistema::getIdFacturas(){
    return idFacturas;
}

void Sistema::setId(int _id){
    id=_id;
}

void Sistema::setIdFacturas(int _idFacturas){
    idFacturas=_idFacturas;
}
void Sistema::verUsuarios(vector<Usuario> usuarios){
    int cantidad = 1;
    for(auto& usuario : usuarios){
        cout<<"\t\t\t\n------------------------------";
        cout<<"\t\t\t\n--------- Usuario #"<< cantidad <<" ---------";
        cout<<"\t\t\t\n------------------------------";
        cout<<"\nNombre: " <<usuario.getNombre();
        cout<<"\nId: " <<usuario.getId();
        cout<<"\nEmail: " <<usuario.getEmail();
        cout<<"\nRol: " <<usuario.getTipoUsuario();
        cout<<"\nActivo: " << boolalpha <<usuario.getActivo();
        cout<<endl;
        cantidad++;
    }
}


void Sistema::setUsuarios(vector<Usuario> _Usuarios){
    usuarios = _Usuarios;
}

void Sistema::idAumento(){
    id++;
}
void Sistema::idFactuasAumento(){
    idFacturas++;
}

void Sistema::pushUsuarios(Usuario _nuevoUsuario){
    usuarios.push_back(_nuevoUsuario);
}

