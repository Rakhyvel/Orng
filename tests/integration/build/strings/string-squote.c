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
uint8_t _1429_main(void);


/* Function definitions */
uint8_t _1429_main(void){
    struct struct0 _1430_x;
    int64_t _1429_t2;
    uint8_t _1429_$retval;
    _1430_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1429_t2 = 3;
    $bounds_check(_1429_t2, _1430_x._1, "tests/integration/strings/string-squote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1429_$retval = *((uint8_t*)_1430_x._0 + _1429_t2);
    return _1429_$retval;
}


int main(void) {
  printf("%u",_1429_main());
  return 0;
}
