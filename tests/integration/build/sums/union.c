/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        struct1 _1;
        int64_t _2;
        struct1 _3;
    };
} struct0;

/* Interned Strings */
char* string_0 = "\x4C\x6D\x61\x6F\x21";
char* string_1 = "\x6C\x6F\x6C";

/* Function forward definitions */
int64_t _1151_main(void);

/* Function definitions */
int64_t _1151_main(void) {
    int64_t _1151_t0;
    struct0 _1152_x;
    struct1 _1151_t2;
    struct1 _1151_t4;
    int64_t _1151_t6;
    int64_t _1151_$retval;
    _1151_t0 = 3;
    _1152_x = (struct0) {.tag=0, ._0=_1151_t0};
    _1151_t2 = (struct1) {(uint8_t*)string_0, 5};
    _1152_x = (struct0) {.tag=1, ._1=_1151_t2};
    _1151_t4 = (struct1) {(uint8_t*)string_1, 3};
    _1152_x = (struct0) {.tag=3, ._3=_1151_t4};
    _1151_t6 = 108;
    _1152_x = (struct0) {.tag=2, ._2=_1151_t6};
    _1151_$retval = _1152_x._2;
    return _1151_$retval;
}

int main(void) {
  printf("%ld",_1151_main());
  return 0;
}
