/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  students_list.c
 *    Description:  
 *                 
 *        Version:  1.0.0(11/2/2016)
 *         Author:  LI WJNG <liwjng@gmail.com>
 *      ChangeLog:  1, Release initial version on "11/2/2016 17:45:31 PM"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <string.h>

#include "link_list.h"

static void show_students_info(Item item);

int main (int argc, char **argv) 
{
    link_node_t         *head = NULL;
    Item                item;

    list_init(&head);

    printf("Enter first students name: ");

    //while(gets(item.name) != NULL && item.name[0]!=EOF)
    while(fgets(item.name, NAME_LEN, stdin) != NULL && item.name[0]!=EOF) //
    {
        item.name[strlen(item.name)-1] = '\0'; /* Remove the '\n' for fgets will save it  */

        printf("Enter student's gender: %d<male> or %d<female>  ", male, female);
        scanf("%d", &item.gender);
    
        printf("Enter student's age: ");
        scanf("%d", &item.age);

        printf("Enter student's score: ");
        scanf("%f", &item.score);

        while(getchar() != '\n')
            continue;

        if(list_add_item(&head, item))
        {
            fprintf(stderr, "Add new node into list failure\n");
            break;
        }

        printf("\nEnter next students name, <CTRL+D> to stop enter: ");
    }

    if( list_is_empty(head) )
    {
        printf("No data entered.\n");
        return 0;
    }

    printf("You entered %d students information, here is the list: \n", list_item_count(head)); 
    list_traverse(head, show_students_info);

    printf("Start reverse list now...\n");
    link_reverse(&head);

    printf("After reverse students information list: \n", list_item_count(head)); 
    list_traverse(head, show_students_info);

    printf("Destroy the students list now.\n");
    list_destroy(&head);

    return 0;
} /* ----- End of main() ----- */


void show_students_info(Item item)
{
    printf("Name: %10s  Gender: %6s age:%2d score: %f\n", 
            item.name, male==item.gender?"male":"female", item.age, item.score);
}

