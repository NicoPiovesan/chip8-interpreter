#include <cstdint>
#include <random>

class Chip8 {
public:
  uint8_t registers[16]{};   // CPU's register
  uint8_t memory[4096]{};    // Main Memory (4KB)
  uint16_t index{};          // Index register for RAM
  uint16_t pc{};             // Program counter
  uint16_t stack[16]{};      // Stack where the PC is saved
  uint8_t sp{};              // Stack pointer
  uint8_t delayTimer{};      // Timer for pauses
  uint8_t soundTimer{};      // Timer for sound
  uint8_t keypad[16]{};      // Keyboard
  uint32_t video[64 * 32]{}; // Display
  uint16_t opcode;
  std::default_random_engine randGen; //random engine that executes a random algorithm that generates random bits
  std::uniform_int_distribution<uint8_t> randByte; //trasnforms the random bits in a uint8_t number between 0 and 255, with the same probability for each number

  Chip8();//constructor
  void LoadROM(char const *filename);//Load ROM's instructions

  //CHIP-8 Instructions (34)
  void OP_00E0(); //CLS
  void OP_00EE(); //RET
  
};

const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int FONTSET_SIZE = 80;
