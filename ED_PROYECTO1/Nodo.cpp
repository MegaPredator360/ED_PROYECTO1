#include "Nodo.h"

Nodo::Nodo(Persona p, Nodo* sig = NULL)
{
	_persona.setTipoCedula(p.getTipoCedula());
	_persona.setCedula(p.getCedula());
	_persona.setNombre(p.getNombre());
	_persona.setNacionalidad(p.getNacionalidad());
	_persona.setResidencia(p.getResidencia());
	_persona.setTelefono(p.getTelefono());
	_persona.setNumeroHijos(p.getNumeroHijos());
	_persona.setEstadoCivil(p.getEstadoCivil());
	_persona.setHorasTrabajo(p.getHorasTrabajo());
	_persona.setHorasExtrasTrabajo(p.getHorasExtrasTrabajo());
	_persona.setTipoEmpleado(p.getTipoEmpleado());
	siguiente = sig;
}

Nodo::~Nodo() { }

// Guardará el valor de la persona a almacenar
void Nodo::setValor(Persona p) 
{
	this -> _persona = p;
}

// Obtendra el valor del siguiente nodo
void Nodo::setSiguienteNodo(Nodo* s) 
{
	this -> siguiente = s;
}

// Obtendra el valor de la persona almacenada
Persona Nodo::getValor() 
{
	return this -> _persona;
}

// Obtendra el valor del siguiente nodo
Nodo* Nodo::getSiguiente() 
{
	return this -> siguiente;
}
