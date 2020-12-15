#include "matrizAdjacencias.h"


void lerMatriz(Vertice vertices[TamMatriz]){
/*Função para ler a Matriz de Adjacencias
  Inicializa as flags dos vertices como false
  Aloca memoria para a matriz de adjacencia
*/

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
/*Imprime a matriz de adjacencias*/
    printf("\nMatriz de Adjacencias:\n");
    for(int i=0; i<TamMatriz; i++ ) {
        for(int j=0; j<TamMatriz; j++) {
            printf("%d\t", vertices[i].adjacencias[j]);
        }
        printf("\n");
    }
}

void inundacao(Vertice vertices[TamMatriz], int vertice){

    int listaVerticeInundacao[TamMatriz]; /*Lista auxiliar para armazenamento dos vertices inundados*/
    int indiceLista, cont; /*indeces de controle*/

    indiceLista = cont = 0;

    inicializaLista(listaVerticeInundacao);

    listaVerticeInundacao[cont] = vertice; /*Add primeiro vertice a lista*/
    vertices[vertice].flagInundado=true;
    cont++;

    while(!listaVazia(listaVerticeInundacao)){
        for(int i = 0; i<TamMatriz; i++){/*Percore a matriz verificando se ha adjacencias e add os vertices adjacentes a lista*/
            if(vertices[listaVerticeInundacao[indiceLista]].adjacencias[i]==1 && vertices[i].flagInundado==false){
                listaVerticeInundacao[cont]=i;
                vertices[i].flagInundado=true;
                cont++;
            }
        }
        listaVerticeInundacao[indiceLista] = -1;/*Tira o vertice verificado da lista*/
        indiceLista++;
    }

    printf("\nVertices Inundados:\n");
    for(int i=0; i<TamMatriz; i++){
        if(vertices[i].flagInundado==true)
            printf("%c\t", vertices[i].nomeVertice);
    }
}

bool listaVazia(int lista[TamMatriz]){
/*Função para verificar se a lista esta vazia*/
    for(int i=0; i<TamMatriz; i++){
        if(lista[i]!=-1){
            return false;
        }
    }
    return true;
}

void inicializaLista(int lista[TamMatriz]){
/*A lista foi inicializada com -1 já que todos os valores add seriam maiores ou iguais a zero*/
    for(int i=0; i<TamMatriz; i++){
        lista[i]=-1;
    }
}

void tipoGrafo(Vertice vertices[TamMatriz]){
/*Verifica se todos os vertices foram inundados*/
    printf("\nTipo do Grafo:\n");
    for(int i=0; i<TamMatriz; i++){
        if(vertices[i].flagInundado==false){
            printf("Grafo Desconexo\n\n");
            return;
        }
    }
    printf("Grafo Conexo\n\n");
}

bool matrizConsistente(Vertice vertices[TamMatriz]){
/* Percorre a matriz verificando se a mesma e simetrica*/
    for(int i=0; i<TamMatriz; i++){
        for(int j=0; j<TamMatriz; j++){
            if(vertices[i].adjacencias[j]!=vertices[j].adjacencias[i]){
                printf("\n\n\nMATRIZ INCONSISTENTE EM (%d,%d)!!!\n\n\n\n", i, j);
                printf("informe matriz consistente:\n");
                return false;
            }
        }
    }
    return true;
}
