#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int stack_construct(stack* stk, int capacity, FILE* log_txt) {

    //! temprorary solution
    if ((stk != NULL) && ((stk->buf) != NULL)) {

        //* checking stack validity
        verification(stk);

        printf("this stack was already construct\n");
        stack_dump(stk, log_txt);

        //* checking stack validity
        verification(stk);

        return 0;
        
    }

    //! если вдруг пользователь захочет создать пустой стек емкостью 0
    if (capacity == 0) {
        stk->buf = NULL;
        stk->size = 0;
        stk->capacity = 0;
        return 0;
    }
    else
        stk->buf = (int*) calloc(capacity, sizeof(int));

    //* checking stack validity
    /*params 'size' and 'capacity' was not declared still
      so, program checking just 'stk' and 'stk->buf' at this place*/
    if (stk == NULL) {
        printf(ErrorNames[STK_IS_NULL-1]);
        exit(STK_IS_NULL);
    }
    else if (stk->buf == NULL) {
        printf(ErrorNames[BUF_IS_NULL-1]);
        exit(BUF_IS_NULL);
    }

    stk->size = 0;
    stk->capacity = capacity;

    for (int i = 0; i < capacity; i++) {
        stk->buf[i] = POISON;
    }

    //* checking stack validity
    verification(stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_distruct(stack* stk) {

    //if stack was already distructed
    if (stk == NULL) {
        printf("This stack was already distructed.\n");
        return 0;
    }

    //* checking stack validity
    STACK_OK (stk);

    free(stk->buf);
    stk->buf = NULL;

    stk = NULL;

    printf("SUCCESSFUL STACK REMOVAL\n");

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_realloc_up(stack* stk) {

    //* checking stack validity
    STACK_OK (stk);

    //? create local variabe
    void* local_arrow = realloc(stk->buf, ((stk->capacity) * 2) * sizeof(int));

    //? if the local return NULL, there is fail --> abort the program
    if (local_arrow == NULL) {
        printf("REALLOCATION FAILED!\n\n");
        return 0;
    }
    else {
        stk->buf = (int*) local_arrow;
    }

    //* checking stack validity
    STACK_OK (stk);

    stk->capacity = ((stk->capacity)*2);

    //* fill expanded memory with POISON value
    for (int i = stk->size; i < stk->capacity; i++) {
        stk->buf[i] = POISON;
    }

    //* checking stack validity
    STACK_OK (stk);

    return 0;
}

//--------------------------------------------------------------------------------------------

int stack_realloc_down(stack* stk) {

    //* checking stack validity
    STACK_OK (stk);

    void* local_arrow = realloc(stk->buf, ((stk->capacity) / 2) * sizeof(int));

    //? if the local return NULL, there is fail --> abort the program
    if (local_arrow == NULL) {
        printf("REALLOCATION FAILED!\n\n");
        return 0;
    }
    else {
        stk->buf = (int*) local_arrow;
    }

    //* checking stack validity
    STACK_OK (stk);

    stk->capacity = ((stk->capacity)/2);

    //* checking stack validity
    STACK_OK (stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_push(stack* stk, int element) {

    //* checking stack validity
    STACK_OK (stk);

    if (stk->size < stk->capacity) {

        stk->buf[stk->size] = element;
        stk->size++;
    }
    else {

        stack_realloc_up(stk);

        stk->buf[stk->size] = element;
        stk->size++;
    }

    //* checking stack validity
    STACK_OK (stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_pop(stack* stk) {

    //* checking stack validity
    STACK_OK (stk);

    if (stk->size == 0) {
        printf("ERROR, STECK IS EMPTY\n");
        return POISON;
    }

    int box = POISON;
    box = stk->buf[--stk->size];
    stk->buf[stk->size] = POISON;


    if (stk->capacity >= (stk->size)*4)
        stack_realloc_down(stk);

    //* checking stack validity
    STACK_OK (stk);

    return box;

}

//--------------------------------------------------------------------------------------------

int stack_dump(stack* stk, FILE* log_txt) {

    fprintf(log_txt, "##################################################\n\n");
    fprintf(log_txt, "START OF PRINTOUT\n\n");

    //* checking stack validity
    STACK_OK (stk);

    fprintf(log_txt, "simple_stack (OK) [%x]\n", stk);
    fprintf(log_txt, "{\n\n");

    fprintf(log_txt, "LEFT CANARY (%X)\n\n", stk->left_canary);

    fprintf(log_txt, "size = %d\n", stk->size);
    fprintf(log_txt, "capacity = %d\n", stk->capacity);
    fprintf(log_txt, "buf [%x]\n", stk->buf);
    fprintf(log_txt, "\t{\n");
    for (int i = 0; i < stk->capacity; i++) {
        if (i <= stk->size - 1) {
            fprintf(log_txt, "\t* [%d] : %d\n", i, stk->buf[i]);
        }
        else {
            fprintf(log_txt, "\t  [%d] : %d ~~ POISON\n", i, stk->buf[i]);
        }
    }
    fprintf(log_txt, "\t}\n\n");

    fprintf(log_txt, "RIGHT CANARY (%X)\n\n", stk->right_canary);

    fprintf(log_txt, "}\n");
    fprintf(log_txt, "END OF PRINTOUT\n");
    fprintf(log_txt, "##################################################\n\n");

    //* checking stack validity
    STACK_OK (stk);

    return 0;

}

//--------------------------------------------------------------------------------------------

int stack_control(stack* stk) {

    if (stk->left_canary != left_canary) 
        return 5;

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

    if (stk->right_canary != right_canary)
        return 6;

}

//--------------------------------------------------------------------------------------------

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
        case 5:
            printf(ErrorNames[FAIL_LEFT_CANARY-1]);
            exit(FAIL_LEFT_CANARY);
            break;
        case 6:
            printf(ErrorNames[FAIL_RIGHT_CANARY-1]);
            exit(FAIL_RIGHT_CANARY);
            break;
        default:
            printf("NO ERRORS!!!\n\n");
            return 0;
    }

}

//--------------------------------------------------------------------------------------------

void stack_work (stack* stk, int select_act, int element, int pop, FILE* log_txt) {
    printf("Enter number to select an action.\n\n"); 

    printf("0 - Exit.\n\n"); 
    printf("1 - Push, put the element to the stack.\n\n"); 
    printf("2 - Pop, take the element from the stack.\n\n"); 
    printf("3 - Dump, get information about stack condition.\n\n"); 
    printf("4 - Verification, immediate stack checking\n\n"); 

    while (1) { 

        printf("put number to select an action: "); 
        scanf("%d", &select_act); 

        switch (select_act) { 
            case 0: 
                printf("completion of working.\n"); 
                return; 
            case 1: 
                printf("input the element to stack_push: "); 
                scanf("%d", &element); 
    
                if (stack_push(stk, element) == 0) { 
                    printf("push compleated successful.\n"); 
                    break; 
                } 
                else { 
                    printf("Error with push.\n"); 
                    break; 
                } 
            case 2: 
                pop = stack_pop(stk); 
                if (pop != POISON) { 
                    printf("output element = %d\n", pop); 
                    break; 
                } 
                else { 
                    printf("Error with pop.\n"); 
                    break; 
                } 
            case 3: 
                if (stack_dump(stk, log_txt) == 0) { 
                    printf("dump compleated successful; look throught log.txt\n"); 
                    break; 
                } 
                else { 
                    printf("Error with dump\n"); 
                    break; 
                } 
            case 4: 
                verification(stk); 
                break; 
            default: 
                printf("Error, no number to action, try again.\n"); 
            } 
        }
}