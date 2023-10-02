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
uint8_t _1_main();

/* Function definitions */
uint8_t _1_main() {
    struct0 _2_x;
    uint8_t _1_$retval;
    _2_x = (struct0) {string_0, 5};
    _1_$retval = *(uint8_t*)_2_x._0;
    return _1_$retval;
}

int main()
{
  printf("%d",_1_main());
  return 0;
}
