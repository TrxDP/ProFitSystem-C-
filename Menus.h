#ifndef MENUS_H
#define MENUS_H
#include<iostream>

using namespace std;

class Menus
{
    public:
        Menus();
        virtual ~Menus();

        void mostrarMenuAdministrador();
        void mostrarMenuCliente();
        void mostrarMenuEntrenador();


    protected:

    private:
};

#endif // MENUS_H
