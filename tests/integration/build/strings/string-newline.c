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
uint8_t _1081_main(void);

/* Function definitions */
uint8_t _1081_main(void) {
    struct0 _1082_x;
    int64_t _1081_t1;
    uint8_t _1081_$retval;
    _1082_x = (struct0) {(uint8_t*)string_0, 5};
    _1081_t1 = 0;
    _1081_$retval = *((uint8_t*)_1082_x._0 + _1081_t1);
    return _1081_$retval;
}

int main(void) {
  printf("%d",_1081_main());
  return 0;
}
