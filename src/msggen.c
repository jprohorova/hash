#include "msggen.h"
#include <stdlib.h>

char random_char(int index) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[index];
}

void msggen_seed(unsigned int seed) {
    srand(seed);
}

void msggen_random(char *str, size_t len) {
    int i;
    int index;

    if (str == NULL || len == 0)
        return;

    for (i = 0; i < (int)len - 1; i++) {
        index = rand() % 62;
        str[i] = random_char(index);
    }

    str[i] = '\0';
}

