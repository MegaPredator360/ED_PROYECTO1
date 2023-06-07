#include <iostream>
#include <wchar.h>	// Para ingresar caracteres especiales
#include "Empleado.h"

using namespace std;

int MenuPricipal(int menuOpcion)
{
	FuncionesCustom FunCus;
	// Limpiar Consola
	system("CLS");

	cout << "				Menú Principal" << endl << endl;
	cout << "	////////////////////////////////////////////////////" << endl;
	cout << "	//" << endl;
	cout << "	// ¿Que deseas realizar?" << endl;
	cout << "	// 1) Ingresar empleados." << endl;
	cout << "	// 2) Mostrar empleados." << endl;
	cout << "	// 3) Actualizar empleados." << endl;
	cout << "	// 4) Eliminar empleados." << endl;
	cout << "	// 5) Calcular salario de un empleados." << endl;
	cout << "	// 6) Calcular salario de todos los empleados." << endl;
	cout << "	// 7) Salir" << endl;
	cout << "	//" << endl;
	cout << "	////////////////////////////////////////////////////" << endl << endl << endl;
	cout << "Seleciona una opcion:" << endl;
	
	try
	{
		menuOpcion = stoi(FunCus.aceptarNumeros());

		while (menuOpcion <= 0 || menuOpcion >= 8)
		{
			cout << RED << "El número escrito no coincide con ninguna de las opciones, selecciona una de las opciones de la lista" << RESET << endl;
			cin >> menuOpcion;
		}

		if (menuOpcion == 7)
		{
			exit(0);
		}
		else
		{
			return menuOpcion;
		}
	}
	catch (exception& e)
	{
		cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
		system("pause");
		return menuOpcion = 0;
	}
}

int main()
{
	// Funcion para mostrar caracteres especiales
	setlocale(LC_ALL, "");

	cout << endl;
	cout << "				 /$$$$$$$$ /$$$$$$$" << endl;
	cout << "				| $$_____/| $$__  $$ " << endl;
	cout << "				| $$      | $$  \\ $$ " << endl;
	cout << "				| $$$$$   | $$  | $$ " << endl;
	cout << "				| $$__/   | $$  | $$ " << endl;
	cout << "				| $$      | $$  | $$ " << endl;
	cout << "				| $$$$$$$$| $$$$$$$/ " << endl;
	cout << "				|________/|_______/ " << endl << endl;
	cout << " /$$$$$$$                                                     /$$                       /$$  " << endl;
	cout << "| $$__  $$                                                   | $$                     /$$$$  " << endl;
	cout << "| $$  \\ $$ /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$       |_  $$  " << endl;
	cout << "| $$$$$$$//$$__  $$ /$$__  $$| $$  | $$ /$$__  $$ /$$_____/|_  $$_/   /$$__  $$        | $$  " << endl;
	cout << "| $$____/| $$  \\__/| $$  \\ $$| $$  | $$| $$$$$$$$| $$        | $$    | $$  \\ $$        | $$  " << endl;
	cout << "| $$     | $$      | $$  | $$| $$  | $$| $$_____/| $$        | $$ /$$| $$  | $$        | $$  " << endl;
	cout << "| $$     | $$      |  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$/       /$$$$$$" << endl;
	cout << "|__/     |__/       \\______/  \\____  $$ \\_______/ \\_______/   \\___/   \\______/       |______/" << endl;
	cout << "                              /$$  | $$" << endl;
	cout << "                             |  $$$$$$/" << endl;
	cout << "                             |  $$$$$$/" << endl;
	cout << "                              \\______/" << endl << endl;
	cout << "					Realizado por:" << endl;
	cout << "				  Aaron Steve Alfaro Zamora" << endl;
	cout << "				 Luis Fabian Arrieta Gonzalez" << endl << endl;

	// Pausar procesos y para continuar hay que pulsar cualquier tecla
	system("pause");

	Persona persona;
	int opcion = 0;

	while (opcion == 0)
	{
		opcion = MenuPricipal(opcion);

		switch(opcion)
		{
			case 1:
				// Ingresar Usuarios
				try
				{
					persona.GuardarPersona();
					opcion = 0;
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresarás al menú principal" << endl;
					system("pause");
					opcion = 0;
				}
				break;
			
			case 2:
				// Mostrar Usuarios
				cout << "*-------Lista de Empleados-------------*" << endl;


				cout << "*-------------------------------------*" << endl;
				break;

			case 3:
				// Actualizar Usuarios
				cout << "Ingrese la identificacion del empleado a modificar: " << endl;
				/*if (empleado != NULL ) {

				}
				else {
					:cout<<RED << "No coincide la identificacion" <<RESET<<endl;
				}*/
				break;
				
			case 4:
				// Eliminar Usuarios
				cout << "Ingrese la identificacion del empleado: " << endl;

				/*if (empleado != NULL ) {

				}
				else
				{
					cout << RED<< "Empleado no encontrado" <<RESET<<endl;
				}*/
				break;

			case 5:
				// Calcular Salario individual
				/*if (!=NUll) {
					cout << "*-------Lista de Salarios-------------*" << endl;


					cout << "*-------------------------------------*" << endl;
				}
				else {
					cout<<RED<< "No hay empleados en el sistema" <<RESET<< endl;
				}
				*/
				break;

			case 6:
				// Calcular Salario de todos los usuarios
				/*if (/*!=NUll) {
					cout << "*-------Lista de Salarios-------------*" << endl;


					cout << "*-------------------------------------*" << endl;
				}
				else {
					cout<<RED<< "No hay empleados en el sistema" <<RESET<< endl;
				}*/
				
				break;
				
			default:
				cout << RED << "Se ha seleccionado una opcion invalida" << RESET << endl;
		}
	}
	return 0;
}