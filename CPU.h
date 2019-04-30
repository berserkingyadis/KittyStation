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

// this union->struct->bitfield magic was adapted with permission from https://github.com/LukeUsher
union InstructionDescr {
	uint32_t value;
	struct {
		uint32_t Funct : 6; // 0-5
		uint32_t ShAmt : 5; // 6-10
		uint32_t RD : 5;    // 11-15
		uint32_t RT : 5;    // 16-20
		uint32_t RS : 5;    // 21-25
		uint32_t OP : 6;    // 26-31
		
	} R;
	struct {
		uint32_t IMM : 16;   // 0-15
		uint32_t RT : 5;    // 16-20
		uint32_t RS : 5;	// 21-25
		uint32_t OP : 6;    // 26-31
	} I;
	struct {
		uint32_t TGT : 26;  // 0-25
		uint32_t OP : 6;    // 26-31
	} J;
};

class CPU
{
public:
	CPU(Interconnect* interconnect);

	void start();

private:
	void initMachineState();
	void processNextInstruction();
	void decodeAndExecute(uint32_t instruction);

	void panicInstruction(uint32_t instruction);

	cpuMachineState m_state;

	bool m_running;
	InstructionDescr m_instrDescr;

	Interconnect* m_interconnect;

	// register store/load
	void setRegister(uint32_t index, uint32_t value);
	inline uint32_t getRegister(uint32_t index);
	// memory store/load
	uint32_t load32(uint32_t address);


	// CPU instructions

	void instruction_LUI();
	void instruction_ORI();
};

