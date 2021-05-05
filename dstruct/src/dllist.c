#include <stdlib.h>
#include <string.h>
#include "dllist.h"

dllist* dllist_create()
{
    dllist* d = malloc(sizeof(struct dllist_struct));
    d->next = NULL;
    d->prev = NULL;
    d->data = NULL;
    return d;
}

void dllist_delete(dllist* dlist)
{
    if(dlist->next){
        dllist_delete(dlist->next);
    }
    free(dlist->data);
    free(dlist);
}

void* dllist_get(dllist* dlist, int index)
{
    dllist* temp = dlist;
    for(int i=0; i<index; i++){
        temp = temp->next;
    }
    return temp->data;
}

void dllist_insert(dllist** dlist, void* data, size_t bytes)
{
    dllist* to_add = dllist_create();

    if((*dlist)->prev == NULL && (*dlist)->prev == NULL && (*dlist)->data == NULL)
    {
        (*dlist)->data = malloc(bytes);
        memcpy((*dlist)->data, data, bytes);
    }
    else 
    {
        to_add->next = (*dlist);
        if((*dlist)->prev == NULL)
        {
            to_add->prev = NULL;
            (*dlist)->prev = to_add;
            to_add->data = malloc(bytes);
            memcpy(to_add->data, data, bytes);

        }

        else 
        {
            to_add->prev = (*dlist)->prev;
            (*dlist)->prev->next = to_add;
            to_add->data = malloc(bytes);
            memcpy(to_add->data, data, bytes);
        }
    }
    *dlist = to_add;
}

void dllist_append(dllist* dlist, void* data, size_t bytes)
{
    
    if(dlist->next == NULL && dlist->prev == NULL && dlist->data==NULL){
        dlist->data = malloc(bytes);
        memcpy(dlist->data, data, bytes);
    }
    else{
        dllist* to_add = dllist_create();
        to_add->data = malloc(bytes);
        memcpy(dlist->data,data,bytes);
        to_add->prev = dllist_end(dlist);
        to_add->next = NULL;
	    dllist_end(dlist)->next = to_add;
    }
}

int dllist_remove(dllist* dlist, int index)
{
    dllist* temp = dlist;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(count > index)
        return 1;
    temp = dlist;

    for(count = 0; count < index; count++){
        temp = temp->next;
    } 
    return 0;
}

dllist* dllist_end(dllist* dlist)
{
    dllist* temp = dlist;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

dllist* dllist_front(dllist* dlist)
{
   dllist* temp = dlist;
    while(temp->prev !=NULL){
        temp = temp->prev;
    }
    return temp;
}
