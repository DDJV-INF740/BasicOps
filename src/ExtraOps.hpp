#pragma once

#include "BasicOps.hpp"

namespace BasicOps
{
	static inline Bit NOT(Bit x)
	{
		// HINT: NAND
		return ZERO;
	}

	static inline Bit AND(Bit x, Bit y)
	{
		// HINT: NAND, NOT
		return ZERO;
	}

	static inline Bit XOR(Bit x, Bit y)
	{
		// HINT: OR, AND, NOT
		return ZERO;
	}

	static inline Bit EQ(Bit x, Bit y)
	{
		// HINT: XOR
		return ZERO;
	}

	// result.bit indicates the 1 bit result for (x + y)
	// result.overflow is set when result x + y > 1
	static inline AddBitResult ADD(Bit x, Bit y)
	{
		// HINT: NOT, XOR, AND
		return AddBitResult();
	}

	// Return x + y and set overflow bit if result exceeds 255.
	// Treat x and y as though they are 9 bit unsigned integers
	// (where the overflow bit is the 9th bit)
	static Register ADD8(Register x, Register y)
	{
		// HINT: ADD, OR
		return Register(0);
	}

	static Register ADD8(uint8 x, uint8 y)
	{
		return ADD8(Register(x, ZERO), Register(y, ZERO));
	}

	// Flip all the bits of the number, including overflow
	static inline Register FLIP8(Register x)
	{
		// HINT: NOT
		return Register(0);
	}

	static inline Register FLIP8(uint8 x)
	{
		return FLIP8(Register(x));
	}

	// Return the negative value of x
	static inline Register NEG8(Register x)
	{
		// HINT: FLIP8, ADD8
		return Register(0);
	}

	static inline Register NEG8(uint8 x)
	{
		return NEG8(Register(x));
	}


	// Returns the value of (x - y) and sets the overflow
	// bit if (x - y) would have been smaller than 0
	static inline Register SUB8(uint8 x, uint8 y)
	{
		// HINT: ADD8, NEG8
		return Register(0);
	}

	// Return ONE if x is strictly less than y (x < y), ZERO otherwise
	static inline Bit LT8(uint8 x, uint8 y)
	{
		// HINT: SUB8, overflow
		return ZERO;
	}

	// Return ONE if x is strictly greater than y (x > y), ZERO otherwise
	static inline Bit GT8(uint8 x, uint8 y)
	{
		// HINT: LT8
		return ZERO;
	}

	// Return ONE if x is less or equal to y (x <= y), ZERO otherwise
	static inline Bit LE8(uint8 x, uint8 y)
	{
		// HINT: NOT, GT8
		return ZERO;
	}

	// Return ONE if x is greater or equal to y (x >= y), ZERO otherwise
	static inline Bit GE8(uint8 x, uint8 y)
	{
		// HINT: NOT, LT8
		return ZERO;
	}

	// Return ONE if x is not equal to y (x != y), ZERO otherwise
	static inline Bit NEQ8(uint8 x, uint8 y)
	{
		// HINT: OR, GT8, LT8
		return ZERO;
	}

	// Return ONE if x is equal to y (x == y), ZERO otherwise
	static inline Bit EQ8(uint8 x, uint8 y)
	{
		// HINT: NOT, NEQ8
		return ZERO;
	}


	// Return the 8 bit result for x * y
	static inline uint8 MULT8(uint8 x, uint8 y)
	{
		// HINT: BRANCH_IF, ADD8, SUB8
		return 0;
	}

	// Shift the bits of x to the left by i bits (just like x << i)
	static inline uint8 LEFT8(uint8 x, uint8 i)
	{
		// HINT: BRANCH_IF, overflow, SET, GET, SUB8
		return 0;
	}

	// Shift the bits of x to the right by i bits (just like x >> i)
	static inline uint8 RIGHT8(uint8 x, uint8 i)
	{
		// HINT: BRANCH_IF, GT8, SET, GET8 ADD8
		return 0;
	}

	// Computes both the quotient (x / y) and modulo (x % y) and returns them
	// in a pair where left is the quotient and right is the modulo
	static std::pair<uint8, uint8> DIVMOD8(uint8 x, uint8 y)
	{
		// HINT: BRANCH_IF, LT8, SUB8, ADD8
		return std::pair<uint8, uint8>(0, 0);
	}

	// Computes the quotient of (x / y)
	static uint8 DIV8(uint8 x, uint8 y)
	{
		return DIVMOD8(x, y).first;
	}

	// Computes the modulo of (x % y)
	static uint8 MOD8(uint8 x, uint8 y)
	{
		return DIVMOD8(x, y).second;
	}
};
