#include <cstdint>
#include <random>

int const VIDEO_WIDTH = 64;
int const VIDEO_HEIGHT = 32;

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
  uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{}; // Display
  uint16_t opcode;
  
  std::default_random_engine randGen; //random engine that executes a random algorithm that generates random bits
  std::uniform_int_distribution<uint8_t> randByte; //trasnforms the random bits in a uint8_t number between 0 and 255, with the same probability for each number

  Chip8();//constructor
  void LoadROM(char const *filename);//Load ROM's instructions
  void Cycle(); // Execute one CPU cycle (Fetch, Decode, Execute)

  // CHIP-8 Instructions (34)
  void OP_00E0(); // CLS
  void OP_00EE(); // RET
  void OP_1nnn(); // JP addr
  void OP_2nnn(); // CALL addr
  void OP_3xkk(); // SE Vx, byte
  void OP_4xkk(); // SNE Vx, byte
  void OP_5xy0(); // SE Vx, Vy
  void OP_6xkk(); // LD Vx, byte
  void OP_7xkk(); // ADD Vx, byte
  void OP_8xy0(); // LD Vx, Vy
  void OP_8xy1(); // OR Vx, Vy
  void OP_8xy2(); // AND Vx, Vy
  void OP_8xy3(); // XOR Vx, Vy
  void OP_8xy4(); // ADD Vx, Vy
  void OP_8xy5(); // SUB Vx, Vy
  void OP_8xy6(); // SHR Vx
  void OP_8xy7(); // SUBN Vx, Vy
  void OP_8xyE(); // SHL Vx
  void OP_9xy0(); // SNE Vx, Vy
  void OP_Annn(); // LD I, addr
  void OP_Bnnn(); // JP V0, addr
  void OP_Cxkk(); // RND Vx, byte
  void OP_Dxyn(); // DRW Vx, Vy, nibble
  void OP_Ex9E(); // SKP Vx
  void OP_ExA1(); // SKNP Vx
  void OP_Fx07(); // LD Vx, DT
  void OP_Fx0A(); // LD Vx, K
  void OP_Fx15(); // LD DT, Vx
  void OP_Fx18(); // LD ST, Vx
  void OP_Fx1E(); // ADD I, Vx
  void OP_Fx29(); // LD F, Vx
  void OP_Fx33(); // LD B, Vx
  void OP_Fx55(); // LD [I], Vx
  void OP_Fx65(); // LD Vx, [I]

private:
  void Table0();
  void Table8();
  void TableE();
  void TableF();
  void OP_NULL();

  typedef void (Chip8::*Chip8Func)();
  Chip8Func table[0xF + 1]{};
  Chip8Func table0[0xE + 1]{};
  Chip8Func table8[0xE + 1]{};
  Chip8Func tableE[0xE + 1]{};
  Chip8Func tableF[0x65 + 1]{};
};

const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int FONTSET_SIZE = 80;
