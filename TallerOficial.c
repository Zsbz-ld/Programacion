#include <stdio.h>
#include <math.h>
int main()
{
    int accion;
    int contador=0;
    int ID, stock, reabastecimiento;
    float precio;
    char nombre[50];
    do
    {
    int vendido;
    int ventaActual=0;
   
    printf("Ingrese la accion que desea registrar (1-6):\n");
    printf("1.Registrar producto\n");
    printf("2.Vender unidades del producto\n");
    printf("3.Reabastecer el producto\n");
    printf("4.Consultar informacion actualizada del producto\n");
    printf("5.Calcular y mostrar las ganancias obtenidas hasta el momento\n");
    printf("6.Salir\n");
    scanf("%d", &accion);
    switch
    (accion)
    {
    case 1:
    printf("Ingrese el ID de su producto-> \n");
    scanf("%d", &ID);
    printf("Ingrese el nombre de su producto-> \n");
    scanf(" %s[^\n]", &nombre);
    printf("Ingrese la cantidad en stock de su producto-> \n");
    scanf("%d", &stock);
    while (stock<0){
    printf("Intente nuevamente->");
    scanf("%d", &stock);
    }
    printf("Ingrese el precio unitario de su producto-> \n");
    scanf("%f", &precio);
    while (precio<0){
    printf("Intente nuevamente->");
    scanf("%f", &precio);
    }


        break;
    case 2:
    printf("Ingrese la cantidad del producto a vender-> \n");
    scanf("%d", &vendido);
    if (vendido > stock){
        printf("No tienes suficiente stock \n");
        break;
    }
    else if (vendido<0){
    printf("No puedes vender negativamente \n");
        break;
    }
    else {
        stock=stock-vendido;
    ventaActual=vendido*precio;
        contador+=ventaActual;
    printf("Su stock actual ahora es de -> %d unidades.\n", stock);
    printf("Ha ganado $%.2f con esta venta.\n", ventaActual);
    }

        break;
    case 3:
    printf("Ingrese la cantidad de stock agregar a su producto-> \n");
    scanf("%d", &reabastecimiento);
    if (reabastecimiento<0){
    printf("No puedes añadir negativamente! \n");
    break;
    }
    stock=stock+reabastecimiento;
    printf("Su stock actual ahora es de -> %d unidades. \n", stock);

        break;
    case 4:
    printf("---------------Informacion actualizada de su producto--------- \n");
    printf("ID: %d \n", ID);
    printf("Nombre: %s \n", nombre);
    printf("Stock: %d \n", stock);
    printf("Precio Unitario: $%.2f  \n", precio);
    printf("----------------------------------------------------------- \n");

        break;
    case 5:
    printf("Ganancias realizadas hasta el momento son de: %.2f\n", contador);
   

        break;
    case 6:
    printf("Fin del programa.\n");

        break;
   
    default:
    printf("Opción no válida, intente nuevamente.\n");
        break;
    }
} while (accion != 6);
    return 0;
}