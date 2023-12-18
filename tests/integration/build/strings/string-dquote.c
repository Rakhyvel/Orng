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
uint8_t _1605_main(void);

/* Function definitions */
uint8_t _1605_main(void){
    struct0 _1606_x;
    int64_t _1605_t1;
    uint8_t _1605_$retval;
    _1606_x = (struct0) {(uint8_t*)string_0, 5};
    _1605_t1 = 4;
    $bounds_check(_1605_t1, _1606_x._1, "tests/integration/strings/string-dquote.orng:2:3:\nfn main() -> Byte {\n ^");
    _1605_$retval = *((uint8_t*)_1606_x._0 + _1605_t1);
    return _1605_$retval;
}

int main(void) {
  printf("%d",_1605_main());
  return 0;
}
