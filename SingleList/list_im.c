/*
******************************************************************************
* @file		: list_im.h
* @brief	: Single List implementation
* @Author	: Ming
* @E-Mail	: Ming <1546274931@qq.com>
* This is a implementation of single list
******************************************************************************
*/

#include "list.h"

void list_init(List list,void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
	
	return;
}

void list_destroy(List list)
{
	void *data;
	Element ptr;
	
	while(list_size(list) > 0) {
		if (list_rem_next(list,NULL,(void**)&data) == 0 && 
			list->destroy != NULL)
		list->destroy(data);
	}
	
	memset(list,0,sizeof(struct list));
	return ;
}

int list_ins_next(List list,Element element,const void *data)
{
	Element new_element;
	
	if ((new_element = (struct node*)malloc(sizeof(struct node))) == NULL)
		return -1;

	new_element->data = (void*)data;

	if (element == NULL) {
		if (list_size(list) == 0) 
		list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	} else {
		
		if (element->next == NULL)
		list->tail = new_element;

		new_element->next = element->next;
		element->next = new_element;
	}
	
	list->size++;
	return 0;
}

int list_rem_next(List list,Element element,void **data)
{
	Element old_element;

	if (list_size(list) == 0)
		return -1;
	
	if (element == NULL) {
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if (list_size(list) == 1)
		list->tail = NULL;
	} else {
		if (element->next == NULL)
			return -1;

		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;
	
		if (element->next == NULL)
		list->tail = element;
	}
	
	free(old_element);
	list->size--;
	return 0;
}

int printList(List mingList)
{
        Element newNode;
        newNode = mingList->head;

        do {
                int* a = (int*)(newNode->data);
                newNode = newNode->next;
                printf("%d\n",*a);
        }while(newNode);

}

int printFromHead(PtrToNode head)
{
	Element  newNode = head;
        do {
                int* a = (int*)(newNode->data);
                newNode = newNode->next;
                printf("%d\n",*a);
        }while(newNode);
	
}

/*
*********************************************
*Reverse single list recursively
*********************************************
*/

PtrToNode reverseList(PtrToNode head)
{
	PtrToNode newHead;

	if (head == NULL || head->next == NULL)  {
		return head;
	} else {
		newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}
}

/*
**********************************************
*Convert single list to simple loop list
**********************************************
*/

PtrToNode SingleToLoop(List mingList)
{
	PtrToNode headTemp,iter,final;
	
	headTemp = mingList->head;

	iter = headTemp->next;
	while(iter->next) {
		iter = iter->next;
	}
	iter -> next =  headTemp;
	final = headTemp;
	return final;
}










