#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
(&stk)->hash = 0; \
(&stk)->right_canary = 0xDEADBEEF; \
(&stk)->capacity = 0; \
(&stk)->size = 0; \
(&stk)->buf = NULL; \
(&stk) = NULL; \
(&stk)->buf[0] = POISON; \
*/

#ifdef UNIT_TEST
    
    #define TEST_MODE { \
        stack stk = {left_canary, NULL, 0, 0, 0, right_canary}; \
        int start_capacity = 5; \
        stack_construct (&stk, start_capacity); \
        for (int i = 0; i < 30; i++) { \
            stack_push(&stk, i); \
        } \
        DUMP(&stk); \
        for (int j = 0; j < 9; j++) { \
            stack_pop(&stk); \
        } \
        STACK_OK(&stk); \
        DUMP(&stk); \
        stack_distruct(&stk); \
    }

#else
    #define TEST_MODE

#endif