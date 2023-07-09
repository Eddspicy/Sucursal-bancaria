
#include "pilademovimientos.h"
#include "cliente.h"
#include "Fila.h"

Cola *crearCola ()
{
    Cola *cola = (Cola *) calloc(1,sizeof(Cola));
    if (cola ==NULL){
        printf("\nError: Espacio insuficiente para crear la cola");
    return NULL;
    }

    return cola;
}

void insertar (Cola *cola, int fa)
{
    Nod2 *nuevo = (Nod2 *) malloc (sizeof(Nod2));
    if (nuevo == NULL){
        printf("\nError: Espacio insuficiente para crear el nodo...");
    return;
    }
        nuevo->cliente = crearCliente ();

        llenarcliente(nuevo->cliente, fa);

        nuevo->sig = NULL;
            if (cola->t == NULL)
                cola->h = cola->t = nuevo;
                else
                cola->t->sig = nuevo;
                cola->t = nuevo;
}

int colavacia (Cola cola)
{
    return cola.h == NULL;
}


Cliente *borrar (Cola *cola)
{
    Cliente *enservicio = (Cliente*) calloc (1, sizeof(Cliente));
        if (enservicio == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

    if (!colavacia(*cola)){
    Nod2 *q = cola->h;

        if (cola->h == cola->t)
            cola->h=cola->t=NULL;
                else
                cola->h = cola->h->sig;
                enservicio = q->cliente;
                    free(q);
                    q = NULL;

    }

    return enservicio;
}

void inicializarcola (Cola *cola)
{
    if (!colavacia (*cola)){
    Nod2 *q = cola->h;
        while(q != NULL)
        {
            cola->h = cola->h->sig;
            free (q);
            q = cola->h;
        }
    cola->h=cola->t=NULL;
    }

    if(colavacia(*cola)){
        printf("\nListo...fila vacia\n");
            printf("\n");
    }
}

void listarcola (Cola cola)
{
    Nod2 *q = cola.h;
    if (colavacia(cola)){
        printf("No hay datos registrados en la fila\n");
        printf("\n");
        return;
    }
    while (q!=NULL){
        listarcliente(q->cliente);
        q = q->sig;
        }
        printf("\n");
}

void atencionventanillas (Cliente *ventanillas, Cola *coladeclientes, int v)
{
    int ocupado, i;

    for (i=0; i<v; i++){
    ocupado = 1+(rand()%11);
        if((ocupado<=5 && !colavacia(*coladeclientes ))){
            printf("\n -Pase cliente a la ventanilla: %d- \n", i+1);
            ventanillas[i] = *borrar (coladeclientes);
            listarcliente (&ventanillas[i]);
            atendercliente (&ventanillas[i]);
            liberarcliente(&ventanillas[i]);
                if(&ventanillas[i] == NULL);
                printf("\n\tEl cliente ha sido atendido !\n \n -La ventanilla %d esta disponible-\n", i+1);
        }
            else if ((ocupado<=5 && colavacia(*coladeclientes))){
                printf("\n -La ventanilla %d esta disponible, pero todos los clientes han sido atendidos- \n",i+1);
            }
                else
                    printf("\n -La ventanilla %d no esta disponible- \n", i+1);
    }
}

