#ifndef PILADEMOVIMIENTOS_H_INCLUDED
#define PILADEMOVIMIENTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 30

typedef struct nodo{

    char *movimiento;
    struct nodo *sig;

}Nodo;


typedef struct{

    Nodo *tope;

}Pila;


Pila *crearPila ();
void push (Pila *pila,  char *dato);
void listarpila (Pila pila);
char *pop (Pila *pila);
int pilavacia (Pila pila);
void inicializarpila (Pila *pila);

#endif // PILADEMOVIMIENTOS_H_INCLUDED
