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
uint8_t _1434_main(void);


/* Function definitions */
uint8_t _1434_main(void){
    struct struct0 _1435_x;
    int64_t _1434_t2;
    uint8_t _1434_$retval;
    _1435_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1434_t2 = 4;
    $bounds_check(_1434_t2, _1435_x._1, "tests/integration/strings/string-dquote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1434_$retval = *((uint8_t*)_1435_x._0 + _1434_t2);
    return _1434_$retval;
}


int main(void) {
  printf("%u",_1434_main());
  return 0;
}
