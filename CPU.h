#pragma once

#include <cstdint>

#include "Interconnect.h"

class CPU
{
public:
	CPU(Interconnect* interconnect);

	void start();

private:
	void processNextInstruction();
	uint32_t load32(uint32_t address);
	void decodeAndExecute(uint32_t instruction);

	void panicInstruction(uint32_t instruction);

	uint32_t m_programCounter;
	bool m_running;

	Interconnect* m_interconnect;
};

