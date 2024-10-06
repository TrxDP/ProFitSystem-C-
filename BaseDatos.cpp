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
