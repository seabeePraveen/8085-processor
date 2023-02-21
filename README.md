# Intel 8085 Virtual Emulator

This is an open-source project that aims to simulate the functionality of the Intel 8085 microprocessor in a software environment. The program is written in C++ and provides a simple interface for users to interact with the virtual machine.

## Installation

To use the Intel 8085 Virtual Emulator, you need to have a C++ compiler installed on your system. You can use any compiler that supports C++11 or higher. We recommend using GCC or Clang for best results.

To compile the program, simply run the following command in your terminal:

```
g++ -std=c++11 8085.cpp -o 8085

```

This will compile the program and generate an executable file named `8085`.

## Usage

To run the Intel 8085 Virtual Emulator, simply execute the `8085` file in your terminal:

```
./8085-processor

```

This will start the program and initialize the virtual machine. The program will then enter into an infinite loop and wait for user input.

### Commands

The program supports the following commands:

- 'M' or 'm': Modify memory contents
- 'R' or 'r': Modify register contents
- 'G' or 'g': Execute the program starting from a particular memory location

### Modify Memory Contents

To modify the contents of memory, enter 'M' or 'm' followed by the memory location you want to modify. The program will then prompt you to enter the new value for that memory location.

If the memory location you enter is invalid, the program will report an error and prompt you to try again.

### Modify Register Contents

To modify the contents of registers, enter 'R' or 'r' followed by the register you want to modify. The program will then prompt you to enter the new value for that register.

If the register you enter is invalid, the program will report an error and prompt you to try again.

### Execute Program

To execute the program, enter 'G' or 'g' followed by the memory location you want to start executing from. The program will then execute the program starting from that memory location.

If the memory location you enter is invalid, the program will report an error and prompt you to try again.

### Error Handling

The program uses error handling to detect and report various errors such as unrecognized memory locations or registers, exceeded memory locations, wrong opcodes, and unrecognized inputs.

If an error is detected, the program will report the error code and prompt you to try again.

## Contributing

We welcome contributions from the community! If you find a bug or have a feature request, please open an issue on our GitHub repository.

If you want to contribute code to the project, please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the LICENSE file for more information.