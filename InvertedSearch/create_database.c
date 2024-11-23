/***************************************************************************************************************************************************
 * Title       : Create database function
 * Description : This function create database In this hashing is used to create database.
                 It has two arguments : database and list which contains file names
 **********************************************************************************************************************************************/


#include "main.h"
int create_database(hash arr[], list **head)
{
    if (*head == NULL)
    {
        printf(BOLDRED"Error : NO files Available in the list\n"RESET);
        return FAILURE;
    }
    list *temp = *head;
    while (temp != NULL)
    {
        FILE *fptr = fopen(temp->string, "r");
        if (fptr == NULL)
        {
            printf(BOLDRED);
            ferror(fptr);
            printf(RESET);
            return FAILURE;
        }
        char ch[50];
        int index;
        /*read from file */
        while (fscanf(fptr, "%s", ch) != -1)
        {
            tolowercase(ch);
            /*Find Index */
            if (isalpha(ch[0]))
            {
                index = ch[0] - 97;
            }
            else
            {
                if (isdigit(ch[0]))
                    index = 26;
                else
                    index = 27;
            }
            if (arr[index].mlink == NULL)
            {
                main_node *Main = create_main_node(ch,temp ->string);
                if(Main == NULL)
                return FAILURE;
                arr[index].mlink = Main;
            }
            else
            {
                insert_word_at_last(arr[index].mlink,ch,temp ->string);
            }
          
        }
        fclose(fptr);
        temp = temp->link;
    }
    return SUCCESS;
}