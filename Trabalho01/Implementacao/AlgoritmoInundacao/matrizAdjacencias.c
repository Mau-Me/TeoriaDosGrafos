#include "matrizAdjacencias.h"


void lerMatriz(Vertice vertices[TamMatriz]){
    char tempAdjacencia;

    for(int i=0; i<TamMatriz; i++ ) {
        printf("Qual o nome do %d vertice?(1 Caracter)\n", i+1);
        scanf(" %c", &vertices[i].nomeVertice);
        vertices[i].flagInundado=false;
        vertices[i].adjacencias=malloc(TamMatriz * sizeof(bool));
    }

    printf("\n\nPreencha as adjacencias dos vertices\n\n");

    for(int i=0; i<TamMatriz; i++){
        for (int j = 0; j < TamMatriz; j++){
            do{
                printf("%c e %c sao adjacentes? (1 para sim, 0 para nao)\n", vertices[i].nomeVertice, vertices[j].nomeVertice);
                scanf(" %c", &tempAdjacencia);
            }
            while(tempAdjacencia != '0' && tempAdjacencia != '1');

            if(tempAdjacencia == '1'){
                vertices[i].adjacencias[j]=true;
            }
            else{
                vertices[i].adjacencias[j]=false;
            }
        }
    }
}

void imprimeMatriz(Vertice vertices[TamMatriz]){
    for(int i=0; i<TamMatriz; i++ ) {
        for(int j=0; j<TamMatriz; j++) {
            printf("%d\t", vertices[i].adjacencias[j]);
        }
        printf("\n");
    }
}

void inundacao(Vertice matriz[TamMatriz], int vertice){
}

void tipoGrafo(Vertice matriz[TamMatriz]){
}
