#include "header.h"

static struct s_node	*gear(char val, struct s_node *prev) {
	struct s_node	*ret = 0;

	if ((ret = malloc(sizeof(struct s_node))))
		*ret = (struct s_node){val, prev, 0};
	return (ret);
}

static struct s_node	*machine(void) {
	struct s_node *hold = 0;
	struct s_node *handle;

	if (!hold) {
		hold = handle = gear(CS[0], 0);
		for (int i=1; CS[i]; i++)
			handle = handle->next = gear(CS[i], handle);
		handle->next = hold;
		hold->prev = handle;
	}
	return (hold);
}

static void			destroy(struct s_node *m) {
	if (m) {
		m->prev->next = 0;
		while (m->next) {
			m = m->next;
			free(m->prev);
		}
		free(m);
		m = 0;
	}
}

char				*precious(int *text, int size) {
	char	*ret = 0;
	struct s_node	*m;

	if (size > 0 && (ret = (char*)malloc(sizeof(char) * (size + 1)))) {
		ret[size] = 0;
		m = machine();
		for (int i=0; i<size; i++) {
			while (text[i] > 0) {
				m = m->next;
				text[i]--;
			}
			while (text[i] < 0) {
				m = m->prev;
				text[i]++;
			}
			ret[i] = m->c;
		}
		destroy(m);
	}
	return (ret);
}
