#ifndef BASEDATOS_H
#define BASEDATOS_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Usuario.h"
#include"Membresia.h"


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
        int leerIdBlockNotas();
        void escribirIdBlockNotas(int _id);
        void actualizarIdBlockNotas(int _id);

        //Membresias
        vector<Membresia> leerMembresiasBlockNotas();
        void escribirMembresiasBlockNotas(vector<Membresia> _membresias);
        void actualizarMembresiasBlockNotas(vector<Membresia> _membresias);

        //idMembresias
        int leerIdMembresiasBlockNotas();
        void escribirIdMembresiasBlockNotas(int _idMembresias);
        void actualizarIdMembresiasBlockNotas(int _idMembresias);




    protected:

    private:
        const string archivoIdMembresias = "idMembresias.txt";
        const string archivoMembresias = "membresias.txt";
        const string archivoUsuarios = "usuarios.txt";
        const string archivoId = "id.txt";
};

#endif // BASEDATOS_H
