#pragma once
#include "Nodo.h"

class ListaEmpleados
{
private:
	Nodo* primerValor;
	Nodo* valorActual;

public:
	ListaEmpleados();
	void agregarEmpleados(Empleado e);
	void actualizarEmpleados(Nodo* valorModificar, Empleado e);
	void mostrarEmpleadosCompleto();
	void mostrarEmpleadosSimple();
	Nodo* buscarEmpleados(string cedula);
	void borrarEmpleados(Nodo* valorBorrar);
	void calcularSalarioIndividual(Nodo* valorConsultar);
	void calcularSalarioTodos();
	void guardarArchivo();
	void cargarArchivo();
	bool verificarCedula(string cedula);
	~ListaEmpleados();
};

