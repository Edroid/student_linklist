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


//�����ʼ��
void list_init(link_node_t **head)
{
    if(!head)  //�������Ϊ�գ��˳�����
        return;

    *head = NULL;
}


//�ж������Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int list_is_empty(link_node_t *head)
{
    return NULL==head ? 1 : 0; //Ϊʲô����head==NULL
}

//ͳ�������ȣ���������Ҳ�ǽṹ�����
int list_item_count(link_node_t *head)
{
    int              count = 0;
    link_node_t      *pnode = head;
	
	
    if(!head)    //�������Ϊ�գ�ֱ�ӷ���0
        return 0;

    while(pnode != NULL)//����Ϊ��ʱ�����㲢����count��ֵ
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}


//������������µĽڵ�
int list_add_item(link_node_t **head, Item item)
{
    link_node_t        *pnew;
    link_node_t        *pnode = *head;//(*head)Ϊ�ṹ��ĵ�ַ�����µĽڵ�

    pnew = (link_node_t *)malloc(sizeof(*pnew));//�����µ��ڴ�ռ���������µĽڵ�
    if(pnew == NULL)  
        return -1;  

    memset(pnew, 0, sizeof(*pnew));//���pnew,Memset ������һ���ڴ�ռ�ȫ������Ϊĳ���ַ���һ�����ڶԶ�����ַ������г�ʼ��Ϊ�� ����/0����
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

        free(*head);  //�ͷ��ڴ�

        *head = psave;
    }
}


//���������е�����
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

