#include <stdio.h>
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

void llist_delete(llist* l)
{
    if(l)
        llist_delete(l->next);
}

void* llist_get(llist* l, int* index)
{
    llist* temp = l;
    for(int i=0; i<*index; i++){
        temp = temp->next;
    }
    return temp->data;
}

void llist_add(void* data, llist* l)
{
    llist* to_add = llist_create();
    to_add->data = data;
    llist_end(l)->next = to_add;
}

int llist_remove(llist* l, int* index)
{
    llist* temp = l;
    llist* to_free;
    llist** head = &l;

    for(int i=0; i<*index; i++){
        if(!temp || temp->next->next == NULL){
            break;
        }
        temp = temp->next;
    }
    if(!temp)
        return 1;
    if(index == 0){
        l = l->next;
        free(*head);
    }
    else{
        temp = l;
        for(int i=0; i<*index-1; i++){
            temp = temp->next;
        }
        to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free);
    }
    return 0;
}

llist* llist_end(llist* l)
{
    llist* temp = l;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}