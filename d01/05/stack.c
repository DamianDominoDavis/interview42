#include "header.h"

struct s_stack	*initStack(void) {
	struct s_stack *out = 0;
	if ((out = malloc(sizeof(struct s_stack))))
		*out = (struct s_stack){0, 0};
	return out;
}

int				pop(struct s_stack *stack) {
	struct s_elem *e = 0;
	int x = 0;

	if (stack && stack->elem) {
		e = stack->elem;
		x = e->energy;
		stack->elem = stack->elem->next;
		free(e);
	}
	return (x);
}

void			push(struct s_stack *stack, int sum) {
	struct s_elem *i;

	if (stack && (i = malloc(sizeof(struct s_elem)))) {
		*i = (struct s_elem){sum, stack->elem};
		stack->elem = i;
	}
}

int				peek(struct s_stack *stack) {
	return (stack && stack->elem)? stack->elem->energy : 0;
}
