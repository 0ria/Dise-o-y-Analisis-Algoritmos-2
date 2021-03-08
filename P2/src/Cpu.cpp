#include "../include/Cpu.h"

Cpu::Cpu(/* args */) {}

Cpu::~Cpu() {}

Cpu::Cpu(std::vector<Instruction*> programInput, std::ifstream& inFile,
         std::ofstream& outFile, int flag)
    : program(programInput),
      inTape(inFile),
      outTape(outFile),
      flagExecution(flag) {
        ctx.mem = &memory;
        ctx.in = &inTape;
        ctx.out = &outTape;
        ctx.p = &pc;
        ctx.tags = program.getTags();
      }

void Cpu::executeProgram() {
  /*program.showProgram();
  inTape.showTape();
  outTape.showTape();
  program.showMap();*/
  char inputMenu;

  while (inputMenu != 'x' && flagExecution == 1) {
    std::cout << "\nr: ver los registros" << std::endl;
    std::cout << "t: traza" << std::endl;
    std::cout << "e: ejecutar" << std::endl;
    std::cout << "s: desensamblador" << std::endl;
    std::cout << "i: ver cinta de entrada" << std::endl;
    std::cout << "o: ver cinta de salida" << std::endl;
    std::cout << "h: ayuda" << std::endl;
    std::cout << "x: salir" << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> inputMenu;
    std::cout << std::endl;

    switch (inputMenu) {
      case 'r':
        memory.showMemoryRegisters();
        break;
      case 't':
        step();
        break;
      case 'e':
        flagExecution = 1;
        break;
      case 's':
        //program.showProgram();
        break;
      case 'i':
        std::cout << "El contenido de la cinta de entrada es: \n";
        inTape.showTape();
        break;
      case 'o':
        std::cout << "El contenido de la cinta de salida es: \n";
        outTape.showTape();
        break;
      case 'h':
        break;
      case 'x':
        break;
      default:
        std::cout << "Opción no valida\n";
        break;
    }
  }
}

void Cpu::step(void) {
  program.getInstruction(pc) -> execute(ctx);
}