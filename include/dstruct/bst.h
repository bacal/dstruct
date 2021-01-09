/*	bst.h
 * 	Binary Search Tree Header - Dstruct Library
 */

#ifndef BST_H
#define BST_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct bst_struct{
	int key;
	void* data;
	struct bst_struct *left;
	struct bst_struct *right;
}bst;


bst* bst_create(void* data, int* key);
void bst_add(bst* add, int* key, void* data, size_t bytes);
void bst_delete(bst* bst);
void* bst_getSmallest(bst* bst);
void* bst_getLargest(bst* bst);
int bst_contains(bst* srch, void* data, size_t bytes);

#ifdef __cplusplus
}
#endif

#endif /* BST_H */