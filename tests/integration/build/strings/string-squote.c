/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _1367_main(void);

/* Function definitions */
uint8_t _1367_main(void){
    struct0 _1368_x;
    int64_t _1367_t1;
    uint8_t _1367_$retval;
    _1368_x = (struct0) {(uint8_t*)string_0, 5};
    _1367_t1 = 3;
    $bounds_check(_1367_t1, _1368_x._1, "tests/integration/strings/string-squote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1367_$retval = *((uint8_t*)_1368_x._0 + _1367_t1);
    return _1367_$retval;
}

int main(void) {
  printf("%d",_1367_main());
  return 0;
}
