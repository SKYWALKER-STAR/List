/*
******************************************************************************
* @file		: doubleList_im.c
* @brief	: double list implementation
* @Author	: Ming
* @E-Mail	: Ming <1546274931@qq.com>
* This is a implementation of double list
******************************************************************************
*/
#include "doubleList.h"

/*Initial it.
 *@list:address of a list or a pointer pointed to a list
 *@destroy:destructor
 *WARNING:THIS FUNCTION DON't ALLOC MEMMORY.THIS IS CALLER'S JOB
 */

void clist_init(CList list,void (*destroy)(void *data))
{
	list->size = 0;
	list->HeadElement = NULL;
	list->TailElement = NULL;
	list->destroy = NULL;
}	

void clist_destroy(CList list)
{
	PtrToNode ptr,tmp;
	
	ptr = list->HeadElement;
	
	while(ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
		
}


/*Insert into next
 *@list:a pointer to or address of a list you operate
 *@element:a pointer to or address of element you want insert after it
 *@data:the data 
 */
int clist_ins_next(CList list,PtrToNode element,const void *data)
{
	PtrToNode newelement;
	
	newelement = (PtrToNode)malloc(sizeof(struct Node));
	if (errno) {
		perror("clist_ins_next() error:");
		return -1;
	}
	
	newelement->data = data;

	/* When clist is empty */
	if (clist_size(list) == 0 || element == NULL) {
		newelement->next = NULL;
		newelement->head = NULL;
		list->HeadElement = newelement;
		list->size++;
		return 0;
	}

	/* When element is tail */
	if (element->head != NULL) {
		newelement->next = NULL;
		newelement->head = element->head;
		element->head = NULL;
		element->next = newelement;
		list->size++;
		return 0;
	}
	
	/* When element is in between clist */
	newelement->next = element->next;
	newelement->head = NULL;
	element->next = newelement;
	list->size++;

	return 0;
}

/*rm data from list
 *@list:a pointer to or address of a list
 *@element:a pointer to or address of a element which is previous element that you want  *to remove.
 *@data:a pointer to a pointer which is pointed to the data which belongs to the elimina *ted element.
 */
int clist_rem_next(CList list,PtrToNode element,const void **data)
{
	PtrToNode oldelement;

	if (!clist_size(list)) {
		fprintf(stderr,"empty list\n");
		return -1;
	}
	
	*data = element->data;
	
	if (element->next->head != NULL) {
		element->head = element->next->head;
		free(element->next);
		return 0;
	}
	
	element->next = element->next->next;
	free(element->next);
	
	return 0;
}
