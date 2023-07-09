#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "pilademovimientos.h"

typedef struct{

    int folio;
    char *nombre;
    char *apellidop;
    char *apellidom;
    Pila *movimientosbancarios;

}Cliente;


Cliente *crearCliente ();
char *nombrealeatorio ();
char *apellidoaleatorio ();
char *movimientoaleatorio ();
void llenarcliente (Cliente *cliente, int fa);
void listarcliente (Cliente *cliente);
void atendercliente (Cliente *cliente);
void liberarcliente (Cliente *cliente);

#endif // CLIENTE_H_INCLUDED
