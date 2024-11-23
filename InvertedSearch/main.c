/**************************************************************************************************************************************************************
 *Title		    : main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/

#include "main.h"

int createDB = 0;
int updateDB = 0;
int main(int argc, char *argv[])
{
    int choice;
    if (argc == 1)
    {
        printf(BOLDRED "Error: Invalid Number of arguments \n" RESET);
        printf (BOLDWHITE"INFO: Usage ./a.out <file.txt> <file1.txt> ...\n" RESET);
        return 0;
    }
    list *head = NULL;
    read_and_validate(argv, &head);
    printf(BOLDMAGENTA "Files are:   ");
    print_list(head);
    printf(RESET);
    hash arr[SIZE];
    createhash(arr, SIZE);

    printf(BOLDWHITE "1.Create Database\n2.Diaplay Database\n3.Search database \n4.Save data base\n5.Update data base\n6.Exit\n" RESET);
    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (createDB == 0 && (updateDB == 1 || updateDB == 0))
            {
                if (create_database(arr, &head) == SUCCESS)
                {
                    printf(WHITE "Info: Database created successfully\n" RESET);
                    createDB = 1;
                }
                else
                {
                    printf(BOLDRED "Info: DB creation is unsuccessfull\n" RESET);
                }
            }
            else
            {
                printf(BOLDRED "Info: Database for entered file already created\n" RESET);
            }
            break;
        case 2:
            display_database(arr);
            break;
        case 3:
            char data[50];
            printf("Enter data to be search: ");
            scanf("%s", data);
            if (search_database(arr, data) == FAILURE)
            {
                printf(BOLDRED "Error: Data not found\n" RESET);
            }
            break;
        case 4:
            char file[50];
        index:
            printf("Enter file name : ");
            scanf("%s", file);
            char *sub = strstr(file,ext);
            if (sub != NULL && strcmp(sub,ext) != 0)
            {
                printf("Enter a valid filename : \n");
                goto index;
            }
            if (save_database(arr, file) == SUCCESS)
            {
                printf(BOLDWHITE "Info: Data saved successfully\n" RESET);
            }
            break;
        case 5:
            if (updateDB == 0 && createDB == 0)
            {
                if (update_database(arr, &head) == SUCCESS)
                    updateDB = 1;
            }
            else
            {
                printf(BOLDRED "Info : May be database is created or data base is already updated \n" RESET);
            }
            break;
        case 6:
            printf(BOLDYELLOW "Exit......\n" RESET);
            exit(0);

        default:
            printf(BOLDRED "Error : Invalid Choice\n" RESET);
        }
    }
}

//To Validate the File Names passed as CLA and store them in the File List.
int read_and_validate(char *args[], list **head)
{
    int i = 1;
    while (args[i])
    {
        char *sub = strstr(args[i], ext);
        if (sub != NULL && strcmp(sub,ext) != 0)
        {
            printf(BOLDRED "Error: %s should be have .txt extention\n" RESET, args[i]);
            i++;
            continue;
        }
        FILE *fptr = fopen(args[i], "r");
        if (fptr == NULL)
        {
            printf(BOLDRED "Error: %s named file not available\n" RESET, args[i]);
            i++;
            continue;
        }
        if (fgetc(fptr) == EOF)
        {
            printf(BOLDRED "Error: %s is empty\n" RESET, args[i]);
            i++;
            continue;
        }
        fclose(fptr);
        if (checkdublicate(*head, args[i]) == SUCCESS)
        {
            printf(BOLDRED "Error: %s already exist\n" RESET, args[i]);
            i++;
            continue;
        }
        insert_at_last(head, args[i]);
        i++;
    }
}
