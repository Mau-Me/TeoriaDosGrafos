#include "matrizAdjacencias.h"

int main()
{
    Vertice vertices[TamMatriz];

    lerMatriz(vertices);
    imprimeMatriz(vertices);

    inundacao(vertices, 0);

    tipoGrafo(vertices);

    return 0;
}
