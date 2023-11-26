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
uint8_t _44_main(void);

/* Function definitions */
uint8_t _44_main(void) {
    struct0 _45_x;
    int64_t _44_t1;
    uint8_t _44_$retval;
    _45_x = (struct0) {(uint8_t*)string_0, 5};
    _44_t1 = 3;
    _44_$retval = *((uint8_t*)_45_x._0 + _44_t1);
    return _44_$retval;
}

int main(void) {
  printf("%d",_44_main());
  return 0;
}
