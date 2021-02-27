//ГОВНОКОДГОВНОКОДГОВНОКОД
//ГОВНОКОДГОВНОКОДГОВНОКОД
//ГОВНОКОДГОВНОКОДГОВНОКОД

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {

    FILE* log_txt = fopen("log.txt", "ab");
    assert(log_txt != NULL);

    stack stk = {left_canary, NULL, 0, 0, right_canary};

    stack_construct (&stk, 5, log_txt);

    int select_act = 0;
    int push = 0;
    int pop = 0;

    START_WORK(stk, select_act, push, pop, log_txt);

    stack_distruct(&stk);

    fclose(log_txt);

    return 0;
}