#ifndef USUARIO_H
#define USUARIO_H

#include<string>
#include<iostream>

using namespace std;

class Usuario
{
    protected:
        int id;
        string nombre;
        string email;
        string contrasena;
        string tipoUsuario;

    public:

        //construtores
        Usuario(int _id, string _nombre,string _email, string _contrasena, string _tipoUsuario);
        Usuario();

        // Destructor
        virtual ~Usuario();



        // Metodos getters y setters
        int getId();
        string getNombre();
        string getEmail();
        string getContrasena();
        string getTipoUsuario();


        void setId(int _id);
        void setNombre(string _nombre);
        void setEmail(string _email);
        void setContrasena(string _contrasena);
        void setTipoUsuario(string _tipoUsuario);

        void setId();
        void setNombre();
        void setEmail();
        void setContrasena();
        void setTipoUsuario();

        void modificarPerfil();

    private:
};

#endif // USUARIO_H
