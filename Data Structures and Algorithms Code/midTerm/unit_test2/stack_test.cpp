/* Name: Christopher McGrath
   Date: 10/7/19
   Desc: Unit tests for a singly linked list.
*/
#include "gtest/gtest.h"
#include "stacklinklist.c"

TEST(peeek, two){
    node * top = NULL;
    EXPECT_EQ( peek(&top), -1);
    top = getnode(1);
    EXPECT_EQ( peek(&top), 1);
    free(top);
}

TEST(empty, two){
    node * top = NULL;
    EXPECT_EQ( isEmpty(&top), 1);
    top = getnode(1);
    EXPECT_EQ( isEmpty(&top), 0);
    free(top);
}

TEST(popp, two){
    node * top = getnode(5);
    EXPECT_EQ( pop(&top, &top), 5);
    free(top);
    EXPECT_EQ( pop(&top, &top), -9999);//stack underflow
}

TEST(pushh, two){
    node * start = getnode(5);
    node * top = start;
    push(&start, &top, 10);
    EXPECT_EQ( pop(&start, &top), 10);
    EXPECT_EQ( pop(&start, &top), 5);
    free(top);
    free(start);
}
