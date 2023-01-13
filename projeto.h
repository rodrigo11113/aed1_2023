//
// Created by ACER-PC on 18/11/2022.
//
#include "stdio.h"

#ifndef PROJETO_AED_2022_PROJETO_H
#define PROJETO_AED_2022_PROJETO_H
typedef struct data
{
    int dia;
    int mes;
    int ano;
}DATA;
typedef struct key_holder{
    int id_keyholder;
    DATA data_criacao;
    DATA data_modificacao;
    int lines;
    short **matrix_int_pub;
    short **matrix_int_priv;
    short **matrix_int_cod;
    short **matrix_char_pub;
    short **matrix_char_priv;
    short **matrix_char_cod;
    struct key_holder *pnext;
}KEY_HOLDER;
typedef struct key_holders{
    KEY_HOLDER *pfirst;
}KEY_HOLDERS;
typedef struct utilizador
{
    char *nome;
    char* email;
    KEY_HOLDERS *key;
    struct utilizador *pnext,*pbefore;
} UTILIZADOR;
typedef struct utilizadores
{
    UTILIZADOR *phead,*ptail;
    int nutilizadores;
} UTILIZADORES;

int main_project();
int verifica_bipolar(int n);
int count_num(int n);
void print_matrix(short **matrix,int lines);
int key_index(short **matrix,int lines, unsigned long long key);
void selection_sort(short **matrix,int lines);
void selection_sort_des(short **matrix,int lines);
void insert_key_holder(int lines,int id,KEY_HOLDERS *kp,DATA data,DATA datamodif, short **matrix_int_pub,short **matrix_int_priv,short **matrix_int_cod,short **matrix_char_pub,short **matrix_char_priv,short **matrix_char_cod);
void selection_sort_all(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod,int lines);
void selection_sort_des_all(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod,int lines);
int diferencna_data(DATA *d1, DATA *d2);
KEY_HOLDER *find_key_holder(KEY_HOLDERS *keyHolders,int id);
void remove_key_holder(KEY_HOLDERS *pcs, int id);
void print_key_holders(KEY_HOLDERS cs);
void insert_utilizador(char *nome,char *email,KEY_HOLDERS *kp,UTILIZADORES *uti);
int comparar_nome(char *a, char *b);
void insertion_sort(UTILIZADORES *uti);
void print_uti(UTILIZADORES *uti);
UTILIZADOR *merge(UTILIZADOR *first,UTILIZADOR *second);
UTILIZADOR * mergeSort(UTILIZADOR *node);
UTILIZADOR * split(UTILIZADOR *head);
UTILIZADOR *partitionLast(UTILIZADOR *start,UTILIZADOR *end);
void sort(UTILIZADOR *start, UTILIZADOR *end);
UTILIZADOR *find_utilizador_bin_search(UTILIZADORES *uti, char *nome);
void remove_cliente(UTILIZADORES *pcs, char * nome);
void print_matrix_char(char **matrix,int lines);
int key_index_char(char **matrix,int lines, unsigned long long key);
void  bubbleSort( UTILIZADORES *uti);
#endif //PROJETO_AED_2022_PROJETO_H
