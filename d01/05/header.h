#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// Tank
#include <stdlib.h>
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

struct s_tank *initTank(void);

void tankPush(struct s_tank *tank, int energy);

int tankPop(struct s_tank *tank);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/
#define N (int)10

struct s_stack  *initStack(void);
int       pop(struct s_stack *stack);
void      push(struct s_stack *stack, int idx);
int       peek(struct s_stack *stack);

#endif
