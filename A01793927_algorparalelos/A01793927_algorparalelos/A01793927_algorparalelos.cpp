// A01793927_algorparalelos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 1000

void realizaSumaArray(int *A, int *B, int *C, int size) {
#pragma omp parallel for
	for (int i = 0; i < size; i++) {
		C[i] = A[i] + B[i];
	}
}

int main() {
	int A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE];

	// SE INICIALIZA LOS ARREGLOS ALEATOREOS
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = rand() % 100;
		B[i] = rand() % 100;
	}

	// SE IMPRIME LOS DOS ARREGLOS
	printf("Arreglo A:\n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", A[i]);
	}
	printf("\n\n");

	printf("Arreglo B:\n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", B[i]);
	}
	printf("\n\n");

	// REALIZA LA SUMA DE LOS ARREGLOS
	realizaSumaArray(A, B, C, ARRAY_SIZE);

	// IMPRIME EL ARREGLO FINAL 
	printf("Resultado de la suma (Arreglo C):\n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d ", C[i]);
	}
	printf("\n");

	return 0;
}
