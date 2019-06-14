#include "header.h"
/*
struct s_item {
	int idx;
	struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};
*/

struct s_stack	*initStack(void) {
	struct s_stack *out = malloc(sizeof(struct s_stack));
	if (out)
		out->item = 0;
	return out;
}

int				pop(struct s_stack *stack) {
	struct s_item *i = NULL;
	int x = 0;

	if (stack && stack->item) {
		i = stack->item;
		x = i->idx;
		stack->item = stack->item->next;
		free(i);
	}
	return (x);
}

void			push(struct s_stack *stack, int idx) {
	struct s_item *i;

	if (stack && (i = malloc(sizeof(struct s_item)))) {
		*i = (struct s_item){idx, stack->item};
		stack->item = i;
	}
}

static char* take(char *input) {
	printf("%s ", PROMPT);
	fgets(input, MLEN, stdin);
	input[strlen(input) - 1] = 0;
	return (input);
}

char *console(void) {
	struct s_stack	*stack = initStack();
	char			*input = (char*)malloc(sizeof(char) * (MLEN + 1));
	char			msg[BLEN] = {0};
	int				len = 0;
	
	while (strcmp(take(input), "SEND")) {
		if (!strcmp(input, "UNDO")) {
			if (stack->item)
				len = pop(stack);
			bzero(msg + len, BLEN - len);
		}
		else {
			push(stack, len);
			memmove(msg + len, input, strlen(input));
			len += strlen(input);
		}
		printf("%s\n\n", msg);
	}
	return (strdup(msg));
}
