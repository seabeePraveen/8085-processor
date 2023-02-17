# 8085 SIMULATOR
<hr>
## Components

The 8085 Simulator consists of the following components:

- **Memory:** A short memory array of 65536 elements is used to store instructions and data.
- **Registers:** A short array of 7 elements is used to store the contents of the registers A, B, C, D, E, H, and L.
- **Flags:** A string of 8 bits is used to store the contents of the flags.

## Usage

The simulator can be used to execute 8085 instructions. The following functions are used to interact with the simulator:

- **hexToDec(string hex):** This function takes a string of hexadecimal digits as an argument and returns its decimal equivalent.
- **decToHex(int dec):** This function takes a decimal number as an argument and returns its hexadecimal equivalent.
- **mem(string loc):** This function takes the memory location as an argument and returns its corresponding value from the memory array.
- **get_reg(char r):** This function takes the register name as an argument and returns the corresponding value from the registers array.
- **getPointer():** This function returns the address of the HL pointer.
- **get_M():** This function returns the value at the memory location pointed to by the HL pointer.
- **put_M(short val):** This function adds the given value to the memory at the location pointed to by the HL pointer.

# 8085 Simulator

This document provides an overview of the 8085 Simulator created by taking reference from #include<bits/stdc++.h>, #include<string> and #include<math.h>. It includes information about the components used in the simulator, such as memory, registers, and flags, and how to use the simulator.

## Components

The 8085 Simulator consists of the following components:

- **Memory:** A short memory array of 65536 elements is used to store instructions and data.
- **Registers:** A short array of 7 elements is used to store the contents of the registers A, B, C, D, E, H, and L.
- **Flags:** A string of 8 bits is used to store the contents of the flags.

## Usage

The simulator can be used to execute 8085 instructions. The following functions are used to interact with the simulator:

- **hexToDec(string hex):** This function takes a string of hexadecimal digits as an argument and returns its decimal equivalent.
- **decToHex(int dec):** This function takes a decimal number as an argument and returns its hexadecimal equivalent.
- **mem(string loc):** This function takes the memory location as an argument and returns its corresponding value from the memory array.
- **get_reg(char r):** This function takes the register name as an argument and returns the corresponding value from the registers array.
- **getPointer():** This function returns the address of the HL pointer.
- **get_M():** This function returns the value at the memory location pointed to by the HL pointer.
- **put_M(short val):** This function adds the given value to the memory at the location pointed to by the HL pointer.

## Execution

The 8085 Simulator can be used to execute 8085 instructions. The following functions are used to interact with the simulator:

- **execute(string inst):** This function takes an instruction as an argument and executes it, making changes to memory and registers as required.
- **get_flag(char flag):** This function takes the flag name as an argument and returns the corresponding value from the flags string.
- **put_flag(char flag, bool val):** This function takes the flag name and the value to be set as arguments and sets the corresponding bit in the flags string.
- **reset():** This function resets all the components of the simulator to their default values.
- **dump_memory():** This function prints the contents of the memory array.
- **dump_registers():** This function prints the contents of the registers array.
- **dump_flags():** This function prints the contents of the flags string.
- **dump_all():** This function prints the contents of the memory, registers, and flags strings.
