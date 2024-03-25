#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NATIVE_MALLOC 1

void* malloc(size_t size) {
    write(2, "FEUR", 5);
    void* (*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
    if (NATIVE_MALLOC)
        return libc_malloc(size);
    return NULL;
}
