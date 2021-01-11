#ifndef STACK_H
#define STACK_H

typedef struct stack_struct{
    int top;
    int size;
    void** data;
}stack;

#endif /* STACK_H */

stack* stack_create();
void stack_delete(stack* stack_name);
void stack_push(stack* stack_name, void* data, size_t bytes);
void* stack_pop(stack* stack_name);
