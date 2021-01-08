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
void bst_add(bst* add, void* data, int* key);
void bst_delete(bst*);
int bst_search(bst*,void*);
void* bst_getSmallest(bst*);
void* bst_getLargest(bst*);

#ifdef __cplusplus
}
#endif

#endif /* BST_H */