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
uint8_t _1053_main(void);

/* Function definitions */
uint8_t _1053_main(void) {
    struct0 _1054_x;
    int64_t _1053_t1;
    uint8_t _1053_$retval;
    _1054_x = (struct0) {(uint8_t*)string_0, 1};
    _1053_t1 = 0;
    _1053_$retval = *((uint8_t*)_1054_x._0 + _1053_t1);
    return _1053_$retval;
}

int main(void) {
  printf("%d",_1053_main());
  return 0;
}
