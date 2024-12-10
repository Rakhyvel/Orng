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
struct struct0 _54_main(void);


/* Function definitions */
struct struct0 _54_main(void){
    struct struct0 _54_t1;
    struct struct0 _54_t2;
    struct struct0 _54_t3;
    struct struct1 _55_x;
    int64_t _54_t5;
    int64_t _54_t6;
    struct struct0 _54_$retval;
    _54_t1 = (struct struct0) {(uint8_t*)string_0, 7};
    _54_t2 = (struct struct0) {(uint8_t*)string_1, 3};
    _54_t3 = (struct struct0) {(uint8_t*)string_2, 6};
    _55_x = (struct struct1) {_54_t1, _54_t2, _54_t3};
    _54_t5 = 1;
    _54_t6 = 3;
    $bounds_check(_54_t5, _54_t6, "tests/integration/arrays/array-string.orng:2:8:\nfn main() -> String {\n      ^");
    _54_$retval = *((struct struct0*)&_55_x + _54_t5);
    return _54_$retval;
}


int main(void) {
  printf("%s",_54_main()._0);
  return 0;
}
