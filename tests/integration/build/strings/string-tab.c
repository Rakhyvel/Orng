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
uint8_t _1482_main(void);


/* Function definitions */
uint8_t _1482_main(void){
    struct struct0 _1483_x;
    int64_t _1482_t2;
    uint8_t _1482_$retval;
    _1483_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1482_t2 = 2;
    $bounds_check(_1482_t2, _1483_x._1, "tests/integration/strings/string-tab.orng:2:8:\nfn main() -> Byte {\n      ^");
    _1482_$retval = *((uint8_t*)_1483_x._0 + _1482_t2);
    return _1482_$retval;
}


int main(void) {
  printf("%u",_1482_main());
  return 0;
}
