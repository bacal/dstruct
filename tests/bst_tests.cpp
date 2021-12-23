#include <gtest/gtest.h>
extern "C"{
  #include <bst.h>
}

TEST(bst_create,bst_create_not_null){
  int a =32;
  bst* tree = bst_create(&a,0,sizeof(int));
  ASSERT_FALSE(tree==NULL);
}

TEST(bst_create,bst_create_first_node){
  int a = 32;
  bst* tree = bst_create(&a,0,sizeof(int));
  ASSERT_TRUE(*(int*)tree->root->data==a);
}
  
TEST(bst_create,bst_create_first_node_test_left_and_right){
  int a = 32;
  bst* tree = bst_create(&a,0,sizeof(int));
  ASSERT_TRUE(tree->root->left == NULL);
  ASSERT_TRUE(tree->root->right == NULL);
}
  
TEST(bst_create,bst_add_key_less_than_root){
  int a = 32;
  bst* tree = bst_create(&a, 4, sizeof(int));
  a = 8;
  bst_add(tree,&a, 0, sizeof(int));
  ASSERT_FALSE(tree->root->left == NULL);
  ASSERT_TRUE(*(int*)tree->root->left->data == a);
  ASSERT_FALSE(tree->root->right != NULL);
}
TEST(bst_delete,delete_empty_tree){
  bst* tree = NULL;
  bst_delete(&tree);
  ASSERT_TRUE(tree == NULL);
}

TEST(bst_delete,delete_size_1){
  int a = 32;
  bst* tree = bst_create(&a, 0, sizeof(int));
  bst_add(tree,&a, 2, sizeof(int));
  bst_delete(&tree);
  ASSERT_FALSE(bst_contains(tree, &a, sizeof(int)));
  ASSERT_TRUE(tree == NULL);
}

TEST(bst_contains, does_contain_num){
  int a = 32;
  bst* tree = bst_create(&a, 0, sizeof(int));
  ASSERT_TRUE(bst_contains(tree, &a,sizeof(int)));
}

TEST(bst_contains, null_list){
  bst* tree = NULL;
  int a =32;
  ASSERT_FALSE(bst_contains(tree, &a,sizeof(int)));
}

TEST(bst_contains, does_not_contain_num){
 int a = 32;
  bst* tree = bst_create(&a, 0, sizeof(int));
  a = 0;
  ASSERT_FALSE(bst_contains(tree, &a,sizeof(int)));
}

TEST(bst_structure, is_depth_accurate_1){
  int a = 32;
  bst* tree = bst_create(&a, 0, sizeof(int));
  ASSERT_EQ(tree->depth,1);
}


TEST(bst_structure, is_depth_accurate_2){
  int a = 32;
  bst* tree = bst_create(&a, 2, sizeof(int));
  bst_add(tree, &a, 3, sizeof(int));
  ASSERT_EQ(tree->depth,2);
}

TEST(bst_structure, is_depth_accurate_15){
  int a = 32;
  bst* tree = bst_create(&a, 15, sizeof(int));
  for(int i=1; i<30; i++)
    bst_add(tree, &a, i, sizeof(int));
  ASSERT_EQ(tree->depth,15);
}
