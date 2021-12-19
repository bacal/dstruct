#include <gtest/gtest.h>
extern "C"{
  #include "llist.h"
}

TEST(llist_create,llist_create_not_null){
  llist* list = llist_create();
  ASSERT_FALSE(list==NULL);
}

TEST(llist_add,llist_add_not_null){
  llist* list = llist_create();
  int a = 32;
  llist_add(list,(void*)&a, sizeof(int));
  ASSERT_FALSE(list->head==NULL);
  ASSERT_TRUE(*(int*)list->head->data ==32);
}

TEST(llist_get,llist_get_valid){
  llist* list = llist_create();
  int a = 32;
  llist_add(list, (void*)&a, sizeof(int));
  ASSERT_TRUE(list->head->data == llist_get(list,0));
}
TEST(llist_get,llist_get_out_of_range){
  llist* list = llist_create();
  int a = 32;
  llist_add(list, (void*)&a, sizeof(int));
  ASSERT_TRUE(llist_get(list,3) == NULL);
}

TEST(llist_get,llist_get_on_empty_list){
  llist* list = llist_create();
  ASSERT_TRUE(llist_get(list,0) == NULL);
}

TEST(llist_remove,llist_remove_on_empty_list){
  llist* list = llist_create();
  ASSERT_TRUE(llist_remove(list,0) == -1);
}

TEST(llist_remove,llist_remove_on_list_of_size_1){
  llist* list = llist_create();
  int a = 32;
  llist_add(list,(void*)&a, sizeof(int));
  llist_remove(list,0);
  ASSERT_TRUE(list->size == 0);
  ASSERT_TRUE(list->head == NULL);
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
