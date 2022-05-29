/*
******************************************************************************
* @file		: doubleList.h
* @brief	: Single List header
* @Author	: Ming
* @E-Mail	: Ming <1546274931@qq.com>
* This is the header file of this double list implementation
******************************************************************************
*/

/* Single direction circular list */

#ifndef LOOPLIST_H
#define	LOOPLIST_H

#define ELEMENTLEN sizeof(int)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>

struct Node;
struct List;
typedef struct List	*CList;
typedef struct Node	*PtrToNode;

struct Node {
	const void	*data;
	PtrToNode	next;
	PtrToNode	head;
	void (*destroy)(void *data);
};

struct List {
	int 		size;
	PtrToNode	HeadElement;
	PtrToNode	TailElement;
	void (*destroy)(void *data);
};

void clist_init(CList list,void (*destroy)(void *data));
void clist_destroy(CList list);
int clist_ins_next(CList list,PtrToNode element,const void *data);

#define clist_data(element) *((int*)(element->data))
#define clist_size(list) list->size
#define clist_head(list) list->HeadElement
#define clist_next(element) element->next


#endif
