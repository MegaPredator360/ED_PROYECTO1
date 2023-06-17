#pragma once
#include "Persona.h"

class Empleado: public Persona
{
private:
    float HorasTrabajoPago;
    float HorasExtra;
    float CantidadHijos;
    float PagoSeguro;
    float OtrosGastos;
    float SalarioMensual;

public:
    Empleado(void);
    Empleado(
        float empHorasTrabajoPago,
        float empHorasExtra,
        float empCantidadHijos,
        float empPagoSeguro,
        float empOtrosGastos,
        float empSalarioMensual
    );

    // Getters
    float getHorasTrabajoPago();
    float getHorasExtra();
    float getCantidadHijos();
    float getPagoSeguro();
    float getOtrosGastos();
    float getSalarioMensual();

    // Setters
    void setHorasTrabajoPago(float empHorasTrabajoPago);
    void setHorasExtra(float empHorasExtra);
    void setCantidadHijos(float empCantidadHijos);
    void setPagoSeguro(float empPagoSeguro);
    void setOtrosGastos(float empOtrosGastos);
    void setSalarioMensual(float empSalarioMensual);
    
    void CalcularSalario();
    void MostrarSalarioTotal();
};

