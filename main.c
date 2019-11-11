#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "instruction.h"

void virtualMachine(inst* instructions) {
	uint64_t i = 0;
	bool running = true;

	uint64_t* reg = malloc(sizeof(uint64_t) * 8);
	uint64_t accumulator = 0;

	while (running) {
		uint64_t p = instructions[i].param;
		switch (instructions[i].inst) {
			case iinp: 
				scanf("%lld", &accumulator);
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
				printf("reg[%lld] = %lld\n", p, reg[p]);
				break;
			case ilda: 
				accumulator = reg[p];
				break;
			case icmp:
				if (accumulator > reg[p]) 		{ accumulator = 1; }
				else if (accumulator == reg[p]) { accumulator = 0; }
				else if (accumulator < reg[p]) 	{ accumulator = 2; }
				break;
			case ijmp: 
				i = p - 1;
				break;
			case ijlt: 
				if (accumulator == 1) { i = p - 1; }
				break;
			case ijet: 
				if (accumulator == 0) { i = p - 1; }
				break;
			case ijmt: 
				if (accumulator == 2) { i = p - 1; }
				break;
			case ipsh: 
				accumulator = p;
				break;
			case ihlt:
				running = false;
				printf("\n----Virtual machine halted----\n");
				break;
			default:
				printf("Invalid instruction\n");
				break;
		}
		i++;
	}
}

int main() {
	inst source[] = {
		// Target terms stored in 0
		{iinp, 0},
		{ista, 0},

		// Counter for terms
		{ipsh, 0},
		{ista, 1},

		// Initializing 1 & 2
		{ipsh, 0},
		{ista, 2},
		{ipsh, 1},
		{ista, 3},

		// Adding 2 & 3 then storing in 4
		{ilda, 2},
		{iadd, 3},
		{ista, 4},

		// Storing 3 in 2
		{ilda, 3},
		{ista, 2},

		// Storing 4 in 3
		{ilda, 4},
		{ista, 3},

		// Adding one to counter
		{ipsh, 1},
		{iadd, 1},
		{ista, 1},

		// Compare target terms to counter
		{ilda, 0},
		{icmp, 1},

		// Printing term
		{iout, 4},

		// Jump to instruction 8 if target is more
		{ijlt, 8},

		// End program
		{ihlt, 0}
	};

	virtualMachine(source);
	system("pause");
	return 0;
}