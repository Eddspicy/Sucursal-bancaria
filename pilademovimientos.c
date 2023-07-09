
#include "pilademovimientos.h"

Pila *crearPila ()
{
    Pila *nuevaPila = (Pila *) calloc (1,sizeof(Pila));
        if (nuevaPila == NULL){
            printf("\nError: Espacio insuficiente para crear la pila...");
        return NULL;
    }

    return nuevaPila;
}

void push (Pila *pila, char *dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevo == NULL){
            printf("Error: memoria insuficiente\n");
        exit (0);
        }

    nuevo->movimiento = (char*) calloc (MAX, sizeof(char));
        if (nuevo->movimiento == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        exit (0);
        }
    strcpy(nuevo->movimiento, dato);

    nuevo->sig = pila->tope;
    pila->tope = nuevo;
}

void listarpila (Pila pila)
{
    if (!pilavacia(pila)){
    Nodo *q = pila.tope;
    printf("Estos son los movimientos del cliente:\n");
        while(q != NULL)
        {
            printf("%s\n", q->movimiento);
            q = q->sig;
        }
    }
}

char *pop (Pila *pila)
{
    char *aux = (char *) calloc (MAX,sizeof(char));
        if (aux == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

    if(!pilavacia(*pila)){
    Nodo *q = pila->tope;
        pila->tope = pila->tope->sig;
        strcpy(aux, q->movimiento);
            free(q);
            q = NULL;
    }

    return aux;
}

int pilavacia (Pila pila)
{
    return pila.tope == NULL;
}


void inicializarpila (Pila *pila)
{
    if (!pilavacia(*pila)){
    Nodo *q = pila->tope;

        while(q != NULL)
        {
            pila->tope = pila->tope->sig;
            free(q);
            q = pila->tope;
        }
    free (q);
    q = NULL;
    }
}
