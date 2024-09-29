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
        bool activo; // Atributo para saber si el usuario está activo o no


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
        bool getActivo();


        void setId(int _id);
        void setNombre(string _nombre);
        void setEmail(string _email);
        void setContrasena(string _contrasena);
        void setTipoUsuario(string _tipoUsuario);
        void setActivo(bool _activo);

        void setId();
        void setNombre();
        void setEmail();
        void setContrasena();
        void setTipoUsuario();


        void mostrarInformacion();
        void modificarPerfil();
        // Método para desactivar al usuario (no lo elimina físicamente)
        void desactivar();
        // Métodos adicionales para la autenticación
        bool login(string _email, string _contrasena);

    private:

};

#endif // USUARIO_H
