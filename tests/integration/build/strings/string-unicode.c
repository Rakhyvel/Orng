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
char* string_0 = "\x48\x65\x6C\x6C\x6F\x2C\x20\x4F\x72\x6E\x67\x21\x20\xF0\x9F\x8D\x8A";

/* Function forward definitions */
struct struct0 _1500_main(void);


/* Function definitions */
struct struct0 _1500_main(void){
    struct struct0 _1500_$retval;
    _1500_$retval = (struct struct0) {(uint8_t*)string_0, 17};
    return _1500_$retval;
}


int main(void) {
  printf("%s",_1500_main()._0);
  return 0;
}
