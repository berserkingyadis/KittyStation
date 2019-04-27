#pragma once

#include <cstdint>

#define BIOS_SIZE 512 * 1024

class BIOS
{
public:
	BIOS(const char* filename);

private:
	uint8_t data[BIOS_SIZE];
};

