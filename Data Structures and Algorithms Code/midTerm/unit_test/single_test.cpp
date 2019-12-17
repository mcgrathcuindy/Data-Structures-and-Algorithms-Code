/* Name: Christopher McGrath
   Date: 10/7/19
   Desc: Unit tests for a singly linked list.
*/
#include "gtest/gtest.h"
#include "singlelinklist.c"


TEST(size, empty){
  node *start = NULL;
  EXPECT_EQ( countnode(start) , 0);
}

TEST(size, one){
  node *start = NULL;
  insert_at_beg(&start, 2);
  EXPECT_EQ( countnode(start) , 1);
  deleteList(&start);
}

TEST(size, two){
  node *start = NULL;
  insert_at_beg(&start, 2);
  insert_at_beg(&start, 3);
  EXPECT_EQ( countnode(start) , 2);
  deleteList(&start);
}

TEST(beg, three){
  node *start = NULL;
  insert_at_beg(&start, 2);
  insert_at_beg(&start, 3);
  insert_at_beg(&start, 4);
  EXPECT_EQ( getLoc(start,0) , 4);
  EXPECT_EQ( getLoc(start,1) , 3);
  EXPECT_EQ( getLoc(start,2) , 2);
  deleteList(&start);
}

TEST(end, three){
  node *start = NULL;
  insert_at_end(&start, 2);
  insert_at_end(&start, 3);
  insert_at_end(&start, 4);
  EXPECT_EQ( getLoc(start,0) , 2);
  EXPECT_EQ( getLoc(start,1) , 3);
  EXPECT_EQ( getLoc(start,2) , 4);
  deleteList(&start);
}

TEST(createlists, two){
    node *start = NULL;
    createlist(&start, 1);
    EXPECT_EQ( countnode(start), 1);
    deleteList(&start);
    createlist(&start, 10);
    EXPECT_EQ( countnode(start), 10);
    deleteList(&start);
}

TEST(mid, three){
    node *start = NULL;
    insert_at_end(&start, 1);
    insert_at_end(&start, 5);
    insert_at_end(&start, 6);
    insert_at_mid(&start, 4, 2);
    insert_at_mid(&start, 3, 3);
    insert_at_mid(&start, 2, 4);
    EXPECT_EQ( getLoc(start, 1) , 4);
    EXPECT_EQ( getLoc(start, 2) , 3);
    EXPECT_EQ( getLoc(start, 3) , 2);
    deleteList(&start);
}

TEST(del_beg, one){
    node *start = NULL;
    insert_at_end(&start, 5);
    
    insert_at_end(&start, 6);
    delete_at_beg(&start);
    EXPECT_EQ( start -> data, 6);
    deleteList(&start);
}

TEST(del_last, two){
    node *start = NULL;
    insert_at_end(&start, 1);
    insert_at_end(&start, 5);
    insert_at_end(&start, 6);
    delete_at_last(&start);
    EXPECT_EQ( countnode(start), 2);
    delete_at_last(&start);
    EXPECT_EQ( countnode(start), 1);
    deleteList(&start);
}

TEST(del_mid, three){
    node *start = NULL;
    insert_at_end(&start, 1);
    insert_at_end(&start, 5);
    insert_at_end(&start, 6);
    delete_at_mid(&start, 2);
    EXPECT_EQ( countnode(start), 2);
    EXPECT_EQ( getLoc(start, 0), 1);
    EXPECT_EQ( getLoc(start, 1), 6);
    deleteList(&start);
}