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
uint8_t _1_main();

/* Function definitions */
uint8_t _1_main() {
    struct0 _2_x;
    uint8_t _1_$retval;
    _2_x = (struct0) {string_0, 11};
    _1_$retval = *((uint8_t*)_2_x._0 + 3);
    return _1_$retval;
}

int main()
{
  printf("%d",_1_main());
  return 0;
}
