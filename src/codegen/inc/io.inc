// console input/output implementation
// Copyright (c) 2023-2025, Joseph Shimel and contributors.

#ifndef ORANGE_CORE_IO_INC
#define ORANGE_CORE_IO_INC

#include <stdio.h>

static inline void orange__core__write(void *self, struct orange_type_73877515D86B0F5 bytes)
{
    (void)self;

    if (bytes._0 != NULL && bytes._1 > 0)
    {
        fwrite(bytes._0, 1, bytes._1, stdout);
        fflush(stdout);
    }
}

static inline void orange__core__read(void *self, struct orange_type_384D608F76C1F2D2 /*&mut dyn identifier("core")::Writer*/ writer)
{
    (void)self;
    unsigned char buffer[1024];

    while (1)
    {
        size_t n = fread(buffer, 1, sizeof(buffer), stdin);
        if (n == 0)
        {
            break;
        }
        struct orange_type_73877515D86B0F5 slice = {._0 = buffer, ._1 = n};
        writer.vtable->write(writer.data_ptr, slice);
    }
}

const struct vtable_core__core__0_Writer orange__core__writer_vtable = {
    .write = orange__core__write,
};

const struct vtable_core__core__0_Reader orange__core__reader_vtable = {
    .read = orange__core__read,
};

#endif
