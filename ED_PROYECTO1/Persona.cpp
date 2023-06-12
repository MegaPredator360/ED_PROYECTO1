#include "Persona.h"

// Constructores
Persona::Persona(void) {}
Persona::Persona(int i) {}
Persona::Persona(
	string perTipoCedula,
	string perCedula,
	string perNombre,
	string perNacionalidad,
	string perResidencia,
	int perTelefono,
	int perNumeroHijos,
	string perEstadoCivil,
	int perHorasTrabajo,
	int perHorasExtrasTrabajo,
	string perTipoEmpleado
) {
	TipoCedula = perTipoCedula;
	Cedula = perCedula;
	Nombre = perNombre;
	Nacionalidad = perNacionalidad;
	Residencia = perResidencia;
	Telefono = perTelefono;
	NumeroHijos = perNumeroHijos;
	EstadoCivil = perEstadoCivil;
	HorasTrabajo = perHorasTrabajo;
	HorasExtrasTrabajo = perHorasExtrasTrabajo;
	TipoEmpleado = perTipoEmpleado;
}

// Getters and Setters
string Persona::getTipoCedula() { return TipoCedula; }
void Persona::setTipoCedula(string perTipoCedula) { TipoCedula = perTipoCedula; }
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
int Persona::getHorasExtrasTrabajo() { return HorasExtrasTrabajo; }
void Persona::setHorasExtrasTrabajo(int perHorasExtrasTrabajo) { HorasExtrasTrabajo = perHorasExtrasTrabajo; }
string Persona::getTipoEmpleado() { return TipoEmpleado; }
void Persona::setTipoEmpleado(string perTipoEmpleado) { TipoEmpleado = perTipoEmpleado; }

void Persona::MostrarPersona()
{
	cout << "--------------------------------------------------" << endl;
	cout << "Tipo de Cedula: " << TipoCedula << endl;
	cout << "Cedula: " << Cedula << endl;
	cout << "Nombre: " << Nombre << endl;
	cout << "Nacionalidad: " << Nacionalidad << endl;
	cout << "Residencia: " << Residencia << endl;
	cout << "Telefono: " << Telefono << endl;
	cout << "Cantidad de Hijos: " << NumeroHijos << endl;
	cout << "Estado Civil: " << EstadoCivil << endl;
	cout << "Horas de Trabajo: " << HorasTrabajo << endl;
	cout << "Horas Extra de Trabajo Acumuladas: " << HorasExtrasTrabajo << endl;
	cout << "Tipo de Empleado: " << TipoEmpleado << endl;
}

void Persona::MostrarPersonaSimple()
{
	cout << "	-- Cedula: " << Cedula << ", Nombre: " << Nombre << endl;
}

string Persona::ObtenerPersona()
{
	return string(TipoCedula + "/" + Cedula + "/" + Nombre + "/" + Nacionalidad + "/" + Residencia + "/" + to_string(Telefono) + "/" + to_string(NumeroHijos) + "/" + EstadoCivil + "/" + to_string(HorasTrabajo) + "/" + to_string(HorasExtrasTrabajo) + "/" + TipoEmpleado);
}

Persona::~Persona() { }
