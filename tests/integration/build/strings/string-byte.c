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
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _1406_main(void);


/* Function definitions */
uint8_t _1406_main(void){
    struct struct0 _1407_x;
    int64_t _1406_t2;
    uint8_t _1406_$retval;
    _1407_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1406_t2 = 0;
    $bounds_check(_1406_t2, _1407_x._1, "tests/integration/strings/string-byte.orng:2:3:\nfn main() -> Byte {\n ^");
    _1406_$retval = *((uint8_t*)_1407_x._0 + _1406_t2);
    return _1406_$retval;
}


int main(void) {
  printf("%u",_1406_main());
  return 0;
}
