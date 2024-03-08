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

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        struct struct3* _0;
    };
};

struct struct1 {
    struct struct0 _0;
    int64_t _1;
};

struct struct2 {
    uint64_t tag;
    union {
        struct struct1* _0;
    };
};

struct struct3 {
    struct struct2 _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1670_main(void);


/* Function definitions */
int64_t _1670_main(void){
    struct struct0 _1670_t1;
    int64_t _1670_t2;
    struct struct1 _1671_a;
    struct struct2 _1670_t4;
    int64_t _1670_t5;
    struct struct3 _1671_b;
    struct struct3* _1670_t6;
    uint64_t _1670_t8;
    int64_t _1670_$retval;
    _1670_t1 = (struct struct0) {.tag=1};
    _1670_t2 = 200;
    _1671_a = (struct struct1) {_1670_t1, _1670_t2};
    _1670_t4 = (struct struct2) {.tag=1};
    _1670_t5 = 86;
    _1671_b = (struct struct3) {_1670_t4, _1670_t5};
    _1670_t6 = &_1671_b;
    _1671_a._0 = (struct struct0) {.tag=0, ._0=_1670_t6};
    _1670_t8 = _1671_a._0.tag;
    $tag_check(_1670_t8, 0, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    _1670_$retval = $add_int64_t(_1671_a._1, (*_1671_a._0._0)._1, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    return _1670_$retval;
}


int main(void) {
  printf("%ld",_1670_main());
  return 0;
}
