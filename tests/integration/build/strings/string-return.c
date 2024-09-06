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
uint8_t _1488_main(void);


/* Function definitions */
uint8_t _1488_main(void){
    struct struct0 _1489_x;
    int64_t _1488_t2;
    uint8_t _1488_$retval;
    _1489_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1488_t2 = 1;
    $bounds_check(_1488_t2, _1489_x._1, "tests/integration/strings/string-return.orng:2:8:\nfn main() -> Byte {\n      ^");
    _1488_$retval = *((uint8_t*)_1489_x._0 + _1488_t2);
    return _1488_$retval;
}


int main(void) {
  printf("%u",_1488_main());
  return 0;
}
