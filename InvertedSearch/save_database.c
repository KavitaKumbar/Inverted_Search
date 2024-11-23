/*******************************************************************************************************************************************************************
 * Title: Save Database
 * Description: Save data base to a text file for later use.In this function has two arguments : data table and filename.
 *******************************************************************************************************************************************************/

#include "main.h"

int save_database(hash arr[], char *file)
{
    FILE *fptr = fopen(file,"w");
    if(fptr == NULL)
    {
        printf("unable to open file\n");
        return FAILURE;
    }
    int i = 0;
    while (i < SIZE)
    {
        main_node *temp = arr[i].mlink;
        while (temp != NULL)
        {
            fprintf(fptr,"#;%d;%s;%d;",i,temp->word, temp->file_count);
            sub_node *sub = temp->subnode;
            int j = 1;
            while (j <= temp->file_count)
            {
                fprintf(fptr,"%s;%d;", sub->file_name, sub->word_count);
                j++;
                sub = sub->subnode;
            }
            fprintf(fptr,"#\n");
            temp = temp->main_node;
        }
        i++;
    }
    fclose(fptr);
    return SUCCESS;
}