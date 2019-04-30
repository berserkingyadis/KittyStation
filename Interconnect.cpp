#include "Interconnect.h"

#include "Macros.h"

#include <iostream>
#include <iomanip>

Interconnect::Interconnect(BIOS* bios)
{
	m_bios = bios;
	m_devices.push_back(bios);
}

uint32_t Interconnect::load32(uint32_t adr)
{
	//TODO: add binary search if there are alot more devices
	for (MemoryMapped* device : m_devices) {
		if (device->containsAddress(adr)) {
			return device->load32(adr);
		}
	}
	std::cerr << "fatal error: no device is memorymapped at address " << HEX(adr, 8) << std::endl;
	exit(99);

	//never reached
	return -1;
}
