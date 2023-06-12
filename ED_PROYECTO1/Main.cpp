#include <iostream>
#include <wchar.h>	// Para ingresar caracteres especiales
#include "ListaEmpleados.h"

using namespace std;

int MenuPricipal(int menuOpcion)
{
	Validaciones _validar;
	// Limpiar Consola
	system("cls");

	cout << "				Menú Principal" << endl << endl;
	cout << "	////////////////////////////////////////////////////" << endl;
	cout << "	//" << endl;
	cout << "	//	¿Que deseas realizar?" << endl;
	cout << "	//	1) Ingresar empleados." << endl;
	cout << "	//	2) Mostrar empleados." << endl;
	cout << "	//	3) Actualizar empleados." << endl;
	cout << "	//	4) Eliminar empleados." << endl;
	cout << "	//	5) Calcular salario de un empleado." << endl;
	cout << "	//	6) Calcular salario de todos los empleados." << endl;
	cout << "	//	7) Salir" << endl;
	cout << "	//" << endl;
	cout << "	////////////////////////////////////////////////////" << endl << endl << endl;
	cout << "Seleciona una opcion:" << endl;
	
	try
	{
		menuOpcion = stoi(_validar.aceptarNumeros());

		while (menuOpcion <= 0 || menuOpcion >= 8)
		{
			cout << RED << "El número escrito no coincide con ninguna de las opciones, selecciona una de las opciones de la lista" << RESET << endl;
			menuOpcion = stoi(_validar.aceptarNumeros());
		}
		
		return menuOpcion;
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
	_listaEmpleados.cargarArchivo();

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
					int numTipoCedula = 0;
					string confirmacion = "N";
					int numTipoEmpleado = 0;
					int numEstadoCivil = 0;

					// Variables para getline
					string Nombre;
					string Nacionalidad;
					string Residencia;

					while (confirmacion == "N")
					{
						system("cls");
						cout << "			Agregar Empleados" << endl << endl;
						cout << "¿Que tipo de cedula tiene el empleado? " << YELLOW << " [1) Nacional, 2) Juridica, 3) Extranjero]" << RESET << endl;
						numTipoCedula = stoi(_validar.aceptarNumeros());

						while (numTipoCedula <= 0 || numTipoCedula >= 4)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoCedula = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoCedula)
						{
						case 1:
							_persona.setTipoCedula("Nacional");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 9 digitos, incluir los 0)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 9 || _persona.getCedula().at(1) != '0' || _persona.getCedula().at(5) != '0'	|| _listaEmpleados.verificarCedula(_persona.getCedula()) == true)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado o ya existe. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());

							}
							break;

						case 2:
							_persona.setTipoCedula("Juridica");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 12 || _listaEmpleados.verificarCedula(_persona.getCedula()) == true)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 3:
							_persona.setTipoCedula("Extranjero");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 12 || _listaEmpleados.verificarCedula(_persona.getCedula()) == true)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());
							}
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");	// Activará el Try Catch, mandando este mensaje como error
						}

						cout << "Ingrese el nombre completo del empleado:" << endl;
						getline(cin, Nombre);
						_persona.setNombre(Nombre);

						cout << "Ingrese la nacionalidad: " << endl;
						getline(cin, Nacionalidad);
						_persona.setNacionalidad(Nacionalidad);

						cout << "Ingrese la residencia: " << endl;
						getline(cin, Residencia);
						_persona.setResidencia(Residencia);

						cout << "Ingrese el telefono: " << endl;
						_persona.setTelefono(_validar.numeroTelefonoAleatorio());
						cout << _persona.getTelefono() << endl;

						cout << "Ingrese la cantidad de hijos: " << endl;
						_persona.setNumeroHijos(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el Estado Civil: " << YELLOW << "[1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << RESET << endl;
						numEstadoCivil = stoi(_validar.aceptarNumeros());

						while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numEstadoCivil = stoi(_validar.aceptarNumeros());
						}

						switch (numEstadoCivil)
						{
						case 1:
							_persona.setEstadoCivil("Soltero(a)");
							break;

						case 2:
							_persona.setEstadoCivil("Casado(a)");
							break;

						case 3:
							_persona.setEstadoCivil("Viudo(a)");
							break;

						case 4:
							_persona.setEstadoCivil("Divorciado(a)");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");

						}

						cout << "Ingrese la cantidad de horas de trabajo: " << endl;
						_persona.setHorasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingrese la cantidad de horas extra de trabajo acumuladas: " << endl;
						_persona.setHorasExtrasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el puesto del empleado: " << YELLOW << "[1) Empleado, 2) Gerente]" << RESET << endl;
						numTipoEmpleado = stoi(_validar.aceptarNumeros());

						while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoEmpleado = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoEmpleado)
						{
						case 1:
							_persona.setTipoEmpleado("Empleado");
							break;

						case 2:
							_persona.setTipoEmpleado("Gerente");
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
							_listaEmpleados.agregarEmpleados(_persona);
							cout << GREEN << "¡El empleado ha sido agregado exitosamente!" << RESET << endl;
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
					system("cls");

					cout << "		Mostrar Empleados " << endl << endl;
					_listaEmpleados.mostrarEmpleadosCompleto();

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
				try
				{
					string cedulaModificar = "";
					Nodo* valorActual = NULL;

					system("cls");

					cout << "		Actualizar Empleados " << endl << endl;
					_listaEmpleados.mostrarEmpleadosSimple();

					cout << "Ingresa el número de cedula del empleado a actualizar:" << endl;
					cedulaModificar = _validar.aceptarNumeros();
					valorActual = _listaEmpleados.buscarEmpleados(cedulaModificar);

					while (valorActual == NULL)
					{
						cout << RED << "La cedula ingresada no fue encontrada, favor ingresar nuevamente la cedula:" << RESET << endl;
						cedulaModificar = _validar.aceptarNumeros();
						valorActual = _listaEmpleados.buscarEmpleados(cedulaModificar);
					}

					int numTipoCedula = 0;
					string confirmacion = "N";
					int numTipoEmpleado = 0;
					int numEstadoCivil = 0;

					// Variables para getline
					string Nombre;
					string Nacionalidad;
					string Residencia;

					while (confirmacion == "N")
					{
						system("cls");
						cout << "		Actualizar Empleados " << endl << endl;
						cout << "¿Que tipo de cedula tiene el empleado? " << YELLOW << " [1) Nacional, 2) Juridica, 3) Extranjero]" << RESET << endl;
						numTipoCedula = stoi(_validar.aceptarNumeros());

						while (numTipoCedula <= 0 || numTipoCedula >= 4)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoCedula = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoCedula)
						{
						case 1:
							_persona.setTipoCedula("Nacional");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 9 digitos, incluir los 0)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 9 || _persona.getCedula().at(1) != '0' || _persona.getCedula().at(5) != '0')
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 2:
							_persona.setTipoCedula("Juridica");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 3:
							_persona.setTipoCedula("Extranjero");

							cout << "Ingrese el número de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_persona.setCedula(_validar.aceptarNumeros());
							while (_persona.getCedula().length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el número de cedula" << RESET << endl;
								_persona.setCedula(_validar.aceptarNumeros());
							}
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");	// Activará el Try Catch, mandando este mensaje como error
						}

						cout << "Ingrese el nombre completo del empleado:" << endl;
						getline(cin, Nombre);
						_persona.setNombre(Nombre);

						cout << "Ingrese la nacionalidad: " << endl;
						getline(cin, Nacionalidad);
						_persona.setNacionalidad(Nacionalidad);

						cout << "Ingrese la residencia: " << endl;
						getline(cin, Residencia);
						_persona.setResidencia(Residencia);

						cout << "Ingrese el telefono: " << endl;
						_persona.setTelefono(_validar.numeroTelefonoAleatorio());
						cout << _persona.getTelefono() << endl;

						cout << "Ingrese la cantidad de hijos: " << endl;
						_persona.setNumeroHijos(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el Estado Civil: " << YELLOW << "[1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << RESET << endl;
						numEstadoCivil = stoi(_validar.aceptarNumeros());

						while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numEstadoCivil = stoi(_validar.aceptarNumeros());
						}

						switch (numEstadoCivil)
						{
						case 1:
							_persona.setEstadoCivil("Soltero(a)");
							break;

						case 2:
							_persona.setEstadoCivil("Casado(a)");
							break;

						case 3:
							_persona.setEstadoCivil("Viudo(a)");
							break;

						case 4:
							_persona.setEstadoCivil("Divorciado(a)");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");

						}

						cout << "Ingrese la cantidad de horas de trabajo: " << endl;
						_persona.setHorasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingrese la cantidad de horas extra de trabajo acumuladas: " << endl;
						_persona.setHorasExtrasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el puesto del empleado: " << YELLOW << "[1) Empleado, 2) Gerente]" << RESET << endl;
						numTipoEmpleado = stoi(_validar.aceptarNumeros());

						while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoEmpleado = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoEmpleado)
						{
						case 1:
							_persona.setTipoEmpleado("Empleado");
							break;

						case 2:
							_persona.setTipoEmpleado("Gerente");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");
						}

						cout << "--------------------------------------------" << endl; //?
						cout << "¿La información ingresada es correcta? [S/n]" << endl;
						confirmacion = _validar.confirmacionDefS();

						if (confirmacion == "S")
						{
							// Ya una vez que los datos son ingresados, serán actualizados mediante un los setters
							_listaEmpleados.actualizarEmpleados(valorActual, _persona);
							opcion = 0;
						}
					}
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
				
			case 4:
				// Eliminar Usuarios
				try
				{
					string cedulaBorrar = "";
					Nodo* valorActual = NULL;

					system("cls");

					cout << "		Eliminar Empleados " << endl << endl;
					_listaEmpleados.mostrarEmpleadosSimple();

					cout << "Ingresa el número de cedula del usuario a borrar:" << endl;
					cedulaBorrar = _validar.aceptarNumeros();
					valorActual = _listaEmpleados.buscarEmpleados(cedulaBorrar);

					while (valorActual == NULL)
					{
						cout << RED << "La cedula ingresada no fue encontrada, favor ingresar nuevamente la cedula:" << RESET << endl;
						cedulaBorrar = _validar.aceptarNumeros();
						valorActual = _listaEmpleados.buscarEmpleados(cedulaBorrar);
					}

					_listaEmpleados.borrarEmpleados(valorActual);

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
				try
				{
					string cedulaConsultar = "";
					Nodo* valorActual = NULL;

					system("cls");

					cout << "		Consultar Salario de un Empleado" << endl << endl;
					_listaEmpleados.mostrarEmpleadosSimple();

					cout << "Ingresa el número de cedula del usuario a consultar:" << endl;
					cedulaConsultar = _validar.aceptarNumeros();
					valorActual = _listaEmpleados.buscarEmpleados(cedulaConsultar);

					while (valorActual == NULL)
					{
						cout << RED << "La cedula ingresada no fue encontrada, favor ingresar nuevamente la cedula:" << RESET << endl;
						cedulaConsultar = _validar.aceptarNumeros();
						valorActual = _listaEmpleados.buscarEmpleados(cedulaConsultar);
					}

					system("cls");

					cout << "		Consultar Salario de un Empleado" << endl << endl;

					_listaEmpleados.calcularSalarioIndividual(valorActual);

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

			case 6:
				// Calcular Salario de todos los usuarios
				try
				{
					system("cls");

					cout << "		Consultar Salarios de todos los Empleados" << endl << endl;
					_listaEmpleados.calcularSalarioTodos();

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
				
			case 7:
				try
				{
					_listaEmpleados.guardarArchivo();
					exit(0);
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

			default:
				cout << RED << "Se ha seleccionado una opcion invalida" << RESET << endl;
		}
	}
	return 0;
}