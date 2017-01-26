# gcc (Ubuntu 4.8.5-4ubuntu2) 4.8.5
CC = gcc

# -m32 	32-bit mode 
# -O0	No optimization option  
# -g 	Enable gdb debugging 
# -S 	Compile to assmebly 
CFLAGS 		= -m32 -O0
DEBUGGER 	= -g
AFLAG 		= -S

SOURCE 		= undead_code.c
TARGET 		= undead_code
ATARGET		= undead_code.s


# Toggle debugger 
ifeq ($(DEBUG), TRUE)
CFLAGS += $(DEBUGGER)
endif

make: 
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

assembly: 
	$(CC) $(CFLAGS) $(AFLAG) -o $(ATARGET) $(SOURCE) 

debug: 
	make DEBUG=TRUE

clean: 
	rm -f $(TARGET) $(ATARGET)

rebuild:
	rm -f $(TARGET) $(ATARGET)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
