#include "Sistema.h"
#include <string>

Sistema::Sistema()
{
    //ctor
    usuarios;
    membresias;
    id = 0;
    idFacturas= 0;
    idMembresias = 0;
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

int Sistema::getIdMembresias(){
    return idMembresias;
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

void Sistema::setIdMembresias(int _idMembresias){
    idMembresias = _idMembresias;
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

void Sistema::verMembresias(Usuario userActivo,vector<Membresia> _membresias, vector<Usuario> _usuarios){
    if(userActivo.getTipoUsuario() == "Administrador"){
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
    }else{
        if(userActivo.getMembresia()!="null"){
            for(auto& membresia : _membresias){
                if(membresia.getIdCliente()==userActivo.getId()){
                    cout<<"\t\t\t\n------------------------------";
                    cout<<"\t\t\t\n--------- Mi Membresia  ---------";
                    cout<<"\t\t\t\n------------------------------";
                    cout<<"\nNombre: " <<membresia.getNombre();
                    cout<<"\nNombre Cliente: " <<userActivo.getNombre();
                    cout<<"\nId membresia: " <<membresia.getIdMembresia();
                    cout<<"\nId Cliente: " <<membresia.getIdCliente();
                    cout<<"\nCosto: $" <<membresia.getCosto();
                    cout<<"\nDuracion (Dias): " <<membresia.getDuracionDias();
                    cout<<"\nFecha inicio: " <<membresia.getFechaInicio();
                    cout<<"\nFecha fin: " <<membresia.getFechaFin();
                    cout<<"\nActivo: " << boolalpha <<membresia.getActivo();
                    cout<<endl;
                }
            }
        }else{cout<<"\n\t---------- No tienes membresia -------------";}
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

void Sistema::idMembresiasAumento(){
    idMembresias++;
}

void Sistema::pushUsuarios(Usuario _nuevoUsuario){
    usuarios.push_back(_nuevoUsuario);
}

void Sistema::pushMembresias(Membresia _nuevaMembresia){
    membresias.push_back(_nuevaMembresia);
}

string Sistema::fecha(){
    // Obtener la fecha actual
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Crear un stream para formatear la fecha
    ostringstream fecha_stream;
    fecha_stream << (now->tm_mday < 10 ? "0" : "") << now->tm_mday << "/"
                 << (now->tm_mon + 1 < 10 ? "0" : "") << (now->tm_mon + 1) << "/"
                 << (now->tm_year + 1900);

    return fecha_stream.str();
}

string Sistema::fechaHora(){
    // Obtener la fecha y hora actual
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Crear un stream para formatear la fecha y la hora
    ostringstream fecha_hora_stream;
    fecha_hora_stream << (now->tm_mday < 10 ? "0" : "") << now->tm_mday << "/"
                      << (now->tm_mon + 1 < 10 ? "0" : "") << (now->tm_mon + 1) << "/"
                      << (now->tm_year + 1900) << " "
                      << (now->tm_hour < 10 ? "0" : "") << now->tm_hour << ":"
                      << (now->tm_min < 10 ? "0" : "") << now->tm_min << ":"
                      << (now->tm_sec < 10 ? "0" : "") << now->tm_sec;

    return fecha_hora_stream.str();
}


Usuario Sistema::getUsuario(int _codigo){
    Usuario usuario;
    for(auto& user : usuarios){
        if(user.getId()==_codigo){
            return user;
        }
    }
    cout<<"\n\t\t------------ Usuario no encontrado ------------";
    return usuario;
}
