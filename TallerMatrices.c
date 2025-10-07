#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    // Datos
    char estudiantes [5] [20] = {0};
    char asignaturas [3] [20] = {0};
    float calificaciones [5] [3] = {0};

    int cont = 0;
    float promedio = 0;

    int Eaprov = 0, Ereprov = 0, opcion = 0;

    int opcE = 0;
    
    do
    {
        printf("-----------------------MENU---------------------------------\n");
            printf("Seleccione una opcion: \n");
            printf("1.Ingresar estudiantes\n");
            printf("2.Ingresar asignatura\n");
            printf("3.Ingresar calificaciones por estudiante\n");
            printf("4.Ver promedio por estudiante\n");
            printf("5.Ver promedio por asignatura\n");
            printf("6.Ver calificacion mas alta y baja por estudiante y por asignatura\n");
            printf("7.El numero de estudiantes reprobados y aprobados por asignatura\n");
            printf("8.Salir\n");
            printf("------------------------------------------------------------\n");
            printf(">> ");
    
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            do
            {
                printf("Ingrese el nombre del estudiante %d: \n",cont + 1);
                fflush(stdin);
                fgets(estudiantes[cont],20,stdin);
                int len = strlen(estudiantes[cont]) - 1;
                estudiantes[cont][len]='\0';
                cont++;
            } while (cont != 5);
            
            cont = 0; //Reiniciamos contador
            break;
        
        case 2:
            cont = 0; //Reiniciamos contador
            do
            {
                printf("Ingrese el nombre de la asignatura %d: \n",cont + 1);
                fflush(stdin);
                fgets(asignaturas[cont],20,stdin);
                int len = strlen(asignaturas[cont]) - 1;
                asignaturas[cont][len]='\0';
                cont++;
            } while (cont != 3);

            
            cont = 0; //Reiniciamos contador
            break;
        
        case 3:
            
            printf("---------------------Estudiantes------------------------------\n");
            for (int i = 0; i <= 4; i++)
            {
                printf("%d\t%s\t\n", i + 1,estudiantes[i]);
            }
            printf("------------------------------------------------------------\n");


            printf("Seleccione el estudiante a subir notas: \n");
            scanf("%d", &opcE);

            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese la nota de %s del alumno %s: ", asignaturas[i], estudiantes[opcE - 1]);
                scanf("%f", &calificaciones[opcE - 1][i]);
            }
            




            break;
        
        case 4:
            /* code */
            break;
        
        case 5:
            /* code */
            break;
        
        case 6:
            /* code */
            break;
        
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        
        default:
            printf("Pato");
            break;
        }














        

        if ((opcion < 1) || (opcion > 8))
        {
            printf("**Error. opcion no valida. Escoja otra opcion.**\n");
        }
        
    } while (opcion != 8);



    





    return 0;
}
