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
uint8_t _1021_main(void);

/* Function definitions */
uint8_t _1021_main(void) {
    struct0 _1022_x;
    int64_t _1021_t1;
    uint8_t _1021_$retval;
    _1022_x = (struct0) {(uint8_t*)string_0, 1};
    _1021_t1 = 0;
    _1021_$retval = *((uint8_t*)_1022_x._0 + _1021_t1);
    return _1021_$retval;
}

int main(void) {
  printf("%d",_1021_main());
  return 0;
}
