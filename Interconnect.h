#pragma once

#include <vector>

#include "BIOS.h"
#include "MemoryMapped.h"

class Interconnect
{
public:
	Interconnect(BIOS* bios);

	uint32_t load32(uint32_t adr);
private:
	BIOS* m_bios;
	std::vector<MemoryMapped*> m_devices;
};

