#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include<vector>
#include"Usuario.h"
#include"Horario.h"
#include"Cliente.h"


class Entrenador : public Usuario
{
    private:
        // Lista de clientes que maneja el entrenador
        vector<Cliente> clientes;
        // Horarios asignados al entrenador
        vector<Horario> horarios;
        // Años de experiencia del entrenador
        int experiencia;
        // Lista de especializaciones del entrenador
        vector<string> especializaciones;
        vector<string> actividades;

    public:
        Entrenador(int _id, string _nombre, string _email, string _contrasena,vector<string> _especializaciones, int _experiencia,bool _activo);
        virtual ~Entrenador();

        // Métodos getters
        vector<string> getEspecializaciones();
        vector<string> getActividades();
        int getExperiencia();

        // Métodos setters
        void setEspecializaciones(vector<string>& _especializaciones);
        void setExperiencia(int _experiencia);

        void registrarProgresoCliente(string cliente, string progreso);
        void consultarActividades();
        void agregarHorario(Horario horario);

        // Método para agregar una especialización al entrenador
        void agregarEspecializacion(string especializacion);
        // Método para agregar una actividad al entrenador
        void agregarActividad(string actividad);
        // Método para mostrar la información del entrenador
        void mostrarInformacion();
        // Método para eliminar una especialización
        void eliminarEspecializacion(string especializacion);
        // Método para eliminar una actividad
        void eliminarActividad(string actividad);
        // Método para agregar un cliente al entrenador
        void agregarCliente(Cliente cliente);
        // Método para mostrar los horarios del entrenador
        void mostrarHorarios();
        // Método para mostrar los clientes del entrenador
        void mostrarClientes();
        // Método para cancelar una sesión (eliminar cliente del horario)
        void cancelarSesion(string cliente, string dia, string horaInicio);
    protected:


};

#endif // ENTRENADOR_H
