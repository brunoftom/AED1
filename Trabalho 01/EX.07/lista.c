#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

#define MAX 50 //usar para tamanho m�ximo de char para nome de soldados

/*tipo de implementa��o escolhida: encadeamento din�mico e
circular, uma vez que n�o se sabe o n�mero m�ximo de soldados
a serem considerados no problemas (ser� dado de entrada pelo
usu�rios); al�m disso, a lista de soldados ter� que ser
percorrida at� dar o n�mero de contagem, o qual pode ser atingido
ap�s uma ou mais voltas no 'c�rculo' de soldados.
Assim, o fato do encadeamento circular guardar o primeiro e
�ltimo n�s da lista, ajudar� nesse processo de rodas mais de
uma vez os soldados, caso necss�rio. Se ainda n�o deu o n�mero
de contagem e j� chegou no �ltimo soldado, tem que continuar
a contagem seguindo para o primeiro novamente. */

//struct de para nomes dos soldados
struct Soldados
{
    char nome[MAX];
};
typedef struct Soldados soldado;

//struct para lista din�mica encadeada do tipo circular, contendo struct soldado
struct no
{
    soldado info[MAX];
    struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
    return NULL;
}

//lista aponta para NULL
int lista_vazia(Lista l)
{
    if(l == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//inser��o no fim da lista
int insere_soldado(Lista *l, char *nome)
{
    Lista N;
    N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    strcpy(N->info->nome, nome);

    if(lista_vazia(*l) == 1)
    {
        N->prox = N;
        *l = N;
    }else
    {
        N->prox = (*l)->prox; //campo pr�ximo do novo n� recebe endere�o do primeiro n� da lista
        (*l)->prox = N; //regi�o que at� ent�o tinha �ltimo n� da lista passa a apontar para novo n� - que corresponde ao �ltimo elemento
        *l = N; //lista aponta para novo n� - �ltimo
    }

    return 1;
}

int remove_inicio(Lista *l, char *nome)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;

    strcpy(nome, aux->info->nome);

    if(*l == (*l)->prox)
    {
        *l = NULL;
    }else
    {
        (*l)->prox = aux->prox;
    }

    free(aux);
    return 1;
}

int remove_final(Lista *l, char *nome)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;
    Lista aux2 = aux->prox; //guarda endere�o primeiro no

    strcpy(nome, aux->info->nome);

    while(aux->prox != *l)
    {
        aux = aux->prox;
    }

    *l = aux;
    free(aux->prox);
    aux->prox = aux2;

    return 1;
}

int remove_pos(Lista *l, int pos, char*elem)
{
    if(lista_vazia(*l)==1 || pos<1)
    {
        return 0;
    }

    int cont=1;

    while(pos > cont)
    {
        *l = (*l)->prox;
        pos--;
    }

    Lista aux = (*l)->prox;
    strcpy(elem, aux->info->nome);
    (*l)->prox = aux->prox;
    free(aux);

    return 1;
}

int remove_elem(Lista *l, char *nome)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;

    if(strcmp(aux->info->nome, nome)==0)
    {
        remove_inicio(l, nome);
        return 1;
    }else
    {
        while(aux->prox != *l && strcmp(aux->prox->info->nome, nome) != 0)
        {
            aux = aux->prox;

            if(aux->prox == *l && strcmp(aux->prox->info->nome, nome) == 0)
            {
                remove_final(l, nome);
                return 1;
            }
        }

        if(aux->prox == *l && strcmp(aux->prox->info->nome, nome) != 0)
        {
            return 0;
        }
    }

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);

    return 1;
}

//contagem para elimina��o a partir do primeiro soldado da lista
int contagem_primeiro_soldado(Lista *l, Lista *E, int numero, char *eliminado)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = (*l)->prox; //aux recebe endere�o do primeiro n�

    while(numero > 1)
    {
        aux = aux->prox; //avan�a aux
        numero--;
    }

    strcpy(eliminado, aux->info->nome);

    insere_soldado(E, eliminado); //insere soldado eliminado na lista de eliminados

    return 1;
}

//contagem para elimina��o a partir de posi��o aleat�ria
int contagem_posicao_aleatoria(Lista *l, int posicao)
{
    if (lista_vazia(*l) == 1 || posicao < 2)
    {
        return 0;
    }

    int cont=1;

    //achar posi��o desejada na lista e fazer lista come�ar naquela posi��o, seguindo ordem da lista original
    while(posicao > cont)
    {
        *l = (*l)->prox;
        posicao--;
    }

    return 1;
}

//contagem para elimina��o a partir de soldado espec�fico
int contagem_soldado_especifico(Lista *l, char *especifico)
{
    if (lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;
    Lista aux2 = *l;

    //achar soldado desejado na lista e fazer lista come�ar naquele soldado, seguindo ordem da lista original
    while(strcmp(especifico, aux->info->nome)!=0 && aux != *l)
    {
        aux2 = aux;
        aux = aux->prox;
    }

    *l = aux2;

    return 1;
}

int get_posicao(Lista l, char *nome)
{
    if (lista_vazia(l) == 1)
    {
        return 0;
    }

    Lista aux = l->prox; //recebe endere�o do primeiro n�

    if (strcmp(nome, l->prox->info->nome)==0) //caso elemento seja igual ao do primeiro n�
    {
        return 1;
    }

    int pos = 1;

    while(aux != l && strcmp(aux->prox->info->nome, nome)!=0) //percorre lista enquanto aux diferente do �ltimo n� e at� elemento ser diferente daquele em seguida do n� aux
    {
        aux = aux->prox;
        pos++;
    }

    int fim;
    get_fim(&l, &fim);

    if (pos+1 > fim) //caso pos resulte em um n�mero maior que o tamanho da lista
    {
        return 0;
    }

    return pos+1;
}

int get_fim(Lista *l, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = *l; //recebe endere�o do primeiro n�

    while(aux->prox != *l)
    {
        aux = aux->prox; //avan�a aux at� fim da lista
        pos++;
    }

    *i = pos;
    return 1;
}


int get_values(Lista *l, char *nome, int p)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = (*l)->prox; //recebe endere�o do primeiro n�

    int pos=1;
    int tam;
    get_fim(l, &tam);

    if(p==1) //caso posi��o seja a primeira
    {
        strcpy(nome, aux->info->nome);
        return 1;
    }

    if(p==tam) //caso posi��o seja a �ltima
    {
        strcpy(nome, (*l)->info->nome);
        return 1;
    }

    while(pos < p)
    {
        if(aux->prox == *l) //caso aux apontar para �ltimo n� da lista, interrompe la�o
        {
            pos=p;
        }else
        {
            aux = aux->prox; //avan�a aux
            pos++;
        }
    }

    strcpy(nome, aux->info->nome);

    return 1;
}
int limpa_lista(Lista *l)
{
    if(lista_vazia(*l) == 1)
        return 0;

    free(*l);
    *l = NULL;

    return 1;
}
