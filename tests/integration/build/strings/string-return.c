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
uint8_t _1515_main(void);

/* Function definitions */
uint8_t _1515_main(void){
    struct0 _1516_x;
    int64_t _1515_t1;
    uint8_t _1515_$retval;
    _1516_x = (struct0) {(uint8_t*)string_0, 5};
    _1515_t1 = 1;
    $bounds_check(_1515_t1, _1516_x._1, "tests/integration/strings/string-return.orng:2:3:\nfn main() -> Byte {\n ^");
    _1515_$retval = *((uint8_t*)_1516_x._0 + _1515_t1);
    return _1515_$retval;
}

int main(void) {
  printf("%d",_1515_main());
  return 0;
}
