# CS518 Assignment 0 
### undead_code 



### dev-notes

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
nexti
```

[checking memory from gdb](http://www.delorie.com/gnu/docs/gdb/gdb_56.html)
[background on x86](http://www.cs.virginia.edu/~evans/cs216/guides/x86.html)


