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
uint8_t _1373_main(void);

/* Function definitions */
uint8_t _1373_main(void){
    struct0 _1374_x;
    int64_t _1373_t1;
    uint8_t _1373_$retval;
    _1374_x = (struct0) {(uint8_t*)string_0, 1};
    _1373_t1 = 0;
    _1373_$retval = *((uint8_t*)_1374_x._0 + _1373_t1);
    return _1373_$retval;
}

int main(void) {
  printf("%d",_1373_main());
  return 0;
}
