#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

#define MAX 50 //usar para tamanho máximo de char para nome de soldados

/*tipo de implementação escolhida: encadeamento dinâmico e
circular, uma vez que não se sabe o número máximo de soldados
a serem considerados no problemas (será dado de entrada pelo
usuários); além disso, a lista de soldados terá que ser
percorrida até dar o número de contagem, o qual pode ser atingido
após uma ou mais voltas no 'círculo' de soldados.
Assim, o fato do encadeamento circular guardar o primeiro e
último nós da lista, ajudará nesse processo de rodas mais de
uma vez os soldados, caso necssário. Se ainda não deu o número
de contagem e já chegou no último soldado, tem que continuar
a contagem seguindo para o primeiro novamente. */

//struct de para nomes dos soldados
struct Soldados
{
    char nome[MAX];
};
typedef struct Soldados soldado;

//struct para lista dinâmica encadeada do tipo circular, contendo struct soldado
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

//inserção no fim da lista
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
        N->prox = (*l)->prox; //campo próximo do novo nó recebe endereço do primeiro nó da lista
        (*l)->prox = N; //região que até então tinha último nó da lista passa a apontar para novo nó - que corresponde ao último elemento
        *l = N; //lista aponta para novo nó - último
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
    Lista aux2 = aux->prox; //guarda endereço primeiro no

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

//contagem para eliminação a partir do primeiro soldado da lista
int contagem_primeiro_soldado(Lista *l, Lista *E, int numero, char *eliminado)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = (*l)->prox; //aux recebe endereço do primeiro nó

    while(numero > 1)
    {
        aux = aux->prox; //avança aux
        numero--;
    }

    strcpy(eliminado, aux->info->nome);

    insere_soldado(E, eliminado); //insere soldado eliminado na lista de eliminados

    return 1;
}

//contagem para eliminação a partir de posição aleatória
int contagem_posicao_aleatoria(Lista *l, int posicao)
{
    if (lista_vazia(*l) == 1 || posicao < 2)
    {
        return 0;
    }

    int cont=1;

    //achar posição desejada na lista e fazer lista começar naquela posição, seguindo ordem da lista original
    while(posicao > cont)
    {
        *l = (*l)->prox;
        posicao--;
    }

    return 1;
}

//contagem para eliminação a partir de soldado específico
int contagem_soldado_especifico(Lista *l, char *especifico)
{
    if (lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;
    Lista aux2 = *l;

    //achar soldado desejado na lista e fazer lista começar naquele soldado, seguindo ordem da lista original
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

    Lista aux = l->prox; //recebe endereço do primeiro nó

    if (strcmp(nome, l->prox->info->nome)==0) //caso elemento seja igual ao do primeiro nó
    {
        return 1;
    }

    int pos = 1;

    while(aux != l && strcmp(aux->prox->info->nome, nome)!=0) //percorre lista enquanto aux diferente do último nó e até elemento ser diferente daquele em seguida do nó aux
    {
        aux = aux->prox;
        pos++;
    }

    int fim;
    get_fim(&l, &fim);

    if (pos+1 > fim) //caso pos resulte em um número maior que o tamanho da lista
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

    Lista aux = *l; //recebe endereço do primeiro nó

    while(aux->prox != *l)
    {
        aux = aux->prox; //avança aux até fim da lista
        pos++;
    }

    *i = pos;
    return 1;
}


int get_values(Lista *l, char *nome, int p)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = (*l)->prox; //recebe endereço do primeiro nó

    int pos=1;
    int tam;
    get_fim(l, &tam);

    if(p==1) //caso posição seja a primeira
    {
        strcpy(nome, aux->info->nome);
        return 1;
    }

    if(p==tam) //caso posição seja a última
    {
        strcpy(nome, (*l)->info->nome);
        return 1;
    }

    while(pos < p)
    {
        if(aux->prox == *l) //caso aux apontar para último nó da lista, interrompe laço
        {
            pos=p;
        }else
        {
            aux = aux->prox; //avança aux
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
