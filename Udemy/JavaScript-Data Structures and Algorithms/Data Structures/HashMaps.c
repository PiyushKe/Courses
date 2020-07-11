#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#pragma pack1

#define Table_Size 10
#define Max_Name_Size 256

typedef struct{
    char color[Max_Name_Size];
    unsigned int hexadecimal_value;
} color;

color *HashTable[Table_Size];

void init_hash_table(void){
    for (int i = 0; i < Table_Size;i++){
        HashTable[i] = NULL;
    }
}

unsigned int hash(char *key)
{
    unsigned int hash_value = 0;
    while(*key){
        hash_value += (int)(*key);
        hash_value *= (int)(*key);
        key++;
    }
    return ((hash_value)%Table_Size);
}

bool insert_in_hash_table(color *value){
    if(value==NULL){
        return (false);
    }
    int index = hash(value->color);
    for (int i = 0; i < Table_Size;i++){
        int try = (index+i) % Table_Size;
        if(HashTable[try]==NULL){
            HashTable[try] = value;
            return (true);
        }
    }
    return (false);
}

bool hash_table_lookup(char *color_name){
    int index = hash(color_name);
    for (int i = 0; i < Table_Size;i++){
        int try = (index+i) % Table_Size;
        if(strcmp(color_name,HashTable[try]->color)==0){
            return (true);
        }
    }
    return (false);
}

color *hash_table_delete(char *color_name){
    int index = hash(color_name);
    for (int i = 0; i < Table_Size;i++){
        int try = (index+i) % Table_Size;
        if(strcmp(color_name,HashTable[try]->color)==0){
            color *temp = HashTable[try];
            HashTable[try] = NULL;
            return (temp);
        }
    }
    return (NULL);
}


void print_table(void){
    printf("\tSTART\t\n");
    for (int i = 0; i < Table_Size; i++){
        if(HashTable[i]==NULL){
            printf("\t%d\t%s\t---\n",i,HashTable[i]->color);
        }else{
            printf("\t%d\t%s\t%X\n",i,HashTable[i]->color,HashTable[i]->hexadecimal_value);
        }
    }
    printf("\tEND\t\n");
}

void main(void){
    printf("Color Name\tHex value\n");
    for (int i = 0; i < 10; i++){
        color *newColor = (color *)malloc(sizeof(color));
        scanf("%s\t%x",&newColor->color,&newColor->hexadecimal_value);
        insert_in_hash_table(newColor);
    }
    if(hash_table_lookup("White")){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    hash_table_delete("white");
    print_table();
}
