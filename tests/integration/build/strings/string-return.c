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
uint8_t _1388_main(void);

/* Function definitions */
uint8_t _1388_main(void){
    struct struct0 _1389_x;
    int64_t _1388_t1;
    uint8_t _1388_$retval;
    _1389_x = (struct struct0) {(uint8_t*)string_0, 5};
    _1388_t1 = 1;
    $bounds_check(_1388_t1, _1389_x._1, "tests/integration/strings/string-return.orng:2:3:\nfn main() -> Byte {\n ^");
    _1388_$retval = *((uint8_t*)_1389_x._0 + _1388_t1);
    return _1388_$retval;
}

int main(void) {
  printf("%u",_1388_main());
  return 0;
}
