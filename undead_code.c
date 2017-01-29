// Author: John-Austen Francisco
// Date: 9 September 2015
//
// Preconditions: Appropriate C libraries
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name:		Roshan Patel (rrp78)
// Ilab machine used:	kill.cs.rutgers.edu

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segment_fault_handler(int signum)
{
	void* ptr;
	printf("I am slain!\n");

	//Use the signnum to construct a pointer to flag on stored stack
	//Increment pointer down to the stored PC
	//Increment value at pointer by length of bad instruction

	/* Signum is used to construct a pointer to the stack frame of seg_fault_handler */
	ptr = (void *) &signum;
	// printf("ptr signum addr %x\n",ptr);


	/* Increment ptr to the address that stores the return address */
	ptr += 0x4c-0x10;
	// printf("ptr rtrn address %x\n",ptr);
	// printf("rtn addr %x\n",*(int*)ptr);

	/* Move address stored in ptr by 0x6 (length of seg fault instruction) */
	*(int *)ptr += 0x6;
	// printf("ptr at end %x\n",ptr);
	// printf("rtn addr %x\n",*(int*)ptr);


	/* Now, when seg_fault_handler compelets, the PC will move to the print statement. */
}


int main()
{
	int r2 = 0;

	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );
	
	printf("I live again!\n");

	return 0;
}
