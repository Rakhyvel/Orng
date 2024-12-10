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
int64_t _9_main(void);


/* Function definitions */
int64_t _9_main(void){
    int64_t _9_t2;
    int64_t _9_t3;
    struct struct3 _9_t1;
    int64_t _9_t4;
    struct struct1 _9_t5;
    struct struct4 _9_t0;
    struct struct1 _10_x;
    uint64_t _9_t8;
    int64_t _9_t9;
    uint8_t _9_t11;
    int64_t _9_$retval;
    _9_t2 = 1;
    _9_t3 = 6148914691236517205;
    _9_t1 = (struct struct3) {_9_t2, _9_t3};
    _9_t4 = 4;
    _9_t5 = (struct struct1) {.tag=0, ._0=_9_t4};
    _9_t0 = (struct struct4) {_9_t1, _9_t5};
    _10_x = _9_t0._1;
    _9_t8 = _10_x.tag;
    _9_t9 = 4;
    $tag_check(_9_t8, 0, "tests/integration/comptime/sum-extract.orng:3:14:\n    let (_, x) = comptime { get_variant() }\n            ^");
    _9_t11 = _10_x._0==_9_t9;
    if (_9_t11) {
        goto BB13;
    } else {
        goto BB17;
    }
BB13:
    _9_$retval = 329;
    return _9_$retval;
BB17:
    $lines[$line_idx++] = "tests/integration/comptime/sum-extract.orng:7:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_9_main());
  return 0;
}
