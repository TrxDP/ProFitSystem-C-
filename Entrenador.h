#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include<vector>
#include<map>
#include"Usuario.h"

class Entrenador : public Usuario
{
    public:
        Entrenador(int _id, string _nombre, string _email, string _contrasena);
        virtual ~Entrenador();

        void consultarClientes();
        void asignarEntrenamiento(string cliente, string plan);
        void registrarProgresoCliente(string cliente, string progreso);
        void consultarActividades();
        void visualizarHorarios();
        void agregarHorario(string horario);



    protected:

    private:
        // Lista de clientes que maneja el entrenador
        vector<string> clientes;
        // Relación cliente - plan de entrenamiento
        map<string, string> entrenamientos;
        // Horarios de clases que imparte el entrenado
        vector<string> horarios;
};

#endif // ENTRENADOR_H
