#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include<vector>
#include"Usuario.h"
#include"Membresia.h"




class Administrador: public Usuario
{
    public:
        Administrador(int _id, string _nombre, string _email, string _contrasena,string _membresia,bool _activo);
        Administrador();
        virtual ~Administrador();
        bool getActivo();
        void setActivo(bool _activo);

        Usuario crearUsuario(int _id);
        vector<Usuario> modificarUsuario(int usuarioId,vector<Usuario> _usuarios,vector<Membresia> _membresias);
        vector<Usuario> eliminarUsuario(int usuarioId,vector<Usuario> _usuarios);
        void gestionarActividades();
        void agregarActividad(string nuevaActividad);
        void consultarEstadisticas();


    protected:

    private:
        vector<Usuario> usuarios;     // Lista de usuarios registrados en el sistema
        vector<string> actividades;    // Lista de actividades disponibles en el gimnasio
        bool activo;
};

#endif // ADMINISTRADOR_H
