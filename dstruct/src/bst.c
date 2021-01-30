/*	bst.h
 * 	Binary Search Tree source - Dstruct Library
 */
#include <stdlib.h>
#include <string.h>
#include "bst.h"

bst* bst_create(void* data,int* key)
{
	bst* newTree = calloc(1,sizeof(struct bst_struct));
	newTree->left=NULL;
	newTree->right=NULL;
	newTree->data=data;
	newTree->key = *key;
	return newTree;
}

/**
 * Adds a node to the tree, uses memcpy() so you must pass a size in bytes to the tree
 */

void bst_add(bst* add, int* key, void* data, size_t bytes)
{
	if(*key < add->key){
		if(add->left==NULL)
			add->left = bst_create(data,key);

		else
			bst_add(add->left,data,key,bytes);
	}
	if(*key > add->key){
		if(add->right==NULL)
			add->right = bst_create(data,key);
		else
			bst_add(add->right,data,key,bytes);
	}
}

void bst_delete(bst* n)
{
	if(n->right!=NULL){
		bst_delete((n->right));
	}
	if(n->left!=NULL){
		bst_delete(n->left);
	}	
	free(n);
}

int bst_contains(bst* srch, void* data, size_t bytes){
	if(srch->left!=NULL){
		if(bst_contains(srch->left,data,bytes)){
			
		}
			return 1;
	}
	if(srch->right!=NULL){
		if(bst_contains(srch->right,data,bytes)){
			return 1;	
		}
	}
	if(!memcmp(srch->data,data,bytes))
		return 1;

	return 0;	
}


void* bst_get_smallest(bst* toSearch)
{
	bst* tmp = toSearch;
	while(tmp->left!=NULL){
		tmp = tmp->left;
	}

	return tmp->data;
}

void* bst_get_largest(bst* toSearch)
{
	bst* tmp = toSearch;
	while(tmp->right!=NULL){
		tmp = tmp->right;
	}

	return tmp->data;
}

