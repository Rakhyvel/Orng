/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;
struct struct2;
struct struct3;
struct struct4;

/* Struct, union, and function definitions */
struct struct0 {
    uint8_t* _0;
    int64_t _1;
};

struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
};

struct struct2 {
    struct struct0 _0;
    struct struct1 _1;
};

struct struct3 {
    int64_t _0;
    int64_t _1;
};

struct struct4 {
    struct struct3 _0;
    struct struct1 _1;
};

/* Interned Strings */
char* string_0 = "\x48\x65\x6C\x6C\x6F\x2C\x20\x57\x6F\x72\x6C\x64\x21";

/* Function forward definitions */
int64_t _373_main(void);


/* Function definitions */
int64_t _373_main(void){
    int64_t _373_t2;
    int64_t _373_t3;
    struct struct3 _373_t1;
    int64_t _373_t4;
    struct struct1 _373_t5;
    struct struct4 _373_t0;
    struct struct1 _374_x;
    uint64_t _373_t8;
    int64_t _373_t9;
    uint8_t _373_t11;
    int64_t _373_$retval;
    _373_t2 = 48;
    _373_t3 = 6148914691236517205;
    _373_t1 = (struct struct3) {_373_t2, _373_t3};
    _373_t4 = 4;
    _373_t5 = (struct struct1) {.tag=0, ._0=_373_t4};
    _373_t0 = (struct struct4) {_373_t1, _373_t5};
    _374_x = _373_t0._1;
    _373_t8 = _374_x.tag;
    _373_t9 = 4;
    $tag_check(_373_t8, 0, "tests/integration/comptime/sum-extract.orng:3:14:\n    let (_, x) = comptime { get_variant() }\n            ^");
    _373_t11 = _374_x._0==_373_t9;
    if (_373_t11) {
        goto BB428;
    } else {
        goto BB432;
    }
BB428:
    _373_$retval = 329;
    return _373_$retval;
BB432:
    $lines[$line_idx++] = "tests/integration/comptime/sum-extract.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_373_main());
  return 0;
}
