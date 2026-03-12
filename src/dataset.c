#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "hash/hash_api.h"
#include "util/hex.h"
#include "msggen.h"

#define N_MESSAGES 1000
#define MSG_LEN 17

int main(void)
{
    FILE *f;
    int i;
    int j;

    char message[MSG_LEN];
    uint8_t digest[HASH_MAX_DIGEST_SIZE];
    char hex[2 * HASH_MAX_DIGEST_SIZE + 1];

    const hash_algo_t *algos[] = {
        hash_get_sha256(),
        hash_get_sha3_256(),
        hash_get_fnv1a32(),
        hash_get_poly32(),
        hash_get_trunc32()
    };

    int n_algos = sizeof(algos) / sizeof(algos[0]);

    msggen_seed(42);

    f = fopen("dataset.csv", "w");
    if (!f) {
        perror("dataset.csv");
        return 1;
    }

    fprintf(f, "id,message,hash_name,digest\n");

    for (i = 0; i < N_MESSAGES; i++) {

        msggen_random(message, MSG_LEN);

        for (j = 0; j < n_algos; j++) {

            const hash_algo_t *algo = algos[j];

            if (!algo->hash_fn(
                    (const uint8_t *)message,
                    strlen(message),
                    digest))
            {
                fprintf(stderr, "hash error: %s\n", algo->name);
                fclose(f);
                return 1;
            }

            bytes_to_hex(digest, algo->digest_len, hex);

            fprintf(
                f,
                "%d,%s,%s,%s\n",
                i,
                message,
                algo->name,
                hex
            );
        }
    }

    fclose(f);

    printf("dataset.csv created\n");

    return 0;
}

