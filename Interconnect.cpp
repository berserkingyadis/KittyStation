#include "Interconnect.h"

#include "Macros.h"

#include <iostream>
#include <iomanip>

Interconnect::Interconnect(BIOS* bios)
{
	m_bios = bios;
	m_devices.push_back(bios);
}

uint32_t Interconnect::load32(uint32_t address)
{
	//TODO: add binary search if there are alot more devices
	for (MemoryMapped* device : m_devices) {
		if (device->containsAddress(address)) {
			return device->load32(address);
		}
	}
	std::cerr << "fatal error: no device is memorymapped at address " << HEX(address, 8) << std::endl;
	exit(99);
}

void Interconnect::store32(uint32_t address, uint32_t value)
{
	std::cerr << "fatal error: storing to memory is not implemented yet " << HEX(address, 8) << std::endl;
	exit(99);
}
