# Readme
1. Use the command "git clone https://github.com/pavel-collab/iLab_stack.git" to pop this repository to your computer.
2. Open the command line in the folder with cloned repository.
3. Use the command "make all" to compile the project.
4. Launch of program:    
    + use the command "./stack protected" to launch stack with protection
    + use the command "./stack no_protected" to launch stack without protection

# Instruction to code edition
There are two modes of stack working:
    - simple menu mode
    - unit_test mode    

If you want to use the first one, open stack.h and comment out the 9th line:    
```C
#define UNIT_TEST
```
```C
//#define UNIT_TEST
```
If you want to use the second mode open stack.h and uncomment this line.

## UNIT_TEST
If you use unit_test mode, the program automatically constructs simple stack, fills it, does some pop, does check, dump and distruct.   
You can change the params of this actions in file unit_test.h   
You can also try to add some mucks to the TEST_MODE, such as:
- (&stk)->hash = 0; \
- (&stk)->right_canary = 0xDEADBEEF; \
- (&stk)->capacity = 0; \
- (&stk)->size = 0; \
- (&stk)->buf = NULL; \
- (&stk) = NULL; \
- (&stk)->buf[0] = POISON; \

All of these actions will lead to error in the program; it will help you to check how the program deals with unusual situation.
# Special for Stas
TODO list 10.02.2021:
- изменил abort() на exit(-1) (stack.h : 101, 112)
- сделал 2 варианта реализации включения защиты спомощью аргументов командной строки; первый вариант в ветке solution_1, второй вариант в ветке solution_2  
    + первое решение заключается в том, что я добавляю файл make.cpp аргументы командной строки передаю туда, а затем, спомощью функции system() выбираю, как и какие файлы компилировать и запускать
