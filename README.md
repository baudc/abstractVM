# abstractVM

The goal of this project is to create a simple virtual machine that is able to interpret programs that are written in a
simplified assembler language.

To be precise, it consists in a stack machine that is able to calculate simple arithmetical expressions.

These very arithmetical expressions are given to the machine in the form of simple assembler programs.

Example of .avm file :

push  int32(33)

push  int32(42)

add

push float(44.55)

mul

push double(42.42)

push int32(42)

dump

pop

assert double(42.42)

exit

# Instructions

• comments

They begin with a semicolon (;) and end at the end of a line. A comment may be indifferent at the beginning of
a line or after an instruction.

• push

Stack the value at the top. The value will naturally take one of the following forms:
int8(n), int16(n), int32(n), float(z), double(z).
(For example : int16(n) - create an signed 16-bit integer with the value n)

• pop

Unstacks the value at the top of the stack. If the stack is empty the program’s execution must stop error.

• clear

Clears the stack. Rendering it empty.

• dup

Duplicates the value on the top of the stack, and stacks the copy of the value.

• swap

Reverses the order of (swaps) the top two values on the stack.

• dump

Display each value on the stack from the newest to the oldest, WITHOUT MODIFYING the stack. Each value is
separated from the next with a line break.

• assert 

Verify that the value at the top of the stack is equal to the one passed as parameter in this instruction. If it’s not
the case, the program execution must stop error. The value, of course, has the same form as those passed as parameter during the push
instruction.

• add

Unstack the first two values in the stack, add them, and then stack the result. If the number of values in the
stack is strictly less than 2, the program execution must stop error.

• sub

Unstack the first two values in the stack, substract them, and then stack the result. If the number of values in
the stack is strictly less than 2, the program execution must stop error.

• mul

Unstack the first two values in the stack, multiply them, and then stack the result. If the number of the values
in the stack is strictly less than 2, the program execution must stop error.

• div

Unstack the first two values in the stack, divide them, and then stack the result. If the number of the values
in the stack is strictly less than 2, the program execution must stop error. Also, if the divisor is equal to 0, the
program execution must also stop error.

• mod

Unstack the first two values in the stack, calculate their modulo, and then stack the result. If the number of the
values in the stack is strictly less than 2, the program execution must stop error. Also, if the divisor is equal to 0,
the program execution must also stop error.

• load

Copy the value from the register and stack it at the top. if the register does not contain a value, the program execution must stop error.

• store

Unstack the first value and store it to the register.

• print

Make sure that the value at the top of the stack is an 8-bit integer (if this is not the case, see the
assert instruction), then interpret it like an ASCII value and display the corresponding character on the standard output.

• exit

Quit the program execution that is underway. If this instruction does not appear, despite the fact that all of the
instructions have been executed, the execution must stop error.
