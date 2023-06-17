#pragma once
#include "Empleado.h"

class Nodo
{
private:
	Empleado _empleado;		// Campo de datos
	Nodo* siguiente;		// Puntero al siguiente nodo

public:
	Nodo(Empleado, Nodo*);
	~Nodo();
	void setValor(Empleado e);
	void setSiguienteNodo(Nodo* s);
	Empleado getValor();
	Nodo* getSiguiente();
};

