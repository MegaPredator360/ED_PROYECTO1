#include "Empleado.h"

void Empleado::CalcularSalario(Persona p)
{
	try
	{

		if (p.getTipoEmpleado() == "Gerente")
		{
			SalarioMensual = p.getHorasTrabajo() * 5000;							// A los gerentes se les paga ₡5000 la hora
			SalarioMensual = SalarioMensual + (p.getHorasExtrasTrabajo() * 3000);	// Cada hora extra equivale a ₡3000
			SalarioMensual = SalarioMensual + (p.getNumeroHijos() * 5000);			// Por cada hijo que tenga, se le añaden ₡5000 al salario
			SalarioMensual = SalarioMensual - (SalarioMensual * 0.1050);			// Se le rebaja un %10.50 para el seguro
			SalarioMensual = SalarioMensual - (SalarioMensual * 0.15);				// Se le rebaja un %15 de otros cargos
		}
		else
		{
			SalarioMensual = p.getHorasTrabajo() * 3000;							// Al empleado común se le paga ₡3000 la hora
			SalarioMensual = SalarioMensual + (p.getHorasExtrasTrabajo() * 1000);	// Cada hora extra equivale a ₡000
			SalarioMensual = SalarioMensual + (p.getNumeroHijos() * 5000);			// Por cada hijo que tenga, se le añaden ₡5000 al salario
			SalarioMensual = SalarioMensual - (SalarioMensual * 0.1050);			// Se le rebaja un %10.50 para el seguro
			SalarioMensual = SalarioMensual - (SalarioMensual * 0.15);				// Se le rebaja un %15 de otros cargos
		}

		cout << "--------------------------------------------------" << endl;
		cout << "Cedula: " << p.getCedula() << endl;
		cout << "Nombre: " << p.getNombre() << endl;
		cout << "Tipo de Empleado: " << p.getTipoEmpleado() << endl;
		cout << "Cantidad de Hijos: " << p.getNumeroHijos() << endl;
		cout << "Horas de Trabajo: " << p.getHorasTrabajo() << endl;
		cout << "Horas Extra de Trabajo Acumuladas: " << p.getHorasExtrasTrabajo() << endl;
		cout << "Salario Mensual: " << SalarioMensual << endl;
	}
	catch (exception& e)
	{
		throw e;
	}
}
