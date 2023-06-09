#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados() 
{
	// Se declararán los valores como nulos
	primerValor = valorActual = NULL;
}

// La funcion queda de tipo bool para realizar una validacion por si regreso los datos
void ListaEmpleados::agregarEmpleados(Persona p) 
{
	valorActual = primerValor;

	//Se buscará si el primer valor de la lista ha sido, si no... Buscará por los nodos hasta encontrar un lugar para agregar los datos
	if (primerValor == NULL || primerValor -> getValor().getCedula() > p.getCedula())
	{
		primerValor = new Nodo(p, primerValor);
	}
	else 
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValor().getCedula() <= p.getCedula())) 
		{
			valorActual = valorActual->getSiguiente();
		}
		Nodo* nuevo = new Nodo(p, valorActual -> getSiguiente());
		valorActual -> setSiguienteNodo(nuevo);
	}
}

void ListaEmpleados::mostrarEmpleados()
{
	try
	{
		system("cls");

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
			cout << "¡Se han cargado todos los empleados registrados!" << endl;
			system("pause");
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void ListaEmpleados::borrarEmpleados() 
{
	mostrarEmpleadosBorrar();

	Validaciones _validar;

	cout << "Ingresa el número de cedula del usuario a eliminar:" << endl;
	string cedulaBorrar = _validar.aceptarNumeros();

	while (valorActual == NULL)
	{
		Nodo* valorAnterior = NULL;
		valorActual = primerValor;

		if (primerValor->getValor().getCedula() == cedulaBorrar)
		{
			valorActual = valorActual->getSiguiente();
			delete(primerValor);
			primerValor = valorActual;
			return;
		}

		while (valorActual != NULL && valorActual -> getValor().getCedula() != cedulaBorrar)
		{
			valorAnterior = valorActual;
			valorActual = valorActual -> getSiguiente();
		}

		if (valorActual == NULL)
		{
			cout << RED << "El número de cedula ingresado no está registrado en el sistema, vuelve a ingresar el número de cedula: " << RESET << endl;
			cedulaBorrar = _validar.aceptarNumeros();
		}
		else
		{
			valorAnterior -> setSiguienteNodo(valorActual -> getSiguiente());
			delete valorActual;
			cout << "¡El empleado ha sido eliminado con exito!" << endl;
			system("pause");
		}
	}
}

void ListaEmpleados::mostrarEmpleadosBorrar()
{
	try
	{
		system("cls");

		valorActual = primerValor;
		if (valorActual == NULL)		// Si la lista no tiene valores registrados
		{
			throw exception("No hay usuarios registrados en el sistema");		// Activará el try catch indicando que no hay usuarios registrados
		}
		else
		{
			cout << "				Eliminar Empleados" << endl << endl;
			cout << "	--------------------------------------------------" << endl;
			while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
			{
				valorActual -> getValor().MostrarPersonaBorrar();
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

