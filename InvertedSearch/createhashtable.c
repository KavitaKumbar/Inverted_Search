/******************************************************************************************************************************************************************
 * Title       : create hash table
 * Description : This function use to create hash table (has two parts key and link )
 
******************************************************************************************************************************************************************* */

#include "main.h"
int createhash(hash arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        arr[i] .key = i;
        arr[i].mlink = NULL;
    }
    return SUCCESS;
}