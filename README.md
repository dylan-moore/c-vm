# Simple virtual machine (C version) by Dylan Moore

The virtual machine has 8 general purpose registers (0-7)
I will probably use this in a interpreter at one point.

I have wrote a example program, you can find it in the main procedure.
It prints out however many terms the fibonacci sequence that you pick.

# Instructions :
This is a custom instruction set (made by me).
It is incredibly limited but you should be able to write most programs with it.

# General instructions
Operand is register number
* ista - Store address. Stores contents of accumulator into register.
* iadd - Add. Adds the contents of a register into the accumulator
* isub - Subtract. Subtracts the contents of the register from the accumulator.
* iout - Output. Outputs the contents of the register to the console.
* ilda - Load address. Loads the contents of register into accumulator.

# Comparisons
Operand is the data you want to compare to.
* icmp - Compare. Compares contents of register and accumulator, should precede conditional jump.
    * Places 1 into the accumulator if the accumulator is larger than the contents of the register.
    * Places 0 into the accumulator if the accumulator and contents of the register are the same.
    * Places 2 into the accumulator if the accumulator is smaller than the contents of the register.

# Conditional branching.
Operand is the instruction you want to jump to.
* ijmp - Jump. Jumps to address provided without condition.
* ijlt - Jump if less than. Jumps to address provided if the result of the comparison was less than or there is 1 in the accumulator.
* ijet - Jump if equal to. Jumps to address provided if the result of the comparison was equal or there is a 0 in the accumulator.
* ijmt - Jump if more than. Jumps to address provided if the result of the comparison was more than or there is a 2 in the accumulator.

# Etc functions
Operand is none.
* iinp - Input. Reads a unsigned int into the accumulator.
* ihlt - Halt. Halts the virtual machine, should be used to end code execution.
* inop - No operation. Does nothing, mainly used for debugging.