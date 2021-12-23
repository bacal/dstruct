/**
 * @file bst.c
 * @author Bacal Mesfin (mesfinb2@vcu.edu)
 * @brief Binary Search Tree implementation
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

bst* bst_create(void* data,int key, size_t bytes)
{
  bst* new_tree = malloc(sizeof(struct bst_struct));
  new_tree->root = bst_node_create(data, key, bytes);
  new_tree->depth = 1;
  return new_tree;
}

bst_node* bst_node_create(void* data, int key, size_t bytes){
  bst_node* node = malloc(sizeof(struct bst_node_struct));
  node->data = malloc(bytes);
  memcpy(node->data, data,bytes);
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void bst_node_add(bst_node* add, void* data, int key, size_t bytes){
  if(key < add->key){
    if(add->left==NULL){
      add->left = bst_node_create(data,key,bytes);
    }
    else{
      bst_node_add(add->left,data,key,bytes);
    }
  }
  if(key > add->key){
    if(add->right==NULL){
      add->right = bst_node_create(data,key,bytes);
    }
    else{
      bst_node_add(add->right,data,key,bytes);
    }
  }
}
int calculate_depth(bst_node* node){
  int l_depth =1,r_depth=1;
  if(node->left != NULL)
    l_depth+= calculate_depth(node->left);
  if(node->right != NULL)
    r_depth+= calculate_depth(node->right);
  return l_depth>r_depth?l_depth:r_depth;
}

void bst_add(bst* tree, void* data, int key, size_t bytes)
{
  if(tree){
    bst_node_add(tree->root,data,key,bytes);
    tree->depth = calculate_depth(tree->root);
  }
}


void bst_delete_nodes(bst_node* n){
  if(n){
    if(n->right){
      bst_delete_nodes(n->right);
    }
    if(n->left){
      bst_delete_nodes(n->left);
    }
    free(n->data);
    free(n);
  }
}


void bst_delete(bst** n)
{
  if(*n){
    bst_delete_nodes((*n)->root);
    free(*n);
    *n = NULL;
  }
}

int bst_internal_contains(bst_node* srch, void* data, size_t bytes){
  if(srch->left!=NULL){
    if(bst_internal_contains(srch->left,data,bytes)){
      return 1;
    }
  }
  if(srch->right!=NULL){
    if(bst_internal_contains(srch->right,data,bytes)){
      return 1;
    }
  }
  if(!memcmp(srch->data,data,bytes))
    return 1;

  return 0;

}

int bst_contains(bst* srch, void* data, size_t bytes){
  if(!srch)
    return 0;
  return bst_internal_contains(srch->root,data,bytes);
}


void* bst_get_smallest(bst* toSearch)
{
  bst_node* tmp = toSearch->root;
  while(tmp->left!=NULL){
    tmp = tmp->left;
  }
  
  return tmp->data;
}

void* bst_get_largest(bst* toSearch)
{
  bst_node* tmp = toSearch->root;
  while(tmp->right!=NULL){
    tmp = tmp->right;
  }
  
  return tmp->data;
}
