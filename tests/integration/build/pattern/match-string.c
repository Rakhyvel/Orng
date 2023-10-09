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
} struct0;

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F";
char* string_1 = "\x57\x6F\x72\x6C\x64";

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    _1_t1 = (struct0) {(uint8_t*)string_0, 4};
    if (_1_t1 == (struct0) {(uint8_t*)string_1, 4}) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1_t0 = 230;
    goto BB5;
BB6:
    if (_1_t1 == (struct0) {(uint8_t*)string_1, 4}) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _1_$retval = _1_t0;
    return _1_$retval;
BB8:
    _1_t0 = 232;
    goto BB5;
BB10:
    _1_t0 = 231;
    goto BB5;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
