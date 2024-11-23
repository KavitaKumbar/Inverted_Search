/********************************************************************************************************************************************************
 * Title        : Display Database
 * Description  : Function used to display the database on the screen/terminal.
 * ***************************************************************************************************************************************************/

#include "main.h"
int display_database(hash arr[])
{
    int i = 0;
    while (i < SIZE)
    {
        main_node *temp = arr[i].mlink;
        while (temp != NULL)
        {
            printf("[%d]\t", i);
            printf("%s\t%d\t", temp->word, temp->file_count);
            sub_node *sub = temp->subnode;
            int j = 1;
            while (j <= temp->file_count)
            {
                printf("%s\t%d\t", sub->file_name, sub->word_count);
                j++;
                sub = sub->subnode;
            }
            printf("\n");
            temp = temp->main_node;
        }
        i++;
    }
}