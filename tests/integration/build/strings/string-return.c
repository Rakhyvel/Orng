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
uint8_t _1065_main(void);

/* Function definitions */
uint8_t _1065_main(void) {
    struct0 _1066_x;
    int64_t _1065_t1;
    uint8_t _1065_$retval;
    _1066_x = (struct0) {(uint8_t*)string_0, 5};
    _1065_t1 = 1;
    _1065_$retval = *((uint8_t*)_1066_x._0 + _1065_t1);
    return _1065_$retval;
}

int main(void) {
  printf("%d",_1065_main());
  return 0;
}
