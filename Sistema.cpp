#include "Sistema.h"
#include <string>

Sistema::Sistema()
{
    //ctor
    usuarios;
    membresias;
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

vector<Membresia> Sistema::getMembresias(){
    return membresias;
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

void Sistema::setMembresias(vector<Membresia> _membresias){
    membresias = _membresias;
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
        cout<<"\nMembresia: " <<usuario.getMembresia();
        cout<<"\nActivo: " << boolalpha <<usuario.getActivo();
        cout<<endl;
        cantidad++;
    }
}

void Sistema::verMembresias(vector<Membresia> _membresias, vector<Usuario> _usuarios){
    int cantidad = 1;
    for(auto& membresia : _membresias){
        string nombreCliente;
        for(auto& usuario : _usuarios){
            if(membresia.getIdCliente()==usuario.getId()){nombreCliente = usuario.getNombre();}
        }
        cout<<"\t\t\t\n------------------------------";
        cout<<"\t\t\t\n--------- Membresia #"<< cantidad <<" ---------";
        cout<<"\t\t\t\n------------------------------";
        cout<<"\nNombre: " <<membresia.getNombre();
        cout<<"\nNombre Cliente: " <<nombreCliente;
        cout<<"\nId membresia: " <<membresia.getIdMembresia();
        cout<<"\nId Cliente: " <<membresia.getIdCliente();
        cout<<"\nCosto: " <<membresia.getCosto();
        cout<<"\nDuracion: " <<membresia.getDuracionDias();
        cout<<"\nFecha inicio: " <<membresia.getFechaInicio();
        cout<<"\nFecha fin: " <<membresia.getFechaFin();
        cout<<"\nActivo: " << boolalpha <<membresia.getActivo();
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

