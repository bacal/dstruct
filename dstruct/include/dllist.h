/**
 * @file dllist.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Doubly Linked List prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the GNU General Public License v3.0 or later
 * 
 */

#ifndef DLLIST_H
#define DLLIST_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Doubly Linked List structure
 * 
 */
typedef struct dllist_struct{
   void* data; ///< The data you wish to store
   struct dllist_struct* prev; ///< Pointer to the previous node in the list
   struct dllist_struct* next; ///< Pointer to the next node in the list
}dllist;

/**
 * @brief Creates an empty doubly linked list
 * @return dllist* - Pointer to an empty list
 */
dllist* dllist_create();

/**
 * @brief Deletes an entire doubly linked list
 * @param dlist Pointer to the beginning of the list
 */
void dllist_delete(dllist* dlist);

/**
 * @brief Gets the data at the index position in the array
 * 
 * @param dlist Pointer to the beginning of the list
 * @param index Index you wish to retrieve the data for
 */
void* dllist_get(dllist* dlist, int index);

/**
 * @brief Adds an item to the end of the linked list
 * 
 * @param dlist Pointer to the beginning of the list
 * @param data Pointer to the data to be added
 * @param bytes Size of the data to be added in bytes
 */
void dllist_add(dllist* dlist, void* data, size_t bytes);

/**
 * @brief Removes an item from the linked list
 * 
 * @param dlist The list to remove an element from
 * @param index The position in the list to remove the element from 
 * @return int 
 */
int dllist_remove(dllist* dlist, int index);

/**
 * @brief Returns a pointer to the end of a doubly linked list
 * 
 * @param dlist 
 * @return dllist* 
 */
dllist* dllist_end(dllist* dlist);

/**
 * @brief Returns a pointer to the front of a doubly linked list
 * 
 * @param dlist 
 * @return dllist* 
 */
dllist* dllist_front(dllist* dlist);

#ifdef __cplusplus
}
#endif

#endif /* DLLIST_H */
