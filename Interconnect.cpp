#include "Interconnect.h"


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
}
