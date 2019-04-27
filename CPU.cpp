#include "CPU.h"


CPU::CPU()
{
	programCounter = 0xbfc00000;
}

void CPU::processNextInstruction()
{
	uint32_t instruction = loadInstruction32(programCounter);
	instruction += 4;
	decodeAndExecute(instruction);
}

uint32_t CPU::loadInstruction32(uint32_t address)
{
	//TODO: load this from RAM
	return uint32_t();
}

void CPU::decodeAndExecute(uint32_t instruction)
{
	//TODO: implement
}
