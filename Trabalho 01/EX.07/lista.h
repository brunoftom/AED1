#ifndef JOSEPHUS_H_INCLUDED
#define JOSEPHUS_H_INCLUDED

typedef struct Soldados soldado;
typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int insere_soldado(Lista *l, char *nome);
int remove_inicio(Lista *l, char *nome);
int remove_final(Lista *l, char *nome);
int remove_pos(Lista *l, int pos, char*elem);
int remove_elem(Lista *l, char *nome);
int contagem_primeiro_soldado(Lista *l, Lista *E, int numero, char *eliminado);
int contagem_posicao_aleatoria(Lista *l, int posicao);
int contagem_soldado_especifico(Lista *l, char *especifico);
int get_posicao(Lista l, char *nome);
int get_fim(Lista *l, int *i);
int get_values(Lista *l, char *nome, int p);
int limpa_lista(Lista *l);

#endif // JOSEPHUS_H_INCLUDED
