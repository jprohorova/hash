#ifndef HEX_H
#define HEX_H

#include <stddef.h>
#include <stdint.h>

void bytes_to_hex(const uint8_t *bytes, size_t len, char *hex);

#endif
