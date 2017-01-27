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

+ The assembly file outputs are exactly the same between the ilab -S compile and mutalisk -S compile 
    * 1 diff
        -   .ident  "GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-4)"
        -   .ident  "GCC: (Ubuntu 4.8.5-4ubuntu2) 4.8.5"
    * All else is same
    * Compiling with debugger flag (-g) will add some .nonsense stuff to the assembly 
        - Doesn't actually functionally change anything, just makes it cluttered 

