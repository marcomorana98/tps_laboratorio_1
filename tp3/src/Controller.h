#include "Jugador.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador, Naciones totalNaciones[], Posiciones posicionJugador[]);
int controller_editarJugador(LinkedList* pArrayListJugador, Naciones totalNaciones[], Posiciones posicionJugador[]);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador, int opcion);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_quita_seleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_convocadosDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados);
