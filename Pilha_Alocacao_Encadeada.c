// PILHA ALOCAÇÃO ENCADEADA
#include<stdio.h>
#define TELEM int

// ESTRUTURA -----------------------------------------

typedef struct NO
{
    TELEM ELEM;
    struct NO *PROX;
}NO;


typedef struct Pilha
{
    NO *inicio;
    int N;
}Pilha;

//---------------------------------------------------
//FUNÇÕES -------------------------------------------

void Construir(Pilha *P)//teta(1);
{
    P -> inicio = NULL;
    P-> N = 0;
}

void Tamanho(Pilha *P)//teta(1);
{
    printf("\n Tamanho da Pilha: %d", P -> N );
}

void Topo(Pilha *P)//teta(1);
{
    printf("\n Elemento do topo: %d", P -> inicio -> ELEM);
}

void Inserir(Pilha *P, TELEM E) // Empilhar teta(1);
{
    NO *NOVO;
    NOVO =(NO *)malloc(sizeof(NO));
    NOVO -> ELEM = E;
    NOVO -> PROX = P -> inicio;
    P -> inicio = NOVO;
    P -> N = P -> N + 1;

}

void Remover(Pilha *P)//Desempilhar teta(1);
{
    if(P -> inicio != NULL)
    {
        NO *noARemover;
        TELEM X;

        noARemover = P -> inicio;
        X = P -> inicio ->ELEM;
        P -> inicio = P -> inicio -> PROX;
        P -> N = P -> N - 1;
        free(noARemover);

    }
    else
    {
        printf("\n Underflow !!!!");
    }
}

//---------------------------------------------------
// Exemplos

void Exemplo_1(Pilha *P)
{
    Inserir(P,2);
    Inserir(P,4);
    Inserir(P,1);
    Tamanho(P);
    Topo(P);

    Remover(P);
    Tamanho(P);
    Topo(P);

    Remover(P);
    Tamanho(P);
    Topo(P);

    Remover(P);
    Tamanho(P);

    Remover(P);

}



//---------------------------------------------------
//Programa principal

void main()
{
    Pilha *P;
    P = (Pilha *)malloc(sizeof(Pilha));
    Construir(P);

    Exemplo_1(P);
}
