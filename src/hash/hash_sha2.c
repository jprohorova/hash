#include "hash_api.h"
#include <openssl/evp.h>

int hash_sha256(const uint8_t *msg, size_t msg_len, uint8_t *out)
{
    EVP_MD_CTX *ctx = NULL;
    unsigned int out_len = 0;
    int ok = 0;

    if (msg == NULL || out == NULL)
        return 0;

    ctx = EVP_MD_CTX_new();
    if (ctx == NULL)
        return 0;

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1)
        goto end;

    if (EVP_DigestUpdate(ctx, msg, msg_len) != 1)
        goto end;

    if (EVP_DigestFinal_ex(ctx, out, &out_len) != 1)
        goto end;

    if (out_len != 32)
        goto end;

    ok = 1;

end:
    EVP_MD_CTX_free(ctx);
    return ok;
}

static const hash_algo_t sha256_algo = {
    "sha256",
    32,
    hash_sha256
};

const hash_algo_t *hash_get_sha256(void)
{
    return &sha256_algo;
}

