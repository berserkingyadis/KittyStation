#pragma once

#include <cstdint>

#define BIOS_SIZE 512 * 1024

class BIOS
{
public:
	BIOS(const char* filename);

	uint32_t load32(uint32_t offset);

private:
	uint8_t m_data[BIOS_SIZE];
};

