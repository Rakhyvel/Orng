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
uint8_t _1336_main(void);

/* Function definitions */
uint8_t _1336_main(void) {
    struct0 _1337_x;
    int64_t _1336_t1;
    uint8_t _1336_$retval;
    _1337_x = (struct0) {(uint8_t*)string_0, 1};
    _1336_t1 = 0;
    _1336_$retval = *((uint8_t*)_1337_x._0 + _1336_t1);
    return _1336_$retval;
}

int main(void) {
  printf("%d",_1336_main());
  return 0;
}
