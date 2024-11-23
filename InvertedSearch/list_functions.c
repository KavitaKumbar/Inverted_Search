/****************************************************************************************************************************************************************************
 * Title    : list_functions
 * Description : This file contains functions that are useful for creating list, deleting elements from the list
 *                converting upper case to lower case etc
 *****************************************************************************************************************************************************************************/

#include "main.h"
int insert_at_last(list ** head , char *string)
{
    list *new;
    if(createnode(&new,string) == NULL)
    {
        return FAILURE;
    }

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    list *temp = *head;

    while(temp ->link != NULL)
    {
        temp = temp -> link;
    }
    temp->link = new;
    return SUCCESS;
}
list *createnode(list **new,char *str)
{
    *new = malloc(sizeof(list));
    if(*new == NULL)
    {
        printf("Node not created\n");
        return NULL;
    }
    strcpy((*new) ->string,str);
    (*new) ->link = NULL; 
    return *new;
}
void print_list(list *head)
{
    if(head == NULL)
    {
        printf("List empty\n");
        return ;
    }
    while(head != NULL)
    {
        printf("%s ",head->string);
        head = head -> link;
    }
    printf("\n");
}
int checkdublicate(list *head , char *str)
{
    if(head == NULL)
    {
        return FAILURE;
    }
    while(head != NULL)
    {
        if(!strcmp(head ->string,str))
        {
            return SUCCESS;
        }
        head = head ->link;
    }
    return FAILURE;
}

void tolowercase(char *str)
{
    int i = 0;
    while(str[i]!= '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}
void delete_file(list ** head,char *file)
{
      if(*head == NULL)
      {
        printf("List Empty: ");
        return ;
      }
      list *temp = *head;
      list *prev = NULL;

      while(temp != NULL)
      {
        if(strcmp(temp -> string,file) == 0)
        {
            if(prev == NULL)
            {
                *head = temp ->link;
            }
            else
            {
                prev ->link = temp -> link;
            }
            free(temp); return ;
        }
        prev = temp;
        temp = temp ->link;
      }
}

/*Function to create nodes */
main_node * create_main_node(char *word,char *file)
{
    main_node *Main = malloc(sizeof(main_node));
    sub_node *sub = malloc(sizeof(sub_node));
    if (Main == NULL || sub == NULL)
        return NULL;
    Main->file_count = 1;
    strcpy(Main->word,word);
    Main->subnode = sub;
    Main->main_node = NULL;
    sub->word_count = 1;
    strcpy(sub->file_name,file);
    sub->subnode = NULL;

    return Main;
}
/* function to perform insert at last */
int insert_word_at_last(main_node *Main,char *word,char *file)
{
    main_node *temp = Main;
    main_node *prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp ->word,word) == 0)
        {
            sub_node *sub = findfile(temp ->subnode,file);
            if(sub != NULL)
            {
                sub ->word_count++;
                return SUCCESS;
            }
            else
            {
                temp ->file_count++;
                insert_file_at_last(temp ->subnode,file);
                return SUCCESS;
            }
        }
        prev = temp;
        temp = temp ->main_node;
    }
    temp = create_main_node(word,file);
    prev ->main_node = temp;
}
sub_node *findfile(sub_node *sub,char *file)
{
    while(sub != NULL)
    {
        if(strcmp(sub ->file_name,file) == 0)
        {
            return sub;
        }
        sub = sub ->subnode;
    }
    return NULL;
}
/*function to insert sub node */
int insert_file_at_last(sub_node *sub,char *file)
{
    while(sub ->subnode != NULL)
    {
        sub = sub ->subnode;
    }
    sub_node * temp = malloc(sizeof(sub_node));
    if(temp == NULL)
    {
        return FAILURE;
    }
    temp ->word_count = 1;
    strcpy(temp ->file_name,file);
    temp ->subnode = NULL;
    sub ->subnode = temp;

    return SUCCESS;
}
