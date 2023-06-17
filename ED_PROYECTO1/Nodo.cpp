#include "Nodo.h"

Nodo::Nodo(Empleado e, Nodo* sig = NULL)
{
	// Clase Persona
	_empleado.setTipoCedula(e.getTipoCedula());
	_empleado.setCedula(e.getCedula());
	_empleado.setNombre(e.getNombre());
	_empleado.setNacionalidad(e.getNacionalidad());
	_empleado.setResidencia(e.getResidencia());
	_empleado.setTelefono(e.getTelefono());
	_empleado.setNumeroHijos(e.getNumeroHijos());
	_empleado.setEstadoCivil(e.getEstadoCivil());
	_empleado.setHorasTrabajo(e.getHorasTrabajo());
	_empleado.setHorasExtrasTrabajo(e.getHorasExtrasTrabajo());
	_empleado.setTipoEmpleado(e.getTipoEmpleado());
	siguiente = sig;
}

Nodo::~Nodo() { }

// Guardará el valor de la persona a almacenar
void Nodo::setValor(Empleado e) 
{
	this -> _empleado = e;
}

// Obtendra el valor del siguiente nodo
void Nodo::setSiguienteNodo(Nodo* s) 
{
	this -> siguiente = s;
}

// Obtendra el valor de la persona almacenada
Empleado Nodo::getValor() 
{
	return this -> _empleado;
}

// Obtendra el valor del siguiente nodo
Nodo* Nodo::getSiguiente() 
{
	return this -> siguiente;
}
