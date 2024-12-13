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
int64_t _375_main(void);


/* Function definitions */
int64_t _375_main(void){
    int64_t _375_t2;
    int64_t _375_t3;
    struct struct3 _375_t1;
    int64_t _375_t4;
    struct struct1 _375_t5;
    struct struct4 _375_t0;
    struct struct1 _376_x;
    uint64_t _375_t8;
    int64_t _375_t9;
    uint8_t _375_t11;
    int64_t _375_$retval;
    _375_t2 = 48;
    _375_t3 = -6148914691236517206;
    _375_t1 = (struct struct3) {_375_t2, _375_t3};
    _375_t4 = 4;
    _375_t5 = (struct struct1) {.tag=0, ._0=_375_t4};
    _375_t0 = (struct struct4) {_375_t1, _375_t5};
    _376_x = _375_t0._1;
    _375_t8 = _376_x.tag;
    _375_t9 = 4;
    $tag_check(_375_t8, 0, "tests/integration/comptime/sum-extract.orng:3:14:\n    let (_, x) = comptime { get_variant() }\n            ^");
    _375_t11 = _376_x._0==_375_t9;
    if (_375_t11) {
        goto BB430;
    } else {
        goto BB434;
    }
BB430:
    _375_$retval = 329;
    return _375_$retval;
BB434:
    $lines[$line_idx++] = "tests/integration/comptime/sum-extract.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_375_main());
  return 0;
}
