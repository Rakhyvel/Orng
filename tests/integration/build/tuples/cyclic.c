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
int64_t _1575_main(void);


/* Function definitions */
int64_t _1575_main(void){
    struct struct0 _1575_t1;
    int64_t _1575_t2;
    struct struct1 _1576_a;
    struct struct2 _1575_t4;
    int64_t _1575_t5;
    struct struct3 _1576_b;
    struct struct3* _1575_t6;
    uint64_t _1575_t8;
    int64_t _1575_$retval;
    _1575_t1 = (struct struct0) {.tag=1};
    _1575_t2 = 200;
    _1576_a = (struct struct1) {_1575_t1, _1575_t2};
    _1575_t4 = (struct struct2) {.tag=1};
    _1575_t5 = 86;
    _1576_b = (struct struct3) {_1575_t4, _1575_t5};
    _1575_t6 = &_1576_b;
    _1576_a._0 = (struct struct0) {.tag=0, ._0=_1575_t6};
    _1575_t8 = _1576_a._0.tag;
    $tag_check(_1575_t8, 0, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    _1575_$retval = $add_int64_t(_1576_a._1, (*_1576_a._0._0)._1, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    return _1575_$retval;
}


int main(void) {
  printf("%ld",_1575_main());
  return 0;
}
