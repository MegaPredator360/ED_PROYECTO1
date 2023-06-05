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
	int perHorasTrabajo,
	string perTipoEmpleado
) {
	Cedula = perCedula;
	Nombre = perNombre;
	Nacionalidad = perNacionalidad;
	Residencia = perResidencia;
	Telefono = perTelefono;
	NumeroHijos = perNumeroHijos;
	EstadoCivil = perEstadoCivil;
	HorasTrabajo = perHorasTrabajo;
	TipoEmpleado = perTipoEmpleado;
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
string Persona::getTipoEmpleado() { return TipoEmpleado; }
void Persona::setTipoEmpleado(string perTipoEmpleado) { TipoEmpleado = perTipoEmpleado; }

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
	cout << "Tipo de Empleado: " << TipoEmpleado << endl;
	cout << "--------------" << endl;
}

void Persona::GuardarPersona()
{
	int confirmacion = 110;
	int numTipoEmpleado = 0;
	int numEstadoCivil = 0;

	try
	{
		while (confirmacion == 110)
		{
			system("CLS");
			cout << "Agregar Empleados" << endl << endl;
			cout << "Ingrese la identificacion: " << endl; //No puede haber 2 cedulas iguales
			cin >> Cedula;
			cout << "Ingrese el nombre del empleado " << endl;
			cin >> Nombre;
			cout << "Ingrese la nacionalidad: " << endl;
			cin >> Nacionalidad;
			cout << "Ingrese la residencia: " << endl;
			cin >> Residencia;
			cout << "Ingrese el telefono" << endl;// No puede haber 2 telefonos iguales
			cin >> Telefono;
			cout << "Ingrese la cantidad de hijos : " << endl;
			cin >> NumeroHijos;
			cout << "Ingresa el Estado Civil: [1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << endl;
			cin >> numEstadoCivil;
			cout << "Ingrese la cantidad de horas de trabajo : " << endl; //?
			cin >> HorasTrabajo;
			cout << "Ingresa el puesto del empleado: [1) Empleado, 2) Gerente]" << endl; //Empleado o Gerente?
			cin >> numTipoEmpleado;
			cout << "¿La información ingresada es correcta? [S/n]" << endl; //?
			// Obtendrá el valor de la tecla que se pulse en el formato "ASCII" y se validará si la opcion ingresada es correcta o no
			confirmacion = _getch();
			while (confirmacion != 13 && confirmacion != 83 && confirmacion != 115 && confirmacion != 78 && confirmacion != 110)
			{
				cout << "La opcion ingresada no es correcta." << endl;
				cout << "¿La información ingresada es correcta? [S/n]" << endl;
				confirmacion = _getch();
			}
			
			if (confirmacion == 78)
			{
				confirmacion = 110;
			}

			if (confirmacion == 13 || confirmacion == 83 || confirmacion == 115)
			{
				ofstream perArchivo("Empleados.txt");	// Creará el archivo
				perArchivo << "{Cedula}/{Nombre}";		// Escribirá los datos del empleado en el archivo
				perArchivo.close();						// Guardará los datos en el archivo
			}
		}
	}
	catch (exception e)
	{
		throw e;
	}
}

void Persona::ActualizarPersona()
{

}

void Persona::EliminarPersona()
{

}

Persona::~Persona()
{
	cout << "Se ha eliminado un empleado" << endl;
}
