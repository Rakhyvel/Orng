/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
    struct struct0 _2;
};

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F\x2C\x20";
char* string_1 = "\x32\x31\x37";
char* string_2 = "\x57\x6F\x72\x6C\x64\x21";

/* Function forward definitions */
struct struct0 _52_main(void);


/* Function definitions */
struct struct0 _52_main(void){
    struct struct0 _52_t1;
    struct struct0 _52_t2;
    struct struct0 _52_t3;
    struct struct1 _53_x;
    int64_t _52_t5;
    int64_t _52_t6;
    struct struct0 _52_$retval;
    _52_t1 = (struct struct0) {(uint8_t*)string_0, 7};
    _52_t2 = (struct struct0) {(uint8_t*)string_1, 3};
    _52_t3 = (struct struct0) {(uint8_t*)string_2, 6};
    _53_x = (struct struct1) {_52_t1, _52_t2, _52_t3};
    _52_t5 = 1;
    _52_t6 = 3;
    $bounds_check(_52_t5, _52_t6, "tests/integration/arrays/array-string.orng:2:8:\nfn main() -> String {\n      ^");
    _52_$retval = *((struct struct0*)&_53_x + _52_t5);
    return _52_$retval;
}


int main(void) {
  printf("%s",_52_main()._0);
  return 0;
}
