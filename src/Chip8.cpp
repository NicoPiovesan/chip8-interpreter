#include "../include/Chip8.hpp"
#include <fstream>
#include <chrono>


//fontset
uint8_t fontset[FONTSET_SIZE] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

const unsigned int START_ADDRESS = 0x200; // Where we can find the instructions from the ROM

//Load ROM's instructions                               
void Chip8::LoadROM(char const *filename) {
  // Open the file as a stream of binary and move the file pointer to the end
  // (to understand the size)
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (file.is_open()) {
    // Get size of file and allocate a buffer to hold the contents
    std::streampos size = file.tellg();
    char *buffer = new char[size]; // buffer = binary file loaded

    // Go back to the beginning of the file and fill the buffer
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();

    // Load the ROM contents into the Chip8's memory, starting at 0x200
    for (long i = 0; i < size; ++i) {
      memory[START_ADDRESS + i] = buffer[i];
    }

    // Free the buffer
    delete[] buffer;
  }
}

//Constructor
Chip8::Chip8()
    : randGen(std::chrono::system_clock::now().time_since_epoch().count()) { //uses the current time as a SEED for number generator
    pc = START_ADDRESS; // inizialize the program counter to the start address of the ROM

    //loads the fontset into memory (from 0x50 to 0x0A0)
    for (unsigned int i = 0; i< FONTSET_SIZE; i++){
        memory[FONTSET_START_ADDRESS + i] = fontset[i]; 
    }

    //initialize the random number generator
    randByte = std::uniform_int_distribution<uint8_t>(0, 255U); //distribution is between 0 and 255

}

//Instructions

//CLS (clear the display)
void Chip8::OP_00E0(){
    memset(video, 0, sizeof(video)); //Set the entire video buffer to zeroes
}

//RET (return from a subroutine)
void Chip8::OP_00EE(){
    --sp; //stack pointer - 1
    pc = stack[sp]; //pc is equals to the top of the stack
    
}

//JP addr (jump to location nnn)
void Chip8::OP_1nnn(){
    uint16_t address = opcode & 0x0FFF; //getting the address using the Bitmasking operation
    pc = address;
}

//CALL addr (Call subroutine at nnn)
void Chip8::OP_2nnn(){
    uint16_t address = opcode & 0x0FFF;
    stack[sp] = pc;
    ++sp;
    pc = address;
}

//SE Vx, byte (skipt next instruction if Vx == kk)
void Chip8::OP_3xkk(){
    uint8_t Vx = (opcode & 0x0F00u) >> 8u; // Bitmasking op to get x (index of the register Vx)
    uint8_t byte = opcode & 0x00FFu; //Bitmasking to get byte

    if(registers[Vx] == byte){
        pc += 2;
    }

}

//TO DO