# CHIP-8 Interpreter

An educational CHIP-8 interpreter written in **C++**.

## 📌 Project Overview
The goal of this project is to learn and understand low-level computer architecture, CPU execution cycles (Fetch, Decode, Execute), memory mapping, registers, and emulation fundamentals by building a functional CHIP-8 interpreter from scratch.

## 📚 Reference & Documentation
For the implementation of this interpreter, I followed the guide by Austin Morlan because i wanted to be free to compare my code with his implementation:
- **Austin Morlan**: [Building a CHIP-8 Emulator [C++]](https://austinmorlan.com/posts/chip8_emulator/#how-does-a-cpu-work)

## 🎓 Educational Note & AI Assistance
> **Note**: This project is created for educational purposes. AI is utilized exclusively as a **pair-programming mentor** to help explore concepts, explain hardware mechanics, and optimize code—**not** to write the implementation automatically. If I had used AI for writing code, this entire project would have been useless!

## 🛠️ Project Structure
- `include/`: Header files defining the CPU structures and interface declarations (`Chip8.hpp`, `Platform.hpp`).
- `src/`: C++ implementation files for the CPU logic, instruction decoding, rendering, and main loop (`Chip8.cpp`, `Platform.cpp`, `main.cpp`).
- `roms/`: Folder reserved for CHIP-8 game binaries and test ROMs.