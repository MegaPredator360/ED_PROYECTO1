#include <iostream>
#include <wchar.h>	// Para ingresar caracteres especiales
#include "ListaEmpleados.h"

using namespace std;

void GuardarPersona()
{
	
}

int MenuPricipal(int menuOpcion)
{
	Validaciones _validar;
	// Limpiar Consola
	system("cls");

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
		menuOpcion = stoi(_validar.aceptarNumeros());

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

	Persona _persona;
	ListaEmpleados _listaEmpleados;
	Validaciones _validar;
	int opcion = 0;

	while (opcion == 0)
	{
		opcion = MenuPricipal(opcion);

		switch(opcion)
		{
			case 1:
				// Ingresar Usuarios

				/*
				¡Te odio nodos!
				Me has arruindado mi metodo "ordenado" de hacer los menús
				*/
				try
				{
					//GuardarPersona();
					int numTipoCedula = 0;
					string confirmacion = "N";
					int numTipoEmpleado = 0;
					int numEstadoCivil = 0;

					// Valores a regresar
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

					while (confirmacion == "N")
					{
						system("cls");
						cout << "			Agregar Empleados" << endl << endl;
						cout << "¿Que tipo de cedula tiene el empleado? [1) Nacional, 2) Juridica, 3) Extranjero]" << endl;
						numTipoCedula = stoi(_validar.aceptarNumeros());	// Stoi convierte de String a Int

						while (numTipoCedula <= 0 || numTipoCedula >= 4)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoCedula = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoCedula)
						{
						case 1:
							TipoCedula = "Nacional";

							cout << "Ingrese el número de identificacion: (Minimo: 9 digitos, incluir los 0)" << endl;
							Cedula = _validar.aceptarNumeros();
							while (Cedula.length() != 9 || Cedula.at(1) != '0' || Cedula.at(5) != '0')
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								Cedula = _validar.aceptarNumeros();
							}
							break;

						case 2:
							TipoCedula = "Juridica";

							cout << "Ingrese el número de identificacion: (Minimo: 12 digitos)" << endl;
							Cedula = _validar.aceptarNumeros();
							while (Cedula.length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								Cedula = _validar.aceptarNumeros();
							}
							break;

						case 3:
							TipoCedula = "Extranjero";

							cout << "Ingrese el número de identificacion: (Minimo: 12 digitos)" << endl;
							Cedula = _validar.aceptarNumeros();
							while (Cedula.length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								Cedula = _validar.aceptarNumeros();
							}
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");	// Activará el Try Catch, mandando este mensaje como error
						}

						cout << "Ingrese el nombre completo del empleado:" << endl;
						cin >> Nombre;
						cout << "Ingrese la nacionalidad: " << endl;
						cin >> Nacionalidad;
						cout << "Ingrese la residencia: " << endl;
						cin >> Residencia;
						cout << "Ingrese el telefono: " << endl;
						Telefono = _validar.numeroTelefonoAleatorio();
						cout << Telefono << endl;
						cout << "Ingrese la cantidad de hijos: " << endl;
						NumeroHijos = stoi(_validar.aceptarNumeros());
						cout << "Ingresa el Estado Civil: [1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << endl;
						numEstadoCivil = stoi(_validar.aceptarNumeros());

						while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numEstadoCivil = stoi(_validar.aceptarNumeros());
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
							throw exception("La opcion seleccionada no esta definida.");

						}

						cout << "Ingrese la cantidad de horas de trabajo: " << endl;
						HorasTrabajo = stoi(_validar.aceptarNumeros());
						cout << "Ingresa el puesto del empleado: [1) Empleado, 2) Gerente]" << endl; //Empleado o Gerente?
						numTipoEmpleado = stoi(_validar.aceptarNumeros());

						while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoEmpleado = stoi(_validar.aceptarNumeros());
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
							throw exception("La opcion seleccionada no esta definida.");
						}

						cout << "--------------------------------------------" << endl; //?
						cout << "¿La información ingresada es correcta? [S/n]" << endl;
						confirmacion = _validar.confirmacionDefS();

						if (confirmacion == "S")
						{
							// Ya una vez que los datos son ingresados, serán enviados a la lista para ser agregados
							Persona nuevaPersona(TipoCedula, Cedula, Nombre, Nacionalidad, Residencia, Telefono, NumeroHijos, EstadoCivil, HorasTrabajo, TipoEmpleado);
							_listaEmpleados.agregarEmpleados(nuevaPersona);
							cout << "¡El empleado ha sido agregado exitosamente!" << endl;
							system("pause");
						}
					}
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
				try
				{
					_listaEmpleados.mostrarEmpleados();
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
				int usuario;

				try
				{
					_listaEmpleados.borrarEmpleados();
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