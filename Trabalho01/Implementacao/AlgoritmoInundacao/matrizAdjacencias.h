#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef MATRIZADJACENCIAS_H_INCLUDED
#define MATRIZADJACENCIAS_H_INCLUDED

#define TamMatriz 3 /*Definição do tamanho da matriz*/

typedef struct vertice {
/*Estrutura para armazenamento do vertice
  Com nome, flag de controle e ponteiro para suas adjacencias
*/
    char nomeVertice;
    bool flagInundado;
    bool *adjacencias;
} Vertice;

/*Definição das funções*/
void lerMatriz(Vertice vertices[TamMatriz]);
bool matrizConsistente(Vertice vertices[TamMatriz]);
void imprimeMatriz(Vertice vertices[TamMatriz]);
void inundacao(Vertice matriz[TamMatriz], int vertice);
bool listaVazia(int lista[TamMatriz]);
void inicializaLista(int lista[TamMatriz]);
void tipoGrafo(Vertice matriz[TamMatriz]); // Indica se grafo é Conexo ou Desconexo




#endif // MATRIZADJACENCIAS_H_INCLUDED
