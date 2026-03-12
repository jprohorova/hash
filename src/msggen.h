#ifndef MSGGEN_H
#define MSGGEN_H

#include <stddef.h>

void msggen_seed(unsigned int seed);
void msggen_random(char *str, size_t len);

#endif


