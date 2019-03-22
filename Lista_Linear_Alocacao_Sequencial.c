#include<stdio.h>
#include<stdlib.h>
#define MAX_N 2
#define TChave int
#define TElem int

typedef struct No
{
    TChave chave;
    TElem elem;
}No;

typedef struct ListaLinear
{
    No val[MAX_N];
    int N; // contador de elementos na lista
    int posIns;
}ListaLinear;

void Tamanho(ListaLinear L) // teta(1)
{
    printf("Tamanho da lista: %d", L.N);
}

void Constroi(ListaLinear L) // teta(1)
{
    L.N = 0;
}

void Enumera(ListaLinear L) // teta(Max_N)
{
    int i;

    for (i = 0; i < L.N; i++)
    {
        printf("Chave: %d", L.val(i).chave);
    }
}

int BuscaPosicao(ListaLinear L, TChave C, int posIns) // pior caso: teta(log N)
{
   int inf, sup, m;
   inf = 1;
   sup = L.N;

    while (inf < sup)
    {
        m = ((inf+sup)/2);

        if (L.val(m).chave = C)
        {
            return(m);
            break;
        }
        else if (L.val(m).chave < C)
        {
            inf = m + 1;
        }
        else
        {
            sup = m - 1;
        }

	posIns = inf;
    }
    return(0);
}



void InsereEm(ListaLinear L, int pos ,TChave C, TElem X)
{
	if (L.N < MAX_N)
	{
		int i;
		for (i = pos; i <= pos; i--)
		{
			L.val(i+1) = L.val(i);
			L.N = L.N+1;
			L.val(pos).chave = C;
			L.val(pos).elem = X;
		}
	}
}


void RemoveEm(ListaLinear L, int pos)
{
	if (L.N > 0)
	{
		int i;
		for (i = pos; i <= L.N-1; i--)
		{
			L.val(i) = L.val(i+1);
			L.N = L.N - 1;
		}
	}
	else
	{
		printf("Underflow");
	}
}


int Busca(ListaLinear L, TChave C) // Pior caso: teta(log N)
{
    int pos = BuscaPosicao(L, C);

    return(L.val(pos).elem);
}



void Insere(ListaLinear L, TChave C, TElem X)
{
	int pos, posIns;

	pos = BuscaPosicao(L, C, posIns);

	if (pos == 0)
	{
		InsereEm(L, posIns,C, X);
	}
	else
	{
		printf("Elemento existente");
	}
}


void Remove(ListaLinear L, TChave C)
{
	int pos,posIns; 
	
	pos= BuscaPosicao(L, C, posIns);
	
	if(pos > 0)
	{
		printf("Elemento: %d, removido", C);		
		//return (RemoveEm(L, Pos));
	}
	else
	{
		printf("Chave inexistente");
	}
}

void main()
{
	//ListaLinear L;
	Constroi(L);        
	Insere(L,1,1,1); 
	Insere(L,2,2,2);
	Enumera(L);
	Remove(L,1);
	Enumera(L);
	//Destroi(L);

}
