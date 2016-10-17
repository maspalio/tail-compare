LIBTAP_ROOT=../libtap

CFLAGS=-O0 -Wall -I$(LIBTAP_ROOT)
LDFLAGS=$(LIBTAP_ROOT)/libtap.a

all: test

test: test.o tail_compare.o
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<
