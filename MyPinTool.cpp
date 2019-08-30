#include "pin.h"
#include <iostream>


VOID Instruction(INS ins, VOID* v)
{
	if (INS_IsCall(ins)) {
		std::cerr << INS_Disassemble(ins) << std::endl;
	}
}

VOID Image(IMG img, VOID* v)
{
	std::string name = IMG_Name(img);
	std::cerr << "[*] Image: " << name << std::endl;
}

VOID Fini(INT32 code, VOID* v)
{
	std::cout << "[+] End of analysis" << std::endl;
}


int main(int argc, char* argv[])
{
	std::cerr << "[+] Starting instrumentation..." << std::endl;
	PIN_InitSymbols();
	PIN_Init(argc, argv);
	IMG_AddInstrumentFunction(Image, NULL);
	INS_AddInstrumentFunction(Instruction, NULL);

	PIN_AddFiniFunction(Fini, NULL);
	PIN_StartProgram();
	return 0;
}
