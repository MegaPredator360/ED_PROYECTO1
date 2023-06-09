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

#include <random>

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
};

