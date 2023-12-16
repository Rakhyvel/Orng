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
uint8_t _1368_main(void);

/* Function definitions */
uint8_t _1368_main(void){
    struct0 _1369_x;
    int64_t _1368_t1;
    uint8_t _1368_$retval;
    _1369_x = (struct0) {(uint8_t*)string_0, 5};
    _1368_t1 = 2;
    _1368_$retval = *((uint8_t*)_1369_x._0 + _1368_t1);
    return _1368_$retval;
}

int main(void) {
  printf("%d",_1368_main());
  return 0;
}
