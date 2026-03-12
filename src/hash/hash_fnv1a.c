#include "hash_api.h"

int hash_fnv1a32(const uint8_t *msg, size_t msg_len, uint8_t *out)
{
    uint32_t hash = 2166136261u;
    uint32_t prime = 16777619u;
    size_t i;

    if (msg == NULL || out == NULL) return 0;

    for (i = 0; i < msg_len; i++) {
        hash ^= msg[i];
        hash *= prime;
    }

    out[0] = (uint8_t)((hash >> 24) & 0xFF);
    out[1] = (uint8_t)((hash >> 16) & 0xFF);
    out[2] = (uint8_t)((hash >> 8) & 0xFF);
    out[3] = (uint8_t)(hash & 0xFF);

    return 1;
}

static const hash_algo_t fnv1a32_algo = {"fnv1a32", 4, hash_fnv1a32};

const hash_algo_t *hash_get_fnv1a32(void) {
    return &fnv1a32_algo;
}
