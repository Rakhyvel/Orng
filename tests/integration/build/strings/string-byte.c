/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

/* Interned Strings */
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _1376_main(void);

/* Function definitions */
uint8_t _1376_main(void){
    struct struct0 _1377_x;
    int64_t _1376_t1;
    uint8_t _1376_$retval;
    _1377_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1376_t1 = 0;
    $bounds_check(_1376_t1, _1377_x._1, "tests/integration/strings/string-byte.orng:2:3:\nfn main() -> Byte {\n ^");
    _1376_$retval = *((uint8_t*)_1377_x._0 + _1376_t1);
    return _1376_$retval;
}

int main(void) {
  printf("%u",_1376_main());
  return 0;
}
