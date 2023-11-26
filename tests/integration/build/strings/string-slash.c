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
uint8_t _970_main(void);

/* Function definitions */
uint8_t _970_main(void) {
    struct0 _971_x;
    int64_t _970_t1;
    uint8_t _970_$retval;
    _971_x = (struct0) {(uint8_t*)string_0, 1};
    _970_t1 = 0;
    _970_$retval = *((uint8_t*)_971_x._0 + _970_t1);
    return _970_$retval;
}

int main(void) {
  printf("%d",_970_main());
  return 0;
}
