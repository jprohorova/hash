#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "../src/hash/hash_api.h"
#include "../src/util/hex.h"

int main(void)
{
    const char *msg = "hello";
    uint8_t digest[HASH_SHA3_256_DIGEST_SIZE];
    char hex[2 * HASH_SHA3_256_DIGEST_SIZE + 1];

    if (!hash_sha3_256((const uint8_t *)msg, strlen(msg), digest)) {
        fprintf(stderr, "hash_sha3_256 failed\n");
        return 1;
    }

    bytes_to_hex(digest, HASH_SHA3_256_DIGEST_SIZE, hex);

    printf("message: %s\n", msg);
    printf("sha3_256: %s\n", hex);

    return 0;
}


