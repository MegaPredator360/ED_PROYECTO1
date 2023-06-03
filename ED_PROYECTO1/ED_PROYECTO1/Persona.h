#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona
{
// Valores a usar en la lista de empleados
private:
	string Cedula;
	string Nombre;
	string Nacionalidad;
	string Residencia;
	int Telefono;
	int NumeroHijos;
	string EstadoCivil;
	int HorasTrabajo;

public:
	// Constructores
	Persona(void);
	Persona(
		string perCedula,
		string perNombre,
		string perNacionalidad,
		string perResidencia,
		int perTelefono,
		int perNumeroHijos,
		string perEstadoCivil,
		int perHorasTrabajo
	);

	// Getters
	string getCedula();
	string getNombre();
	string getNacionalidad();
	string getResidencia();
	int getTelefono();
	int getNumeroHijos();
	string getEstadoCivil();
	int getHorasTrabajo();

	// Setters
	void setCedula(string perCedula);
	void setNombre(string perNombre);
	void setNacionalidad(string perNacionalidad);
	void setResidencia(string perResidencia);
	void setTelefono(int perTelefono);
	void setNumeroHijos(int perNumeroHijos);
	void setEstadoCivil(string perEstadoCivil);
	void setHorasTrabajo(int perHorasTrabajo);

	void MostrarPersona();
	~Persona();
};

