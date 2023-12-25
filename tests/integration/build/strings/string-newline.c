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
uint8_t _1358_main(void);

/* Function definitions */
uint8_t _1358_main(void){
    struct0 _1359_x;
    int64_t _1358_t1;
    uint8_t _1358_$retval;
    _1359_x = (struct0) {(uint8_t*)string_0, 5};
    _1358_t1 = 0;
    $bounds_check(_1358_t1, _1359_x._1, "tests/integration/strings/string-newline.orng:2:3:\nfn main() -> Byte {\n ^");
    _1358_$retval = *((uint8_t*)_1359_x._0 + _1358_t1);
    return _1358_$retval;
}

int main(void) {
  printf("%u",_1358_main());
  return 0;
}
