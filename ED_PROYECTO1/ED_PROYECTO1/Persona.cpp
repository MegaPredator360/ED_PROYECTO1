#include "Persona.h"

// Constructores
Persona::Persona(void) {}
Persona::Persona(
	string perCedula,
	string perNombre,
	string perNacionalidad,
	string perResidencia,
	int perTelefono,
	int perNumeroHijos,
	string perEstadoCivil,
	int perHorasTrabajo
) {
	Cedula = perCedula;
	Nombre = perNombre;
	Nacionalidad = perNacionalidad;
	Residencia = perResidencia;
	Telefono = perTelefono;
	NumeroHijos = perNumeroHijos;
	EstadoCivil = perEstadoCivil;
	HorasTrabajo = perHorasTrabajo;
}

// Getters and Setters
string Persona::getCedula() { return Cedula; }
void Persona::setCedula(string perCedula) { Cedula = perCedula; }
string Persona::getNombre() { return Nombre; }
void Persona::setNombre(string perNombre) { Nombre = perNombre; }
string Persona::getNacionalidad() { return Nacionalidad; }
void Persona::setNacionalidad(string perNacionalidad) { Nacionalidad = perNacionalidad; }
string Persona::getResidencia() { return Residencia; }
void Persona::setResidencia(string perResidencia) { Residencia = perResidencia; }
int Persona::getTelefono() { return Telefono; }
void Persona::setTelefono(int perTelefono) { Telefono = perTelefono; }
int Persona::getNumeroHijos() { return NumeroHijos; }
void Persona::setNumeroHijos(int perNumeroHijos) { NumeroHijos = perNumeroHijos; }
string Persona::getEstadoCivil() { return EstadoCivil; }
void Persona::setEstadoCivil(string perEstadoCivil) { EstadoCivil = perEstadoCivil; }
int Persona::getHorasTrabajo() { return HorasTrabajo; }
void Persona::setHorasTrabajo(int perHorasTrabajo) { HorasTrabajo = perHorasTrabajo; }

void Persona::MostrarPersona()
{
	cout << "--------------" << endl;
	cout << "Cedula: " << Cedula << endl;
	cout << "Nombre: " << Nombre << endl;
	cout << "Nacionalidad: " << Nacionalidad << endl;
	cout << "Residencia: " << Residencia << endl;
	cout << "Telefono: " << Telefono << endl;
	cout << "Cantidad de Hijos: " << NumeroHijos << endl;
	cout << "Estado Civil: " << EstadoCivil << endl;
	cout << "Horas de Trabajo: " << HorasTrabajo << endl;
	cout << "--------------" << endl;
}

Persona::~Persona()
{
	cout << "Se ha eliminado un empleado" << endl;
}
