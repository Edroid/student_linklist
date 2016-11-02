/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  link_list.c
 *    Description:  
 *                 
 *        Version:  1.0.0(11/2/2016)
 *         Author:  LI WJNG <liwjng@gmail.com>
 *      ChangeLog:  1, Release initial version on "11/2/2016 17:34:31 PM"
 *                 
 ********************************************************************************/

#include <string.h>
#include "link_list.h"


//链表初始化
void list_init(link_node_t **head)
{
    if(!head)  //如果链表为空，退出函数
        return;

    *head = NULL;
}


//判断链表是否为空，为空返回1，不为空返回0
int list_is_empty(link_node_t *head)
{
    return NULL==head ? 1 : 0; //为什么不用head==NULL
}

//统计链表长度，即在这里也是结构体个数
int list_item_count(link_node_t *head)
{
    int              count = 0;
    link_node_t      *pnode = head;
	
	
    if(!head)    //如果链表为空，直接返回0
        return 0;

    while(pnode != NULL)//链表不为空时，计算并返回count的值
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}


//向链表中添加新的节点
int list_add_item(link_node_t **head, Item item)
{
    link_node_t        *pnew;
    link_node_t        *pnode = *head;//(*head)为结构体的地址，即新的节点

    pnew = (link_node_t *)malloc(sizeof(*pnew));//开辟新的内存空间用来存放新的节点
    if(pnew == NULL)  
        return -1;  

    memset(pnew, 0, sizeof(*pnew));//清空pnew,Memset 用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’；
    pnew->item = item;

    if(NULL == *head)
    {
        *head = pnew;
    }
    else
    {
        while(pnode->next != NULL)
        {
            pnode = pnode->next;
        }
    
        pnode->next = pnew;
    }

    return 0;
}


void list_traverse(link_node_t *head, void (*pfunc)(Item item))
{
    link_node_t   *pnode = head;

    while(pnode != NULL)
    {
        pfunc(pnode->item);
        pnode = pnode->next;
    }
}

int list_destroy(link_node_t **head)
{
    link_node_t   *psave;

    while(  *head )
    {
        psave = (*head)->next;

        free(*head);  //释放内存

        *head = psave;
    }
}


//倒序链表中的内容
void link_reverse(link_node_t **head)
{
   link_node_t        *revsd_ptr;  /* Last one time reversed linker pointer*/
   link_node_t        *cur_ptr;    /* Currently need reverse node pointer*/
   link_node_t        *next_ptr;   /* Next need revers node pointer*/


   revsd_ptr = NULL;
   cur_ptr = *head;
   while( cur_ptr != NULL)
   {
   /* Step1:
    * revsd  cur  next  
    *         |    |
    *  NULL   A -> B -> C -> D -> E
    */
       next_ptr = cur_ptr->next;

   /* Step2:
    * revsd   cur  next  
    *          |    |
    *  NULL <- A    B -> C -> D -> E
    */
       cur_ptr->next = revsd_ptr;

   /* Step3:
    *         revsd cur/next   
    *          |      |    
    * NULL <-  A      B  ->  C -> D -> E 
    */ 
       revsd_ptr =  cur_ptr;
       cur_ptr = next_ptr;
   }

   *head = revsd_ptr;
}

