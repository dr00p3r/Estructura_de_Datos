#include <iostream>
#include "Operaciones.cpp"

int main()
{
    float a;
    float b;

    std::cout<<"Ingrese el primer numero: \n";
    std::cin>>a;
    std::cout<<"Ingrese el segundo numero: \n";
    std::cin>>b;

    std::cout<<"Calculo con typename int \n";

    Operaciones<int> intOperaciones(a,b);
    intOperaciones.calculo();

    std::cout<<"Calculo con typename float \n";

    Operaciones<float> floatOperaciones(a,b);
    floatOperaciones.calculo();

    system("pause");
    return 0;
}
