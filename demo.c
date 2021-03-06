#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"
#include "dstruct.h"
#define SIZE 20

void print_llisti(llist* list);
void print_dllisti(dllist* dlist);

void print_llistc(llist* list);

int main(void){
    int* i = malloc(sizeof(int));
    char* c = malloc(sizeof(char));
    llist* listi = llist_create();
    llist* listc = llist_create();
    stack* stk = stack_create();
    dllist* dlist = dllist_create();
    dyarray* array = dyarray_create(30);
    bst* tree;
    
    printf("Adding to llist\n");

    for((*i)=0; (*i)<SIZE; (*i)++){
      llist_add(listi,(void*)i,sizeof(int));
    }

    
    for((*c)='a';(*c)<='z';(*c)++){
        llist_add(listc,(void*)c,sizeof(char));
    }
    
    printf(" done\n");

    
    print_llisti(listi);
    printf("\n");
    print_llistc(listc);

    stack_push(stk, i, sizeof(int));
    printf("Stack Data = %d\n",*(int*)stack_peek(stk));
    stack_pop(stk);

    printf("dlist data: ");
    dllist_insert(&dlist, (void*)i,sizeof(int));
    dllist_append(dlist,(void*)i,sizeof(int));
    *i =32;
    dllist_insert(&dlist, (void*)i, sizeof(int));
    *i=-120;
    dllist_insert(&dlist, (void*)i, sizeof(int));
    *i=42;
    dllist_insert(&dlist, (void*)i, sizeof(int));
    *i = 12;
    dllist_append(dlist,(void*)i,sizeof(int));


    print_dllisti(dlist);

    tree = bst_create((void*)i, i, sizeof(int));

    dyarray_add(array,(void*)i,sizeof(int));
    printf("Number = %d\n",*(int*)array->data[0]);
    
    stack_delete(stk);
    llist_delete(listi);
    llist_delete(listc);
    dyarray_delete(array);
    dllist_delete(dlist);
    bst_delete(tree);
    
    free(c);
    free(i);
    
    return 0;
}


void print_llisti(llist* list){
    llist* ptr = list;
    while(ptr!=NULL){
        printf("%d ",*(int*)(ptr->data));
        ptr = ptr->next;
    }
    printf("\n");
}
void print_dllisti(dllist* dlist){
    dllist* ptr = dlist;
    while(ptr!=NULL){
        printf("%d ",*(int*)(ptr->data));
        ptr = ptr->next;
    }
    printf("\n");
}
void print_llistc(llist* list){
    llist* ptr = list;
    while(ptr!=NULL){
        printf("%c ",*(char*)(ptr->data));
        ptr = ptr->next;
    }
    printf("\n");
}
