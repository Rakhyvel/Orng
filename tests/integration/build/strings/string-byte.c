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
uint8_t _1418_main(void);

/* Function definitions */
uint8_t _1418_main(void){
    struct0 _1419_x;
    int64_t _1418_t1;
    uint8_t _1418_$retval;
    _1419_x = (struct0) {(uint8_t*)string_0, 1};
    _1418_t1 = 0;
    _1418_$retval = *((uint8_t*)_1419_x._0 + _1418_t1);
    return _1418_$retval;
}

int main(void) {
  printf("%d",_1418_main());
  return 0;
}
