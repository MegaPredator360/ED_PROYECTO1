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
	// Metodo para confirmar una accion con Si o No, por defecto Sí
	string confirmacionDefS();
	// Metodo para confirmar una accion con Si o No, por defecto No
	string confirmacionDefN();
	// Tamaño del String para el Split
	int tamanoString(string texto);
};

