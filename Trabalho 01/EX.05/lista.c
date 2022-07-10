#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no* prox;
};

Lista cria_lista(){
    return NULL;
}


int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1;
    else
        return 0;
}

int insere_final(Lista *lst,int elem){
    Lista N=(Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    N->info=elem;
    if(lista_vazia(*lst)==1){
        N->prox=N;
        *lst=N;
    }
    else{
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
        (*lst)=N;
    }
    return 1;
}

int remove_inicio(Lista *lst,int *elem){
    if(lista_vazia(*lst)==1)
        return 0;
    Lista aux=(*lst)->prox;
    *elem=aux->info;
    if(*lst==(*lst)->prox)
        *lst=NULL;
    else
        (*lst)->prox=aux->prox;
    free(aux);
    return 1;
}

int insere_inicio(Lista *lst,int elem){
    Lista N=(Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    N->info=elem;
    if(lista_vazia(*lst)==1){
        N->prox=N;
        *lst=N;
    }
    else{
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
    }
    return 1;
}

int insere_posicao(Lista *lst,int pos,int elem){
    if(pos<1)
        return 0;
    if (pos==1){
        int R=insere_inicio(&(*lst),elem);
        return R;
    }
    //posição maior que 1 em lista vazia não existe
    if(pos>1 && *lst!=NULL){
        int i=2;
        Lista aux=(*lst)->prox;
        //percorrer a lista até achar posição ou a lista ser toda percorrida
        while(aux!=*lst && i<pos){
            aux=aux->prox;
            i++;
        }
        //verificar se a posição é maior que a lista
        if(pos>i)
            return 0;
        Lista N=(Lista)malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        N->info=elem;
        N->prox=aux->prox;
        aux->prox=N;
        //caso seja colocado na maior posição
        if(*lst==aux)
            *lst=N;
    }
    //caso posição seja maior q 1 e lista não exista, posição é fora de alcance
    if(*lst==NULL)
        return 0;
    return 1;
}

int remove_final(Lista *l, int *elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;
    Lista aux2 = aux->prox; //guarda endereço primeiro no

    elem = aux->info;

    while(aux->prox != *l)
    {
        aux = aux->prox;
    }

    *l = aux;
    free(aux->prox);
    aux->prox = aux2;

    return 1;
}

int remove_elem(Lista *l, int *elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;

    if(aux->info == elem)
    {
        remove_inicio(l, elem);
        return 1;
    }else
    {
        while(aux->prox != *l && aux->prox->info != elem)
        {
            aux = aux->prox;

            if(aux->prox == *l && aux->prox->info == elem)
            {
              remove_final(l, elem);
                return 1;
            }
        }

        if(aux->prox == *l && aux->prox->info != elem)
        {
            return 0;
        }
    }

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);

    return 1;
}

int remove_pos(Lista *l, int pos, int *elem)
{
    int tam;
    get_fim(l, &tam);

    if (pos < 1 || pos > tam || lista_vazia(*l)==1)
        return 0;

    int cont=1;
    Lista aux = *l;

    if(pos == 1)
    {
        remove_inicio(l, elem);
        return 1;
    }

    if(pos == tam)
    {
        remove_final(l, elem);
        return 1;
    }

    while(cont < pos+1)
    {
        aux = aux->prox;
        cont++;
    }

    elem = aux->info;
    remove_elem(l, aux->info);

    return 1;
}


int get_fim(Lista *l, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = (*l)->prox;

    while(aux->prox != (*l)->prox)
    {
        aux = aux->prox;
        pos++;
    }

    *i = pos;
    return 1;
}

int remove_par(Lista *lst){
    if(lista_vazia(*lst)==1)
        return 0;
    Lista aux=(*lst);
    //verificar a paridade da lista até o penúltimo último elemento
    while(aux->prox!=*lst){

        while(aux->prox->info%2==0 && aux->prox!=*lst){
            Lista aux2=aux->prox;
            aux->prox=aux->prox->prox;
            free(aux2);
        }
        aux=aux->prox;
    }
    //verificar o último elemento
    if(aux->prox->info%2==0 ){
            if((*lst)==(*lst)->prox){
                *lst=NULL;
                free(aux);
                return 1;
            }
            else{
                Lista aux2=aux->prox;
                aux->prox=(*lst)->prox;
                free(aux2);
                *lst=aux;

            }
    }
    return 1;
}

int obtem_valor_elem(Lista lst,int pos,int *elem){
    if(lst==NULL || pos<1)
        return 0;
    //lista com 1 elemento
    if(lst==lst->prox){
        if(pos==1){
            *elem=lst->info;
            return 1;
        }
        else
            return 0;
    }
    else{
        Lista aux=lst->prox;
        int i=1;
        //percorrer a lista até achar posição
        while(aux!=lst && i<pos){
            aux=aux->prox;
            i++;
        }
        //posição não existir
        if(pos>i)
            return 0;
        *elem=aux->info;
        return 1;
    }
}
