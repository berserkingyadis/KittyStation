#pragma once

#include <cstdint>

class CPU
{
public:
	CPU();

private:
	void processNextInstruction();
	uint32_t loadInstruction32(uint32_t address);
	void decodeAndExecute(uint32_t instruction);

	uint32_t m_programCounter;
};

