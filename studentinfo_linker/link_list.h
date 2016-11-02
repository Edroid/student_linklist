/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  link_list.h
 *    Description:  
 *                 
 *        Version:  1.0.0(11/2/2016)
 *         Author:  LI WJNG <liwjng@gmail.com>
 *      ChangeLog:  1, Release initial version on "11/2/2016 17:10:31 PM"
 *                 
 ********************************************************************************/
#ifndef  _LINK_LIST_H_
#define  _LINK_LIST_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "students_list.h"


typedef student_t          Item;

typedef struct link_node_s 
{
    Item                   item;
    struct  link_node_s    *next;
} link_node_t;  /*---  end of struct link_node_s  ---*/


void list_init(link_node_t **head);
int list_is_empty(link_node_t *head);
int list_item_count(link_node_t *head);
int list_add_item(link_node_t **head, Item item);
void link_reverse(link_node_t **head);
void list_traverse(link_node_t *head, void (*pfunc)(Item item));
int list_destroy(link_node_t **head);

#endif   /* ----- #ifndef _LINK_LIST_H_  ----- */
