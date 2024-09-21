



#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include<iostream>


#include "Usuario.h"

using namespace std;


class Sistema
{
    public:
        Sistema();
        virtual ~Sistema();

        // getters
        vector<Usuario> getUsuarios();
        //vector<Usuario*> getCopiaUsuarios();
        int getId();
        int getIdFacturas();

        // setters

        void setUsuarios(vector<Usuario> _Usuarios);
        void setUsuariosCopia(vector<Usuario> _usuarios);
        void setId(int _id);
        void setIdFacturas(int _idFacturas);

        void verUsuarios(vector<Usuario> usuarios);

        void idAumento();
        void idFactuasAumento();

        //Update
        void pushUsuarios(Usuario _nuevoUsuario);

    protected:

    private:
        vector<Usuario> usuarios;
        //vector<Usuario*> usuarioscopia;
        int id;
        int idFacturas;

};

#endif // SISTEMA_H
