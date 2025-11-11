// console input/output implementation
// Copyright (c) 2023-2025, Joseph Shimel and contributors.

#ifndef ORANGE_CORE_IO_INC
#define ORANGE_CORE_IO_INC

#include <stdio.h>

static inline struct orange_type_C53265BF4F923210 orange__core__write(void *self, struct orange_type_73877515D86B0F5 bytes)
{
    (void)self;

    if (bytes._0 != NULL && bytes._1 > 0)
    {
        size_t written = fwrite(bytes._0, 1, bytes._1, stdout);
        if (written < (size_t)bytes._1)
        {
            if (ferror(stdout))
            {
                clearerr(stdout);
                return (struct orange_type_C53265BF4F923210){.tag = 1};
            }
        }
        fflush(stdout);
    }
    return (struct orange_type_C53265BF4F923210){.tag = 0};
}

static inline struct orange_type_C53265BF4F923210 orange__core__read(void *self, struct orange_type_384D608F76C1F2D2 /*&mut dyn identifier("core")::Writer*/ writer)
{
    (void)self;
    unsigned char buffer[4096];

    while (1)
    {
        size_t n = fread(buffer, 1, sizeof(buffer), stdin);
        if (n == 0)
        {
            if (ferror(stdin))
            {
                clearerr(stdin);
                return (struct orange_type_C53265BF4F923210){.tag = 1};
            }
            break;
        }
        struct orange_type_73877515D86B0F5 slice = {._0 = buffer, ._1 = n};

        struct orange_type_C53265BF4F923210 write_result = writer.vtable->write(writer.data_ptr, slice);
        if (write_result.tag == 1)
        {
            return write_result;
        }
    }

    return (struct orange_type_C53265BF4F923210){.tag = 0};
}

const struct vtable_core__core__0_Writer orange__core__writer_vtable = {
    .write = orange__core__write,
};

const struct vtable_core__core__0_Reader orange__core__reader_vtable = {
    .read = orange__core__read,
};

#endif
