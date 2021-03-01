#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _STACK_H_
#define _STACK_H_

#define DEBUG_MODE
#define STACK_MODE

static const int POISON = -2147483648;

static const unsigned long long left_canary = 0xDEADBEEF;
static const unsigned long long right_canary = 0xBADDCAFE;

// stucture declaration
typedef struct _stack {

    unsigned long long left_canary;

    int*  buf;        // pointer to allocated memory 
    int   size;       // count of date in memory
    int   capacity;   // capacity of memory

    unsigned long long right_canary;

} stack;

static char *ErrorNames[] = {
    "ERROR 1\n"
    "pointer \'stk\' is NULL\n",

    "ERROR 2\n"
    "pointer \'buf\' is nullptr\n",

    "ERROR 3\n"
    "size > capacity\n",

    "ERROR 4\n"
    "empty cell of memory hadn't be poisoned\n",

    "ERROR 5\n"
    "destroided left canary\n",

    "ERROR 5\n"
    "destroided right canary\n",

    "ERROR 6\n"
    "cell with data is poisoned\n"
};
 
enum Errors {
    STK_IS_NULL = 1,
    BUF_IS_NULL,
    OUT_OF_CAPACITY,
    EMPTY_CELL_NOT_POISOEND,
    FAIL_LEFT_CANARY,
    FAIL_RIGHT_CANARY,
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

void stack_work(stack* stk, int select_act, int element, int pop);

//*--------------------------------------------------------------------

#ifdef DEBUG_MODE

    #define STACK_OK(stk) \
        verification(stk); 
#else
    #define STACK_OK
#endif

//*--------------------------------------------------------------------

#define DUMP(stack_name) \
    stack_dump((stack_name));

//*--------------------------------------------------------------------

#ifdef STACK_MODE
    #define STACK_WORK(stack_name, select_act, push, pop) \
        stack_work(&(stack_name), (select_act), (push), (pop));
        
#else
    #define STACK_WORK
#endif

//*--------------------------------------------------------------------

#endif /* _STACK_H_ */