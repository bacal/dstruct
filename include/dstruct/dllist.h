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
void dllist_delete(dllist* dlist);
void* dllist_get(dllist* dlist, int index);
void dllist_add(dllist* dlist, void* data, size_t bytes);
int dllist_remove(dllist* dlist, int index);
dllist* dllist_end(dllist* dlist);
dllist* dllist_front(dllist* dlist);


#endif /* DLLIST_H */
