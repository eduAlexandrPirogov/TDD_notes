#include "gtest/gtest.h"
#include "pch.h"
#include "./../TDD_oart1_money/Dollar.h"
#include "./../TDD_oart1_money/Dollar.cpp"
#include "./../TDD_oart1_money/Franc.h"
#include "./../TDD_oart1_money/Franc.cpp"

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

TEST(DollarTest, TestEquality)
{
	EXPECT_TRUE((new Dollar(5))->equals(*(new Dollar(5))));
	EXPECT_TRUE((new Dollar(0))->equals(*(new Dollar(0))));
	EXPECT_FALSE((new Dollar(5))->equals(*(new Dollar(15))));
	EXPECT_FALSE((new Dollar(0))->equals(*(new Dollar(5))));
}

TEST(FrancTest, Multiply)
{
	Franc* franc = new Franc{ 5 };
	franc = franc->times(2);
	EXPECT_EQ(franc->getAmount(), 10);
}

TEST(FrancTest, ReturnNewObject)
{
	Franc* franc = new Franc{ 5 };
	Franc* product = franc->times(2);
	EXPECT_EQ(product->getAmount(), 10);

	Franc* three_product = franc->times(3);
	EXPECT_EQ(three_product->getAmount(), 15);
}

TEST(FrancTest, TestEquality)
{
	EXPECT_TRUE((new Franc(5))->equals(*(new Franc(5))));
	EXPECT_TRUE((new Franc(0))->equals(*(new Franc(0))));
	EXPECT_FALSE((new Franc(5))->equals(*(new Franc(15))));
	EXPECT_FALSE((new Franc(0))->equals(*(new Franc(5))));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

