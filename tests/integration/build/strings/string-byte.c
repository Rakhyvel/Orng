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
uint8_t _1358_main(void);

/* Function definitions */
uint8_t _1358_main(void){
    struct0 _1359_x;
    int64_t _1358_t1;
    uint8_t _1358_$retval;
    _1359_x = (struct0) {(uint8_t*)string_0, 1};
    _1358_t1 = 0;
    _1358_$retval = *((uint8_t*)_1359_x._0 + _1358_t1);
    return _1358_$retval;
}

int main(void) {
  printf("%d",_1358_main());
  return 0;
}
