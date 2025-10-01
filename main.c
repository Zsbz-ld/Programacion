#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char id[5][10];
    char nombre[5][20];
    float precio[5];
    int stock[5];

    float ganancia=0;

    int opc=0, opc2=0;

    int cont=0;

    int pv=0;
    int cantidad;
    float valor=0;
    int inicializador=0;

    do{
        printf("-----------------------MENU---------------------------------\n");
        printf("Seleccione una opcion: \n");
        printf("1.Ingresar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion del producto\n");
        printf("5.Ver ganancias\n");
        printf("------------------------------------------------------------\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            inicializador=1;
            printf("Ingrese el ID del producto %d: \n",cont);
            fflush(stdin);
            scanf("%s",&id[cont]);
            printf("Ingrese el nombre del producto %d: \n",cont);
            fflush(stdin);
            fgets(nombre[cont],20,stdin);
            int len = strlen(nombre[cont]) - 1;
            nombre[cont][len]='\0';


            printf("Ingrese el precio del producto %d: \n",cont);
            scanf("%f",&precio[cont]);
            printf("Ingrese el stock del producto %d: \n",cont);
            scanf("%d",&stock[cont]);
            cont++;
            break;
        case 2:
            if (inicializador!=1){
                printf("Debe registrar un producto primero!\n");
                break;
            }
            printf("---------------------Productos------------------------------\n");
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t\t%.2f\t%d\n",i,id[i],nombre[i],precio[i],stock[i]);
            }
            printf("------------------------------------------------------------\n");
            printf("Seleccione el producto a vender: \n");
            scanf("%d",&pv);
            while (pv < 0 || pv >= cont) {
                printf("Ingrese un producto existente. Intentelo nuevamente.\n");
                printf(">>");
                scanf("%d",&pv);
            }
            do
            {
                printf("Que cantidad de producto desea vender: ");
                scanf("%d", &cantidad);
                if (cantidad > stock[pv])
                {
                    printf("No hay suficiente stock para realizar la venta\n");
                }
                else if (cantidad < 0){
                    while (cantidad <0)
                    {
                        printf("La cantidad no puede ser negativa, intente nuevamente.\n");
                        printf(">>");
                        scanf("%d", &cantidad);
                        while (cantidad < 0 || cantidad > stock[pv]){
                            if (cantidad < 0){
                                printf("Ingrese una cantidad positiva.\n");
                                printf(">> "); 
                            }
                            else {
                                printf("Ingrese un stock valido. Intente nuevamente\n");
                                printf(">> "); 
                            }
                            scanf("%d", &cantidad);
                        }
                    }
                    

                    
                }
            } while (cantidad > stock[pv]);
            valor = cantidad * precio[pv];
            stock[pv]-=cantidad;
            ganancia+=valor;
            printf("Venta realizada por el valor de: $%.2f\n",valor);
            break;
        case 3:
            if (inicializador!=1){
                printf("Debe registrar un producto primero!\n");
                break;
            }
            printf("---------------------Productos------------------------------\n");
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            }
            printf("------------------------------------------------------------\n");
            printf("Seleccione el producto a reabastecer: \n");
            scanf("%d", &pv);
            while (pv < 0 || pv >= cont) {
                printf("Ingrese un producto existente. Intentelo nuevamente.\n");
                printf(">>");
                scanf("%d",&pv);
            }
            do{
                printf("Que cantidad de producto desea reabastecer: ");
                scanf("%d",&cantidad);
                if (cantidad<=0)
                {
                    printf("La cantidad debe ser mayor a cero\n");
                }
            }while (cantidad<=0);
            stock[pv]+=cantidad;
            printf("El nuevo stock del producto %d es: %d.\n",pv,stock[pv]);
            break;
        case 4:
            if (inicializador!=1){
                printf("Debe registrar un producto primero!\n");
                break;
            }
            printf("---------------------Productos------------------------------\n");
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t%s\t\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            }
            printf("------------------------------------------------------------\n");
            break;
        case 5:
            printf("Las ganancias totales son: $%.2f\n",ganancia);
            break;
        default:
            printf("Ingrese un numero valido 1-5!\n");
            break;
        }

        printf("Desea seleccionar otra opcion: 1.Si/2.No\n");
        scanf("%d",&opc2);
    }while(opc2!=2);



    return 0;
}