/*	llist.h
 *  Singly Linked List Source - Dstruct Library
 */
#include <stdlib.h>
#include <string.h>
#include "llist.h"


llist* llist_create()
{
    llist* list = malloc(sizeof(struct llist_struct));
    list->next = NULL;
    list->data = NULL;
    return list;
}

void llist_delete(llist* list)
{
    if(list)
        llist_delete(list->next);
}

void* llist_get(llist* list, int* index)
{
    llist* temp = list;
    for(int i=0; i<*index; i++){
        temp = temp->next;
    }
    return temp->data;
}

void llist_add( llist* list,void* data, size_t bytes)
{
    if(list->next == NULL && list->data==NULL){
        list->data = malloc(bytes);
        memcpy(list->data,data,bytes);
    }
    else{
        llist* to_add = llist_create();
        to_add->data = malloc(bytes);

        memcpy(to_add->data,data,bytes);
        llist_end(list)->next = to_add;
    }
}

int llist_remove(llist* list, int* index)
{
    llist* temp = list;
    llist* to_free;
    llist** head = &list;

    for(int i=0; i<*index; i++){
        if(!temp || temp->next->next == NULL){
            break;
        }
        temp = temp->next;
    }
    if(!temp)
        return 1;
    if(index == 0){
        list = list->next;
        free(*head);
    }
    else{
        temp = list;
        for(int i=0; i<*index-1; i++){
            temp = temp->next;
        }
        to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free);
    }
    return 0;
}

llist* llist_end(llist* list)
{
    llist* temp = list;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}