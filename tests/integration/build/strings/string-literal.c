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
char* string_0 = "\x4E\x4F\x57\x20\x59\x55\x4F\x20\x43\x45\x45\x2E\x2E\x2E";

/* Function forward definitions */
uint8_t _1412_main(void);


/* Function definitions */
uint8_t _1412_main(void){
    struct struct0 _1413_x;
    int64_t _1412_t2;
    uint8_t _1412_$retval;
    _1413_x = (struct struct0) {(uint8_t*)string_0, 14};
    _1412_t2 = 5;
    $bounds_check(_1412_t2, _1413_x._1, "tests/integration/strings/string-literal.orng:2:3:\nfn main() -> Byte {\n ^");
    _1412_$retval = *((uint8_t*)_1413_x._0 + _1412_t2);
    return _1412_$retval;
}


int main(void) {
  printf("%u",_1412_main());
  return 0;
}
