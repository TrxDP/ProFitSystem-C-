#ifndef BASEDATOS_H
#define BASEDATOS_H

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include"Usuario.h"


using namespace std;


class BaseDatos
{
    public:
        BaseDatos();
        virtual ~BaseDatos();


        // usuarios
        vector<Usuario> leerUsuariosBlockNotas();
        void escribirUsuariosBlockNotas(vector<Usuario> _usuarios);
        void actualizarUsuariosBlockNotas(vector<Usuario> _usuarios);
        void eliminarUsuarioUserBlockNotas(int idUsuario, vector<Usuario>& _usuarios);
        //id
        void leerIdBlockNotas();
        void escribirIdBlockNotas();
        void actualizarIdBlockNotas();


    protected:

    private:
        const string archivoUsuarios = "usuarios.txt";
        const string archivoId = "id.txt";
};

#endif // BASEDATOS_H
