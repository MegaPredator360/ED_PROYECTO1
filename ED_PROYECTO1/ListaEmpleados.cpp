#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados() 
{
	// Se declararán los valores como nulos
	primerValor = valorActual = NULL;
}

void ListaEmpleados::agregarEmpleados(Persona p) 
{
	valorActual = primerValor;

	//Se buscará si el primer valor de la lista ha sido usado, si no... Buscará por los nodos hasta encontrar un lugar para agregar los datos
	if (primerValor == NULL || primerValor -> getValor().getCedula() > p.getCedula())
	{
		primerValor = new Nodo(p, primerValor);
	}
	else 
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValor().getCedula() <= p.getCedula())) 
		{
			valorActual = valorActual -> getSiguiente();
		}
		Nodo* nuevo = new Nodo(p, valorActual -> getSiguiente());
		valorActual -> setSiguienteNodo(nuevo);
	}
}

void ListaEmpleados::actualizarEmpleados(Nodo* valorModificar, Persona p)
{
	try
	{
		valorModificar -> setValor(p);
		cout << GREEN << "¡El empleado ha sido actualizado exitosamente!" << RESET << endl;
		system("pause");
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::mostrarEmpleadosCompleto()
{
	try
	{
		valorActual = primerValor;
		if (valorActual == NULL)		// Si la lista no tiene valores registrados
		{
			throw exception("No hay usuarios registrados en el sistema");		// Activará el try catch indicando que no hay usuarios registrados
		}
		else
		{
			while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
			{
				valorActual -> getValor().MostrarPersona();
				valorActual = valorActual -> getSiguiente();
			}
			cout << "--------------------------------------------------" << endl;
			cout << GREEN << "¡Se han cargado todos los empleados registrados!" << RESET << endl;
			system("pause");
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::borrarEmpleados(Nodo* valorBorrar) 
{
	try
	{
		valorActual = primerValor;

		if (primerValor == valorBorrar)	// Revisará si el primer empleado coincide con la cedula recibida
		{
			valorActual = valorActual -> getSiguiente();
			delete(primerValor);
			primerValor = valorActual;
			cout << GREEN << "¡El empleado ha sido eliminado con exito!" << RESET << endl;
			system("pause");
			return;
		}

		delete valorBorrar;
		cout << GREEN << "¡El empleado ha sido eliminado con exito!" << RESET << endl;
		system("pause");
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::calcularSalarioIndividual(Nodo* valorConsultar)
{
	try
	{
		Empleado _empleado;

		_empleado.CalcularSalario(valorConsultar -> getValor());
		cout << "--------------------------------------------------" << endl;
		cout << GREEN << "¡Se han cargado los datos con exito!" << RESET << endl;
		system("pause");
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::calcularSalarioTodos()		// Se reutiliza la mayoria por no decir todo lo usado para mostrar todos los usuarios
{
	try
	{
		Empleado _empleado;
		valorActual = primerValor;

		if (valorActual == NULL)		// Si la lista no tiene valores registrados
		{
			throw exception("No hay usuarios registrados en el sistema");		// Activará el try catch indicando que no hay usuarios registrados
		}
		else
		{
			while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
			{
				_empleado.CalcularSalario(valorActual -> getValor());
				valorActual = valorActual -> getSiguiente();
			}

			cout << "--------------------------------------------------" << endl;
			cout << GREEN << "¡Se han cargado los datos con exito!" << RESET << endl;
			system("pause");
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::guardarArchivo()
{
	try
	{
		string valor;
		ofstream archivoDatos("datosEmpleado.dat");
		valorActual = primerValor;

		while (valorActual != NULL) // Se ira por cada nodo buscando los datos para guardalos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			archivoDatos << valorActual -> getValor().ObtenerPersona() << "\n";
			valorActual = valorActual -> getSiguiente();
		}

		archivoDatos.close();
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::cargarArchivo()
{
	try
	{
		Persona _persona;
		Validaciones _validar;

		// Cargar datos del archivo
		ifstream cargarDatos("datosEmpleado.dat");
		if (cargarDatos.is_open())
		{
			string datos;
			int cantidadLetras;
			while (getline(cargarDatos, datos))
			{
				_persona.setTipoCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getTipoCedula()) + 1);

				_persona.setCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getCedula()) + 1);

				_persona.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getNombre()) + 1);

				_persona.setNacionalidad(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getNacionalidad()) + 1);

				_persona.setResidencia(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getResidencia()) + 1);

				_persona.setTelefono(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_persona.getTelefono())) + 1);

				_persona.setNumeroHijos(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_persona.getNumeroHijos())) + 1);

				_persona.setEstadoCivil(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getEstadoCivil()) + 1);

				_persona.setHorasTrabajo(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_persona.getHorasTrabajo())) + 1);

				_persona.setHorasExtrasTrabajo(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_persona.getHorasExtrasTrabajo())) + 1);

				_persona.setTipoEmpleado(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_persona.getTipoEmpleado()) + 1);

				agregarEmpleados(_persona);
			}
		}
		cargarDatos.close();
	}
	catch (exception& e)
	{
		cout << RED << "Un error a ocurrido al leer el archivo: " << RESET << e.what() << endl;
		system("pause");
	}
}

bool ListaEmpleados::verificarCedula(string cedula)
{
	valorActual = primerValor;

	if (primerValor -> getValor().getCedula() == cedula)
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValor().getCedula() != cedula)
	{
		valorActual = valorActual->getSiguiente();
	}

	if (valorActual == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ListaEmpleados::mostrarEmpleadosSimple()
{
	try
	{
		valorActual = primerValor;
		if (valorActual == NULL)		// Si la lista no tiene valores registrados
		{
			throw exception("No hay usuarios registrados en el sistema");		// Activará el try catch indicando que no hay usuarios registrados
		}
		else
		{
			cout << "	--------------------------------------------------" << endl;
			while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
			{
				valorActual -> getValor().MostrarPersonaSimple();
				valorActual = valorActual -> getSiguiente();
			}
			cout << "	--------------------------------------------------" << endl << endl;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

Nodo* ListaEmpleados::buscarEmpleados(string cedula)
{
	valorActual = primerValor;

	if (primerValor -> getValor().getCedula() == cedula)
	{
		return primerValor;
	}

	while (valorActual != NULL && valorActual -> getValor().getCedula() != cedula)
	{
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL)
	{
		return valorActual = NULL;
	}
	else
	{
		return valorActual;
	}
}

ListaEmpleados::~ListaEmpleados()
{
	valorActual = primerValor;
	while (primerValor != NULL) 
	{
		valorActual = primerValor;
		primerValor = primerValor -> getSiguiente();
		delete valorActual;
	}
	valorActual = NULL;
	primerValor = NULL;
}

