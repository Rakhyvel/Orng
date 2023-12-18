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
uint8_t _1592_main(void);

/* Function definitions */
uint8_t _1592_main(void){
    struct0 _1593_x;
    int64_t _1592_t1;
    uint8_t _1592_$retval;
    _1593_x = (struct0) {(uint8_t*)string_0, 1};
    _1592_t1 = 0;
    $bounds_check(_1592_t1, _1593_x._1, "tests/integration/strings/string-byte.orng:2:3:\nfn main() -> Byte {\n ^");
    _1592_$retval = *((uint8_t*)_1593_x._0 + _1592_t1);
    return _1592_$retval;
}

int main(void) {
  printf("%d",_1592_main());
  return 0;
}
