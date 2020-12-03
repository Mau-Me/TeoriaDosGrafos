#include <stdio.h>
#include <stdlib.h>

#ifndef MATRIZADJACENCIAS_H_INCLUDED
#define MATRIZADJACENCIAS_H_INCLUDED

void lerMatriz(int matriz[6][6]);
void inundacao(int matriz[6][6], int vertice);
void tipoGrafo(int matriz[6][6]); // Indica se grafo é Conexo ou Desconexo


#endif // MATRIZADJACENCIAS_H_INCLUDED
