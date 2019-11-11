# Simple virtual machine (C version) by Dylan Moore

The virtual machine has 8 general purpose registers (0-7)
I will probably use this in a interpreter at one point.

I have wrote a example program, you can find it in the main procedure.
It prints out however many terms the fibonacci sequence that you pick.

---

# Instructions :
The expected parameter is in the brackets after the description of the instruction.

* iinp - Input. Reads a unsigned int into the accumulator. (none)
* ista - Store address. Stores contents of accumulator into register. (register)
* iadd - Add. Adds the contents of a register into the accumulator. (register)
* isub - Subtract. Subtracts the contents of the register from the accumulator. (register)
* iout - Output. Outputs the contents of the register to the console. (register)
* ilda - Load address. Loads the contents of register into accumulator. (register)
* icmp - Compare. Compares contents of register and accumulator, should precede conditional jump.
    * Places 1 into the accumulator if the accumulator is larger than the contents of the register.
    * Places 0 into the accumulator if the accumulator and contents of the register are the same.
    * Places 2 into the accumulator if the accumulator is smaller than the contents of the register. (register)
* ijmp - Jump. Jumps to address provided without condition. (address of target instruction)
* ijlt - Jump if less than. Jumps to address provided if the result of the comparison was less than or there is 1 in the accumulator. (address of target instruction)
* ijet - Jump if equal to. Jumps to address provided if the result of the comparison was equal or there is a 0 in the accumulator. (address of target instruction)
* ijmt - Jump if more than. Jumps to address provided if the result of the comparison was more than or there is a 2 in the accumulator. (address of target instruction)
* ihlt - Halt. Halts the virtual machine, should be used to end code execution.	(none)
* inop - No operation. Does nothing, mainly used for debugging.					(none)