# Readme
1. Use the command "git clone https://github.com/pavel-collab/iLab_stack.git" to pop this repository to your computer.
2. Open the command line in the folder with cloned repository.
3. Use the command "make all" to compile the project.
4. Use the command "./stack" or "./stack.exe" to start.

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
___
You can switch off the protecting. In this case program will do less check and won't print thousant of messages to the consol.  
If you want to switch off protecting mode open stack.h and comment out the 8th line:
```C
#define DEBUG_MODE
```
```C
//#define DEBUG_MODE
```
If you want to switch on this mode, uncomment this line.

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
TODO list:
- убрал в stack_control "странные цифры", заменил их на имена констант (stack.c : 247)
- проверяю scanf в функции stack_work спомощью условий if (stack.c : 322)
- переделал макрос STACK_OK, теперь при возникновении ошибки программа делает дамп в лог файл и абортится (stack.h : 84), но почему-то при этом программа сначала делает дамп в log, а только потом пишет тип ошибки, файл и строку, хотя в коде порядок нормальный (stack.h : 100)
- сделал функцию хэщирования данных (stack.c : 154), добавил hash в структуру stack (stack.h : 25)
- так же пересчитываю хэш при добавлении - удалении элемента и делаю проверку хэша в STACK_OK (stack.h : 107, stack.c : 305)
- сделал файл с юниттестом, сделал для него отдельный макрос, 
- теперь можно переключаться с режима ручного ввода на режим тестирования
- слелал Readme.md
