/*****************************************************************************************************************************************************************************
 * Title    : Search database
 * Description : Search Database Operation for a given Word entered by the User.
 *****************************************************************************************************************************************************************************/

#include "main.h"

int search_database(hash arr[],char *data)
{
    tolowercase(data);
    int index = data[0] % 97;
    main_node *temp = arr[index].mlink;
    while (temp != NULL)
    {
        /*validate data is word is present */
        if(strcmp(temp ->word,data) == 0)
        {
            printf(BOLDCYAN"[%d]\t%s\t%d\t",index,data,temp ->file_count);
            int i = 1;
            sub_node *sub = temp ->subnode;
            while (sub != NULL)
            {
                printf(BOLDCYAN"%s\t %-5d",sub ->file_name,sub ->word_count);
                sub = sub ->subnode;
            }
            printf(RESET"\n");
            return SUCCESS;
        }
        temp = temp ->main_node;
    }
    return FAILURE;
}