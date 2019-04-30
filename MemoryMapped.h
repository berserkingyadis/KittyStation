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

	uint32_t offset(uint32_t adr) {
		return adr - i_mappingBegin;
	}

	virtual uint32_t load32(uint32_t adr) = 0;
protected:
	uint32_t i_mappingBegin;
	uint32_t i_mappingLength;
};
