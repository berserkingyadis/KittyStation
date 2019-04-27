#pragma once

#include <cstdint>

class MemoryMapped
{
public:
	bool containsAddress(uint32_t adr) {
		if (adr >= i_mappingBegin && adr < i_mappingBegin + i_mappingLength) {
			return true;
		}
		else return false;
	}
	virtual uint32_t load32(uint32_t adr) = 0;
protected:
	uint32_t i_mappingBegin;
	uint32_t i_mappingLength;
};
