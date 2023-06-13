#include "Empleado.h"

Empleado::Empleado(void) { }

Empleado::Empleado(
	float empHorasTrabajo,
	float empHorasExtra,
	float empCantidadHijos,
	float empPagoSeguro,
	float empOtrosGastos,
	float empSalarioMensual,
	float empHorasTrabajoTotal,
	float empHorasExtraTotal,
	float empCantidadHijosTotal,
	float empPagoSeguroTotal,
	float empOtrosGastosTotal,
	float empSalarioMensualTotal
) {
	HorasTrabajo = empHorasTrabajo;
	HorasExtra = empHorasExtra;
	CantidadHijos = empCantidadHijos;
	PagoSeguro = empPagoSeguro;
	OtrosGastos = empOtrosGastos;
	SalarioMensual = empSalarioMensual;
	HorasTrabajoTotal = empHorasTrabajoTotal;
	HorasExtraTotal = empHorasExtraTotal;
	CantidadHijosTotal = empCantidadHijosTotal;
	PagoSeguroTotal = empPagoSeguroTotal;
	OtrosGastosTotal = empOtrosGastosTotal;
	SalarioMensualTotal = empSalarioMensualTotal;
}

// Getters and Setters
float Empleado::getHorasTrabajo() { return HorasTrabajo; }
void Empleado::setHorasTrabajo(float empHorasTrabajo) { HorasTrabajo = empHorasTrabajo; }
float Empleado::getHorasExtra() { return HorasExtra; }
void Empleado::setHorasExtra(float empHorasExtra) { HorasExtra = empHorasExtra; }
float Empleado::getCantidadHijos() { return CantidadHijos; }
void Empleado::setCantidadHijos(float empCantidadHijos) { CantidadHijos = empCantidadHijos; }
float Empleado::getPagoSeguro() { return PagoSeguro; }
void Empleado::setPagoSeguro(float empPagoSeguro) { PagoSeguro = empPagoSeguro; }
float Empleado::getOtrosGastos() { return OtrosGastos; }
void Empleado::setOtrosGastos(float empOtrosGastos) { OtrosGastos = empOtrosGastos; }
float Empleado::getSalarioMensual() { return SalarioMensual; }
void Empleado::setSalarioMensual(float empSalarioMensual) { SalarioMensual = empSalarioMensual; }

// Para el resumen total de datos
float Empleado::getHorasTrabajoTotal() { return HorasTrabajoTotal; }
void Empleado::setHorasTrabajoTotal(float empHorasTrabajoTotal) { HorasTrabajoTotal = empHorasTrabajoTotal; }
float Empleado::getHorasExtraTotal() { return HorasExtraTotal; }
void Empleado::setHorasExtraTotal(float empHorasExtraTotal) { HorasExtraTotal = empHorasExtraTotal; }
float Empleado::getCantidadHijosTotal() { return CantidadHijosTotal; }
void Empleado::setCantidadHijosTotal(float empCantidadHijosTotal) { CantidadHijosTotal = empCantidadHijosTotal; }
float Empleado::getPagoSeguroTotal() { return PagoSeguroTotal; }
void Empleado::setPagoSeguroTotal(float empPagoSeguroTotal) { PagoSeguroTotal = empPagoSeguroTotal; }
float Empleado::getOtrosGastosTotal() { return OtrosGastosTotal; }
void Empleado::setOtrosGastosTotal(float empOtrosGastosTotal) { OtrosGastosTotal = empOtrosGastosTotal; }
float Empleado::getSalarioMensualTotal() { return SalarioMensualTotal; }
void Empleado::setSalarioMensualTotal(float empSalarioMensualTotal) { SalarioMensualTotal = empSalarioMensualTotal; }

void Empleado::CalcularSalario(Persona p)
{
	try
	{

		if (p.getTipoEmpleado() == "Gerente")
		{
			HorasTrabajo = p.getHorasTrabajo() * 5000;								// A los gerentes se les paga ₡5000 la hora
			HorasExtra = p.getHorasExtrasTrabajo() * 3000;							// Cada hora extra equivale a ₡3000
			CantidadHijos = p.getNumeroHijos() * 5000;								// Por cada hijo que tenga, se le añaden ₡5000 al salario
			SalarioMensual = HorasExtra + HorasTrabajo + CantidadHijos;
			PagoSeguro = SalarioMensual * 0.1050;									// Se le rebaja un %10.50 para el seguro
			OtrosGastos = SalarioMensual * 0.15;									// Se le rebaja un %15 de otros cargos
			SalarioMensual = SalarioMensual - (PagoSeguro + OtrosGastos);
		}
		else
		{
			HorasTrabajo = p.getHorasTrabajo() * 3000;								// A los empleados comunes se les paga ₡3000 la hora
			HorasExtra = p.getHorasExtrasTrabajo() * 1000;							// Cada hora extra equivale a ₡1000
			CantidadHijos = p.getNumeroHijos() * 5000;								// Por cada hijo que tenga, se le añaden ₡5000 al salario
			SalarioMensual = HorasExtra + HorasTrabajo + CantidadHijos;
			PagoSeguro = SalarioMensual * 0.1050;									// Se le rebaja un %10.50 para el seguro
			OtrosGastos = SalarioMensual * 0.15;									// Se le rebaja un %15 de otros cargos
			SalarioMensual = SalarioMensual - (PagoSeguro + OtrosGastos);
		}

		cout << "--------------------------------------------------" << endl;
		cout << "Cedula: " << p.getCedula() << endl;
		cout << "Nombre: " << p.getNombre() << endl;
		cout << "Tipo de Empleado: " << p.getTipoEmpleado() << endl;
		cout << "Cantidad de Hijos: " << p.getNumeroHijos() << " = $" << CantidadHijos << endl;
		cout << "Horas de Trabajo: " << p.getHorasTrabajo() << " = $" << HorasTrabajo << endl;
		cout << "Horas Extra de Trabajo Acumuladas: " << p.getHorasExtrasTrabajo() << " = $" << HorasExtra << endl;
		cout << "Pago de Seguro: $" << PagoSeguro << endl;
		cout << "Otros Gastos: $" << OtrosGastos << endl;
		cout << "Salario Mensual: $" << SalarioMensual << endl;
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Empleado::MostrarSalarioTotal()
{
	cout << "--------------------------------------------------" << endl;
	cout << "------- Resumen mensual del total de pagos -------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Total de Horas Pagadas: $" << HorasTrabajoTotal << endl;
	cout << "Total de Horas Extras Pagadas: $" << HorasExtraTotal << endl;
	cout << "Total de Pago por cantidad de hijos por empleado: $" << CantidadHijosTotal << endl;
	cout << "Total de Gasto por Pago de Seguro por empleado: $" << PagoSeguroTotal << endl;
	cout << "Total de Otros Gastos por empleado: $" << OtrosGastosTotal << endl;
	cout << "Total de Salario Mensual Pagado: $" << SalarioMensualTotal << endl;
	cout << "--------------------------------------------------" << endl;

}


