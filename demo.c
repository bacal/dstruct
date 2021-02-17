#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dstruct.h"
#define SIZE 20000

int i=0;

void update_bar(){
  printf("\rProgress: %d",(int)(100*((float)i/SIZE)));
  fflush(stdout);
  i++;  
}

void print_llisti(llist* list);
void print_llistc(llist* list);

int main(void){
    int* i = malloc(sizeof(int));
    // char* c = malloc(sizeof(char));
    llist* listi = llist_create();
    // llist* listc = llist_create();
    printf("Adding to list\n");

    for((*i)=0; (*i)<SIZE; (*i)++){
      llist_add(listi,(void*)i,sizeof(int));
      update_bar();
    }

    /*
    for((*c)='a';(*c)<='z';(*c)++){
        llist_add(listc,(void*)c,sizeof(char));
	update_spinner();
    }
    */
    printf(" done\n");
    
    // print_dllisti(dlisti);
    // printf("\n");
    // print_llistc(listc);
    // stack* stk = stack_create();
    // stack_push(stk, i, sizeof(int));
    // printf("Stack Data = %d\n",*(int*)stack_pop(stk));
    // stack_pop(stk);
    // dllist* dlist = dllist_create();
    // dllist_add(dlist,(void*)i,sizeof(int));
    
    // dyarray* array = dyarray_create(30);
    // dyarray_add(array,(void*)i,sizeof(int));
    // printf("Number = %d\n",*(int*)array->data[0]);
    
    // stack_delete(stk);
    llist_delete(listi);
    // llist_delete(listc);
    // dyarray_erase(array);
    // dllist_delete(dlist);
    
    // free(c);
    free(i);
    
    return 0;
}


void print_dllisti(dllist* list){
    dllist* ptr = list;
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
