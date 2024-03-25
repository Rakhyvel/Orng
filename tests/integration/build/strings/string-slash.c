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
uint8_t _1421_main(void);


/* Function definitions */
uint8_t _1421_main(void){
    struct struct0 _1422_x;
    int64_t _1421_t2;
    uint8_t _1421_$retval;
    _1422_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1421_t2 = 0;
    $bounds_check(_1421_t2, _1422_x._1, "tests/integration/strings/string-slash.orng:2:3:\nfn main() -> Byte {\n ^");
    _1421_$retval = *((uint8_t*)_1422_x._0 + _1421_t2);
    return _1421_$retval;
}


int main(void) {
  printf("%u",_1421_main());
  return 0;
}
