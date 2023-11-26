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
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _955_main(void);

/* Function definitions */
uint8_t _955_main(void) {
    struct0 _956_x;
    int64_t _955_t1;
    uint8_t _955_$retval;
    _956_x = (struct0) {(uint8_t*)string_0, 1};
    _955_t1 = 0;
    _955_$retval = *((uint8_t*)_956_x._0 + _955_t1);
    return _955_$retval;
}

int main(void) {
  printf("%d",_955_main());
  return 0;
}
