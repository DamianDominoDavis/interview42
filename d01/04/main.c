#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	char *word, *txt[] = {"Literal", "hardcoded", "strings,", "coded", "strings,", "coded", "strings...", 0};
	struct s_queue *q = queueInit();

	for (int i=0; txt[i]; i++)
		enqueue(q, txt[i]);
	while ((word = dequeue(q)))
		printf("%s%s", word, peek(q)?" ":"");
	printf("%s", "\n");
	return (0);
}



// Function used for the test
// Don't go further :)

