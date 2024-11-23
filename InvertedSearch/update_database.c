/****************************************************************************************************************************************************************
 * Title        : Update database
 * Description  : Update Database Operation to fill the Words of a New File in the Database.
 *                Update Database can be called only after the Database has been created.
 *****************************************************************************************************************************************************************/

#include "main.h"
int update_database(hash arr[],list ** head)
{
    /*To read the File Name to be updated in the Database.*/
    char file[50];
    printf("Enter file name : ");
    scanf("%s", file);
    /*validate file name */
    char *sub = strstr(file,ext);
    if(sub != NULL && strcmp(sub,ext)!= 0)
    {
        printf(RED"Info: Enter a valid file name\n"RESET);
        return update_database(arr,head);
    }
    /*open file */
    FILE *fptr = fopen(file, "r");
    if (fptr == NULL)
    {
        ferror(fptr);
        return FAILURE;
    }
    if (fgetc(fptr) != '#')
    {
        return FAILURE;
    }
    rewind(fptr);
    char str[100];
    while (fscanf(fptr, " %s", str) != -1)
    {
        char *temp = strtok(str, "#;");
        int index = atoi(temp);
        if (arr[index].mlink == NULL)
        {
            main_node *Main = malloc(sizeof(main_node));
            if (Main == NULL)
            {
                return FAILURE;
            }
            temp = strtok(NULL, ";");
            strcpy(Main->word, temp);
            temp = strtok(NULL, ";");
            Main->file_count = atoi(temp);
            Main->subnode = NULL;
            int i = 0;
            while (i < Main->file_count)
            {
                if (i == 0)
                {
                    temp = strtok(NULL, ";");
                    sub_node *sub = malloc(sizeof(sub_node));
                    if (sub == NULL)
                    {
                        return FAILURE;
                    }
                    delete_file(head,temp);
                    strcpy(sub->file_name, temp);
                    temp = strtok(NULL, ";");
                    sub->word_count = atoi(temp);
                    sub->subnode = NULL;
                    Main->subnode = sub;
                }
                else
                {
                    sub_node *tempsub = Main->subnode;
                    while (tempsub->subnode != NULL)
                    {
                        tempsub = tempsub->subnode;
                    }
                    temp = strtok(NULL, ";");
                    delete_file(head,temp);
                    sub_node *sub = malloc(sizeof(sub_node));
                    if (sub == NULL)
                    {
                        return FAILURE;
                    }
                    strcpy(sub->file_name, temp);
                    temp = strtok(NULL, ";");
                    sub->word_count = atoi(temp);
                    sub->subnode = NULL;
                    tempsub->subnode = sub;
                }
                i++;
            }
            arr[index].mlink = Main;
        }
        else
        {
            main_node *tempmain = arr[index].mlink;
            while (tempmain->main_node != NULL)
            {
                tempmain = tempmain->main_node;
            }
            main_node *Main = malloc(sizeof(main_node));
            if (Main == NULL)
            {
                return FAILURE;
            }
            temp = strtok(NULL, ";");
            strcpy(Main->word, temp);
            temp = strtok(NULL, ";");
            Main->file_count = atoi(temp);
            Main->subnode = NULL;
            int i = 0;
            while (i < Main->file_count)
            {
                if (i == 0)
                {
                    temp = strtok(NULL, ";");
                    sub_node *sub = malloc(sizeof(sub_node));
                    if (sub == NULL)
                    {
                        return FAILURE;
                    }
                    strcpy(sub->file_name, temp);
                    temp = strtok(NULL, ";");
                    sub->word_count = atoi(temp);
                    sub->subnode = NULL;
                    Main->subnode = sub;
                }
                else
                {
                    sub_node *tempsub = Main->subnode;
                    while (tempsub->subnode != NULL)
                    {
                        tempsub = tempsub->subnode;
                    }
                    temp = strtok(NULL, ";");
                    sub_node *sub = malloc(sizeof(sub_node));
                    if (sub == NULL)
                    {
                        return FAILURE;
                    }
                    strcpy(sub->file_name, temp);
                    temp = strtok(NULL, ";");
                    sub->word_count = atoi(temp);
                    sub->subnode = NULL;
                    tempsub->subnode = sub;
                }
                i++;
            }
            tempmain->main_node = Main;
        }
    }
    create_database(arr,head);
    display_database(arr);
    char ch;
    printf(RED"Do you want to update the database ?(Y/y) : "RESET);
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y')
    save_database(arr,file);
    else
    printf(BOLDWHITE"Info Database is not updated "RESET);
    return SUCCESS;
}