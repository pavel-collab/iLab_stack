//ГОВНОКОДГОВНОКОДГОВНОКОД
//ГОВНОКОДГОВНОКОДГОВНОКОД
//ГОВНОКОДГОВНОКОДГОВНОКОД

// TODO:
// chancge "loud" vereficator
// solve problem with EOF in vs code 
// download TXlib
// slack_dump(stack* stk, const char* message);

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {

    stack simple_stack = {NULL, 0, 0};

    stack_construct (&simple_stack, 5);

    int element = 0;

    //! режим тестирования
    printf("test mode\n"
            "input data:\n");
    while (scanf("%d", &element) == 1) {
        stack_push(&simple_stack, element);
    }

    int last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);
    last = stack_pop(&simple_stack);

    printf("last element in stack is %d\n", last);

    stack_dump(&simple_stack);

    stack_distruct(&simple_stack);

    return 0;
}