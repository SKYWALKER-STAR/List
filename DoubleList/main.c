#include "doubleList.h"

#define MAXLEN 2000000

int main(int arc,char **argv)
{	
	int array[MAXLEN],i;
	struct List minglist;

	CList ptrminglist = &minglist;
	clist_init(ptrminglist,NULL);

	
	for (i = 0;i < MAXLEN;i++) {
		array[i] = i;
		clist_ins_next(ptrminglist,NULL,(void*)&array[i]);
	}
	
	printf("%d\n",clist_data(ptrminglist->HeadElement));
	printf("%d\n",clist_size(ptrminglist));
	
	clist_destroy(ptrminglist);
}
