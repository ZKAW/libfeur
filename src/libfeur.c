#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* malloc(size_t size) {
    write(2, "FEUR\n", 5);
    void* (*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
    return libc_malloc(size);
}
