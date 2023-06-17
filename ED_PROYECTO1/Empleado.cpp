#include "Empleado.h"

Empleado::Empleado(void) { }

Empleado::Empleado(
	float empHorasTrabajoPago,
	float empHorasExtra,
	float empCantidadHijos,
	float empPagoSeguro,
	float empOtrosGastos,
	float empSalarioMensual
) {
	HorasTrabajoPago = empHorasTrabajoPago;
	HorasExtra = empHorasExtra;
	CantidadHijos = empCantidadHijos;
	PagoSeguro = empPagoSeguro;
	OtrosGastos = empOtrosGastos;
	SalarioMensual = empSalarioMensual;
}

// Getters and Setters
float Empleado::getHorasTrabajoPago() { return HorasTrabajoPago; }
void Empleado::setHorasTrabajoPago(float empHorasTrabajoPago) { HorasTrabajoPago = empHorasTrabajoPago; }
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

void Empleado::CalcularSalario()
{
	try
	{
		if (getTipoEmpleado() == "Gerente")
		{
			HorasTrabajoPago = getHorasTrabajo() * 5000;							// A los gerentes se les paga ₡5000 la hora
			HorasExtra = getHorasExtrasTrabajo() * 3000;							// Cada hora extra equivale a ₡3000
		}
		else
		{
			HorasTrabajoPago = getHorasTrabajo() * 3000;							// A los empleados comunes se les paga ₡3000 la hora
			HorasExtra = getHorasExtrasTrabajo() * 1000;							// Cada hora extra equivale a ₡1000
		}

		CantidadHijos = getNumeroHijos() * 5000;								// Por cada hijo que tenga, se le añaden ₡5000 al salario
		SalarioMensual = HorasExtra + HorasTrabajoPago + CantidadHijos;
		PagoSeguro = SalarioMensual * 0.1050;									// Se le rebaja un %10.50 para el seguro
		OtrosGastos = SalarioMensual * 0.15;									// Se le rebaja un %15 de otros cargos
		SalarioMensual = SalarioMensual - (PagoSeguro + OtrosGastos);

		cout << "--------------------------------------------------" << endl;
		cout << "Cedula: " << getCedula() << endl;
		cout << "Nombre: " << getNombre() << endl;
		cout << "Tipo de Empleado: " << getTipoEmpleado() << endl;
		cout << "Cantidad de Hijos: " << getNumeroHijos() << " = $" << CantidadHijos << endl;
		cout << "Horas de Trabajo: " << getHorasTrabajo() << " = $" << HorasTrabajoPago << endl;
		cout << "Horas Extra de Trabajo Acumuladas: " << getHorasExtrasTrabajo() << " = $" << HorasExtra << endl;
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
	cout << "Total de Horas Pagadas: $" << HorasTrabajoPago << endl;
	cout << "Total de Horas Extras Pagadas: $" << HorasExtra << endl;
	cout << "Total de Pago por cantidad de hijos por empleado: $" << CantidadHijos << endl;
	cout << "Total de Gasto por Pago de Seguro por empleado: $" << PagoSeguro << endl;
	cout << "Total de Otros Gastos por empleado: $" << OtrosGastos << endl;
	cout << "Total de Salario Mensual Pagado: $" << SalarioMensual << endl;
	cout << "--------------------------------------------------" << endl;

}


