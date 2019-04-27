#include "BIOS.h"

#include <fstream>
#include <iostream>

BIOS::BIOS(const char* filename)
{
	std::ifstream file(filename, std::ios::in | std::ios::binary);

	if (file.is_open()) {
		file.seekg(0, std::ios::end);
		uint32_t filesize = file.tellg();
		if (filesize == BIOS_SIZE) {
			std::cout << "Meow. BIOS file size is correct." << std::endl;
			
			file.seekg(0, std::ios::beg);
			file.read((char*)&data[0x0], filesize);
			uint32_t writtensize = file.gcount();
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