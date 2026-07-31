# CHIP-8 Interpreter

An educational CHIP-8 interpreter written in **C++**.

## 📌 Project Overview
The goal of this project is to learn and understand low-level computer architecture, CPU execution cycles (Fetch, Decode, Execute), memory mapping, registers, and emulation fundamentals by building a functional CHIP-8 interpreter from scratch.

## 📚 Reference & Documentation
For the implementation of this interpreter, I followed the guide by Austin Morlan because i wanted to be free to compare my code with his implementation:
- **Austin Morlan**: [Building a CHIP-8 Emulator [C++]](https://austinmorlan.com/posts/chip8_emulator/#how-does-a-cpu-work)

## 🎓 Educational Note & AI Assistance
> **Note**: This project is created for educational purposes. AI is utilized exclusively as a **pair-programming mentor** to help explore concepts, explain hardware mechanics, and optimize code—**not** to write the implementation automatically. If I had used AI for writing code, this entire project would have been useless!

## How to try it

### Prerequisites
Make sure you have **SDL2** installed. If you are on macOS using Homebrew, you can install it with:
```bash
brew install sdl2
```

### Build
You can compile the emulator easily using the provided Makefile. Open your terminal in the project root and run:
```bash
make
```
This will compile the source code and generate the `chip8` executable.

### Run
To run the emulator, you need to provide the video scale (e.g. 10 for a 10x window), the delay (in milliseconds), and the path to a CHIP-8 ROM.

```bash
./chip8 <Video Scale> <Delay> <ROM path>
```
**Example:**
```bash
./chip8 10 1 roms/test_opcode.ch8
```

### Clean
To remove the compiled files and the executable, simply run:
```bash
make clean
```

## 🛠️ Project Structure
- `include/`: Header files defining the CPU structures and interface declarations (`Chip8.hpp`, `Platform.hpp`).
- `src/`: C++ implementation files for the CPU logic, instruction decoding, rendering, and main loop (`Chip8.cpp`, `Platform.cpp`, `main.cpp`).
- `roms/`: Folder reserved for CHIP-8 game binaries and test ROMs.
