/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

/* Interned Strings */
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _1483_main(void);


/* Function definitions */
uint8_t _1483_main(void){
    struct struct0 _1484_x;
    int64_t _1483_t2;
    uint8_t _1483_$retval;
    _1484_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1483_t2 = 0;
    $bounds_check(_1483_t2, _1484_x._1, "tests/integration/strings/string-newline.orng:2:8:\nfn main() -> Byte {\n      ^");
    _1483_$retval = *((uint8_t*)_1484_x._0 + _1483_t2);
    return _1483_$retval;
}


int main(void) {
  printf("%u",_1483_main());
  return 0;
}
