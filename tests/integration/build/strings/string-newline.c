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
uint8_t _1351_main(void);

/* Function definitions */
uint8_t _1351_main(void) {
    struct0 _1352_x;
    int64_t _1351_t1;
    uint8_t _1351_$retval;
    _1352_x = (struct0) {(uint8_t*)string_0, 5};
    _1351_t1 = 0;
    _1351_$retval = *((uint8_t*)_1352_x._0 + _1351_t1);
    return _1351_$retval;
}

int main(void) {
  printf("%d",_1351_main());
  return 0;
}
