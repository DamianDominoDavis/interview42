#include "header.h"

struct s_stack	*stackInit(void) {
	struct s_stack *out = malloc(sizeof(struct s_stack));
	if (out)
		out->item = NULL;
	return out;
}

void			*pop(struct s_stack *stack) {
	struct s_item *i = NULL;
	char *w = NULL;

	if (stack && stack->item) {
		i = stack->item;
		w = i->word;
		stack->item = stack->item->next;
		free(i);
	}
	return (w);
}

void			push(struct s_stack *stack, char *word) {
	struct s_item *n;

	if (stack && (n = malloc(sizeof(struct s_item)))) {
		*n = (struct s_item){word, stack->item};
		stack->item = n;
	}
}

void			printReverseV2(struct s_node *lst) {
	struct s_stack *s = stackInit();
	char *w;

	while (lst) {
		push(s, lst->word);
		lst = lst->next;
	}
	while ((w = pop(s))) {
		printf("%s", w);
		if (s->item)
			printf("%s", " ");
	}
	printf("%s", "\n");
}
