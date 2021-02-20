#ifndef _STACK_H_
#define _STACK_H_

static int POISON = -2147483648;

// stucture declaration
typedef struct _stack {

    int*  buf;        // pointer to allocated memory 
    int   size;      // count of date in memory
    int   capacity; // capacity of memory

} stack;

static char *ErrorNames[] = {
    "ERROR 1\n"
    "pointer \'stk\' is NULL\n",

    "ERROR 2\n"
    "pointer \'buf\' is NULL\n",

    "ERROR 3\n"
    "size > capacity\n",

    "ERROR 4\n"
    "empty cell of memory hadn't be poisoned\n"

    "ERROR 5\n"
    "cell with date had be poisoned\n"
};
 
enum Errors {
    STK_IS_NULL = 1,
    BUF_IS_NULL,
    OUT_OF_CAPACITY,
    EMPTY_CELL_NOT_POISOEND,
    POISONED_CELL
};

int stack_construct(stack* stk, int Capacity);

int stack_distruct(stack* stk);

int stack_push(stack* stk, int element);

int stack_realloc_up(stack* stk);

int stack_realloc_down(stack* stk);

int stack_pop(stack* stk);

int stack_dump(stack* stk);

int verification(stack* stk);

int stack_control(stack* stk);

#endif /* _STACK_H_ */