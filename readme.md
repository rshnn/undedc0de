# CS518 Assignment 0 
### undead_code 

The purpose of this exercise is to study a signal handler and the callee stack frame.   
The callee stack frame (signal handler in this case) will contain a parametric variable (signum).  Obtaining the address of this variable will give us a pointer to the callee stack frame.  The pointer is located at `0xffffc7b0`.  The callee stack frame also contains the return address.  This is stored a set number of instructions away from the location of signum (`0xffffc7b0`).  

Dereferencing the address where the return address is located gives us the address of the line that caused the segmentation fault (`r2=*(int*)0`).  THis address is `0x08048492`.  

For the code to run to completion, the dereference instruction needs to be skipped.  Assessing the program run in gdb one assembly instruction at a time, one can determine that the length of the instruction of the dereference is 0x6 memory addresses long.  Therefore, the return address will be incremented from the callee function by 0x6. 

0xffffc7b0:     0x0000000b      (SIGNUM=11)  
0xffffc7ec:     0x08048492      (RETURN ADDRESS)

| Value of ptr  |  contents of address |
|---------------|----------------------|
| 0x8048492 <main+42> |    0x4489008b  |
| 0x8048498 <main+48> |    0x3c2404c7  |


#### misc-dev-notes

+ 32-bit compiler 
    * `rshn@optimusprime:~/Developer/school/undedc0de$ sudo apt-get install lib32gcc-4.8-dev`  
    + `rshn@optimusprime:~/Developer/school/undedc0de$ sudo apt-get install libc6-dev:i386`

+ makefile created
    + make commands available 
        - make all
        - make debug
        - make assembly
        - make clean
    * Compiling with no optimizations and in 32bit
        - -m32 -O0 
    * Compiles to assembly with -S flag 

#### gdb and assembly file 

+ The assembly file outputs are exactly the same between the ilab -S compile and mutalisk -S compile 
    * 1 diff
        -   .ident  "GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-4)"  
        -   .ident  "GCC: (Ubuntu 4.8.5-4ubuntu2) 4.8.5"
    * All else is same
    * Compiling with debugger flag (-g) will add some .nonsense stuff to the assembly 
        - Doesn't actually functionally change anything, just makes it cluttered 

+ Assessing assmebly file
    * starts at main: 
    * `pushl %ebp`          
        * points to stack frame of caller 
        * the calling convention is to save the caller's base pointe rby pushing it on the stack
    * `movl %esp, %ebp`
    * ebp = base pointer
        - contains address of the base of the stack frame (stack grows up) 
    * esp = stack pointer
        - address of the top element of the current stack frame


```bash
gdb -tui undead_code
layout asm
break (linenumber)
run
nexti (ni)
info registers (i r)
```

[checking memory from gdb](http://www.delorie.com/gnu/docs/gdb/gdb_56.html)
[background on x86](http://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
