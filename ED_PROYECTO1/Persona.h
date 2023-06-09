#pragma once
#include "Validaciones.h"

// Colores para consola
#define RED     "\033[31m"
#define RESET   "\033[0m"

using namespace std;

class Persona
{
// Valores a usar en la lista de empleados
private:
	string TipoCedula;
	string Cedula;
	string Nombre;
	string Nacionalidad;
	string Residencia;
	int Telefono;
	int NumeroHijos;
	string EstadoCivil;
	int HorasTrabajo;
	string TipoEmpleado;

public:
	// Constructores n
	Persona(void);
	Persona(
		string perTipoCedula,
		string perCedula,
		string perNombre,
		string perNacionalidad,
		string perResidencia,
		int perTelefono,
		int perNumeroHijos,
		string perEstadoCivil,
		int perHorasTrabajo,
		string perTipoEmpleado
	);

	// Getters
	string getTipoCedula();
	string getCedula();
	string getNombre();
	string getNacionalidad();
	string getResidencia();
	int getTelefono();
	int getNumeroHijos();
	string getEstadoCivil();
	int getHorasTrabajo();
	string getTipoEmpleado();

	// Setters
	void setTipoCedula(string perTipoCedula);
	void setCedula(string perCedula);
	void setNombre(string perNombre);
	void setNacionalidad(string perNacionalidad);
	void setResidencia(string perResidencia);
	void setTelefono(int perTelefono);
	void setNumeroHijos(int perNumeroHijos);
	void setEstadoCivil(string perEstadoCivil);
	void setHorasTrabajo(int perHorasTrabajo);
	void setTipoEmpleado(string perTipoEmpleado);

	void MostrarPersona();
	void MostrarPersonaBorrar();
	~Persona();
};