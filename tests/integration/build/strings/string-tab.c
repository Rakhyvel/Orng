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
uint8_t _1107_main(void);

/* Function definitions */
uint8_t _1107_main(void) {
    struct0 _1108_x;
    int64_t _1107_t1;
    uint8_t _1107_$retval;
    _1108_x = (struct0) {(uint8_t*)string_0, 5};
    _1107_t1 = 2;
    _1107_$retval = *((uint8_t*)_1108_x._0 + _1107_t1);
    return _1107_$retval;
}

int main(void) {
  printf("%d",_1107_main());
  return 0;
}
