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
uint8_t _35_main(void);

/* Function definitions */
uint8_t _35_main(void) {
    struct0 _36_x;
    int64_t _35_t1;
    uint8_t _35_$retval;
    _36_x = (struct0) {(uint8_t*)string_0, 5};
    _35_t1 = 0;
    _35_$retval = *((uint8_t*)_36_x._0 + _35_t1);
    return _35_$retval;
}

int main(void) {
  printf("%d",_35_main());
  return 0;
}
