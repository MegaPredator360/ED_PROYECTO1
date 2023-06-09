#pragma once
#include "Nodo.h"

class ListaEmpleados
{
private:
	Nodo* primerValor;
	Nodo* valorActual;

public:
	ListaEmpleados();
	void agregarEmpleados(Persona p);
	void actualizarEmpleados();
	void mostrarEmpleados();
	void mostrarEmpleadosBorrar();
	void borrarEmpleados();
	~ListaEmpleados();
};

