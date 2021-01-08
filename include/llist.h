/*	llist.h
 *  Singly Linked List Header - Dstruct Library
 */

#ifndef LLIST_H
#define LLIST_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct llist_struct{
    void* data;
    struct llist_struct* next;
}llist;


llist* llist_create();
void llist_delete(llist* l);
void* llist_get(llist* l, int* index);
void llist_add(void* data, llist* l);
int llist_remove(llist* l, int* index);
llist* llist_end(llist* l);


#ifdef __cplusplus
}
#endif

#endif /* LLIST_H */