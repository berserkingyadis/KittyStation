#include "CPU.h"

#include <iostream>
#include <iomanip>
#include <bitset>

#include "Interconnect.h"
#include "Macros.h"

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
		m_state.registers[i] = 0xdeadbeef; //register state after boot is undefined
	}
	m_state.registers[0] = 0; //the first register is always zero

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

void CPU::store32(uint32_t address, uint32_t value)
{
	m_interconnect->store32(address, value);
}

void CPU::decodeAndExecute(uint32_t instruction)
{
	m_instrDescr.value = instruction;

	switch (m_instrDescr.I.OP) {
	case 0x0F:
		instruction_LUI();
		break;
	case 0x0D:
		instruction_ORI();
		break;
	case 0x2B:
		instruction_SW();
		break;
	default:
		panicInstruction(instruction);
		break;
	}
}

inline uint32_t CPU::getRegister(uint32_t index)
{
	return m_state.registers[index];
}

void CPU::setRegister(uint32_t index, uint32_t value) {
	m_state.registers[index] = value;
	m_state.registers[0] = 0; //making sure first register is zero
}
void CPU::panicInstruction(uint32_t instruction)
{
	std::cerr << "CAT PANIC! Unknown Instruction: " << HEX(instruction, 8) << std::endl;
	std::cout << "instruction[31:26] = " << BIN(instruction >> 26,6) << " // " << HEX(instruction >> 26, 2) << std::endl;
	exit(99);
}



void CPU::instruction_LUI() {
	setRegister(m_instrDescr.I.RT, m_instrDescr.I.IMM << 16);
	//std::cout << "LUI test: " << "0x" << std::setfill('0') << std::setw(8) << std::hex << m_state.registers[0x8] << std::endl;
}

void CPU::instruction_ORI() {
	setRegister(m_instrDescr.I.RT, getRegister(m_instrDescr.I.RS) | m_instrDescr.I.IMM);
	//std::cout << HEX(getRegister(0x8), 8) << std::endl;
}

void CPU::instruction_SW()
{
	uint32_t addr = getRegister(m_instrDescr.I.RS) + m_instrDescr.I.IMM;
	store32(addr, getRegister(m_instrDescr.I.RT));
}


