#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("ERROR, expected more arguments!\n");
        return -1;
    }
    else if (!strcmp(argv[1], "protected")) {

        system("gcc -c -D DEBUG_MODE lib.c");
        system("gcc -c main.c");
        system("gcc -o main main.o lib.o\n");

    }
    else if (!strcmp(argv[1], "no_protected")) {

        system("gcc -c lib.c");
        system("gcc -c main.c");
        system("gcc -o main main.o lib.o");

    }
    else {
        printf("ERROR, expected another argument\n");
        return -1;
    }

    system("main.exe");

    return 0;

}