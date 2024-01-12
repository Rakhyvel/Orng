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
uint8_t _1391_main(void);

/* Function definitions */
uint8_t _1391_main(void){
    struct struct0 _1392_x;
    int64_t _1391_t1;
    uint8_t _1391_$retval;
    _1392_x = (struct struct0) {(uint8_t*)string_0, 1};
    _1391_t1 = 0;
    $bounds_check(_1391_t1, _1392_x._1, "tests/integration/strings/string-byte.orng:2:3:\nfn main() -> Byte {\n ^");
    _1391_$retval = *((uint8_t*)_1392_x._0 + _1391_t1);
    return _1391_$retval;
}

int main(void) {
  printf("%u",_1391_main());
  return 0;
}
