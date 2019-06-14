#include "header.h"

/*
struct s_elem {
    int energy;
    struct s_elem *next;
};

struct s_stack {
    struct s_elem *elem;
    int sum;
};

struct s_tank {
    struct s_stack **stacks;
    int n;
};
*/

struct s_tank *initTank(void) {
	struct s_tank *out = 0;
	if ((out = malloc(sizeof(struct s_tank)))) {
		*out = (struct s_tank){0, 0};
		out->stacks = malloc(sizeof(struct s_stack) * (N + 1));
		for (int i=0; i<N; i++)
			out->stacks[n] = stackInit();
		out->stacks[N] = 0;
	}
	return out;
}

void tankPush(struct s_tank *tank, int energy) {
	int p;

	if (!tank || energy <= 0)
		return;
	for (int s=0; s<N; s++) {
		p = peek(tank->stacks[s]);
		if (p + energy <= 1000) {
			tank->stacks[s].push(p + energy);
			break ;
		}
	}
	if (s < N && s > tank->n)
		tank->n = s;
	// else
	// 	printf("Failed to push onto %d tanks\n", N);
}

int tankPop(struct s_tank *tank) {
	int p;
	if (!tank)
		return 0;
	for (int s=tank->n; s>=0; s--) {
		if (p = peek(tank->stacks[s])) {
			p = pop(tank->stacks[s]);
			if (!peek(tank->stacks[s]))
				n--;
			return p;
		}
		
	}
}
