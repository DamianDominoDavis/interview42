#include "header.h"

static void sueMe(struct s_node *lst) {
	if (lst) {
		if (lst->next) {
			sueMe(lst->next);
			printf("%s", " ");
		}
		printf("%s", lst->word);
	}
}

void printReverse(struct s_node *lst) {
	if (lst) {
		sueMe(lst);
		printf("%s", "\n");
	}
}
