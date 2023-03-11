/*
******************************************************************************
* @file		: list.h
* @brief	: Single List header
* @Author	: Ming
* @E-Mail	: Ming <1546274931@qq.com>
* This is the header file of this single lisy implementation
******************************************************************************
*/
#include "list.h"

int a = 10;
int b = 20;
int c = 39;
int d = 29;
int e = 211;

void destroy(void *data)
{
	printf("Hello world from destroy function");
}

int insAgroup(List *mingList)
{
	list_ins_next(*mingList,NULL,&a);
	list_ins_next(*mingList,(*mingList)->head->next,&b);
	list_ins_next(*mingList,(*mingList)->head->next->next,&c);
	list_ins_next(*mingList,(*mingList)->head->next->next->next,&d);
	list_ins_next(*mingList,(*mingList)->head->next->next->next->next,&e);

}

int main(int arc,int **argv)
{
	/* Your code begin here 
	printf("Usage:editing main.c to create your "
		"own program using this single list\n");
	*/

	List mingList = (struct list*)malloc(sizeof(struct list));
	if (!mingList) {
		fprintf(stderr,"errno = %d \n",errno);
		exit(-1);
	}

	list_init(mingList,destroy);/* List initialization */
	insAgroup(&mingList); /* Insert a group of data */

	printf("Before reverse\n");
	printList(mingList);

	PtrToNode newHead = reverseList(mingList->head); /* reverse list */

	printf("\n");
	printFromHead(newHead);

	PtrToNode LoopHead = SingleToLoop(mingList); /* change single list to loop list */
}
