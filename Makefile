CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -I/opt/homebrew/opt/openssl/include
LDFLAGS = -L/opt/homebrew/opt/openssl/lib -lcrypto

SRC_HASH = \
	src/hash/hash_sha2.c \
	src/hash/hash_sha3_256.c \
	src/hash/hash_fnv1a.c \
	src/hash/hash_poly.c \
	src/hash/hash_trunc.c

SRC_UTIL = \
	src/util/hex.c

SRC_MSG = \
	src/msggen.c

dataset: src/dataset.c $(SRC_HASH) $(SRC_UTIL) $(SRC_MSG)
	$(CC) $(CFLAGS) src/dataset.c $(SRC_HASH) $(SRC_UTIL) $(SRC_MSG) -o dataset $(LDFLAGS)

test_sha3: tests/test_sha3.c src/hash/hash_sha2.c src/hash/hash_sha3_256.c src/util/hex.c
	$(CC) $(CFLAGS) tests/test_sha3.c src/hash/hash_sha2.c src/hash/hash_sha3_256.c src/util/hex.c -o test_sha3 $(LDFLAGS)

clean:
	rm -f test_sha3 *.csv
