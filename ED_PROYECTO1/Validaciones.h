#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
// Para intereacción con archivos
#include <fstream>
// Para reproducir sonidos
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib") // Vinculará las funciones multimedia de Windows con el programa
// Para generar números aleatorios
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
	// Para ingresar solo números
	string aceptarNumeros();
	// Generar números de telefono aleatorios
	int numeroTelefonoAleatorio();
	// Metodo de confirmacion que solo acepte 5 botones
	string confirmacionDefS();
	// Tamaño del String para el Split
	int tamanoString(string texto);
};

