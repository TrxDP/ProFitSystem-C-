#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include<vector>
#include<map>
#include"Usuario.h"
#include"Horario.h"

class Entrenador : public Usuario
{
    public:
        Entrenador(int _id, string _nombre, string _email, string _contrasena,vector<string> _especializaciones, int _experiencia);
        virtual ~Entrenador();

        // Métodos getters
        vector<string> getEspecializaciones();
        vector<string> getActividades();
        int getExperiencia();

        // Métodos setters
        void setEspecializaciones(const vector<string>& _especializaciones) { especializaciones = _especializaciones; }
        void setExperiencia(int _experiencia) { experiencia = _experiencia; }


        void consultarClientes();
        void registrarProgresoCliente(string cliente, string progreso);
        void consultarActividades();
        void visualizarHorarios();
        void agregarHorario(Horario horario);

        // Método para agregar una especialización al entrenador
        void agregarEspecializacion(string especializacion) {
            especializaciones.push_back(especializacion);
            cout << "Especialización '" << especializacion << "' agregada al entrenador " << getNombre() << endl;
        }
            // Método para agregar una actividad al entrenador
        void agregarActividad(string actividad);
        // Método para mostrar la información del entrenador
        void mostrarInformacion();
        // Método para eliminar una especialización
        void eliminarEspecializacion(string especializacion);
        // Método para eliminar una actividad
        void eliminarActividad(string actividad);


    protected:

    private:
        // Lista de clientes que maneja el entrenador
        vector<string> clientes;
        // Horarios de clases que imparte el entrenado
        vector<string> horarios;
        // Años de experiencia del entrenador
        int experiencia;
        // Lista de especializaciones del entrenador
        vector<string> especializaciones;

};

#endif // ENTRENADOR_H
