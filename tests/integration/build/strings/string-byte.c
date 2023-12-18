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
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _1602_main(void);

/* Function definitions */
uint8_t _1602_main(void){
    struct0 _1603_x;
    int64_t _1602_t1;
    uint8_t _1602_$retval;
    _1603_x = (struct0) {(uint8_t*)string_0, 1};
    _1602_t1 = 0;
    $bounds_check(_1602_t1, _1603_x._1, "tests/integration/strings/string-byte.orng:2:3:\nfn main() -> Byte {\n ^");
    _1602_$retval = *((uint8_t*)_1603_x._0 + _1602_t1);
    return _1602_$retval;
}

int main(void) {
  printf("%d",_1602_main());
  return 0;
}
