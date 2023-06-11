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
	void actualizarEmpleados(Nodo* valorModificar, Persona p);
	void mostrarEmpleadosCompleto();
	void mostrarEmpleadosSimple();
	Nodo* buscarEmpleados(string cedula);
	void borrarEmpleados(Nodo* valorBorrar);
	void calcularSalarioIndividual(Nodo* valorConsultar);
	void calcularSalarioTodos();
	void guardarArchivo();
	void cargarArchivo();
	~ListaEmpleados();
};

