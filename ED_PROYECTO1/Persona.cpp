#include "Persona.h"

// Constructores
Persona::Persona(void) {}
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
string Persona::getTipoEmpleado() { return TipoEmpleado; }
void Persona::setTipoEmpleado(string perTipoEmpleado) { TipoEmpleado = perTipoEmpleado; }

void Persona::MostrarPersona()
{
	cout << "--------------" << endl;
	cout << "Tipo de Cedula: " << TipoCedula << endl;
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
	int numTipoCedula = 0;
	string confirmacion = "N";
	int numTipoEmpleado = 0;
	int numEstadoCivil = 0;
	FuncionesCustom FunCus;

	try
	{
		while (confirmacion == "N")
		{
			system("CLS");
			cout << "			Agregar Empleados" << endl << endl;
			cout << "¿Que tipo de cedula tiene el empleado? [1) Nacional, 2) Juridica, 3) Extranjero]" << endl;
			numTipoCedula = stoi(FunCus.aceptarNumeros());	// Stoi convierte de String a Int

			while (numTipoCedula <= 0 || numTipoCedula >= 4)
			{
				cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
				numTipoCedula = stoi(FunCus.aceptarNumeros());
			}

			switch (numTipoCedula)
			{
			case 1:
				TipoCedula = "Nacional";

				cout << "Ingrese el número de identificacion: (Minimo: 9 digitos, incluir los 0)" << endl;
				Cedula = FunCus.aceptarNumeros();
				while (Cedula.length() != 9 || Cedula.at(1) != '0' || Cedula.at(5) != '0')
				{
					cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
					Cedula = FunCus.aceptarNumeros();
				}
				break;

			case 2:
				TipoCedula = "Juridica";

				cout << "Ingrese el número de identificacion: (Minimo: 12 digitos)" << endl;
				Cedula = FunCus.aceptarNumeros();
				while (Cedula.length() != 12)
				{
					cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
					Cedula = FunCus.aceptarNumeros();
				}
				break;

			case 3:
				TipoCedula = "Extranjero";

				cout << "Ingrese el número de identificacion: (Minimo: 12 digitos)" << endl;
				Cedula = FunCus.aceptarNumeros();
				while (Cedula.length() != 12)
				{
					cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
					Cedula = FunCus.aceptarNumeros();
				}
				break;

			default:
				cout << RED << "Se ha seleccionado una opcion invalida" << RESET << endl;
				cout << "Regresarás al menú principal" << endl;
				system("pause");
				return;
			}

			cout << "Ingrese el nombre completo del empleado" << endl;
			cin >> Nombre;
			cout << "Ingrese la nacionalidad: " << endl;
			cin >> Nacionalidad;
			cout << "Ingrese la residencia: " << endl;
			cin >> Residencia;
			cout << "Ingrese el telefono: " << endl;
			Telefono = FunCus.numeroTelefonoAleatorio();
			cout << Telefono << endl;
			cout << "Ingrese la cantidad de hijos: " << endl;
			NumeroHijos = stoi(FunCus.aceptarNumeros());
			cout << "Ingresa el Estado Civil: [1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << endl;
			numEstadoCivil = stoi(FunCus.aceptarNumeros());
			
			while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
			{
				cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
				numEstadoCivil = stoi(FunCus.aceptarNumeros());
			}

			switch (numEstadoCivil)
			{
			case 1:
				EstadoCivil = "Soltero(a)";
				break;

			case 2:
				EstadoCivil = "Casado(a)";
				break;

			case 3:
				EstadoCivil = "Viudo(a)";
				break;

			case 4:
				EstadoCivil = "Divorciado(a)";
				break;

			default:
				cout << RED << "Se ha seleccionado una opcion invalida" << RESET << endl;
				cout << "Regresarás al menú principal" << endl;
				system("pause");
				return;

			}

			cout << "Ingrese la cantidad de horas de trabajo: " << endl;
			HorasTrabajo = stoi(FunCus.aceptarNumeros());
			cout << "Ingresa el puesto del empleado: [1) Empleado, 2) Gerente]" << endl; //Empleado o Gerente?
			numTipoEmpleado = stoi(FunCus.aceptarNumeros());

			while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
			{
				cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
				numTipoEmpleado = stoi(FunCus.aceptarNumeros());
			}

			switch (numTipoEmpleado)
			{
			case 1:
				TipoEmpleado = "Empleado";
				break;

			case 2:
				TipoEmpleado = "Gerente";
				break;

			default:
				cout << RED << "Se ha seleccionado una opcion invalida" << RESET << endl;
				cout << "Regresarás al menú principal" << endl;
				system("pause");
				return;
			}

			cout << "--------------------------------------------" << endl; //?
			cout << "¿La información ingresada es correcta? [S/n]" << endl;
			confirmacion = FunCus.confirmacionDefS();

			if (confirmacion == "S")
			{
				ofstream perArchivo("Empleados.txt", ios::app);		// Creará el archivo
				perArchivo << TipoCedula << "/" << Cedula << "/" << Nombre << "/" << Nacionalidad << "/" << Residencia << "/" << Telefono << "/" << NumeroHijos << "/" << EstadoCivil << "/" << HorasTrabajo << "/" << TipoEmpleado << "\n";				// Escribirá los datos del empleado en el archivo
				perArchivo.close();									// Guardará los datos
				
				if (!perArchivo)
				{
					cout << "Ocurrio un error al guardar los datos" << endl;
					system("pause");
				}
				else
				{
					cout << "El empleado fue agregado con exito" << endl;
					system("pause");
				}
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
