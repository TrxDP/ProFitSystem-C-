#ifndef CLIENTE_H
#define CLIENTE_H


#include<vector>
#include"Usuario.h"


class Cliente: public Usuario
{
    private:
        // Lista de actividades inscritas
        vector<string> actividades;
        // Registro del progreso del cliente
        vector<string> progreso;
        // Lista de sesiones reservadas <día, hora>
        vector<pair<string, string>> sesionesReservadas;

    public:
        Cliente(int _id, string _nombre, string _email, string _contrasena);
        virtual ~Cliente();

        void verPerfil();
        void consultarActividades();
        void registrarAsistencia();
        void visualizarProgreso();
        void reservarClase(string clase);
        // Método para reservar una sesión con fecha y hora
        void reservarSesion(string dia, string horaInicio);
        // Método para cancelar una sesión
        void cancelarSesion(string dia, string horaInicio);


    protected:



};

#endif // CLIENTE_H
