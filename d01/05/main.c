#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

static void printTank(struct s_tank *t) {
	if (!t) return;
	printf("normal:%d%s", peek(t->stacks[0]), peek(t->stacks[1])?" ":"");
	for (int s=1; s<=t->n && peek(t->stacks[s]); s++)
		printf("nitro%d:%d%s", s, peek(t->stacks[s]), peek(t->stacks[s+1])?" ":"");
	printf("%s","\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 990);
	printTank(tank);
	tankPush(tank, 100);
	printTank(tank);
	tankPush(tank, 10);
	printTank(tank);
	tankPop(tank);
	printTank(tank);
	tankPop(tank);
	tankPop(tank);
	printTank(tank);
	tankPop(tank);
	printTank(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
