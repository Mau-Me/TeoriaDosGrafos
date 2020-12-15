#include "matrizAdjacencias.h"

int main()
{
    int indiceVertice = 0;
    Vertice vertices[TamMatriz];

    do{
    /*Repete leitura da matriz até que a matriz seja consistente*/
        lerMatriz(vertices);
        imprimeMatriz(vertices);
    }
    while(!matrizConsistente(vertices));

    printf("\n\nInforme o indice do vertice inicial na inundação:(de 0 a %d, considerando a posicao da matriz em C)\n", TamMatriz-1);
    scanf("%d", &indiceVertice);
    inundacao(vertices, indiceVertice);

    tipoGrafo(vertices);

    return 0;
}
