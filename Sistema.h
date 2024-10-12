



#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include<iostream>
#include<ctime>
#include<sstream>


#include "Usuario.h"
#include "Membresia.h"

using namespace std;


class Sistema
{
    public:
        Sistema();
        virtual ~Sistema();

        // getters
        vector<Usuario> getUsuarios();
        vector<Membresia> getMembresias();
        //vector<Usuario*> getCopiaUsuarios();
        int getId();
        int getIdFacturas();
        int getIdMembresias();

        // setters

        void setUsuarios(vector<Usuario> _Usuarios);
        void setUsuariosCopia(vector<Usuario> _usuarios);
        void setMembresias(vector<Membresia> _membresias);
        void setId(int _id);
        void setIdFacturas(int _idFacturas);
        void setIdMembresias(int _idMembresias);

        void verUsuarios(vector<Usuario> usuarios);
        void verMembresias(Usuario userActivo,vector<Membresia> _membresias,vector<Usuario> _usuarios);

        void idAumento();
        void idFactuasAumento();
        void idMembresiasAumento();


        //Update
        void pushUsuarios(Usuario _nuevoUsuario);
        void pushMembresias(Membresia _nuevaMembresia);

        //retorna valores de las listas
        Usuario getUsuario(int _codigo);

        //Funcion que me retorna la fecha en formato DD/MM/AAAA
        string fecha();

        //Funcion que me retorna la fecha y hora
        string fechaHora();

    protected:

    private:
        vector<Usuario> usuarios;
        vector<Membresia> membresias;
        //vector<Usuario*> usuarioscopia;
        int id;
        int idFacturas;
        int idMembresias;

};

#endif // SISTEMA_H
