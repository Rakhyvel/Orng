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
char* string_0 = "\x4E\x4F\x57\x20\x59\x55\x4F\x20\x43\x45\x45\x2E\x2E\x2E";

/* Function forward definitions */
uint8_t _1402_main(void);

/* Function definitions */
uint8_t _1402_main(void){
    struct struct0 _1403_x;
    int64_t _1402_t1;
    uint8_t _1402_$retval;
    _1403_x = (struct struct0) {(uint8_t*)string_0, 14};
    _1402_t1 = 5;
    $bounds_check(_1402_t1, _1403_x._1, "tests/integration/strings/string-literal.orng:2:3:\nfn main() -> Byte {\n ^");
    _1402_$retval = *((uint8_t*)_1403_x._0 + _1402_t1);
    return _1402_$retval;
}

int main(void) {
  printf("%u",_1402_main());
  return 0;
}
