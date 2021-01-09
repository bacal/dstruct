/*	dllist.h
 *  Doubly Linked List Header - Dstruct Library
 */

#ifndef DLLIST_H
#define DLLIST_H

typedef struct dllist_struct{
    void* data;
   struct dllist_struct* prev;
   struct dllist_struct* next;
}dllist;

dllist* dllist_create();
void dllist_delete(llist* l);
void* dllist_get(llist* l, int* index);
void dllist_add(void* data, llist* l);
int dllist_remove(llist* l, int* index);
dllist* dllist_end(llist* l);


#endif /* DLLIST_H */
