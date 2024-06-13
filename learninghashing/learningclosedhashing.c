#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//the occupied flag holds 0 when initialized, 1 when inserted and -1 when removed
typedef struct Element
{
    char* key;
    int value;
    int occupied_flag;
}Element;

typedef struct Dic_closed_stirng
{
    int m;
    int n_elements;
    Element* hash;
}Dic_closed_stirng;

struct Dic_closed_stirng* initialize_dictionary(int size){
    Dic_closed_stirng* table = (Dic_closed_stirng*)malloc(sizeof(Dic_closed_stirng));
    table->n_elements = 0;
    table->m = size;
    table->hash = (Element*)malloc(size*sizeof(Element));
    for (int i = 0; i < size; i++)
    {
        table->hash[i].key = (char*)malloc(16*sizeof(char));
        table->hash[i].value = 0;
        table->hash[i].occupied_flag = 0;
    }
    return table;
}

int Hash_function(char* key,int m){
    int value = 0;
    int lenght = strlen(key);
    for (int i = 0; i < lenght; i++)
    {
        value += (key[i]*(i+1));
    }
    value *= 19;
    return value % m;
}

//this should be used with an loop/arbitrary counter since it only returns a value based on the current j-ith of a possible insertion/search
int Probing(char* key, int j, int m){
    return ((Hash_function(key,m)+ j*j + 23*j) % m);
}

int search_dic_closed_string(Dic_closed_stirng* dictionary, char* key){
    int current_index = Hash_function(key,dictionary->m);
    if (strcmp(dictionary->hash[current_index].key,key) == 0 && dictionary->hash[current_index].occupied_flag == 1) {
            return current_index;
    } else {
        for (int j = 1; j <= 19; j++)
        {
            current_index = Probing(key,j,dictionary->m);
            if (strcmp(dictionary->hash[current_index].key,key) == 0 && dictionary->hash[current_index].occupied_flag == 1)
            {
                return current_index;
            }
        }
    }
    return -1;
}

//won't be using the value part in this specific exercise but will leave it there anyway in case i need to use this again the act of refactoring should be easier
void insert_dic_closed_string(Dic_closed_stirng* dictionary, char* key, int value){
    if (dictionary->n_elements == dictionary->m || search_dic_closed_string(dictionary,key) != -1) {
        return;
    }
    int current_index = Hash_function(key,dictionary->m);
    if (dictionary->hash[current_index].occupied_flag != 1) {
        strcpy(dictionary->hash[current_index].key,key);
        dictionary->hash[current_index].value = current_index;
        dictionary->hash[current_index].occupied_flag = 1;
        dictionary->n_elements++;
        return;
    } else {
        for (int j = 1; j <= 19; j++)
        {
            current_index = Probing(key,j,dictionary->m); // this could be optimized by passing only the hash function already calculated and saved in an auxiliary variable instead of passing dic->m and key
            if (dictionary->hash[current_index].occupied_flag != 1) //  se estiver com espaco disponivel ele insere
            {
                strcpy(dictionary->hash[current_index].key,key);
                dictionary->hash[current_index].value = current_index;
                dictionary->hash[current_index].occupied_flag = 1;
                dictionary->n_elements++;
                return;
            }
        }
    }
    return;
}



int delete_dic(Dic_closed_stirng* dictionary, char* key){
    if (search_dic_closed_string(dictionary,key) != -1) {
        int current_index = search_dic_closed_string(dictionary,key);
        dictionary->hash[current_index].occupied_flag = -1;
        dictionary->n_elements--;
        return current_index;
    }
    
}


int main(){
    int test_cases;
    scanf("%d",&test_cases);
    Dic_closed_stirng* dictionary = initialize_dictionary(101);
    for (int i = 0; i < test_cases; i++)
    {
        int operations;
        scanf("%d",&operations);
        for (int i2 = 0; i2 < operations; i2++)
        {
            char entrada[20];
            char action[4];
            char key_word[16];
            scanf("%s",entrada);
            sscanf(entrada, "%3s:%15s", action, key_word);
            if ((sscanf(entrada, "%3s:%15s", action, key_word) == 2))
            {
                if (strcmp(action,"ADD") == 0)
            {
                insert_dic_closed_string(dictionary,key_word,0);
            } else if(strcmp(action,"DEL") == 0){
                delete_dic(dictionary,key_word);
            }
            }
            
        }
        printf("%d\n",dictionary->n_elements);
        for (int i2 = 0; i2 < dictionary->m; i2++)
        {
            if (dictionary->hash[i2].occupied_flag == 1)
            {
                printf("%d:%s\n",i2, dictionary->hash[i2].key);
            }
        }
        for (int i2 = 0; i2 < dictionary->m; i2++)
        {
            dictionary->hash[i2].occupied_flag = 0;
        }
        dictionary->n_elements = 0;
    }
    free(dictionary->hash); // ficou faltando dar free nas keys mas mim cansado
    free(dictionary);
    return 0;
}

// gcc learningclosedhashing.c -o learningclosedhashing.exe ; Get-Content input.txt | ./learningclosedhashing.exe