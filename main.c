
#include "pilademovimientos.h"
#include "cliente.h"
#include "Fila.h"

int main()
{
    printf("\n\t\t\t \'BIENVENIDO AL BANCO\' \n");

    srand(time(NULL));

    Cola *coladeclientes;
    coladeclientes = crearCola();

    int timer = 0, horas, fa = 101, i, v;

    printf("\nCuantas ventanillas desea que abran?\n");
    scanf("%d", &v);

    printf("\nPor cuantas horas desea que abra la sucursal? \n");
    scanf("%d", &horas);

    Cliente *ventanillas = (Cliente*) calloc (v, sizeof(Cliente));
        if ((ventanillas == NULL)){
            printf("Espacio insuficiente para crear ventanillas\n");
        return (0);
        }

    do
    {

    int llc = 1+(rand()%11), nc;

        if ((llc<=5)){

        while (timer<horas)
        {
            nc = 1+(rand()%v);
            for (i=0; i<nc; i++){
                insertar (coladeclientes, fa);
                fa++;
            }

            timer ++;
            printf("\n\t\t --Horas trasncurridas %d:00-- \n", timer);
            printf("\n\tEl numero folios asignados hasta ahora es: %d\n", fa-101);
            printf("\nEstos son los clientes en la fila de espera:\n");
            listarcola(*coladeclientes);

            atencionventanillas (ventanillas,coladeclientes,v);

            printf("\nEstos son los clientes que continuan en la fila de espera:\n");
            listarcola(*coladeclientes);

        }

        if ((!colavacia(*coladeclientes))){
        printf("\n\t\t --LA FILA SE HA CERRADO, ATENDEREMOS SOLO A LOS CLIENTES RESTANTES-- \n");
        printf("\n\t\t\tEl numero de folios asignados el dia de hoy es: %d\n", fa-101);
            while (!colavacia(*coladeclientes))
            {
            atencionventanillas (ventanillas,coladeclientes,v);
            }
        }
            printf("\n\t --EL BANCO HA CERRADO, NO HAY MAS CLIENTES EN LA FILA-- \n");
        }

            else if ((llc>=6)){
                timer++;
                printf("\n\t\t --Horas transcurridas %d:00-- \n", timer);
                printf("\nNO HAN LLEGADO NUEVOS CLIENTES A LA SUCURSAL\n");
            }

    } while (timer<horas);

    return 0;
}
