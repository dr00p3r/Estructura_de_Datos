/***********************************************************************
 * Module:  Nodo.h
 * Author:  Joan Cobeña
 * Modified: viernes, 1 de diciembre de 2023 12:05:38 a. m.
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

class Nodo
{
public:
   int get_valor();
   void set_valor(int new_valor);
   Nodo* get_siguiente();
   void set_siguiente(Nodo* new_siguiente);
   Nodo();
   Nodo(int _valor, Nodo* _siguiente);
   ~Nodo();

protected:
private:
   int valor;
   Nodo* siguiente;

};

#endif
