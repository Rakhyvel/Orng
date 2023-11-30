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
uint8_t _1342_main(void);

/* Function definitions */
uint8_t _1342_main(void) {
    struct0 _1343_x;
    int64_t _1342_t1;
    uint8_t _1342_$retval;
    _1343_x = (struct0) {(uint8_t*)string_0, 5};
    _1342_t1 = 2;
    _1342_$retval = *((uint8_t*)_1343_x._0 + _1342_t1);
    return _1342_$retval;
}

int main(void) {
  printf("%d",_1342_main());
  return 0;
}
