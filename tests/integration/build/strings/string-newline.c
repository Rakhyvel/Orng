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
uint8_t _1611_main(void);

/* Function definitions */
uint8_t _1611_main(void){
    struct0 _1612_x;
    int64_t _1611_t1;
    uint8_t _1611_$retval;
    _1612_x = (struct0) {(uint8_t*)string_0, 5};
    _1611_t1 = 0;
    $bounds_check(_1611_t1, _1612_x._1, "tests/integration/strings/string-newline.orng:2:3:\nfn main() -> Byte {\n ^");
    _1611_$retval = *((uint8_t*)_1612_x._0 + _1611_t1);
    return _1611_$retval;
}

int main(void) {
  printf("%d",_1611_main());
  return 0;
}
