#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include<vector>
#include"Usuario.h"




class Administrador: public Usuario
{
    public:
        Administrador(int _id, string _nombre, string _email, string _contrasena);
        virtual ~Administrador();

        void crearUsuario(Usuario* nuevoUsuario);
        void modificarUsuario(int usuarioId, string nuevoNombre, string nuevoEmail);
        void eliminarUsuario(int usuarioId);
        void gestionarActividades();
        void agregarActividad(string nuevaActividad);
        void consultarEstadisticas();


    protected:

    private:
        vector<Usuario*> usuarios;     // Lista de usuarios registrados en el sistema
        vector<string> actividades;    // Lista de actividades disponibles en el gimnasio
};

#endif // ADMINISTRADOR_H
