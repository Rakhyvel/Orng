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
char* string_0 = "\x4E\x4F\x57\x20\x59\x55\x4F\x20\x43\x45\x45\x2E\x2E\x2E";

/* Function forward definitions */
uint8_t _1051_main(void);

/* Function definitions */
uint8_t _1051_main(void) {
    struct0 _1052_x;
    int64_t _1051_t1;
    uint8_t _1051_$retval;
    _1052_x = (struct0) {(uint8_t*)string_0, 14};
    _1051_t1 = 5;
    _1051_$retval = *((uint8_t*)_1052_x._0 + _1051_t1);
    return _1051_$retval;
}

int main(void) {
  printf("%d",_1051_main());
  return 0;
}
