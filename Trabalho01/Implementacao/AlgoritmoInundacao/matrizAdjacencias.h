#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MATRIZADJACENCIAS_H_INCLUDED
#define MATRIZADJACENCIAS_H_INCLUDED

typedef struct vertice {
    int num;
    bool flag;
} Vertice;

void lerMatriz(Vertice matriz[6][6]);
void inundacao(Vertice matriz[6][6], int vertice);
void tipoGrafo(Vertice matriz[6][6]); // Indica se grafo é Conexo ou Desconexo


#endif // MATRIZADJACENCIAS_H_INCLUDED
