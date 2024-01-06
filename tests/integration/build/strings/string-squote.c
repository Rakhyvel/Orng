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
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _1399_main(void);

/* Function definitions */
uint8_t _1399_main(void){
    struct struct0 _1400_x;
    int64_t _1399_t1;
    uint8_t _1399_$retval;
    _1400_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1399_t1 = 3;
    $bounds_check(_1399_t1, _1400_x._1, "tests/integration/strings/string-squote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1399_$retval = *((uint8_t*)_1400_x._0 + _1399_t1);
    return _1399_$retval;
}

int main(void) {
  printf("%u",_1399_main());
  return 0;
}
