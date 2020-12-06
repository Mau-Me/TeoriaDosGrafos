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

void inundacao(Vertice vertices[TamMatriz], int vertice){
    int listaVerticeInundacao[TamMatriz];
    int indiceLista, cont;

    indiceLista = cont = 0;

    inicializaLista(listaVerticeInundacao);

    listaVerticeInundacao[cont] = vertice;
    vertices[cont].flagInundado=true;
    cont++;

    while(!listaVazia(listaVerticeInundacao)){
        for(int i = 0; i<TamMatriz; i++){
            if(vertices[cont].adjacencias[i]==1 && vertices[cont].flagInundado==false){
                listaVerticeInundacao[cont]=i;
                vertices[cont].flagInundado=true;
                cont++;
            }
        }
        listaVerticeInundacao[indiceLista] = -1;
        indiceLista++;
    }

    for(int i=0; i<TamMatriz; i++){
        printf("%c\t%d\n", vertices[i].nomeVertice, vertices[i].flagInundado);
    }
}

bool listaVazia(int lista[TamMatriz]){
    for(int i=0; i<TamMatriz; i++){
        if(lista[i]!=-1){
            return false;
        }
    }
    return true;
}

void inicializaLista(int lista[TamMatriz]){
    for(int i=0; i<TamMatriz; i++){
        lista[i]=-1;
    }
}

void tipoGrafo(Vertice vertices[TamMatriz]){
    for(int i=0; i<TamMatriz; i++){
        if(vertices[i].flagInundado==false){
            printf("\n\nGrafo Desconexo\n\n");
            return;
        }
    }
    printf("\n\nGrafo Conexo\n\n");
}
