/**
 * @file stack.c
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Stack implementation
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin
 * This project is licensed under the GNU General Public License v3.0 or later
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
stack* stack_create()
{
    stack* stk = malloc(sizeof(struct stack_struct));
    stk->size = 0;
    stk->data = NULL;
    stk->top = -1;
    return stk;
}
void stack_delete(stack* stack_name)
{
    while(stack_name->top > 0){
        stack_pop(stack_name);
    }
    if(stack_name->data){
      if(stack_name->data[0])
	free(stack_name->data[0]);
      free(stack_name->data);
    }
    free(stack_name);
}
void stack_push(stack* stack_name, void* data, size_t bytes)
{
    if(stack_name->data == NULL){
        stack_name->data = malloc(10*bytes);
        stack_name->size = 10;
    }
    if(stack_name->top == stack_name->size){
        stack_name->data = realloc(stack_name->data, stack_name->size+10 * bytes);
        stack_name->size += 10;
    }
    stack_name->top++;
    stack_name->data[stack_name->top] = malloc(bytes);
    memcpy(stack_name->data[stack_name->top],data,bytes);

}

void stack_pop(stack* stack_name)
{
    if(stack_name->top == -1){
        printf("Error: Stack underflow\n");
        exit(1);
    }
    free(stack_name->data[stack_name->top]);
    stack_name->data[stack_name->top] = NULL;
    stack_name->top--;
}

void* stack_peek(stack* stack_name){
  if(stack_name->top < 0){
    printf("Stack is empty");
    return NULL;
  }
  else
    return stack_name->data[stack_name->top];

}
