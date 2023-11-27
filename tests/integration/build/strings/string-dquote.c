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
uint8_t _989_main(void);

/* Function definitions */
uint8_t _989_main(void) {
    struct0 _990_x;
    int64_t _989_t1;
    uint8_t _989_$retval;
    _990_x = (struct0) {(uint8_t*)string_0, 5};
    _989_t1 = 4;
    _989_$retval = *((uint8_t*)_990_x._0 + _989_t1);
    return _989_$retval;
}

int main(void) {
  printf("%d",_989_main());
  return 0;
}
