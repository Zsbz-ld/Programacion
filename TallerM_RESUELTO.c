#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEst[ESTUDIANTES], promedioAsig[ASIGNATURAS];
    float maxEst[ESTUDIANTES], minEst[ESTUDIANTES];
    float maxAsig[ASIGNATURAS], minAsig[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0}, reprobados[ASIGNATURAS] = {0};

    // Ingreso y validación de notas
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("\n--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese la calificación de la asignatura %d: ", j + 1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                    printf("Error: la nota debe estar entre 0 y 10.\n");
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    // Cálculo de promedios, máximos y mínimos por estudiante
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        maxEst[i] = minEst[i] = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxEst[i]) maxEst[i] = calificaciones[i][j];
            if (calificaciones[i][j] < minEst[i]) minEst[i] = calificaciones[i][j];
        }
        promedioEst[i] = suma / ASIGNATURAS;
    }

    // Cálculo de promedios, máximos, mínimos y aprobados por asignatura
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        maxAsig[j] = minAsig[j] = calificaciones[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > maxAsig[j]) maxAsig[j] = nota;
            if (nota < minAsig[j]) minAsig[j] = nota;
            if (nota >= 6) aprobados[j]++;
            else reprobados[j]++;
        }
        promedioAsig[j] = suma / ESTUDIANTES;
    }

    // Resultados
    printf("\n=== RESULTADOS ===\n");

    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++)
        printf("Estudiante %d: %.2f (Máx: %.2f / Mín: %.2f)\n", i + 1, promedioEst[i], maxEst[i], minEst[i]);

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++)
        printf("Asignatura %d: %.2f (Máx: %.2f / Mín: %.2f)\n", j + 1, promedioAsig[j], maxAsig[j], minAsig[j]);

    printf("\nAprobados y reprobados por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++)
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j + 1, aprobados[j], reprobados[j]);

    return 0;
}