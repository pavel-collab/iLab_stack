#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int stack_construct(stack* stk, int capacity) {

    stk->buf = (int*) calloc(capacity, sizeof(int));

    //! checking stack validity
    verification(stk);

    stk->size = 0;
    stk->capacity = capacity;

    for (int i = 0; i < capacity; i++) {
        stk->buf[i] = POISON;
    }

    //! checking stack validity
    verification(stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_distruct(stack* stk) {

    //! checking stack validity
    verification(stk);

    free(stk->buf);
    stk->buf = NULL;

    stk = NULL;

    printf("SUCCESSFUL STACK REMOVAL\n");

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_push(stack* stk, int element) {

    //! checking stack validity
    verification(stk);

    if (stk->size < stk->capacity) {

        stk->buf[stk->size] = element;
        stk->size++;
    }
    else {
        realloc(stk->buf, ((stk->capacity) * 2) * sizeof(int));

        //! checking stack validity
        verification(stk);

        stk->capacity = ((stk->capacity)*2);

        //! fill expanded memory with POISON value
        for (int i = stk->size; i < stk->capacity; i++) {
            stk->buf[i] = POISON;
        }

        stk->buf[stk->size] = element;
        stk->size++;
    }

    //??? реаллок сам возвращает указатель на новое место в памяти, зачем мне его перезаписывать вручную?

    //! checking stack validity
    verification(stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_pop(stack* stk) {

    //! checking stack validity
        verification(stk);

    if (stk->size != 0) {

        int box = stk->buf[--stk->size];

        stk->buf[stk->size] = POISON;

        return box;
    }
    else {
        printf("ERROR, STECK IS EMPTY\n");
        return POISON;
    }

    //! checking stack validity
    verification(stk);

}

//--------------------------------------------------------------------------------------------

int stack_dump(stack* stk) {

    printf("START OF PRINTOUT\n\n");

    //! checking stack validity
    verification(stk);

    printf("simple_stack (OK) [%x]\n", stk);
    printf("{\n");
    printf("size = %d\n", stk->size);
    printf("capacity = %d\n", stk->capacity);
    printf("buf [%x]\n", stk->buf);
    printf("\t{\n");
    for (int i = 0; i < stk->capacity; i++) {
        if (i <= stk->size - 1) {
            printf("\t* [%d] : %d\n", i, stk->buf[i]);
        }
        else {
            printf("\t  [%d] : %d ~~ POISON\n", i, stk->buf[i]);
        }
    }
    printf("\t}\n");
    printf("}\n");
    printf("END OF PRINTOUT\n");

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_control(stack* stk) {

    if (stk == NULL)
        return 1;

    if (stk->buf == NULL)
        return 2;

    if (stk->size > stk->capacity)
        return 3;

    for (int i = stk->size; i < stk->capacity; i++) {
        if (stk->buf[i] != POISON)
            return 4; 
    }

}

//verification
int verification(stack* stk) {

    switch (stack_control(stk)) {
        case 1:
            printf(ErrorNames[STK_IS_NULL-1]);
            exit(STK_IS_NULL);
            break;
        case 2:
            printf(ErrorNames[BUF_IS_NULL-1]);
            exit(BUF_IS_NULL);
            break;
        case 3:
            printf(ErrorNames[OUT_OF_CAPACITY-1]);
            exit(OUT_OF_CAPACITY);
            break;
        case 4:
            printf(ErrorNames[EMPTY_CELL_NOT_POISOEND-1]);
            exit(EMPTY_CELL_NOT_POISOEND);
            break;
        default:
            printf("NO ERRORS!!!\n");
    }

    return 0;

}

