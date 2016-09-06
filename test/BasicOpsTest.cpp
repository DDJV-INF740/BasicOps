#include "gtest/gtest.h"

#include "BasicOps.hpp"
#include "ExtraOps_solutions.hpp"

using namespace BasicOps;

TEST(BasicOpsTest, testGetBit) 
{
	EXPECT_THROW(GET(ZERO, 8), std::exception);
	EXPECT_THROW(GET(ZERO, -1), std::exception);

	// expect the first bit to be set
	EXPECT_EQ(ONE, GET(1, 0));

	// expect all other bits to be unset
	for (int i = 1; i < 8; ++i)
		EXPECT_EQ(ZERO, GET(1, i));
}

TEST(BasicOpsTest, testSetBit) 
{
	EXPECT_THROW(SET(0, ONE, 8), std::exception);
	EXPECT_THROW(SET(0, ONE, -1), std::exception);

	EXPECT_EQ(ZERO, GET(0, 1));
	for (int i = 0; i < 8; ++i)
	{
		uint8 val = SET(0, ONE, i);
		for (int j = 0; j < 8; ++j)
		{
			if (j == i)
				EXPECT_EQ(ONE, GET(val, j));
			else
				EXPECT_EQ(ZERO, GET(val, j));
		}
	}
}

TEST(BasicOpsTest, testNAND)
{
	EXPECT_EQ(ZERO, NAND(ONE, ONE));
	EXPECT_EQ(ZERO, NAND(ONE, ZERO));
	EXPECT_EQ(ONE, NAND(ZERO, ONE));
	EXPECT_EQ(ZERO, NAND(ZERO, ZERO));
}

TEST(BasicOpsTest, testNOT)
{
	EXPECT_EQ(ZERO, NOT(ONE));
	EXPECT_EQ(ONE, NOT(ZERO));
}

TEST(BasicOpsTest, testAND)
{
	EXPECT_EQ(ONE, AND(ONE, ONE));
	EXPECT_EQ(ZERO, AND(ONE, ZERO));
	EXPECT_EQ(ZERO, AND(ZERO, ONE));
	EXPECT_EQ(ZERO, AND(ZERO, ZERO));
}

TEST(BasicOpsTest, testOR)
{
	EXPECT_EQ(ONE, OR(ONE, ONE));
	EXPECT_EQ(ONE, OR(ONE, ZERO));
	EXPECT_EQ(ONE, OR(ZERO, ONE));
	EXPECT_EQ(ZERO, OR(ZERO, ZERO));
}

TEST(BasicOpsTest, testXOR)
{
	EXPECT_EQ(ONE, XOR(ONE, ONE));
	EXPECT_EQ(ZERO, XOR(ONE, ZERO));
	EXPECT_EQ(ZERO, XOR(ZERO, ONE));
	EXPECT_EQ(ONE, XOR(ZERO, ZERO));
}

TEST(BasicOpsTest, testEQ)
{
	EXPECT_EQ(ONE, EQ(ONE, ONE));
	EXPECT_EQ(ZERO, EQ(ONE, ZERO));
	EXPECT_EQ(ZERO, EQ(ZERO, ONE));
	EXPECT_EQ(ONE, EQ(ZERO, ZERO));
}

TEST(BasicOpsTest, testADD)
{
	EXPECT_EQ(ZERO, ADD(ZERO, ZERO).bit);
	EXPECT_EQ(ZERO, ADD(ZERO, ZERO).overflow);

	EXPECT_EQ(ONE, ADD(ZERO, ONE).bit);
	EXPECT_EQ(ZERO, ADD(ZERO, ONE).overflow);

	EXPECT_EQ(ONE, ADD(ONE, ZERO).bit);
	EXPECT_EQ(ZERO, ADD(ONE, ZERO).overflow);

	EXPECT_EQ(ZERO, ADD(ONE, ONE).bit);
	EXPECT_EQ(ONE, ADD(ONE, ONE).overflow);
}

TEST(BasicOpsTest, testADD8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(uint8(i+j), ADD8(i, j).value);
}

TEST(BasicOpsTest, testFLIP8)
{
	for (int i = 0; i < 255; ++i)
		EXPECT_EQ(uint8(~i), FLIP8(i).value);
}

TEST(BasicOpsTest, testNEG8)
{
	for (int i = 0; i < 255; ++i)
		EXPECT_EQ(uint8(-i), NEG8(i).value);
}

TEST(BasicOpsTest, testSUB8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(uint8(i - j), SUB8(i, j).value);
}

TEST(BasicOpsTest, testLT8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(i < j ? ONE : ZERO, LT8(i, j));
}

TEST(BasicOpsTest, testGT8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(i > j ? ONE : ZERO, GT8(i, j));
}

TEST(BasicOpsTest, testLE8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(i <= j ? ONE : ZERO, LE8(i, j));
}

TEST(BasicOpsTest, testNEQ8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(i != j ? ONE : ZERO, NEQ8(i, j));
}

TEST(BasicOpsTest, testEQ8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(i == j ? ONE : ZERO, EQ8(i, j));
}

TEST(BasicOpsTest, testMULT8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			EXPECT_EQ(uint8(i * j), MULT8(i, j));
}

TEST(BasicOpsTest, testLEFT8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 8; ++j)
			EXPECT_EQ(uint8(i << j), LEFT8(i, j));
}

TEST(BasicOpsTest, testRIGHT8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 8; ++j)
			EXPECT_EQ(uint8(i >> j), RIGHT8(i, j));
}

TEST(BasicOpsTest, testDIV8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 1; j < 256; ++j)
			EXPECT_EQ(uint8(i / j), DIV8(i, j));
}

TEST(BasicOpsTest, testMOD8)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 1; j < 256; ++j)
			EXPECT_EQ(uint8(i % j), MOD8(i, j));
}
