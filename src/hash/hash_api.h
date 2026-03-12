#ifndef HASH_API_H
#define HASH_API_H

#include <stddef.h>
#include <stdint.h>

#define HASH_MAX_DIGEST_SIZE 64

#define HASH_SHA256_DIGEST_SIZE 32
#define HASH_SHA3_256_DIGEST_SIZE 32
#define HASH_FNV1A32_DIGEST_SIZE 4
#define HASH_POLY32_DIGEST_SIZE 4
#define HASH_TRUNC32_DIGEST_SIZE 4

typedef struct {
    const char *name;
    size_t digest_len;
    int (*hash_fn)(const uint8_t *msg, size_t msg_len, uint8_t *out);
} hash_algo_t;

int hash_sha256(const uint8_t *msg, size_t msg_len, uint8_t *out);
int hash_sha3_256(const uint8_t *msg, size_t msg_len, uint8_t *out);
int hash_fnv1a32(const uint8_t *msg, size_t msg_len, uint8_t *out);
int hash_poly32(const uint8_t *msg, size_t msg_len, uint8_t *out);
int hash_trunc32(const uint8_t *msg, size_t msg_len, uint8_t *out);

const hash_algo_t *hash_get_sha256(void);
const hash_algo_t *hash_get_sha3_256(void);
const hash_algo_t *hash_get_fnv1a32(void);
const hash_algo_t *hash_get_poly32(void);
const hash_algo_t *hash_get_trunc32(void);

#endif

