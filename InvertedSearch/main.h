#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "colors.h"
#define SIZE 28
#define SUCCESS 0
#define FAILURE -1
#define ext ".txt"

typedef struct node
{
    char string[20];
    struct node *link;
}list;

typedef struct sub_node
{
    int word_count;
    char file_name[20];
    struct sub_node *subnode;
}sub_node;
typedef struct main_node
{
    int file_count;
    char word[50];
    sub_node *subnode;
    struct main_node *main_node;
}main_node;
typedef struct Hash_table
{
    int key;
    main_node *mlink;
}hash;

int read_and_validate(char *argv[],list **head);
int insert_at_last(list ** head , char *string);
void print_list(list *head);

int checkdublicate(list *head , char *str);
list *createnode(list **new,char *str);
int createhash(hash arr[],int size);
void tolowercase(char *str);

int create_database(hash arr[],list **head);
int display_database(hash arr[]);
int search_database(hash arr[],char *data);
int save_database(hash arr[],char *file);
int update_database(hash arr[],list **head);

main_node *create_main_node(char *word,char *file);
int insert_word_at_last(main_node *Main,char *word,char *file);
sub_node *findfile(sub_node *sub,char *file);
int insert_file_at_last(sub_node *sub,char *file);
void delete_file(list ** head,char *file);

#endif