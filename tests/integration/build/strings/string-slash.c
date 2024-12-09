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
char* string_0 = "\x5C";

/* Function forward definitions */
uint8_t _1518_main(void);


/* Function definitions */
uint8_t _1518_main(void){
    struct struct0 _1519_x;
    int64_t _1518_t2;
    uint8_t _1518_$retval;
    _1519_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1518_t2 = 0;
    $bounds_check(_1518_t2, _1519_x._1, "tests/integration/strings/string-slash.orng:2:8:\nfn main() -> Byte {\n      ^");
    _1518_$retval = *((uint8_t*)_1519_x._0 + _1518_t2);
    return _1518_$retval;
}


int main(void) {
  printf("%u",_1518_main());
  return 0;
}
