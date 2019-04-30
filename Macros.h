#pragma once

#define HEX(x, s) "0x" << std::setw(s) << std::setfill('0') << std::hex << (unsigned)(x) << std::dec
#define BIN(x, s) "0b" << std::bitset<s>(x) << std::dec