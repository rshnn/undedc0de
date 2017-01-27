// Author: John-Austen Francisco
// Date: 9 September 2015
//
// Preconditions: Appropriate C libraries
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name:		Roshan Patel rrp78
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

	ptr = (void *) &signum;
	printf("%i\n",signum);
	printf("%x\n",ptr);
	
}


int main()
{
	int r2 = 0;

	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );
	
	printf("I live again!\n");

	return 0;
}
