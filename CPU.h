#pragma once

#include <cstdint>

#include "Interconnect.h"

#define CPU_REGISTERS_SIZE 32

struct cpuMachineState
{
	// ===== Registers

	// General Purpose registers
	uint32_t registers[CPU_REGISTERS_SIZE];

	// Special Purpose regigsters
	uint32_t program_counter;
	uint32_t spr_HIGH;
	uint32_t spr_LOW;

};

class CPU
{
public:
	CPU(Interconnect* interconnect);

	void start();

private:
	void initMachineState();
	void processNextInstruction();
	uint32_t load32(uint32_t address);
	void decodeAndExecute(uint32_t instruction);

	void panicInstruction(uint32_t instruction);

	cpuMachineState m_state;
	bool m_running;

	Interconnect* m_interconnect;

	
};

