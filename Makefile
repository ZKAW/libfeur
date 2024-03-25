CC := gcc
CFLAGS := -Wall -fPIC
LDFLAGS := -shared

SRC := src/libfeur.c
LIB := libfeur.so

all: $(LIB)

$(LIB): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(LIB)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean
