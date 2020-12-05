#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef MATRIZADJACENCIAS_H_INCLUDED
#define MATRIZADJACENCIAS_H_INCLUDED

#define TamMatriz 2

typedef struct vertice {
    char nomeVertice;
    bool flagInundado;
    bool *adjacencias;
} Vertice;

void lerMatriz(Vertice vertices[TamMatriz]);
void imprimeMatriz(Vertice vertices[TamMatriz]);
void inundacao(Vertice matriz[TamMatriz], int vertice);
void tipoGrafo(Vertice matriz[TamMatriz]); // Indica se grafo é Conexo ou Desconexo




#endif // MATRIZADJACENCIAS_H_INCLUDED
