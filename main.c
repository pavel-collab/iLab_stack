// TODO: убрал в stack_control "странные цифры", заменил их на имена констант (stack.c : 247)
// TODO: проверяю scanf в функции stack_work спомощью условий if (stack.c : 322)
// TODO: вроде как сделал вызов дампа при нахождении ошибок;
//* по всей видимости у меня не определен макрос __FUNCTION__, поэтому пришлось обойтись __FILE__ и __LINE__
//* хорошо бы кончено протестировать, как эти ошибки работают

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {

    //FILE* log_txt = fopen("log.txt", "ab");
    //assert(log_txt != NULL);

    stack stk = {left_canary, NULL, 0, 0, right_canary};

    stack_construct (&stk, 5);

    int select_act = 0;
    int push = 0;
    int pop = 0;

    STACK_WORK(stk, select_act, push, pop);

    stack_distruct(&stk);

    //fclose(log_txt);

    return 0;
}