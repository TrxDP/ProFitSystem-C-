#include "BaseDatos.h"

BaseDatos::BaseDatos(){

}

BaseDatos::~BaseDatos(){



}

// Método para leer usuarios desde un archivo de texto
vector<Usuario> BaseDatos::leerUsuariosBlockNotas() {
    vector<Usuario> usuarios;
    ifstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string id, nombre, email, contrasena, tipoUsuario,membresia,stringActivo;
            bool activo;
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, email, ',');
            getline(ss, contrasena, ',');
            getline(ss, tipoUsuario, ',');
            getline(ss, membresia, ',');
            getline(ss,stringActivo,',');
            activo = (stringActivo == "true");
            Usuario usuario(stoi(id), nombre, email, contrasena, tipoUsuario,membresia,activo);
            usuarios.push_back(usuario);
        }
        archivo.close();
        return usuarios;
    } else {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
    }
    return usuarios;
}

// Método para escribir usuarios en un archivo de texto
void BaseDatos::escribirUsuariosBlockNotas(vector<Usuario> _usuarios) {
    ofstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        for (auto& usuario : _usuarios) {
            string activo ="false";
            if(usuario.getActivo()==true){activo="true";}
            archivo << usuario.getId() << ","
                    << usuario.getNombre() << ","
                    << usuario.getEmail() << ","
                    << usuario.getContrasena() << ","
                    << usuario.getTipoUsuario() << ","
                    << usuario.getMembresia() << ","
                    << activo << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
    }
}

// Método para actualizar el archivo de usuarios (sobreescribe el archivo)
void BaseDatos::actualizarUsuariosBlockNotas(vector<Usuario> _usuarios) {
    escribirUsuariosBlockNotas(_usuarios);
}


// Método para "eliminar" usuarios cambiando su estado activo a false
void BaseDatos::eliminarUsuarioUserBlockNotas(int idUsuario, vector<Usuario>& _usuarios) {
    for (auto& usuario : _usuarios) {
        if (usuario.getId() == idUsuario) {
            usuario.setActivo(false); // Cambiar el estado de activo a false
            cout << "Usuario " << usuario.getNombre() << " ha sido desactivado." << endl;
            actualizarUsuariosBlockNotas(_usuarios);  // Actualizamos el archivo
            return;
        }
    }
    cout << "Usuario no encontrado." << endl;
}

int BaseDatos::leerIdBlockNotas(){
    int id = 0;
    ifstream archivo(archivoId);
    // Verifica si el archivo se abrió correctamente
    if(archivo.is_open()){
        string linea;
        //Lee la linea del archivo
        getline(archivo,linea);
        id=stoi(linea);
        // Cierra el archivo
        archivo.close();
        return id;
    }else{
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
        //return -1;
    }
    return id;
}

void BaseDatos::escribirIdBlockNotas(int _id){
    ofstream archivo(archivoId);
    // Verifica si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribe en el archivo
        archivo << _id;

        // Cierra el archivo
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
}

void BaseDatos::actualizarIdBlockNotas(int _id){
    escribirIdBlockNotas(_id);
}

// Método para leer las membresias desde un archivo de texto
vector<Membresia> BaseDatos::leerMembresiasBlockNotas() {
    vector<Membresia> membresias;
    ifstream archivo(archivoMembresias);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string idMembresia, idCliente, nombre, costo, duracionDias,fechaInicio,fechaFin,stringActivo;
            bool activo;
            getline(ss, idMembresia, ',');
            getline(ss, idCliente, ',');
            getline(ss, nombre, ',');
            getline(ss, costo, ',');
            getline(ss, duracionDias, ',');
            getline(ss, fechaInicio, ',');
            getline(ss, fechaFin,',');
            getline(ss, stringActivo,',');
            activo = (stringActivo == "true");
            Membresia membresia(stoi(idMembresia), stoi(idCliente), nombre, stoi(costo), stoi(duracionDias),fechaInicio,fechaFin,activo);
            membresias.push_back(membresia);
        }
        archivo.close();
        return membresias;
    } else {
        cout << "No se pudo abrir el archivo de membresias." << endl;
    }
    return membresias;
}


// Método para escribir las membresias en un archivo de texto
void BaseDatos::escribirMembresiasBlockNotas(vector<Membresia> _membresias){
    ofstream archivo(archivoMembresias);
    if (archivo.is_open()) {
        for (auto& membresia : _membresias) {
            string activo ="false";
            if(membresia.getActivo()==true){activo="true";}
            archivo << membresia.getIdMembresia() << ","
                    << membresia.getIdCliente() << ","
                    << membresia.getNombre() << ","
                    << membresia.getCosto() << ","
                    << membresia.getDuracionDias() << ","
                    << membresia.getFechaInicio() << ","
                    << membresia.getFechaFin() << ","
                    << activo << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir las membresias." << endl;
    }
}


// Método para actualizar el archivo de membresias (sobreescribe el archivo)
void BaseDatos::actualizarMembresiasBlockNotas(vector<Membresia> _membresias){
    escribirMembresiasBlockNotas(_membresias);
}


int BaseDatos::leerIdMembresiasBlockNotas(){
    int idMembresias = 0;
    ifstream archivo(archivoIdMembresias);
    // Verifica si el archivo se abrió correctamente
    if(archivo.is_open()){
        string linea;
        //Lee la linea del archivo
        getline(archivo,linea);
        idMembresias=stoi(linea);
        // Cierra el archivo
        archivo.close();
        return idMembresias;
    }else{
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
        //return -1;
    }
    return idMembresias;
}

void BaseDatos::escribirIdMembresiasBlockNotas(int _idMembresias){
    ofstream archivo(archivoIdMembresias);
    // Verifica si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribe en el archivo
        archivo << _idMembresias;

        // Cierra el archivo
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
}

void BaseDatos::actualizarIdMembresiasBlockNotas(int _idMembresias){
    escribirIdMembresiasBlockNotas(_idMembresias);
}
