#pragma once

#include <cstdint>
#include <exception>

namespace BasicOps
{
	using int32 = int32_t;
	using uint32 = uint32_t;
	using int8 = int8_t;
	using uint8 = uint8_t;

	enum Bit : uint8
	{
		ZERO = 0,
		ONE = 1
	};

	// Bit accompanied with overflow information
	struct AddBitResult
	{
		AddBitResult()
			: AddBitResult(ZERO)
		{}

		AddBitResult(Bit bit)
			: AddBitResult(bit, ZERO)
		{}

		AddBitResult(Bit bit, Bit overflow)
			: bit(bit)
			, overflow(overflow)
		{}

		Bit bit;
		Bit overflow;
	};

	// Theoretical register, which holds 8 bit and an extra bit for overflow.
	// In practice, the register would have only 8 bit and the overflow bit would
	// be in a separate dedicated registered shared by all other registers
	struct Register
	{
		explicit Register(uint8 value)
		{
			this->value = value;
			this->overflow = ZERO;
		}

		Register(uint8 value, Bit overflow)
		{
			this->value = value;
			this->overflow = overflow;
		}

		union {
			struct {
				union {
					uint8 value;
					struct {
						Bit bit0 : 1;
						Bit bit1 : 1;
						Bit bit2 : 1;
						Bit bit3 : 1;
						Bit bit4 : 1;
						Bit bit5 : 1;
						Bit bit6 : 1;
						Bit bit7 : 1;
					};
				};
				Bit overflow : 1;
			};
			struct {
				uint32 full : 9;
			};
		};
	};

	// PROVIDED OPERATION: Get the bit value at the specified index
	static inline Bit GET(uint8 val, uint8 index)
	{
		if (index >= 8)
			throw std::exception("index out of bound");

		return (Bit)((val >> index) & 0x00000001);
	}

	// PROVIDED OPERATION: Get the bit value at the specified index
	static inline uint32 SET(uint32 val, Bit bit, uint8 index)
	{
		if (index >= 8)
			throw std::exception("index out of bound");

		if (bit == ONE)
			val |= 0x00000001 << index;
		else
			val &= ~(0x00000001 << index);

		return val;
	}

	// PROVIDED OPERATION: Equivalent to (!x && y)
	static inline Bit NAND(Bit x, Bit y)
	{
		//return !x && y ? ONE : ZERO;
		return (Bit)((~x & y) & 1); // faster to execute
	}

	// PROVIDED OPERATION: x || y
	static inline Bit OR(Bit x, Bit y)
	{
		//return x || y ? ONE : ZERO;
		return (Bit)(x | y); // faster to execute
	}

	// You are not allowed to use if, ?, for, while, do-while, but
	// you may use the following BRANCH_IF statement:

#define BRANCH_IF(_bit, _label) if (_bit == ONE) goto _label

	// For example, to loop 10 times:
	//
	//	{
	//		Register i = 10;
	// start:
	//		BRANCH_IF(i.overflow, end);
	//		i = SUB8(i, 1);
	//		BRANCH_IF(ONE, start);
	//	end:
	//		// done!
	//	}
	//		



};