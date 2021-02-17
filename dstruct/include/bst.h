/**
 * @file bst.h
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Binary Search Tree prototype
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021 Bacal Mesfin. 
 * This project is released under the MIT License
 * 
 */
#ifndef BST_H
#define BST_H

#ifdef __cplusplus
extern "C"{
#endif
/**
 * @brief Binary search tree strucutre
 * 
 */
typedef struct bst_struct{
	int key; ///< Key value which is used to sort tree
	void* data; ///< Store any data type in the tree
	struct bst_struct *left; ///< Pointer to left node in tree
	struct bst_struct *right; ///< Pointer to right node in tree
}bst;

/**
 * Creates a binary search tree root
 * @param data Data to be stored in tree
 * @param key Key that represents the node
 * @param bytes Size of the data in bytes
 */
  
bst* bst_create(void* data, int* key, size_t bytes);

/**
 * @brief Adds a root to a binary search tree
 * @param bst Binary search tree you want to add the data to
 * @param key Key for the new node in the tree
 * @param data Data to be stored in the new node
 * @param bytes Size of each element in bytes
 */
void bst_add(bst* bst, int* key, void* data, size_t bytes);

/**
 * Recursively deletes a parent nodes and all nodes beneath it
 * @param bst Binary Search Tree node from which to recursively delete
 */
void bst_delete(bst* bst);

/**
 * Gets the smallest key in the binary search tree
 * @param bst Binary Search Tree to search
 */
void* bst_getSmallest(bst* bst);

/**
 * Gets the largest key in the binary search tree
 * @param bst Binary Search Tree to search
 */
void* bst_getLargest(bst* bst);

/**
 * Checks if the binary search tree contains the value passed in
 * @param srch Binary Search Tree to search
 * @param data Data to compare
 * @param bytes Size of the comparison data in bytes
 */
int bst_contains(bst* srch, void* data, size_t bytes);

#ifdef __cplusplus
}
#endif

#endif /* BST_H */
