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
uint8_t _1341_main(void);

/* Function definitions */
uint8_t _1341_main(void) {
    struct0 _1342_x;
    int64_t _1341_t1;
    uint8_t _1341_$retval;
    _1342_x = (struct0) {(uint8_t*)string_0, 1};
    _1341_t1 = 0;
    _1341_$retval = *((uint8_t*)_1342_x._0 + _1341_t1);
    return _1341_$retval;
}

int main(void) {
  printf("%d",_1341_main());
  return 0;
}
