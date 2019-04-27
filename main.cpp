#include <iostream>

#define VERSION "0.0.1"

static const char* OP_HELP = "--help";
static const char* OP_HELP_S = "-h";

static const char* OP_VERSION = "--version";
static const char* OP_VERSION_S = "-v";

void print_help();
void print_version();

int main(int argc, char *argv[]) {

	// parse program arguments and if applicable print info and exit
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], OP_HELP) == 0 || strcmp(argv[i], OP_HELP_S) == 0) {
			print_help();
			return 0;
		}
		else if (strcmp(argv[i], OP_VERSION) == 0 || strcmp(argv[i], OP_VERSION_S) == 0) {
			print_version();
			return 0;
		}
	}

	std::cout << "Meow." << std::endl;
	return 0;
}


void print_help() {
	std::cout << "KittyStation is a work in progress PSX emulator, you can call it with:" << std::endl;
	std::cout << "./KittyStation" << std::endl;
	std::cout << std::endl;
	std::cout << "Optional parameters: " << std::endl;
	std::cout << "-v or --v to display the version of the emulator" << std::endl;
	std::cout << "-h or --h to display this message" << std::endl;
}
void print_version() {
	std::cout << "KittyStation version " << VERSION << std::endl;
}
