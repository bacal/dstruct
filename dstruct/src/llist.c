/*	llist.c
 *  Singly Linked List Source - Dstruct Library
 */
#include <stdlib.h>
#include <string.h>
#include "llist.h"


llist* llist_create()
{
    llist* list = malloc(sizeof(struct llist_struct));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
void free_nodes(ll_node* n){

  if(n->next){
    free_nodes(n->next);
  }
  free(n->data);
  free(n);
}
void llist_delete(llist* list)
{
    free_nodes(list->head);
    free(list);
}

void* llist_get(llist* list, int index)
{
    ll_node* temp = list->head;
    if(!list)
      return NULL;
    if(index>=list->size)
      return NULL;
    
    for(int i=0; i<index; i++){
        temp = temp->next;
    }
    if(!temp)
      return NULL;
    
    return temp->data;
}

ll_node* ll_node_create(){
  ll_node* node = malloc(sizeof(struct ll_node_struct));
  node->data = NULL;
  return node;
}

void llist_add(llist* list,void* data, size_t bytes)
{
  ll_node* to_add = ll_node_create();
  to_add->data = malloc(bytes);
  memcpy(to_add->data,data,bytes);
  //list->tail->next = to_add;

  if(!list->head || !list->tail){
    list->head = to_add;
    list->tail = to_add;
    list->size++;
  }
  else{
    list->tail->next = to_add;
    list->tail = list->tail->next;
    list->size++;
  }
}

int llist_remove(llist* list, int index)
{
    ll_node* temp = list->head;
    ll_node* to_free;
    ll_node** head = &list->head;

    if(list->size==0)
      return -1;
    
    for(int i=0; i<index; i++){
        if(!temp || temp->next->next == NULL){
            break;
        }
        temp = temp->next;
    }
    if(!temp)
        return 1;
    if(index == 0){
      list->head = list->head->next;
      free(*head);
    }
    else if(index == list->size-1){
      for(int i=0; i<index-1; i++){
	temp = temp->next;
      }
      to_free = temp->next;
      list->tail = temp;
    } 
    else{
        temp = list->head;
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free);
    }
    list->size--;
    return 0;
}
