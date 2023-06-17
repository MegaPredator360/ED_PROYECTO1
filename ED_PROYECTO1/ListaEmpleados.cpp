#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados() 
{
	// Se declararán los valores como nulos
	primerValor = valorActual = NULL;
}

void ListaEmpleados::agregarEmpleados(Empleado e) 
{
	valorActual = primerValor;

	//Se buscará si el primer valor de la lista ha sido usado, si no... Buscará por los nodos hasta encontrar un lugar para agregar los datos
	if (primerValor == NULL || primerValor -> getValor().getCedula() > e.getCedula())
	{
		primerValor = new Nodo(e, primerValor);
	}
	else 
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValor().getCedula() <= e.getCedula())) 
		{
			valorActual = valorActual -> getSiguiente();
		}
		Nodo* nuevo = new Nodo(e, valorActual -> getSiguiente());
		valorActual -> setSiguienteNodo(nuevo);
	}
}

void ListaEmpleados::actualizarEmpleados(Nodo* valorModificar, Empleado e)
{
	try
	{
		valorModificar -> setValor(e);
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
		Nodo* valorAnterior = NULL;
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

		while (valorActual != NULL && valorActual -> getValor().getCedula() != valorBorrar -> getValor().getCedula())
		{
			valorAnterior = valorActual;
			valorActual = valorActual -> getSiguiente();
		}

		if (valorActual == NULL)
		{
			throw exception("Hubo un error al borrar el empleado");
			return;
		}
		else
		{
			valorAnterior -> setSiguienteNodo(valorActual -> getSiguiente());
			delete valorActual;
			cout << GREEN << "¡El empleado ha sido eliminado con exito!" << RESET << endl;
			system("pause");
			return;
		}
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
		valorConsultar -> getValor().CalcularSalario();
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
		float cantidadHoras = 0;
		float cantidadExtras = 0;
		float cantidadHijos = 0;
		float cantidadSeguro = 0;
		float cantidadGastos = 0;
		float salarioMensual = 0;

		valorActual = primerValor;

		if (valorActual == NULL)		// Si la lista no tiene valores registrados
		{
			throw exception("No hay usuarios registrados en el sistema");		// Activará el try catch indicando que no hay usuarios registrados
		}
		else
		{

			while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
			{
				valorActual -> getValor().CalcularSalario();
				
				// Recopilación de datos para resumen
				if (valorActual -> getValor().getTipoEmpleado() == "Gerente")
				{
					cantidadHoras = cantidadHoras + (valorActual -> getValor().getHorasTrabajo() * 5000);
					cantidadExtras = cantidadExtras + (valorActual -> getValor().getHorasExtrasTrabajo() * 3000);
				}
				else
				{
					cantidadHoras = cantidadHoras + (valorActual -> getValor().getHorasTrabajo() * 3000);
					cantidadExtras = cantidadExtras + (valorActual -> getValor().getHorasExtrasTrabajo() * 1000);
				}

				cantidadHijos = cantidadHijos + (valorActual -> getValor().getNumeroHijos() * 5000);

				valorActual = valorActual -> getSiguiente();
			}

			salarioMensual = cantidadExtras + cantidadHijos + cantidadHoras;
			cantidadSeguro = salarioMensual * 0.1050;
			cantidadGastos = salarioMensual * 0.15;
			salarioMensual = salarioMensual - (cantidadSeguro + cantidadGastos);
			Empleado _empleado(cantidadHoras, cantidadExtras, cantidadHijos, cantidadSeguro, cantidadGastos, salarioMensual);

			_empleado.MostrarSalarioTotal();

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
		Empleado _empleado;
		Validaciones _validar;

		// Cargar datos del archivo
		ifstream cargarDatos("datosEmpleado.dat");
		if (cargarDatos.is_open())
		{
			string datos;
			int cantidadLetras;
			while (getline(cargarDatos, datos))
			{
				_empleado.setTipoCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getTipoCedula()) + 1);

				_empleado.setCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getCedula()) + 1);

				_empleado.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getNombre()) + 1);

				_empleado.setNacionalidad(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getNacionalidad()) + 1);

				_empleado.setResidencia(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getResidencia()) + 1);

				_empleado.setTelefono(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_empleado.getTelefono())) + 1);

				_empleado.setNumeroHijos(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_empleado.getNumeroHijos())) + 1);

				_empleado.setEstadoCivil(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getEstadoCivil()) + 1);

				_empleado.setHorasTrabajo(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_empleado.getHorasTrabajo())) + 1);

				_empleado.setHorasExtrasTrabajo(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, _validar.tamanoString(to_string(_empleado.getHorasExtrasTrabajo())) + 1);

				_empleado.setTipoEmpleado(datos.substr(0, datos.find("/")));
				datos.erase(0, _validar.tamanoString(_empleado.getTipoEmpleado()) + 1);

				agregarEmpleados(_empleado);
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

	if (primerValor != NULL && primerValor -> getValor().getCedula() == cedula)
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValor().getCedula() != cedula)
	{
		valorActual = valorActual -> getSiguiente();
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

