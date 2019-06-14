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
			out->stacks[i] = initStack();
		out->stacks[N] = 0;
	}
	return out;
}

void tankPush(struct s_tank *tank, int energy) {
	int p;

	if (!tank || energy <= 0)
		return;
	for (int s=tank->n; s<N; s++) {
		p = peek(tank->stacks[s]);
		if (p + energy <= 1000) {
			push(tank->stacks[s], p + energy);
			if (s > tank->n)
				tank->n = s;
			return ;
		}
	}
	// 	printf("Failed to push onto %d tanks\n", N);
}

int tankPop(struct s_tank *tank) {
	int p = 0;
	if (tank)
		for (int s=tank->n; s>=0; s--)
			if ((p = peek(tank->stacks[s]))) {
				pop(tank->stacks[s]);
				if (!peek(tank->stacks[s]))
					tank->n--;
				return p;
			}
	return (p);
}
