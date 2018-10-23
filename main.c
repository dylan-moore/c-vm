#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define iinp 1
#define ista 2
#define iadd 3
#define isub 4
#define iout 5
#define ilda 6
#define icmp 7
#define ijmp 8
#define ijlt 9
#define ijet 10
#define ijmt 11
#define ihlt 12
#define ipsh 13
#define inop 14

typedef struct instruction {
	char inst;
	unsigned char param;
} inst;

/*

	Instructions :
	The expected parameter is in the brackets after the description of the instruction.

	iinp - Input. Reads a unsigned int into the accumulator.						(none)
	ista - Store address. Stores contents of accumulator into register.				(register)
	iadd - Add. Adds the contents of a register into the accumulator.				(register)
	isub - Subtract. Subtracts the contents of the register from the accumulator.	(register)
	iout - Output. Outputs the contents of the register to the console.				(register)
	ilda - Load address. Loads the contents of register into accumulator.			(register)
	icmp - Compare. Compares contents of register and accumulator, should precede conditional jump.
		Places 1 into the accumulator if the accumulator is larger than the contents of the register.
		Places 0 into the accumulator if the accumulator and contents of the register are the same.
		Places 2 into the accumulator if the accumulator is smaller than the contents of the register.
		(register)
	ijmp - Jump. Jumps to address provided without condition.						(address of target instruction)
	ijlt - Jump if less than. Jumps to address provided if the result of the;
		comparison was less than or there is 1 in the accumulator.					(address of target instruction)
	ijet - Jump if equal to. Jumps to address provided if the result of the;
		comparison was equal or there is a 0 in the accumulator.					(address of target instruction)
	ijmt - Jump if more than. Jumps to address provided if the result of the;
		comparison was more than or there is a 2 in the accumulator.				(address of target instruction)
	ihlt - Halt. Halts the virtual machine, should be used to end code execution.	(none)
	inop - No operation. Does nothing, mainly used for debugging.					(none)

*/

void virtualMachine(inst* instructions)
{
	unsigned int* reg = malloc(sizeof(unsigned int)*8);
	unsigned int accumulator = 0;

	int i = 0;
	bool running = true;

	while (running)
	{
		unsigned int p = instructions[i].param;
		switch (instructions[i].inst) {
			case iinp:
				scanf("%u", &accumulator);
				break;
			case ista:
				reg[p] = accumulator;
				break;
			case iadd:
				accumulator += reg[p];
				break;
			case isub:
				accumulator -= reg[p];
				break;
			case iout:
				printf("reg[%u] = %u\n", p, reg[p]);
				break;
			case ilda:
				accumulator = reg[p];
				break;
			case icmp:
				if (accumulator > reg[p])
					accumulator = 1;
				else if (accumulator == reg[p])
					accumulator = 0;
				else if (accumulator < reg[p])
					accumulator = 2;
				break;
			case ijmp:
				i = p-1;
				break;
			case ijlt:
				if (accumulator == 1)
					i = p - 1;
				break;
			case ijet:
				if (accumulator == 0)
					i = p-1;
				break;
			case ijmt:
				if (accumulator == 2)
					i = p - 1;
				break;
			case ihlt:
				running = false;
				printf("\n----Virtual machine halted----\n");
				break;	
			case ipsh:
				accumulator = p;
				break;
		}
		i++;
	}
}

int main()
{
	// Target terms stored in 0
	// INP
	// STA 0

	// Counter for terms
	// PSH 0
	// STA 1

	// Initializing 1 & 2
	// PSH 0
	// STA 2
	// PSH 1
	// STA 3

	// Adding 2 & 3 then storing in 4
	// LDA 2
	// ADD 3
	// STA 4

	// Storing 3 in 2
	// LDA 3
	// STA 2

	// Storing 4 in 3
	// LDA 4
	// STA 3

	// Adding one to counter
	// PSH 1
	// ADD 1
	// STA 1

	// Compare target terms to counter
	// LDA 0
	// CMP 1

	// Printing term
	// OUT 4

	// Jump to instruction 8 if target is more
	// JLT 8

	// End program
	// HLT

	inst* sourcecode = malloc(sizeof(inst) * 22);

	sourcecode[0].inst = iinp;
	sourcecode[1].inst = ista;
	sourcecode[1].param = 0;

	sourcecode[2].inst = ipsh;
	sourcecode[2].param = 0;
	sourcecode[3].inst = ista;
	sourcecode[3].param = 1;

	sourcecode[4].inst = ipsh;
	sourcecode[4].param = 0;
	sourcecode[5].inst = ista;
	sourcecode[5].param = 2;
	sourcecode[6].inst = ipsh;
	sourcecode[6].param = 1;
	sourcecode[7].inst = ista;
	sourcecode[7].param = 3;

	sourcecode[8].inst = ilda;
	sourcecode[8].param = 2;
	sourcecode[9].inst = iadd;
	sourcecode[9].param = 3;
	sourcecode[10].inst = ista;
	sourcecode[10].param = 4;

	sourcecode[11].inst = ilda;
	sourcecode[11].param = 3;
	sourcecode[12].inst = ista;
	sourcecode[12].param = 2;

	sourcecode[13].inst = ilda;
	sourcecode[13].param = 4;
	sourcecode[14].inst = ista;
	sourcecode[14].param = 3;

	sourcecode[15].inst = ipsh;
	sourcecode[15].param = 1;
	sourcecode[16].inst = iadd;
	sourcecode[16].param = 1;
	sourcecode[17].inst = ista;
	sourcecode[17].param = 1;

	sourcecode[18].inst = ilda;
	sourcecode[18].param = 0;
	sourcecode[19].inst = icmp;
	sourcecode[19].param = 1;

	sourcecode[20].inst = iout;
	sourcecode[20].param = 4;

	sourcecode[21].inst = ijlt;
	sourcecode[21].param = 8;

	virtualMachine(sourcecode);
	
	system("pause");
	return 0;
}