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

#include <random>

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
};

