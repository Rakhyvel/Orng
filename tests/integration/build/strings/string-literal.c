/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

/* Interned Strings */
char* string_0 = "\x4E\x4F\x57\x20\x59\x55\x4F\x20\x43\x45\x45\x2E\x2E\x2E";

/* Function forward definitions */
uint8_t _1509_main(void);


/* Function definitions */
uint8_t _1509_main(void){
    struct struct0 _1510_x;
    int64_t _1509_t2;
    uint8_t _1509_$retval;
    _1510_x = (struct struct0) {(uint8_t*)string_0, 14};
    _1509_t2 = 5;
    $bounds_check(_1509_t2, _1510_x._1, "tests/integration/strings/string-literal.orng:2:8:\nfn main() -> Byte {\n      ^");
    _1509_$retval = *((uint8_t*)_1510_x._0 + _1509_t2);
    return _1509_$retval;
}


int main(void) {
  printf("%u",_1509_main());
  return 0;
}
