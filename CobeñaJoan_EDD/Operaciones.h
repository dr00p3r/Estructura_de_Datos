#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

template <typename T>
class Operaciones{
    private:
        T valor1;
        T valor2;
    public:
        Operaciones(T v1, T v2):valor1(v1),valor2(v2){};
        T sumar();
        T restar();
        T multiplicar();
        T dividir();
        void calculo();
    protected:
};


#endif // OPERACIONES_H_INCLUDED
