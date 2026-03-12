#include "hash_api.h"

int hash_trunc32(const uint8_t *msg, size_t msg_len, uint8_t *out) {
    uint8_t full_digest[HASH_SHA256_DIGEST_SIZE];
    size_t i;

    if (msg == NULL || out == NULL) return 0;
    if (!hash_sha256(msg, msg_len, full_digest)) return 0;
    for (i = 0; i < 4; i++) {
        out[i] = full_digest[i];
    }

    return 1;
}

static const hash_algo_t trunc32_algo = {"trunc32", 4, hash_trunc32};

const hash_algo_t *hash_get_trunc32(void) {
    return &trunc32_algo;
}

