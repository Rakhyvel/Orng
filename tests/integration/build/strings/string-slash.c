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
uint8_t _1438_main(void);


/* Function definitions */
uint8_t _1438_main(void){
    struct struct0 _1439_x;
    int64_t _1438_t1;
    uint8_t _1438_$retval;
    _1439_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1438_t1 = 0;
    $bounds_check(_1438_t1, _1439_x._1, "tests/integration/strings/string-slash.orng:2:3:\nfn main() -> Byte {\n ^");
    _1438_$retval = *((uint8_t*)_1439_x._0 + _1438_t1);
    return _1438_$retval;
}


int main(void) {
  printf("%u",_1438_main());
  return 0;
}
