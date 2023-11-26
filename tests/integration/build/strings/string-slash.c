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
uint8_t _41_main(void);

/* Function definitions */
uint8_t _41_main(void) {
    struct0 _42_x;
    int64_t _41_t1;
    uint8_t _41_$retval;
    _42_x = (struct0) {(uint8_t*)string_0, 1};
    _41_t1 = 0;
    _41_$retval = *((uint8_t*)_42_x._0 + _41_t1);
    return _41_$retval;
}

int main(void) {
  printf("%d",_41_main());
  return 0;
}
