#pragma once
#include "Empleado.h"

class Nodo
{
private:
	Persona _persona;		// Campo de datos
	Nodo* siguiente;		// Puntero al siguiente nodo

public:
	Nodo(Persona, Nodo*);
	~Nodo();
	void setValor(Persona p);
	void setSiguienteNodo(Nodo* s);
	Persona getValor();
	Nodo* getSiguiente();
};

