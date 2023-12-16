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
uint8_t _1362_main(void);

/* Function definitions */
uint8_t _1362_main(void){
    struct0 _1363_x;
    int64_t _1362_t1;
    uint8_t _1362_$retval;
    _1363_x = (struct0) {(uint8_t*)string_0, 1};
    _1362_t1 = 0;
    _1362_$retval = *((uint8_t*)_1363_x._0 + _1362_t1);
    return _1362_$retval;
}

int main(void) {
  printf("%d",_1362_main());
  return 0;
}
