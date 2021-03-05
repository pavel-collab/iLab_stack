// TODO: убрал в stack_control "странные цифры", заменил их на имена констант (stack.c : 247)
// TODO: проверяю scanf в функции stack_work спомощью условий if (stack.c : 322)
// TODO: переделал макрос STACK_OK, теперь при возникновении ошибки программа делает дамп в лог файл и абортится (stack.h : 84)
//! почему-то при этом программа сначала делает дамп в log, а только потом пишет тип ошибки, файл и строку, 
//! хотя в коде порядок нормальный (stack.h : 100)
// TODO: сделал функцию хэщирования данных (stack.c : 154), добавил hash в структуру stack (stack.h : 25)
// TODO: так же пересчитываю хэш при добавлении - удалении элемента и делаю проверку хэша в STACK_OK (stack.h : 107, stack.c : 305)

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {

    stack stk = {left_canary, NULL, 0, 0, 0, right_canary};

    stack_construct (&stk, 5);

    int select_act = 0;
    int push = 0;
    int pop = 0;

    STACK_WORK(stk, select_act, push, pop);

    stack_distruct(&stk);

    return 0;
}