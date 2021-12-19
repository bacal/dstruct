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

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
