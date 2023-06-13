#pragma once
#include "Persona.h"

class Empleado
{
private:
    float HorasTrabajo;
    float HorasExtra;
    float CantidadHijos;
    float PagoSeguro;
    float OtrosGastos;
    float SalarioMensual;
    float HorasTrabajoTotal = 0;
    float HorasExtraTotal = 0;
    float CantidadHijosTotal = 0;
    float PagoSeguroTotal = 0;
    float OtrosGastosTotal = 0;
    float SalarioMensualTotal = 0;

public:
    Empleado(void);
    Empleado(
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
    );

    // Getters
    float getHorasTrabajo();
    float getHorasExtra();
    float getCantidadHijos();
    float getPagoSeguro();
    float getOtrosGastos();
    float getSalarioMensual();
    float getHorasTrabajoTotal();
    float getHorasExtraTotal();
    float getCantidadHijosTotal();
    float getPagoSeguroTotal();
    float getOtrosGastosTotal();
    float getSalarioMensualTotal();

    // Setters
    void setHorasTrabajo(float empHorasTrabajo);
    void setHorasExtra(float empHorasExtra);
    void setCantidadHijos(float empCantidadHijos);
    void setPagoSeguro(float empPagoSeguro);
    void setOtrosGastos(float empOtrosGastos);
    void setSalarioMensual(float empSalarioMensual);
    void setHorasTrabajoTotal(float empHorasTrabajoTotal);
    void setHorasExtraTotal(float empHorasExtraTotal);
    void setCantidadHijosTotal(float empCantidadHijosTotal);
    void setPagoSeguroTotal(float empPagoSeguroTotal);
    void setOtrosGastosTotal(float empOtrosGastosTotal);
    void setSalarioMensualTotal(float empSalarioMensualTotal);

    void CalcularSalario(Persona p);
    void MostrarSalarioTotal();
};

