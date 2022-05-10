#include "gtest/gtest.h"
#include "pch.h"
#include "./../TDD_oart1_money/Dollar.h"
#include "./../TDD_oart1_money/Dollar.cpp"

TEST(FirstTest, OneEqualsOne) {
  EXPECT_EQ(1, 1) << "1 equals 1";
  EXPECT_TRUE(true) << "QWE";
}

TEST(DollarTest, Multiply)
{
	Dollar* dollar = new Dollar{ 5 };
	dollar = dollar->times(2);
	EXPECT_EQ(dollar->getAmount(), 10);
}

TEST(DollarTest, ReturnNewObject)
{
	Dollar* dollar = new Dollar{ 5 };
	Dollar* product = dollar->times(2);
	EXPECT_EQ(product->getAmount(), 10);
	
	Dollar* three_product = dollar->times(3);
	EXPECT_EQ(three_product->getAmount(), 15);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}