#include "BIOS.h"

#include <fstream>
#include <iostream>

BIOS::BIOS(const char* filename)
{	
	i_mappingBegin = 0xbfc00000;
	i_mappingLength = BIOS_SIZE;

	std::ifstream file(filename, std::ios::in | std::ios::binary);

	if (file.is_open()) {
		file.seekg(0, std::ios::end);
		std::streamoff filesize = file.tellg();
		if (filesize == BIOS_SIZE) {
			std::cout << "Meow. BIOS file size is correct." << std::endl;
			
			file.seekg(0, std::ios::beg);
			file.read((char*)&m_data[0x0], filesize);
			std::streamsize writtensize = file.gcount();
			if (filesize == writtensize) {
				std::cout << "BIOS load success." << std::endl;
			}
			else {
				std::cerr << "BIOS was not loaded correctly." << std::endl;
				exit(1);
			}
		}
		else {
			std::cout << "Mrow. BIOS file size is incorrect. Exiting." << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "Error while opening file from '" << filename << "'" << std::endl;
		file.close();
	}
	file.close();
}


uint32_t BIOS::load32(uint32_t adr)
{
	uint32_t off = offset(adr);
	uint32_t b0 = m_data[off + 0];
	uint32_t b1 = m_data[off + 1];
	uint32_t b2 = m_data[off + 2];
	uint32_t b3 = m_data[off + 3];

	return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}
