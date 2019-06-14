#include "header.h"

// struct s_city {
// 	char *name;
// 	struct s_city *next;
// };

char *NthLastCity(struct s_city *city, int n) {
	struct s_city *s;

	for (s = city; n > 0; n--)
		if (!s)
			return 0;
		else
			s = s->next;
	while (s->next) {
		s = s->next;
		city = city->next;
	}
	return city->name;
}
