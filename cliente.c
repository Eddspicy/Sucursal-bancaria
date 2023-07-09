
#include "pilademovimientos.h"
#include "cliente.h"

Cliente *crearCliente ()
{
    Cliente *nuevoCliente = (Cliente *) malloc (sizeof(Cliente));
    if (nuevoCliente == NULL){
        printf("\nError: Espacio insuficiente para crear cliente...");
    return NULL;
    }

        nuevoCliente->folio = 0;

        nuevoCliente->apellidop = (char *) calloc (MAX,sizeof(char));
        if (nuevoCliente->apellidop == NULL){
                printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        nuevoCliente->apellidom = (char *) calloc (MAX,sizeof(char));
        if (nuevoCliente->apellidom == NULL){
                printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        nuevoCliente->nombre = (char *) calloc (MAX,sizeof(char));
        if (nuevoCliente->nombre == NULL){
                printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        nuevoCliente->movimientosbancarios = crearPila();

    return nuevoCliente;
}

char *nombrealeatorio ()
{
    int rn = rand()%5;
    char *aux = (char *) calloc (MAX, sizeof(char));
        if(aux == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        char nombres [5][MAX] = {"Ana","Patricio","Juana","Pedro","Luis"};
        strcpy(aux, nombres[rn]);

    return aux;
}

char *apellidoaleatorio ()
{
    int ra = rand()%5;
    char *aux = (char *) calloc (MAX, sizeof(char));
        if(aux == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        char apellidos [5][MAX] = {"Hernandez","Martinez","Cervantes","Duran","Garcia"};
        strcpy(aux, apellidos[ra]);

    return aux;
}

char *movimientoaleatorio ()
{
    int mv = rand()%6;
    char *aux = (char *) calloc (MAX, sizeof(char));
        if(aux == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        char mb [6][MAX] = {"Deposito","Retiro","Pago con tarjeta","Pago servicios","Consulta saldo","Aclaraciones"};
        strcpy(aux, mb[mv]);

    return aux;
}

void llenarcliente (Cliente *cliente, int fa)
{
    if((cliente != NULL)){

        cliente->folio = (cliente->folio + fa);

        cliente->nombre = nombrealeatorio ();

        cliente->apellidop = apellidoaleatorio ();

        cliente->apellidom = apellidoaleatorio ();

        int mxmv = 1+(rand()%7), c = 0;
        while (c < mxmv)
        {
            push(cliente->movimientosbancarios, movimientoaleatorio());
                c++;
        }
    }
}

void listarcliente (Cliente *cliente)
{
    printf("\nCliente con folio: %d\t\n",cliente->folio);
    printf("Nombre del cliente: %s\t",cliente->nombre);
    printf("%s\t",cliente->apellidop);
    printf("%s\t",cliente->apellidom);
        fflush(stdout);
}

void atendercliente (Cliente *cliente)
{
    char *atendiendo = (char *) calloc (MAX,sizeof(char));
        if(atendiendo == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        exit (0);
        }
    int nm = 0;

    printf("\nMovimientos del cliente:");
    if(!pilavacia(*cliente->movimientosbancarios)){
        while ((cliente->movimientosbancarios->tope != NULL))
        {
            atendiendo = pop (cliente->movimientosbancarios);
                if ((atendiendo != NULL)){
                    nm++;
                    printf("\n%d:%s", nm, atendiendo);
                        fflush(stdout);
                }
        }
    }
        else
            printf("El cliente no tiene movimientos disponibles");
                fflush(stdout);

    free(atendiendo);
        atendiendo = NULL;

    printf(" ->El cliente ha terminado de ser atendido!");

    printf("\n");
}

void liberarcliente (Cliente *cliente)
{
    if((cliente != NULL)){
        cliente->folio = 0;
        free(cliente->apellidop);
            cliente->apellidop = NULL;
        free(cliente->apellidom);
            cliente->apellidom = NULL;
        free(cliente->nombre);
            cliente->nombre = NULL;
        inicializarpila(cliente->movimientosbancarios);
        free(cliente->movimientosbancarios);
            cliente->movimientosbancarios = NULL;

    cliente = NULL;
    }
}
