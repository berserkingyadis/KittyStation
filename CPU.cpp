#include "CPU.h"

#include <iostream>
#include <iomanip>

#include "Interconnect.h"

CPU::CPU(Interconnect* interconnect)
{
	m_interconnect = interconnect;
	initMachineState();
}

void CPU::start()
{
	m_running = true;
	while (m_running) {
		processNextInstruction();
	}
}

void CPU::initMachineState()
{
	for (int i = 0; i < CPU_REGISTERS_SIZE; i++) {
		m_state.registers[i] = 0xdeadbeef;
	}
	m_state.registers[0] = 0;

	m_state.program_counter = 0xbfc00000; //beginning of BIOS
}

void CPU::processNextInstruction()
{
	uint32_t instruction = load32(m_state.program_counter);
	m_state.program_counter += 4;
	decodeAndExecute(instruction);
	
}

uint32_t CPU::load32(uint32_t address)
{
	return m_interconnect->load32(address);
}

void CPU::decodeAndExecute(uint32_t instruction)
{
	panicInstruction(instruction);
}

void CPU::panicInstruction(uint32_t instruction)
{
	std::cerr << "CAT PANIC! Unknown Instruction: " << "0x" << std::setfill('0') << std::setw(8) << std::hex << instruction << std::endl;
	exit(99);
}
