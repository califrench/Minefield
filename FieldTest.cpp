/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}


/*
TEST(FieldTest, getMineOutOfBounds) {
    Field minefield;

    minefield.placeMine(11,11);
    //Don't know what type of exception this is throwing so can't get this to work
    ASSERT_THROW(minefield.get(11,11));
}
*/

TEST(FieldTest, revealAdjacent) {
    Field minefield;

    ASSERT_EQ(minefield.get(4,5), EMPTY_HIDDEN);
    minefield.revealAdjacent(4,5);
    ASSERT_EQ(minefield.get(4,5), EMPTY_SHOWN);
    ASSERT_EQ(minefield.get(5,5), EMPTY_SHOWN);
    ASSERT_EQ(minefield.get(3,5), EMPTY_SHOWN);
    ASSERT_EQ(minefield.get(4,4), EMPTY_SHOWN);
    ASSERT_EQ(minefield.get(4,6), EMPTY_SHOWN);
}