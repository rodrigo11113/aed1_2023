//
// Created by ACER-PC on 18/11/2022.
//

#include <stdlib.h>
#include <time.h>
#include "projeto.h"
#include "lib_util.h"
#include "aed1_lp1_2223_proj_part1_chars.h"
#include "aed1_lp1_2223_proj_part1_ints.h"

#define NCOLS 10

int main_project() {
    //printf("%d\n",comparar_nome("a","b"));
    //key_long_2_digits_int(1234);
    // calc_private_key_int(2013);
    //calc_runlength_int(1222);
    //private_key_from_runlength_int(3433);
    //key_digits_2_long_int(key_long_2_digits_int(1234));
    time_t t;
    srand((unsigned) time(&t));
    short **matrix = alloc_matrix_int(10, NCOLS);
    short **matrix1 = alloc_matrix_int(10, NCOLS);
    short **matrix2 = alloc_matrix_int(10, NCOLS);
    /* store_key_int(matrix,10,1);
      store_key_int(matrix,10,1122);
      store_key_int(matrix,10,113);
      store_key_int(matrix,10,117);
      store_key_int(matrix,10,1110);
      print_matrix(matrix,10);
      store_key_int(matrix_1,10,calc_private_key_int(1));
      store_key_int(matrix_1,10,calc_private_key_int(1112));
      store_key_int(matrix_1,10,calc_private_key_int(113));
    store_key_int(matrix_1,10,calc_private_key_int(1110));
      print_matrix(matrix1,10);
      store_key_int(matrix2,10,calc_runlength_int(calc_private_key_int(1)));
      store_key_int(matrix2,10,calc_runlength_int(calc_private_key_int(1112)));
      store_key_int(matrix2,10,calc_runlength_int(calc_private_key_int(113)));
      store_key_int(matrix2,10,calc_runlength_int(calc_private_key_int(1110)));
      print_matrix(matrix2,10);
      delete_key_int(matrix,matrix1,matrix2,10,113);
      print_matrix(matrix,10);
      print_matrix(matrix1,10);
      print_matrix(matrix2,10);*/
    //bulk_populate_public_keys_int(matrix,10);
    //print_matrix(matrix,10);
    //selection_sort(matrix,10);
    //selection_sort_des(matrix,10);
    //print_matrix(matrix,10);
    //bulk_compute_private_keys_int(matrix,matrix1,10);
    //print_matrix(matrix1,10);
    //bulk_compute_runlengths_int(matrix1,matrix2,10);
    //list_keys_int(matrix,matrix1,matrix2,10,0);
    //print_matrix(matrix2,10);
    //selection_sort_all(matrix,matrix1,matrix2,10);
    //print_matrix(matrix,10);
    // print_matrix(matrix1,10);
    // print_matrix(matrix2,10);
    /*store_key_int(matrix,10,1);
    store_key_int(matrix,10,1122);
    store_key_int(matrix,10,113);
    store_key_int(matrix,10,117);
    store_key_int(matrix,10,1110);
    print_matrix(search_private_keys_int(matrix,matrix2,10,11),10);*/
/*KEY_HOLDERS pcs={NULL};
bulk_populate_public_keys_int(matrix,10);
bulk_compute_private_keys_int(matrix,matrix1,10);
bulk_compute_runlengths_int(matrix1,matrix2,10);
    DATA d1 = {11, 1, 2000};
    DATA d2 = {11, 1, 2001};
    DATA d3 = {11, 2, 2000};
    DATA d4 = {11, 3, 2000};
insert_key_holder(10,1,&pcs,d1,d2,matrix,matrix1,matrix2,NULL,NULL,NULL);
insert_key_holder(10,2,&pcs,d1,d3,matrix,matrix1,matrix2,NULL,NULL,NULL);
insert_key_holder(10,3,&pcs,d1,d4,matrix,matrix1,matrix2,NULL,NULL,NULL);
print_key_holders(pcs);
remove_key_holder(&pcs,2);
    print_key_holders(pcs);*/
    UTILIZADORES uti = {NULL, NULL, 0};
    insert_utilizador("joao", "oi", NULL, &uti);
    insert_utilizador("ana", "oi", NULL, &uti);
    insert_utilizador("bruno", "oi", NULL, &uti);
    insert_utilizador("zeto", "oi", NULL, &uti);
    insert_utilizador("maria", "oi", NULL, &uti);
    insert_utilizador("mario", "oi", NULL, &uti);
    print_uti(&uti);
    //remove_cliente(&uti,"bruno");
    bubbleSort(&uti);
    print_uti(&uti);
//printf("%llu \n",key_digits_2_long_char(key_long_2_digits_char(12)));
    char **matrix_char = alloc_matrix_char(10, NCOLS);
    store_key_char(matrix_char, 10, new_public_key_int());
    store_key_char(matrix_char, 10, new_public_key_int());
    store_key_char(matrix_char, 10, new_public_key_int());
    print_matrix_char(matrix_char, 10);
//bulk_populate_public_keys_char(matrix_char,10);
    //print_matrix_char(matrix_char,10);
    return 0;
}

/**
 * Generate a random integer to be used as the public key.
 * @return random number representing a public key
 */
unsigned long long new_public_key_int(void) {//gera numero entre 1 e 1000
    int r = rand() % 1000 + 1;
    return r;

}

/**
 * Create an array of digits for a given key.
* @param key - long key
 * @return address of array of digits for a given key
 */
short *key_long_2_digits_int(unsigned long long key) {

    int count = count_num(key);

    short *array = (short *) calloc(count, sizeof(short));
    int n = key;
    int i = count;
    count = 0;
    //short *a=array;
    for (int k = i - 1; k >= 0; k--) {
        array[k] = n % 10;
        n /= 10;
        count++;
    }
    return array;
}

/**
 * Receives an array of digits and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_int(short *keydigits) {
    unsigned long long key = 0;
    int i = 0;
    while (keydigits[i] >= 0) {
        key = key * 10 + keydigits[i];
        i++;
    }
    //printf("%llu",key);
    return key;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).bruteforce
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_int(unsigned long long pubkey) {
    unsigned long long bip = 2 * pubkey;
    int i = 3;
    while (1) {
        if (verifica_bipolar(bip) == 1) {
            break;
        }
        bip = i * pubkey;
        i++;
    }
    return bip;
}

/**
 * verifica se e o numero e bipolar ou nao
 * @param n numero
 * @return
 */
int verifica_bipolar(int n) {//recebe um numero e verifica se e bipolar retorna 1 se sim e 0 senao
    int countchange = 0;
    int count = count_num(n);
    if (count == 1) {
        //printf("nao e bipolar\n");
        return 0;
    }
    short *array = key_long_2_digits_int(n);
    for (int i = 0; i < count - 1; i++) {
        if (array[i] != array[i + 1]) {
            countchange++;
        }
    }
    if (n < 0)
        return 0;
    if (countchange > 1) {
        //printf("nao e bipolar\n");
        return 0;
    }
//printf("e bipolar\n");
    return 1;
}

/**
 * conta o num de digitos
 * @param n numero
 * @return numero de digitos
 */
int count_num(int n) { //conta o num de digitos
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_int(unsigned long long privkey) {
    int count = count_num(privkey);
    int a = 0;
    int a1 = 0;
    int b = 0;
    int b1 = 0;
    int flag = 0;
    short *ar = key_long_2_digits_int(privkey);
    a1 = ar[0];
    for (int i = 0; i < count; ++i) {
        if (flag == 0) {
            a++;
            if (ar[i] != ar[i + 1]) {
                b1 = ar[i + 1];
                flag = 1;
            }

        } else
            b++;
    }
    unsigned long long num = b1 + (10 * b) + (100 * a1) + (1000 * a);
    //printf("%d",num);
    return num;
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_int(unsigned long long runlengthkey) {
    short *ar = key_long_2_digits_int(runlengthkey);
    unsigned long long num = 0;

    for (int i = 0; i < ar[2]; i++) {
        num = num + (ar[3] * pow(10, i));
    }
    for (int i = 0; i < ar[0]; i++) {
        num = num + (ar[1] * pow(10, ar[2] + i));
    }
    return num;
}

/**
 * Memory allocation for a int matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
short **alloc_matrix_int(int nlines, int ncolumns) {
    short **matrix = calloc(nlines, sizeof(short *));
    for (int i = 0; i < nlines; i++) {
        matrix[i] = calloc(ncolumns, sizeof(short));
    }
    return matrix;
}

/**
 * Store a key (pub, priv or run-length) into the first available position of given matrix.
 * @param matrix - matrix to store the key
 * @param lines - matrix number of lines
 * @param key - key to be stored
 */
void store_key_int(short **matrix, int lines, unsigned long long key) {
    short *key_digits = key_long_2_digits_int(key);
    int num = count_num(key);
    for (int i = 0; i < lines; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < num + 1; j++) {
                if (j == num)
                    matrix[i][j] = -1;
                else
                    matrix[i][j] = key_digits[j];
            }

            return;
        }
    }
}

/**
 * Verify if a given key exists in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return 1 if it exists, 0 if it doesn't
 */
int exists_key_int(short **matrix, int lines, unsigned long long key) {
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_int(matrix[i]) == key)
            return 1;
    }
    return 0;
}

/**
 * index of  a given key  in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return index if it exists, -1 if it doesn't
 */
int key_index(short **matrix, int lines, unsigned long long key) {
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_int(matrix[i]) == key)
            return i;
    }
    return -1;
}

/**
 * imprime uma amtrix
 * @param matrix a imprimir
 * @param lines numero de linhas
 */
void print_matrix(short **matrix, int lines) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Returns the private key corresponding to the given public key
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key of the given pubkey
 */
unsigned long long
get_private_key_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long pubkey) {
    /*if(exists_key_int(matrix_kpub,lines,pubkey)==1){
        unsigned long long privkey=calc_private_key_int(pubkey);
        short *keydigit=key_long_2_digits_int(privkey);
        int num=count_num(privkey);
        for (int i = 0; i < lines; i++) {
            if (matrix_kpriv[i][0] == 0) {
                for (int j = 0; j<num+1; j++) {
                    if(j==num)
                        matrix_kpriv[i][j]=-1;
                    else
                        matrix_kpriv[i][j] = keydigit[j];
                }
                return privkey;
            }
        }
        return -1;
    } else{
        printf("Nao existe \n");
        return -1;}*/
    unsigned long long privkey = calc_private_key_int(pubkey);
    if (exists_key_int(matrix_kpriv, 10, privkey) == 1)
        return privkey;
    else {
        printf("Nao existe \n");
        return -1;
    }
}

/**
 * Returns the run-length key of a given private key
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key runlength of the given pubkey
 */
unsigned long long get_runlength_int(short **matrix_kpriv, short **matrix_kcod, int lines, unsigned long long privkey) {
    /* if(exists_key_int(matrix_kpriv,lines,privkey)==1){
         unsigned long long privrun=calc_runlength_int(privkey);
         short *keydigit=key_long_2_digits_int(privrun);
         int num=count_num(privrun);
         for (int i = 0; i < lines ; i++) {
             if(matrix_kcod[i][0]==0){
                 for (int j = 0; j <num+1 ; j++) {
                     if(j==num)
                         matrix_kcod[i][j]=-1;
                     else
                         matrix_kcod[i][j] = keydigit[j];
                 }
                 return privrun;
             }
         }
         printf("Nao existe \n");
         return -1;
     }
     else {
         printf("Nao existe \n");
         return -1;
     }*/
    unsigned long long runkey = calc_private_key_int(privkey);
    if (exists_key_int(matrix_kcod, 10, runkey) == 1)
        return runkey;
    else {
        printf("Nao existe \n");
        return -1;
    }
}

/**
 * Delete a given public key (and corresponding priv and runlength keys) from all matrices.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key to delete
 * @return pubkey that was deleted
 */
unsigned long long   delete_key_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, short pubkey) {
    if (exists_key_int(matrix_kpub, 10, pubkey)) {
        unsigned long long privkey = calc_private_key_int(pubkey);
        unsigned long long runkey = calc_runlength_int(privkey);
        for (int i = key_index(matrix_kpub, 10, pubkey); i < lines; ++i) {
            if (i + 1 == lines) {
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpub[i][j] = 0;
                }
            } else {
                matrix_kpub[i] = matrix_kpub[i + 1];
                if (matrix_kpub[i + 1][0] == 0)
                    break;
            }
        }
        for (int i = key_index(matrix_kpriv, 10, privkey); i < lines; ++i) {
            if (i == -1)
                break;
            if (i + 1 == lines) {
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpriv[i][j] = 0;
                }
            } else {
                matrix_kpriv[i] = matrix_kpriv[i + 1];
                if (matrix_kpriv[i + 1][0] == 0)
                    break;
            }
        }
        for (int i = key_index(matrix_kcod, 10, runkey); i < lines; ++i) {
            if (i == -1)
                break;
            if (i + 1 == lines) {
                for (int j = 0; j < 4; ++j) {
                    matrix_kcod[i][j] = 0;
                }
            } else {
                matrix_kcod[i] = matrix_kcod[i + 1];
                if (matrix_kcod[i + 1][0] == 0)
                    break;
            }
        }
    } else {
        printf("Nao existe\n");
    }
}

/**
 * Automatically generate and save a given amount (<lines>) of public keys.
 * @param matrix_kpub - public keys matrix
 * @param lines - matrix number of lines
 */
void bulk_populate_public_keys_int(short **matrix_kpub, int lines) {
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kpub, lines, new_public_key_int());
    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines) {
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kpriv, 10, calc_private_key_int(key_digits_2_long_int(matrix_kpub[i])));
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_int(short **matrix_kpriv, short **matrix_kcod, int lines) {
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kcod, 10, calc_runlength_int(key_digits_2_long_int(matrix_kpriv[i])));
    }
}

/**
 * Return a list of all private keys matching a given partial public key.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param partialpubkey - part of public key to filter the private keys
 * @return array of private keys matching the partialpubkey
 */
short **
search_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long partialpubkey) {
    short **matrix = calloc(lines, sizeof(short *));
    for (int i = 0; i < lines; i++) {
        matrix[i] = calloc(NCOLS, sizeof(short));
    }
    for (int i = 0; i < lines; ++i) {
        short *key = matrix_kpub[i];
        short *partialkey = key_long_2_digits_int(partialpubkey);
        int sizepartkey = count_num(partialpubkey);
        int sizekey = count_num(key_digits_2_long_int(matrix_kpub[i]));
        int flag = 0;
        if (sizepartkey > sizekey)
            continue;
        else {
            for (int j = 0; j < sizekey; ++j) {
                if (j + sizepartkey >= sizekey) {
                    flag = 1;
                    break;
                }

                if (key[j] == partialkey[0]) {
                    for (int k = 1; k < sizepartkey; ++k) {

                        if (key[j + k] != partialkey[k]) {
                            flag = 1;
                            break;
                        }

                    }

                }
                if (flag == 0) {
                    store_key_int(matrix, 10, calc_private_key_int(key_digits_2_long_int(matrix_kpub[i])));

                }

            }
        }
    }
    return matrix;
}

/**
 * selection sort para ordenar a matrix
 * @param matrix a ser ordenaada
 * @param lines numero de linhas
 */
void selection_sort(short **matrix, int lines) {
    int n = lines;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (key_digits_2_long_int(matrix[j]) < key_digits_2_long_int(matrix[min_idx]))
                min_idx = j;

        // Swap the found minimum element with the first
        // element
        short *temp = matrix[min_idx];
        matrix[min_idx] = matrix[i];
        matrix[i] = temp;
    }
}

/**
 * selection sort para ordenar as 3
 * @param matrix_kpub
 * @param matrix_kpriv
 * @param matrix_kcod
 * @param lines
 */
void selection_sort_all(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines) {
    int n = lines;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (key_digits_2_long_int(matrix_kpub[j]) < key_digits_2_long_int(matrix_kpub[min_idx]))
                min_idx = j;

        // Swap the found minimum element with the first
        // element
        short *temp = matrix_kpub[min_idx];
        matrix_kpub[min_idx] = matrix_kpub[i];
        matrix_kpub[i] = temp;
        short *temp1 = matrix_kpriv[min_idx];
        matrix_kpriv[min_idx] = matrix_kpriv[i];
        matrix_kpriv[i] = temp1;
        short *temp2 = matrix_kcod[min_idx];
        matrix_kcod[min_idx] = matrix_kcod[i];
        matrix_kcod[i] = temp2;
    }
}

/**
 * selection sort para ordenar descendentemente
 * @param matrix
 * @param lines
 */
void selection_sort_des(short **matrix, int lines) {
    int n = lines;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the maximum element in unsorted array
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (key_digits_2_long_int(matrix[j]) > key_digits_2_long_int(matrix[max_idx]))
                max_idx = j;

        // Swap the found minimum element with the first
        // element
        short *temp = matrix[max_idx];
        matrix[max_idx] = matrix[i];
        matrix[i] = temp;
    }
}

/**
 *  selection sort para ordenar descendentemente as 3
 * @param matrix_kpub
 * @param matrix_kpriv
 * @param matrix_kcod
 * @param lines
 */
void selection_sort_des_all(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines) {
    int n = lines;

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the maximum element in unsorted array
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (key_digits_2_long_int(matrix_kpub[j]) > key_digits_2_long_int(matrix_kpub[max_idx]))
                max_idx = j;

        // Swap the found minimum element with the first
        // element
        short *temp = matrix_kpub[max_idx];
        matrix_kpub[max_idx] = matrix_kpub[i];
        matrix_kpub[i] = temp;
        short *temp1 = matrix_kpriv[max_idx];
        matrix_kpriv[max_idx] = matrix_kpriv[i];
        matrix_kpriv[i] = temp1;
        short *temp2 = matrix_kcod[max_idx];
        matrix_kcod[max_idx] = matrix_kcod[i];
        matrix_kcod[i] = temp2;
    }
}

/**
 * Sort a matrix keys in ascending or descending order
 * @param matrix - matrix to be sorted
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_matrix_int(short **matrix, int lines, int order) {
    if (order == 1) {
        selection_sort(matrix, lines);
    } else {
        selection_sort_des(matrix, lines);
    }
}

/**
 * Sort all matrices keys in ascending or descending order
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_all_matrices_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order) {
    if (order == 1) {
        selection_sort_all(matrix_kpub, matrix_kpriv, matrix_kcod, lines);
    } else {
        selection_sort_des_all(matrix_kpub, matrix_kpriv, matrix_kcod, lines);
    }
}

/**
 * inserir na lista ligada de key_holder
 * @param lines numero de linhas
 * @param id id do key_holder
 * @param kp aontador
 * @param data
 * @param datamodif
 * @param matrix_int_pub
 * @param matrix_int_priv
 * @param matrix_int_cod
 * @param matrix_char_pub
 * @param matrix_char_priv
 * @param matrix_char_cod
 */
void insert_key_holder(int lines, int id, KEY_HOLDERS *kp, DATA data, DATA datamodif, short **matrix_int_pub,
                       short **matrix_int_priv,
                       short **matrix_int_cod, short **matrix_char_pub, short **matrix_char_priv,
                       short **matrix_char_cod) {
    KEY_HOLDER *temp = (KEY_HOLDER *) malloc(sizeof(KEY_HOLDER));
    KEY_HOLDER *temp2;
    temp->lines = lines;
    temp->data_criacao = data;
    temp->id_keyholder = id;
    temp->data_modificacao = datamodif;
    temp->matrix_char_cod = matrix_char_cod;
    temp->matrix_char_priv = matrix_char_priv;
    temp->matrix_char_pub = matrix_char_pub;
    temp->matrix_int_cod = matrix_int_cod;
    temp->matrix_int_priv = matrix_int_priv;
    temp->matrix_int_pub = matrix_int_pub;
    if (kp->pfirst == NULL) {
        kp->pfirst = temp;
        temp->pnext = NULL;
        return;
    } else {

        if (diferencna_data(&kp->pfirst->data_modificacao, &datamodif) == 0) {
            temp2 = kp->pfirst;
            kp->pfirst = temp;
            kp->pfirst->pnext = temp2;
            return;
        }
        KEY_HOLDER *current = kp->pfirst;
        while (current->pnext != NULL && diferencna_data(&current->data_modificacao, &datamodif) == 1) {
            temp2 = current;
            current = current->pnext;
        }
        if (diferencna_data(&current->data_modificacao, &datamodif) == 0) {

            temp2->pnext = temp;
            temp->pnext = current;

            return;
        }
        if (current->pnext == NULL) {
            current->pnext = temp;
            current->pnext->pnext = NULL;
            return;
        }/*
            KEY_HOLDER *current = kp->pfirst;
            while (current->pnext != NULL) {
                current = current->pnext;
            }
            current->pnext = temp;
            temp->pnext = NULL;
            temp->pbefore = current;*/
    }
}

/**
* Ve qual a data mais recente.
* @param d1 - apontador para a primeira data.
* @param d2 - apontador para a segunda data.
*/
int diferencna_data(DATA *d1, DATA *d2) {
    if (d1 == NULL) {
        return 0;
    }
    if (d1->ano > d2->ano)
        return 0;

    else if (d1->ano < d2->ano)
        return 1;

    if (d1->ano == d2->ano) {
        if (d1->mes > d2->mes)
            return 0;
        else if (d1->mes < d2->mes)
            return 1;
        else if (d1->dia > d2->dia)
            return 0;
        else if (d1->dia < d2->dia)
            return 1;

        return 1;
    }
    return 1;
}

KEY_HOLDER *find_key_holder(KEY_HOLDERS *keyHolders, int id) {
    KEY_HOLDER *current = keyHolders->pfirst;
    if (current->id_keyholder == id)
        return current;
    current = current->pnext;
    while (current != NULL) {
        if (current->id_keyholder == id)
            return current;

        current = current->pnext;
    }
    return NULL;
}

/**
 * Print all keys on the console, sorted by pubkeys sizes (i.e. number of digits).
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 0 ? current order : order == 1 ? ascending : descending
 */
void list_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order) {
    if (order == 0) {
        selection_sort_all(matrix_kpub, matrix_kpriv, matrix_kcod, lines);
    } else if (order == 1) {
        selection_sort_des_all(matrix_kpub, matrix_kpriv, matrix_kcod, lines);
    }
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < NCOLS; ++j) {
            printf("%d ", matrix_kpub[i][j]);
        }
        printf(" ");
        for (int j = 0; j < NCOLS; ++j) {
            printf("%d ", matrix_kpriv[i][j]);
        }
        printf(" ");
        for (int j = 0; j < NCOLS; ++j) {
            printf("%d ", matrix_kcod[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Remove um dado cliente.
 * @param pcs - apontador para a lista ligada (KEYHOLDERS).
 * @param pc - apontador para a lista ligada (KEYHOLDER).
 */
void remove_key_holder(KEY_HOLDERS *pcs, int id) {
    KEY_HOLDER *pcl = find_key_holder(pcs, id);
    KEY_HOLDER *temp;
    if (pcl != NULL) {
        if (pcl == pcs->pfirst) {
            printf(" Foi removido com sucesso com o id %d\n", id);
            pcs->pfirst = pcl->pnext;
            return;
        }
        if (pcl->pnext->pnext == NULL) {
            printf(" Foi removido com sucesso com o id %d\n", id);
            pcl->pnext = NULL;
            return;
        }
        printf(" Foi removido com sucesso com o id %d\n", id);
        pcl->pnext = pcl->pnext->pnext;
        return;
    }
    printf("Nao existe esse keyHolder com o id %d\n", id);
}

/**
 * Imprime toda a informação da lista ligada de keyholders.
 * @param cs - apontador para a lista ligada (keyholders).
 */
void print_key_holders(KEY_HOLDERS cs) {
    KEY_HOLDER *pc = cs.pfirst;
    while (pc != NULL) {


        printf("ID[%d] \n", pc->id_keyholder);
        list_keys_int(pc->matrix_int_pub, pc->matrix_int_priv, pc->matrix_int_cod, pc->lines, 2);
        pc = pc->pnext;

    }
}

/**
 * Compara dois nomes.
 * @param a - nome a.
 * @param b - nome b.
 */
int comparar_nome(char *a, char *b) {
    if (a == NULL)
        return 0;
    if (strcmp(a, b) > 0)
        return 0;
    return 1;
}

/**
 * insere utilizador ordenadamnete pelo nome
 * @param nome nome
 * @param email email
 * @param kp porta chaves
 * @param uti lista de utilizadores
 */
void insert_utilizador(char *nome, char *email, KEY_HOLDERS *kp, UTILIZADORES *uti) {
    UTILIZADOR *temp = (UTILIZADOR *) malloc(sizeof(UTILIZADOR));
    UTILIZADOR *temp2;
    temp->nome = (char *) malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(temp->nome, nome);
    temp->email = (char *) malloc(sizeof(char) * strlen(email) + 1);
    strcpy(temp->email, email);
    uti->nutilizadores++;
    temp->pnext = NULL;
    temp->pbefore = NULL;
    temp->key = kp;
    if (uti->phead == NULL) {
        uti->phead = temp;
        uti->ptail = temp;
    } else if (uti->phead == uti->ptail) {
        uti->ptail = temp;
        temp->pbefore = uti->phead;
        uti->phead->pnext = uti->ptail;
    } else {
        temp->pbefore = uti->ptail;
        uti->ptail = temp;
        uti->ptail->pbefore->pnext = uti->ptail;
    }
}

/**
 * imprime utilizadores
 * @param uti
 */
void print_uti(UTILIZADORES *uti) {
    UTILIZADOR *current = uti->phead;
    for (int i = 0; i < uti->nutilizadores; ++i) {
        printf("%s \n", current->nome);
        current = current->pnext;
    }
    printf("\n");
}

/**
 * usa bubblesort para ordenar a lista ligada
 * @param uti
 */
void bubbleSort(UTILIZADORES *uti) {
    int swapped;
    UTILIZADOR *ptr1;
    UTILIZADOR *lptr = NULL;

    // Checking for empty list
    if (uti->phead == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = uti->phead;

        while (ptr1->pnext != lptr) {
            if (comparar_nome(ptr1->nome, ptr1->pnext->nome) == 0) {
                UTILIZADOR temp;
                temp.nome = ptr1->nome;
                temp.key = ptr1->key;
                temp.email = ptr1->email;
                ptr1->nome = ptr1->pnext->nome;
                ptr1->key = ptr1->pnext->key;
                ptr1->email = ptr1->pnext->email;
                ptr1->pnext->nome = temp.nome;
                ptr1->pnext->key = temp.key;
                ptr1->pnext->email = temp.email;
                swapped = 1;
            }
            ptr1 = ptr1->pnext;
        }
        lptr = ptr1;
    } while (swapped != 0);
}

/**
 * Remove um dado utilizador.
 * @param pcs - apontador para a lista ligada (utilizador).
 * @param nome - nome do utilizador.
 */
void remove_cliente(UTILIZADORES *pcs, char *nome) {
    UTILIZADOR *pcl = find_utilizador_bin_search(pcs, nome);
    UTILIZADOR *temp;
    if (pcl != NULL) {
        if (pcl == pcs->phead) {
            printf("UTILIZADOR-> %s; Foi removido com sucesso\n", pcl->nome);
            pcs->phead = pcl->pnext;
            pcs->phead->pbefore = NULL;
            pcs->nutilizadores--;
            return;
        }
        if (pcl->pnext == NULL) {
            printf("UTILIZADOR -> %s; Foi removido com sucesso\n", pcl->nome);
            pcl->pbefore->pnext = NULL;
            pcs->nutilizadores--;
            return;
        }
        printf("UTILIZADOR -> %s; Foi removido com sucesso\n", pcl->nome);
        temp = pcl->pbefore;
        temp->pnext = pcl->pnext;
        pcl->pnext->pbefore = temp;
        pcs->nutilizadores--;

        return;
    }
    printf("Nao existe esse cliente com o %s\n", nome);
}

/**
 * Encontra um dado utilizador usando binary search.
 * @param uti - apontador para a lista ligada (UTILIZADORES).
 * @param nome - nome do cliente.
 */
UTILIZADOR *find_utilizador_bin_search(UTILIZADORES *uti, char *nome) {
    int first, last, middle;

    first = 0;
    last = uti->nutilizadores;
    middle = (first + last) / 2;

    while (first <= last) {
        UTILIZADOR *pmiddle = uti->phead;

        for (int i = 0; i < middle - 1; i++) {
            pmiddle = pmiddle->pnext;
        }

        if (strcmp(pmiddle->nome, nome) < 0)
            first = middle + 1;
        else if (strcmp(pmiddle->nome, nome) == 0) {
            return pmiddle;
        } else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last) {
        printf("Not found! %s is not present in the list.\n", nome);
        return NULL;
    }
    return 0;
}

/**
 * Create an array of digits in ascii i.e. chars for a given key.
* @param key - long key
 * @return address of array of digits in ascii for a given key
 */
char *key_long_2_digits_char(unsigned long long key) {

    int num_digits = count_num(key);

    char *key_digits = malloc(num_digits * sizeof(char));
    if (key_digits == NULL) {
        printf("Error allocating memory for key digits array\n");
        exit(1);
    }

    // Convert key to array of digits
    sprintf(key_digits, "%llu", key);

    return key_digits;
}

/**
 * Receives an array of digits in ascii i.e. chars and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_char(char *keydigits) {
    unsigned long long key = strtoull(keydigits, NULL, 10);
    return key;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_char(unsigned long long pubkey) {
    return calc_private_key_int(pubkey);
}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_char(unsigned long long privkey) {
    return calc_runlength_int(privkey);
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_char(unsigned long long runlengthkey) {
    return private_key_from_runlength_int(runlengthkey);
}

/**
 * Memory allocation for a char matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
char **alloc_matrix_char(int nlines, int ncolumns) {
    char **matrix = calloc(nlines, sizeof(char *));
    for (int i = 0; i < nlines; i++) {
        matrix[i] = calloc(ncolumns, sizeof(char));
    }
    return matrix;
}

/**
 * Store a key (pub, priv or run-length) into the first available position of given matrix.
 * @param matrix - matrix to store the key
 * @param lines - matrix number of lines
 * @param key - key to be stored
 */
void store_key_char(char **matrix, int lines, unsigned long long key) {
    char *key_digits = key_long_2_digits_char(key);
    int num = count_num(key);
    for (int i = 0; i < lines; i++) {
        if (matrix[i][0] == '\0') {
            strcpy(matrix[i], key_digits);
            break;

        }
    }
}

/**
 * imprime uma amtrix
 * @param matrix a imprimir
 * @param lines numero de linhas
 */
void print_matrix_char(char **matrix, int lines) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Verify if a given key exists in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return 1 if it exists, 0 if it doesn't
 */
int exists_key_char(char **matrix, int lines, unsigned long long key) {
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_char(matrix[i]) == key)
            return 1;
    }
    return 0;
}

/**
 * Delete a given public key (and corresponding priv and runlength keys) from all matrices.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key to delete
 * @return pubkey that was deleted
 */
unsigned long long
delete_key_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char pubkey) {
    if (exists_key_char(matrix_kpub, 10, pubkey)) {
        unsigned long long privkey = calc_private_key_int(pubkey);
        unsigned long long runkey = calc_runlength_int(privkey);
        for (int i = key_index_char(matrix_kpub, 10, pubkey); i < lines; ++i) {
            if (i + 1 == lines) {
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpub[i][j] = '\0';
                }
            } else {
                matrix_kpub[i] = matrix_kpub[i + 1];
                if (matrix_kpub[i + 1][0] == '\0')
                    break;
            }
        }
        for (int i = key_index_char(matrix_kpriv, 10, privkey); i < lines; ++i) {
            if (i == -1)
                break;
            if (i + 1 == lines) {
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpriv[i][j] = '\0';
                }
            } else {
                matrix_kpriv[i] = matrix_kpriv[i + 1];
                if (matrix_kpriv[i + 1][0] == '\0')
                    break;
            }
        }
        for (int i = key_index_char(matrix_kcod, 10, runkey); i < lines; ++i) {
            if (i == -1)
                break;
            if (i + 1 == lines) {
                for (int j = 0; j < 4; ++j) {
                    matrix_kcod[i][j] = '\0';
                }
            } else {
                matrix_kcod[i] = matrix_kcod[i + 1];
                if (matrix_kcod[i + 1][0] == '\0')
                    break;
            }
        }
    } else {
        printf("Nao existe\n");
    }
}

/**
 * index of  a given key  in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return index if it exists, -1 if it doesn't
 */
int key_index_char(char **matrix, int lines, unsigned long long key) {
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_char(matrix[i]) == key)
            return i;
    }
    return -1;
}

/**
 * Automatically generate and save a given amount (<lines>) of public keys.
 * @param matrix_kpub - public keys matrix
 * @param lines - matrix number of lines
 */
void bulk_populate_public_keys_char(char **matrix_kpub, int lines) {
    for (int i = 0; i < lines; ++i) {
        store_key_char(matrix_kpub, 10, new_public_key_int());
    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_char(char **matrix_kpub, char **matrix_kpriv, int lines) {
    for (int i = 0; i < lines; ++i) {
        unsigned long long priv = calc_private_key_char(key_digits_2_long_char(matrix_kpub[i]));
        store_key_char(matrix_kpriv, 10, priv);
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_char(char **matrix_kpriv, char **matrix_kcod, int lines) {
    for (int i = 0; i < lines; ++i) {
        unsigned long long run = calc_runlength_char(key_digits_2_long_char(matrix_kpriv[i]));
        store_key_char(matrix_kcod, 10, run);
    }
}
