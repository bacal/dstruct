/* tree.c
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

bst* bst_create(void* data,int* key){
	bst* newTree = calloc(1,sizeof(struct bst_struct));
	newTree->left=NULL;
	newTree->right=NULL;
	newTree->data=data;
	newTree->key = *key;
	return newTree;
}
void bst_add(bst* add, void* data, int* key){
	if(*key < add->key){
		if(add->left==NULL)
			add->left = bst_create(data,key);

		else
			bst_add(add->left,data,key);
	}
	if(*key > add->key){
		if(add->right==NULL)
			add->right = bst_create(data,key);
		else
			bst_add(add->right,data,key);
	}
}

void bst_delete(bst* n){
	if(n->right!=NULL){
		bst_delete((n->right));
	}
	if(n->left!=NULL){
		bst_delete(n->left);
	}	
	free(n);
}

/*
int bst_search_data(bst* srch, void* data){
	if(srch->left!=NULL){
		if(bst_search(srch->left,data)){
			
		}
			return 1;
	}
	if(srch->right!=NULL){
		if(bst_search(srch->right,data)){
			return 1;	
		}
	}
	if( *(srch->data) == *data)
		return 1;

	return 0;	
}
*/

void* bst_get_smallest(bst* toSearch){
	bst* tmp = toSearch;
	while(tmp->left!=NULL){
		tmp = tmp->left;
	}

	return tmp->data;
}
void* bst_get_largest(bst* toSearch){
	bst* tmp = toSearch;
	while(tmp->right!=NULL){
		tmp = tmp->right;
	}

	return tmp->data;
}

