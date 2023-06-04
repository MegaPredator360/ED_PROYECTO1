#include <iostream>
#include <wchar.h>	// Para ingresar caracteres especiales

using namespace std;

int MenuPricipal(int menuOpcion)
{
	cout << endl << endl;
	cout << "	////////////////////////////////////////////////////" << endl;
	cout << "	//" << endl;
	cout << "	// ¿Que deseas realizar?" << endl;
	cout << "	// 1) Ingresar usuarios." << endl;
	cout << "	// 2) Mostrar usuarios." << endl;
	cout << "	// 3) Actualizar usuarios." << endl;
	cout << "	// 4) Eliminar usuarios." << endl;
	cout << "	// 5) Calcular salario de un usuario." << endl;
	cout << "	// 6) Calcular salario de todos los usuarios." << endl;
	cout << "	// 7) Salir" << endl;
	cout << "	//" << endl;
	cout << "	////////////////////////////////////////////////////" << endl << endl << endl;
	cout << "Seleciona una opcion:" << endl;
	cin >> menuOpcion;

	while (menuOpcion <= 0 || menuOpcion >= 8)
	{
		cout << "La número escrito no coincide con ninguna de las opciones, selecciona una de las opciones de la lista" << endl;
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

	int opcion = 0;

	// Limpiar Consola
	system("CLS");

	opcion = MenuPricipal(opcion);
	
	cout << opcion;

	return 0;
}