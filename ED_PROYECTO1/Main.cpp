#include <iostream>
#include <wchar.h>	// Para ingresar caracteres especiales
#include "ListaEmpleados.h"

using namespace std;

int MenuPricipal(int menuOpcion)
{
	Validaciones _validar;
	// Limpiar Consola
	system("cls");

	cout << "				Men� Principal" << endl << endl;
	cout << "	////////////////////////////////////////////////////" << endl;
	cout << "	//" << endl;
	cout << "	//	�Que deseas realizar?" << endl;
	cout << "	//	1) Ingresar empleados." << endl;
	cout << "	//	2) Mostrar empleados." << endl;
	cout << "	//	3) Actualizar empleados." << endl;
	cout << "	//	4) Eliminar empleados." << endl;
	cout << "	//	5) Eliminar lista completa." << endl;
	cout << "	//	6) Calcular salario de un empleado." << endl;
	cout << "	//	7) Calcular salario de todos los empleados." << endl;
	cout << "	//	8) Salir" << endl;
	cout << "	//" << endl;
	cout << "	////////////////////////////////////////////////////" << endl << endl << endl;
	cout << "Seleciona una opcion:" << endl;
	
	try
	{
		menuOpcion = stoi(_validar.aceptarNumeros());

		while (menuOpcion <= 0 || menuOpcion >= 9)
		{
			cout << RED << "El n�mero escrito no coincide con ninguna de las opciones, selecciona una de las opciones de la lista" << RESET << endl;
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

	Empleado _empleado;
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
				�Te odio nodos!
				Me has arruindado mi metodo "ordenado" de hacer los men�s
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
						cout << "�Que tipo de cedula tiene el empleado? " << YELLOW << "[1) Nacional, 2) Juridica, 3) Extranjero]" << RESET << endl;
						numTipoCedula = stoi(_validar.aceptarNumeros());

						while (numTipoCedula <= 0 || numTipoCedula >= 4)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numTipoCedula = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoCedula)
						{
						case 1:
							_empleado.setTipoCedula("Nacional");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 9 digitos, incluir los 0)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 9 || _empleado.getCedula().at(1) != '0' || _empleado.getCedula().at(5) != '0'	|| _listaEmpleados.verificarCedula(_empleado.getCedula()) != false)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado o ya existe. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 2:
							_empleado.setTipoCedula("Juridica");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 12 || _listaEmpleados.verificarCedula(_empleado.getCedula()) == true)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 3:
							_empleado.setTipoCedula("Extranjero");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 12 || _listaEmpleados.verificarCedula(_empleado.getCedula()) == true)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");	// Activar� el Try Catch, mandando este mensaje como error
						}

						cout << "Ingrese el nombre completo del empleado:" << endl;

						getline(cin, Nombre);

						while (Nombre == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar el nombre del empleado:" << RESET << endl;
							getline(cin, Nombre);
						}
						
						_empleado.setNombre(Nombre);

						cout << "Ingrese la nacionalidad: " << endl;
						getline(cin, Nacionalidad);

						while (Nacionalidad == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar la nacionalidad del empleado:" << RESET << endl;
							getline(cin, Nacionalidad);
						}

						_empleado.setNacionalidad(Nacionalidad);

						cout << "Ingrese la residencia: " << endl;
						getline(cin, Residencia);

						while (Residencia == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar la residencia del empleado:" << RESET << endl;
							getline(cin, Residencia);
						}

						_empleado.setResidencia(Residencia);

						cout << "Ingrese el telefono: " << endl;
						_empleado.setTelefono(_validar.numeroTelefonoAleatorio());
						cout << _empleado.getTelefono() << endl;

						cout << "Ingrese la cantidad de hijos: " << endl;
						_empleado.setNumeroHijos(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el Estado Civil: " << YELLOW << "[1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << RESET << endl;
						numEstadoCivil = stoi(_validar.aceptarNumeros());

						while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numEstadoCivil = stoi(_validar.aceptarNumeros());
						}

						switch (numEstadoCivil)
						{
						case 1:
							_empleado.setEstadoCivil("Soltero(a)");
							break;

						case 2:
							_empleado.setEstadoCivil("Casado(a)");
							break;

						case 3:
							_empleado.setEstadoCivil("Viudo(a)");
							break;

						case 4:
							_empleado.setEstadoCivil("Divorciado(a)");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");

						}

						cout << "Ingrese la cantidad de horas de trabajo al mes: " << endl;
						_empleado.setHorasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingrese la cantidad de horas extra de trabajo acumuladas en el mes: " << endl;
						_empleado.setHorasExtrasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el puesto del empleado: " << YELLOW << "[1) Empleado, 2) Gerente]" << RESET << endl;
						numTipoEmpleado = stoi(_validar.aceptarNumeros());

						while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numTipoEmpleado = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoEmpleado)
						{
						case 1:
							_empleado.setTipoEmpleado("Empleado");
							break;

						case 2:
							_empleado.setTipoEmpleado("Gerente");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");
						}

						cout << "--------------------------------------------" << endl; //?
						cout << "�La informaci�n ingresada es correcta? [S/n]" << endl;
						confirmacion = _validar.confirmacionDefS();

						if (confirmacion == "S")
						{
							// Ya una vez que los datos son ingresados, ser�n enviados a la lista para ser agregados
							_listaEmpleados.agregarEmpleados(_empleado);
							_listaEmpleados.guardarArchivo();
							cout << GREEN << "�El empleado ha sido agregado exitosamente!" << RESET << endl;
							system("pause");
						}
					}
					opcion = 0;
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresar�s al men� principal" << endl;
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
					cout << "Regresar�s al men� principal" << endl;
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

					cout << "Ingresa el n�mero de cedula del empleado a actualizar:" << endl;
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
						cout << "�Que tipo de cedula tiene el empleado? " << YELLOW << " [1) Nacional, 2) Juridica, 3) Extranjero]" << RESET << endl;
						numTipoCedula = stoi(_validar.aceptarNumeros());

						while (numTipoCedula <= 0 || numTipoCedula >= 4)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numTipoCedula = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoCedula)
						{
						case 1:
							_empleado.setTipoCedula("Nacional");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 9 digitos, incluir los 0)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 9 || _empleado.getCedula().at(1) != '0' || _empleado.getCedula().at(5) != '0')
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 2:
							_empleado.setTipoCedula("Juridica");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						case 3:
							_empleado.setTipoCedula("Extranjero");

							cout << "Ingrese el n�mero de cedula: " << YELLOW << "(Minimo: 12 digitos)" << RESET << endl;
							_empleado.setCedula(_validar.aceptarNumeros());
							while (_empleado.getCedula().length() != 12)
							{
								cout << RED << "Lo ingresado no coincide con el formato solicitado. Vuelve a ingresar el n�mero de cedula" << RESET << endl;
								_empleado.setCedula(_validar.aceptarNumeros());
							}
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");	// Activar� el Try Catch, mandando este mensaje como error
						}

						cout << "Ingrese el nombre completo del empleado:" << endl;
						getline(cin, Nombre);

						while (Nombre == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar el nombre del empleado:" << RESET << endl;
							getline(cin, Nombre);
						}

						_empleado.setNombre(Nombre);

						cout << "Ingrese la nacionalidad: " << endl;
						getline(cin, Nacionalidad);

						while (Nacionalidad == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar la nacionalidad del empleado:" << RESET << endl;
							getline(cin, Nacionalidad);
						}

						_empleado.setNacionalidad(Nacionalidad);

						cout << "Ingrese la residencia: " << endl;
						getline(cin, Residencia);

						while (Residencia == "")
						{
							cout << RED << "El espacio est� vacio, desbes de ingresar la residencia del empleado:" << RESET << endl;
							getline(cin, Residencia);
						}

						_empleado.setResidencia(Residencia);

						cout << "Ingrese el telefono: " << endl;
						_empleado.setTelefono(_validar.numeroTelefonoAleatorio());
						cout << _empleado.getTelefono() << endl;

						cout << "Ingrese la cantidad de hijos: " << endl;
						_empleado.setNumeroHijos(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el Estado Civil: " << YELLOW << "[1) Soltero(a), 2) Casado(a), 3) Viudo(a), 4) Divorciado(a)]" << RESET << endl;
						numEstadoCivil = stoi(_validar.aceptarNumeros());

						while (numEstadoCivil <= 0 || numEstadoCivil >= 5)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numEstadoCivil = stoi(_validar.aceptarNumeros());
						}

						switch (numEstadoCivil)
						{
						case 1:
							_empleado.setEstadoCivil("Soltero(a)");
							break;

						case 2:
							_empleado.setEstadoCivil("Casado(a)");
							break;

						case 3:
							_empleado.setEstadoCivil("Viudo(a)");
							break;

						case 4:
							_empleado.setEstadoCivil("Divorciado(a)");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");

						}

						cout << "Ingrese la cantidad de horas de trabajo al mes: " << endl;
						_empleado.setHorasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingrese la cantidad de horas extra de trabajo acumuladas en el mes: " << endl;
						_empleado.setHorasExtrasTrabajo(stoi(_validar.aceptarNumeros()));

						cout << "Ingresa el puesto del empleado: " << YELLOW << "[1) Empleado, 2) Gerente]" << RESET << endl;
						numTipoEmpleado = stoi(_validar.aceptarNumeros());

						while (numTipoEmpleado <= 0 || numTipoEmpleado >= 3)
						{
							cout << RED << "El n�mero ingresado no coincide con ninguna de las opciones, ingresa un n�mero que coincida con las opciones: " << RESET << endl;
							numTipoEmpleado = stoi(_validar.aceptarNumeros());
						}

						switch (numTipoEmpleado)
						{
						case 1:
							_empleado.setTipoEmpleado("Empleado");
							break;

						case 2:
							_empleado.setTipoEmpleado("Gerente");
							break;

						default:
							throw exception("La opcion seleccionada no esta definida.");
						}

						cout << "--------------------------------------------" << endl; //?
						cout << "�La informaci�n ingresada es correcta? [S/n]" << endl;
						confirmacion = _validar.confirmacionDefS();

						if (confirmacion == "S")
						{
							// Ya una vez que los datos son ingresados, ser�n actualizados mediante un los setters
							_listaEmpleados.actualizarEmpleados(valorActual, _empleado);
							_listaEmpleados.guardarArchivo();
							opcion = 0;
						}
					}
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresar�s al men� principal" << endl;
					system("pause");
					opcion = 0;
				}

				break;
				
			case 4:
				// Eliminar Usuarios
				try
				{
					string cedulaBorrar = "", confirmar = "N";
					Nodo* valorActual = NULL;

					system("cls");

					cout << "		Eliminar Empleados " << endl << endl;
					_listaEmpleados.mostrarEmpleadosSimple();

					while (confirmar == "N")
					{
						cout << "Ingresa el n�mero de cedula del usuario a borrar:" << endl;
						cedulaBorrar = _validar.aceptarNumeros();
						valorActual = _listaEmpleados.buscarEmpleados(cedulaBorrar);

						while (valorActual == NULL)
						{
							cout << RED << "La cedula ingresada no fue encontrada, favor ingresar nuevamente la cedula:" << RESET << endl;
							cedulaBorrar = _validar.aceptarNumeros();
							valorActual = _listaEmpleados.buscarEmpleados(cedulaBorrar);
						}

						cout << "El usuario seleccionado es: " << valorActual->getValor().getNombre() << endl;
						cout << "�Estas seguro de borrar este empleado? - " << RED << "La accion no se puede revertir." << RESET << " [s/N]" << endl;
						confirmar = _validar.confirmacionDefN();

						if (confirmar == "S")
						{
							_listaEmpleados.borrarEmpleados(valorActual);
							_listaEmpleados.guardarArchivo();
						}
					}

					opcion = 0;
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresar�s al men� principal" << endl;
					system("pause");
					opcion = 0;
				}
				break;

			case 5:
				// Borrar lista Completa
				try
				{
					string confirmar;
					system("cls");

					cout << "		Eliminar lista de Empleados" << endl << endl;
					cout << "�Est�s apunto de eliminar la lista completa de empleados registrados!" << endl;
					cout << "�Est�s seguro de realizar est� acci�n? - " << RED << "Est� acci�n no se puede revertir." << RESET << " [s/N]" << endl;
					confirmar = _validar.confirmacionDefN();

					if (confirmar == "S")
					{
						_listaEmpleados.~ListaEmpleados();
						_listaEmpleados.guardarArchivo();
						cout << GREEN << "�La lista ha sido eliminada con exito!" << RESET << endl;
						system("pause");
						opcion = 0;
					}

					opcion = 0;
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresar�s al men� principal" << endl;
					system("pause");
					opcion = 0;
				}
				break;

			case 6:
				// Calcular Salario individual
				try
				{
					string cedulaConsultar = "";
					Nodo* valorActual = NULL;

					system("cls");

					cout << "		Consultar Salario de un Empleado" << endl << endl;
					_listaEmpleados.mostrarEmpleadosSimple();

					cout << "Ingresa el n�mero de cedula del usuario a consultar:" << endl;
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
					cout << "Regresar�s al men� principal" << endl;
					system("pause");
					opcion = 0;
				}
				break;

			case 7:
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
					cout << "Regresar�s al men� principal" << endl;
					system("pause");
					opcion = 0;
				}
				break;
				
			case 8:
				try
				{
					exit(0);
				}
				catch (exception& e)
				{
					cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
					cout << RED << "---------------------------------" << RESET << endl;
					cout << "Regresar�s al men� principal" << endl;
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