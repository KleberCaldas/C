/*************************************
 *Lista Linear de Alocacao Encadeada*
 *Linear List - chained allocation*
 *************************************/

 //Inclusao dos arquivos Header
 //Include Headers
 
#include <stdio.h>
#include <stdlib.h>

//Troca todas as ocorrencias pelo valor indicado
//Change all occurrences by the indicated value 

#define Tchave int
#define Telem int

typedef struct No
{
    Tchave chave;
    Telem elem;
    struct No *prox;//referencia ao proximo elemento da lista | Next element reference on list 
}No;
typedef struct ListaLinear
{
    No *inicio;//ponteiro para o inicio | Points to the beginning
    int N;
}ListaLinear;


void constroi(ListaLinear *L)
{
    L->inicio=NULL;
    L->N=0;
}
void enumera(ListaLinear *L)//tempo: teta(N) | Complexity analysis
{
    No *p;
    p=L->inicio;
    while(p!=NULL)//Se trocar o int no define tem que trocar o %d
    {             //pelo identificador de formato respectivo
	printf("chave: %d,elemento: %d\n",p->chave,p->elem);
	p=p->prox;
    }    
}
void destroi(ListaLinear *L)//Destroi a lista );
{                            //tempo: teta(N)
    No *p,*pprox,*aux;
    pprox=L->inicio;
    while(pprox!=NULL)
    {
	    aux=pprox;//Em C é necessario usar variavel auxiliar
        pprox=pprox->prox;
        p=aux;
        free(p);//desalocar(p)
    }
}
Telem busca(ListaLinear *L,Tchave c)//Melhor caso: teta(1)
{                                       //Pior caso: teta(N)
    No *p=L->inicio;
    while(p!=NULL && p->chave < c)//para o loop quando encontrar c
	p=p->prox;                
    if(p!=NULL && p->chave == c)//Se 'c' nao for encontrado pula para 
	return(p->elem);      //o else.Se for encontrado retorna
    else                      //o elemento correspondente a chave c
	return(0);
}
void insere(ListaLinear *L,Tchave c,Telem x,int Pos)//Minha lista está ordenada
{
    No *novo,*p,*aux;
    novo=(No *) malloc(sizeof(No));//Memmory Allocation(malloc)
    novo->chave= c;
    novo->elem= x;
    int i;    
    p=L->inicio;
    if(Pos==1)
    {
	aux=L->inicio;
	L->inicio=novo;                     //tempo: teta(Pos)
	novo->prox=aux;
    }
    else
    {
	for(i=1;i<=Pos-2;i++)
	    p=p->prox;
	aux=p->prox;
	p->prox=novo;
	novo->prox=aux;
    }
    L->N=L->N+1;
}
Telem Remove(ListaLinear *L, int Pos)//tempo: teta(Pos)
{
    No *p,*pAnt;
    Telem x;
    int i;
    if(Pos==1)
    {
        pAnt=NULL,
        p=L->inicio;
    }
    else
    {
	pAnt=L->inicio;
	for(i=2;i<Pos-1;i++)
	    pAnt=pAnt->prox;
	p=pAnt->prox;
    }
    if(pAnt==NULL)
	    L->inicio=L->inicio->prox;
    else
	    pAnt->prox=p->prox;
    free(p);
    L->N=L->N-1;
    return x;
}

void Exemplo1()
{
    ListaLinear *L;
    L=(ListaLinear *) malloc(sizeof(ListaLinear)); //Sem esta linha ocorre falha de segmentaçao na funçao constroi
    constroi(L);        
    insere(L,1,1,1); 
    insere(L,2,2,2);
    enumera(L);
    Remove(L,1);
    enumera(L);
    destroi(L);
}

int main()
{
    printf("Inicio do Programa\n");
    Exemplo1();
    printf("Fim do Programa\n");
    return 0;
}	