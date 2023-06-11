#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
// Para intereacci�n con archivos
#include <fstream>
// Para reproducir sonidos
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib") // Vincular� las funciones multimedia de Windows con el programa
// Para generar n�meros aleatorios
#include <random>
// Colores para consola
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define YELLOW	"\x1B[33m"
#define GREEN	"\x1B[32m"

using namespace std;

class Validaciones
{
public:
	// Para ingresar solo n�meros
	string aceptarNumeros();
	// Generar n�meros de telefono aleatorios
	int numeroTelefonoAleatorio();
	// Metodo de confirmacion que solo acepte 5 botones
	string confirmacionDefS();
	// Tama�o del String para el Split
	int tamanoString(string texto);
};

