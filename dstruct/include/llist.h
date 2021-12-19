/**
 * @file llist.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Singly Linked List prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the GNU General Public License v3.0 or later
 */

#ifndef LLIST_H
#define LLIST_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Singly Linked List structure
 * 
 */
typedef struct ll_node_struct{
  void* data;
  struct ll_node_struct* next;
}ll_node;
  
typedef struct llist_struct{
  ll_node* head;
  ll_node* tail;
  int size;
}llist;

/**
 * @brief Create an empty Linked List
 *
 * @return llist* - Pointer to a Linked List node
 */
llist* llist_create();

/**
 * @brief Deletes a Linked List
 *
 * @param list The List that needs to be deleted
 */
void llist_delete(llist* list);

/**
 * @brief
 *
 * @param list
 * @param index The place in the Linked List
 * @return void* - Returns the data at the index in the Linked List
 */
void* llist_get(llist* list, int index);

/**
 * @brief Add an item to the Linked List
 *
 * @param list The List to add an element to
 * @param data Data to be added to the list
 * @param bytes Size of the data in bytes
 */
void llist_add(llist* list,void* data, size_t bytes);

/**
 * @brief Remove an item from the list
 * 
 * @param list The list to remove an item from
 * @param index The position in the list that the item needs to be removed from
 * @return int - Returns 1 if successful, -1 if failed
 */
int llist_remove(llist* list, int index);

#ifdef __cplusplus
}
#endif

#endif /* LLIST_H */
