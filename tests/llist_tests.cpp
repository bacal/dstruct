#include <gtest/gtest.h>
extern "C"{
  #include "llist.h"
}

TEST(llist_create,create_not_null){
  llist* list = llist_create();
  ASSERT_FALSE(list==NULL);
  llist_delete(&list);
}

TEST(llist_add,add_not_null){
  llist* list = llist_create();
  int a = 32;
  llist_add(list,(void*)&a, sizeof(int));
  ASSERT_FALSE(list->head==NULL);
  ASSERT_TRUE(*(int*)list->head->data ==32);
  llist_delete(&list);
}

TEST(llist_get,get_valid){
  llist* list = llist_create();
  int a = 32;
  llist_add(list, (void*)&a, sizeof(int));
  ASSERT_TRUE(list->head->data == llist_get(list,0));
  llist_delete(&list);
}
TEST(llist_get,get_out_of_range){
  llist* list = llist_create();
  int a = 32;
  llist_add(list, (void*)&a, sizeof(int));
  ASSERT_TRUE(llist_get(list,3) == NULL);
}

TEST(llist_get,get_on_empty_list){
  llist* list = llist_create();
  ASSERT_TRUE(llist_get(list,0) == NULL);
  llist_delete(&list);
}

TEST(llist_remove,remove_on_empty_list){
  llist* list = llist_create();
  ASSERT_TRUE(llist_remove(list,0) == -1);
}

TEST(llist_remove,remove_on_list_of_size_1){
  llist* list = llist_create();
  int a = 32;
  llist_add(list,(void*)&a, sizeof(int));
  llist_remove(list,0);
  ASSERT_TRUE(list->size == 0);
  ASSERT_TRUE(list->head == nullptr);
  llist_delete(&list);
}

TEST(llist_delete, delete_on_NULL_list){
  llist* list = nullptr;
  llist_delete(&list);
  ASSERT_TRUE(list == nullptr);
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
