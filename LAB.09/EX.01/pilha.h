#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, int elem);//push
int pop(Pilha p, int *elem);//pop
int le_topo(Pilha p, int *elem);
void print1(Pilha p);

#endif // PILHA_H_INCLUDED
