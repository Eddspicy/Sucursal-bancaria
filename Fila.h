#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "pilademovimientos.h"
#include "cliente.h"

typedef struct nod2{

    Cliente *cliente;
    struct nod2 *sig;

}Nod2;

typedef struct{

    Nod2 *h;
    Nod2 *t;

}Cola;


Cola *crearCola ();
void insertar (Cola *cola, int af);
void listarcola (Cola cola);
Cliente *borrar (Cola *cola);
int colavacia (Cola cola);
void inicializarcola (Cola *cola);
void atencionventanillas (Cliente *ventanillas, Cola *coladeclientes,int v);
#endif // FILA_H_INCLUDED
