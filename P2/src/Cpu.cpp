#include "../include/Cpu.h"

Cpu::Cpu(/* args */) {}

Cpu::~Cpu() {}

Cpu::Cpu(std::vector<Instruction*> programInput, std::ifstream& inFile,
         std::string outName, int flag, std::map<std::string, int>& tags)
    : program(programInput, tags),
      inTape(inFile),
      outTape(outName),
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
  if (flagExecution == 1) {
    while ((inputMenu != 'x') && (flagExecution == 1) && (keepRunning == true)) {
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
          while (keepRunning == true) {
            step();
          }
          break;
        case 's':
          program.getInstruction(pc) -> disassemble();
          break;
        case 'i':
          std::cout << "El contenido de la cinta de entrada es: \n";
          inTape.showTape(std::cout);
          break;
        case 'o':
          std::cout << "El contenido de la cinta de salida es: \n";
          outTape.showTape(std::cout);
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
  } else {
    while (keepRunning == true) {
      step();
    }
  }
}

void Cpu::step(void) {
  try {
    program.getInstruction(pc)->execute(ctx);
  } catch (char exit) {
      if (exit == 'x') {
        outTape.print();
        keepRunning = false;
      }
  }
}