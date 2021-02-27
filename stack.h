#include <stdio.h>
#include <stdlib.h>

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
    "empty cell of memory hadn't be poisoned\n"

    "ERROR 5\n"
    "destroided left canary\n"

    "ERROR 5\n"
    "destroided right canary\n"
};
 
enum Errors {
    STK_IS_NULL = 1,
    BUF_IS_NULL,
    OUT_OF_CAPACITY,
    EMPTY_CELL_NOT_POISOEND,
    FAIL_LEFT_CANARY,
    FAIL_RIGHT_CANARY
};

int stack_construct(stack* stk, int Capacity, FILE* log_txt);

int stack_distruct(stack* stk);

int stack_push(stack* stk, int element);

int stack_realloc_up(stack* stk);

int stack_realloc_down(stack* stk);

int stack_pop(stack* stk);

int stack_dump(stack* stk, FILE* log_txt);

int verification(stack* stk);

int stack_control(stack* stk);


#ifdef DEBUG_MODE

#define STACK_OK \
    verification(stk); \

#else

    #define STACK_OK

#endif

#ifdef STACK_MODE
    #define START_WORK \
        printf("Enter number to select an action.\n\n"); \
        printf("0 - Exit.\n\n"); \
        printf("1 - Push, put the element to the stack.\n\n"); \
        printf("2 - Pop, take the element from the stack.\n\n"); \
        printf("3 - Dump, get information about stack condition.\n\n"); \
        printf("4 - Verification, immediate stack checking\n\n"); \
        while (1) { \
            printf("put number to select an action: "); \
            scanf("%d", &select_act); \
            switch (select_act) { \
                case 0: \
                    printf("completion of working.\n"); \
                    return 0; \
                case 1: \
                    printf("input the element to stack_push: "); \
                    scanf("%d", &element); \
                    \
                    if (stack_push(&stk, element) == 0) { \
                        printf("push compleated successful.\n"); \
                        break; \
                    } \
                    else { \
                        printf("Error with push.\n"); \
                        break; \
                    } \
                case 2: \
                    pop = stack_pop(&stk); \
                    if (pop != POISON) { \
                        printf("output element = %d", pop); \
                        break; \
                    } \
                    else { \
                        printf("Error with pop.\n"); \
                        break; \
                    } \
                case 3: \
                    if (stack_dump(&stk, log_txt) == 0) { \
                        printf("dump compleated successful; look throught log.txt\n"); \
                        break; \
                    } \
                    else { \
                        printf("Error with dump\n"); \
                        break; \
                    } \
                case 4: \
                    verification(&stk); \
                    break; \
                default: \
                    printf("Error, no number to action, try again.\n"); \
            } \
        }
#else
#endif
// TODO 
// 
#endif /* _STACK_H_ */