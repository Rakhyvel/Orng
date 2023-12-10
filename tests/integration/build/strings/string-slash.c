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
char* string_0 = "\x5C";

/* Function forward definitions */
uint8_t _1060_main(void);

/* Function definitions */
uint8_t _1060_main(void) {
    struct0 _1061_x;
    int64_t _1060_t1;
    uint8_t _1060_$retval;
    _1061_x = (struct0) {(uint8_t*)string_0, 1};
    _1060_t1 = 0;
    _1060_$retval = *((uint8_t*)_1061_x._0 + _1060_t1);
    return _1060_$retval;
}

int main(void) {
  printf("%d",_1060_main());
  return 0;
}
