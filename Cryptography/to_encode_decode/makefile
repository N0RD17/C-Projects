# Compiler
CC = g++

CFLAGS = -Wall -Wextra -pedantic -g

LDFLAGS = -lcrypto -lssl

bio_b64_encode: encode_object
	${CC} ${LDFLAGS} bio_b64_encode.o -o bio_b64_encode
encode_object: bio_b64_encode.cpp
	${CC} ${}bio_b64_encode.cpp -c

bio_b64_object: decoded_object
	${CC} ${LDFLAGS} bio_b64_decoded.o -o bio_b64_decoded
decoded_object: bio_b64_decoded.cpp
	${CC} ${CFLAGS} bio_b64_decoded.cpp -c


clean:
	rm -f *.o bio_b64_encode bio_b64_decoded

