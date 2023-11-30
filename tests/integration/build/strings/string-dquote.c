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
uint8_t _1323_main(void);

/* Function definitions */
uint8_t _1323_main(void) {
    struct0 _1324_x;
    int64_t _1323_t1;
    uint8_t _1323_$retval;
    _1324_x = (struct0) {(uint8_t*)string_0, 5};
    _1323_t1 = 4;
    _1323_$retval = *((uint8_t*)_1324_x._0 + _1323_t1);
    return _1323_$retval;
}

int main(void) {
  printf("%d",_1323_main());
  return 0;
}
