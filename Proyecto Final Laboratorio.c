/*Arenas Mimbrera Karen Mariel >>PROYECTO FINAL<<
HABITOS DE CONSUMO: BEBIDAS*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PUEBLOS 100
#define NUM_BEBIDAS 8

// Función para inicializar la matriz con ceros
void inicializarMatriz(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) 
{
    for (int i = 0; i < NUM_PUEBLOS; i++) 
    {
        for (int j = 0; j < NUM_BEBIDAS; j++) 
        {
            arr[i][j] = 0;
        }
    }
}

// Función para llenar la matriz con los datos de consumo
void llenarMatriz(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) 
{
    int var1, var2;

    for (int i = 0; i < NUM_PUEBLOS; i++) 
    {
        printf("Dame la bebida correspondiente del pueblo %d (0-7 o -1 para terminar): ", i);
        scanf("%d", &var1);

        while (var1 != -1) 
        {
            // Validamos que el número de bebida esté entre 0 y 7
            if (var1 < 0 || var1 > 7) 
            {
                printf("Número de bebida no válido. Ingresa un número entre 0 y 7, o -1 para terminar: ");
                scanf("%d", &var1);
                continue;
            }
            printf("Dame la cantidad en litros: ");
            scanf("%d", &var2);
            arr[i][var1] = var2;

            printf("Dame otra bebida (0-7 o -1 para terminar): ");
            scanf("%d", &var1);
        }
    }
}

// Función para calcular el consumo total de cada bebida en todos los pueblos
void calcularConsumoBebidas(int arr[NUM_PUEBLOS][NUM_BEBIDAS], int total[NUM_BEBIDAS]) 
{
    for (int j = 0; j < NUM_BEBIDAS; j++) 
    {
        total[j] = 0; // Aseguramos que el total esté en cero al iniciar la suma
        for (int i = 0; i < NUM_PUEBLOS; i++) 
        {
            total[j] += arr[i][j];  // Sumar el consumo de la bebida j en todos los pueblos
        }
    }
}

// Función para calcular cuál es la bebida más consumida
void calcularBebidaMasConsumida(int total[NUM_BEBIDAS], int *max, int *bebida) 
{
    *max = 0;   // Inicializamos el valor máximo a 0
    *bebida = -1;  // Inicializamos la bebida más consumida en un valor no válido (-1)

    for (int i = 0; i < NUM_BEBIDAS; i++) 
    {
        if (*max < total[i]) 
        {  // Si encontramos un valor mayor al máximo actual
            *max = total[i];  // Actualizamos el máximo
            *bebida = i;  // Guardamos el índice de la bebida más consumida
        }
    }
}

// Función para mostrar el nombre de la bebida según el índice
void mostrarNombreBebida(int bebida) 
{
    const char *bebidas[] =
    {
         "Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energeticos", "Combinados"
    };
    printf("La bebida más consumida es: %s\n", bebidas[bebida]);
}

// Función para imprimir el total de consumo de cada bebida
void imprimirTotales(int total[NUM_BEBIDAS]) 
{
    const char *bebidas[] = {
        "Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energeticos", "Combinados"
    };

    printf("\nTotal de consumo por bebida (en litros):\n");
    for (int i = 0; i < NUM_BEBIDAS; i++) 
    {
        printf("%s: %d litros\n", bebidas[i], total[i]);
    }
}

int main() 
{
    int arr[NUM_PUEBLOS][NUM_BEBIDAS]; 
    int total[NUM_BEBIDAS] = {0};
    int max = 0, bebida = 0;

    // Inicializar la matriz con ceros
    inicializarMatriz(arr);
    printf("Se inicializó la matriz de forma correcta.\n");

    // Llenar la matriz con los datos de consumo
    llenarMatriz(arr);

    // Calcular el total de consumo de cada bebida
    calcularConsumoBebidas(arr, total);

    // Imprimir el total de consumo de cada bebida
    imprimirTotales(total);

    // Calcular cuál es la bebida más consumida en total
    calcularBebidaMasConsumida(total, &max, &bebida);
    
    // Mostrar el resultado
    mostrarNombreBebida(bebida);
    printf("La bebida más consumida es la bebida número %d con %d litros.\n", bebida, max);

    return 0;
}
