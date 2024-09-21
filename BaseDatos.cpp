#include "BaseDatos.h"

BaseDatos::BaseDatos(){

}

BaseDatos::~BaseDatos(){



}

// Método para leer usuarios desde un archivo de texto
vector<Usuario> BaseDatos::leerUsuariosBlockNotas() {
    ifstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        vector<Usuario> usuarios;
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string id, nombre, email, contrasena, tipoUsuario;
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, email, ',');
            getline(ss, contrasena, ',');
            getline(ss, tipoUsuario, ',');

            Usuario usuario(stoi(id), nombre, email, contrasena, tipoUsuario);
            usuarios.push_back(usuario);
        }
        archivo.close();
        return usuarios;
    } else {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
    }
}

// Método para escribir usuarios en un archivo de texto
void BaseDatos::escribirUsuariosBlockNotas(vector<Usuario> _usuarios) {
    ofstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        for (auto& usuario : _usuarios) {
            archivo << usuario.getId() << ","
                    << usuario.getNombre() << ","
                    << usuario.getEmail() << ","
                    << usuario.getContrasena() << ","
                    << usuario.getTipoUsuario() << endl;
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


