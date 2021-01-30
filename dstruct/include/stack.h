/**
 * @file stack.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Stack prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef STACK_H
#define STACK_H
/**
 * @brief Stack structure
 * 
 * This is an array based stack, resizing may happen often
 */
typedef struct stack_struct{
    int top; ///< The top of the stack's position
    int size; ///< Size of the stack
    void** data; ///< Array of void* elements
}stack;

/**
 * @brief Creates an empty stack with default parameters
 * 
 * @return stack* 
 */
stack* stack_create();

/**
 * @brief Deletes the entire stack
 * 
 * @param stack_name Name of the stack that must be deleted 
 */
void stack_delete(stack* stack_name);

/**
 * @brief Push data to the top of the stack
 * 
 * @param stack_name Name of the stack to push data on
 * @param data Data to be pushed to the stack
 * @param bytes Size of data in bytes
 */
void stack_push(stack* stack_name, void* data, size_t bytes);

/**
 * @brief Pops an item from the stack (removes)
 * 
 * @param stack_name Name of the stack to pop data from
 * @return void* data
 */
void* stack_pop(stack* stack_name);

#endif /* STACK_H */
