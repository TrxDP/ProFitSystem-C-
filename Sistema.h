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



        //base de datos
        void leerBlockNotas();
        void escribiBlockNotas();
        void actualizarBlockNotas();
        void eliminarUserBlockNotas();

    protected:

    private:
        vector<Usuario> usuarios;
        int id;
        int idFacturas;

};

#endif // SISTEMA_H
