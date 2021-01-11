#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/dstruct/dstruct.h"

void print_llisti(llist* list);
void print_llistc(llist* list);

int main(void){
    int* i = malloc(sizeof(int));
    char* c = malloc(sizeof(char));
    llist* listi = llist_create();
    llist* listf = llist_create();
    llist* listc = llist_create();
    
    for((*i)=0; (*i)<200; (*i)++){
        llist_add(listi,(void*)i,sizeof(int));
    }
    for((*c)='a';(*c)<='z';(*c)++){
        llist_add(listc,(void*)c,sizeof(char));
    }

    print_llisti(listi);
    printf("\n");
    print_llistc(listc);
    // print_llist_f(listf);
    stack* stk = stack_create();
    stack_push(stk, i, sizeof(int));
    printf("Stack Data = %d\n",*(int*)stack_pop(stk));
    stack_pop(stk);
    dllist* dlist = dllist_create();
    dllist_add(dlist,&i,sizeof(int));
    
    
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
void print_llistc(llist* list){
    llist* ptr = list;
    while(ptr!=NULL){
        printf("%c ",*(char*)(ptr->data));
        ptr = ptr->next;
    }
    printf("\n");
}

