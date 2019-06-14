#include "header.h"

struct s_stack	*initStack(void) {
	struct s_stack *out = 0;
	if ((out = malloc(sizeof(struct s_stack))))
		*out = (struct s_stack){0, 0};
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
