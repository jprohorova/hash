#include "hex.h"
#include <stdio.h>

void bytes_to_hex(const uint8_t *bytes, size_t len, char *hex)
{
    size_t i = 0;

    for (i = 0; i < len; i++) {
        sprintf(hex + 2 * i, "%02x", bytes[i]);
    }

    hex[2 * len] = '\0';
}
