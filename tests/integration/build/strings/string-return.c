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
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _1098_main(void);

/* Function definitions */
uint8_t _1098_main(void) {
    struct0 _1099_x;
    int64_t _1098_t1;
    uint8_t _1098_$retval;
    _1099_x = (struct0) {(uint8_t*)string_0, 5};
    _1098_t1 = 1;
    _1098_$retval = *((uint8_t*)_1099_x._0 + _1098_t1);
    return _1098_$retval;
}

int main(void) {
  printf("%d",_1098_main());
  return 0;
}
