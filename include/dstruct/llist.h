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
void llist_delete(llist* list);
void* llist_get(llist* list, int* index);
void llist_add(llist* list,void* data, size_t bytes);
int llist_remove(llist* list, int* index);
llist* llist_end(llist* list);


#ifdef __cplusplus
}
#endif

#endif /* LLIST_H */