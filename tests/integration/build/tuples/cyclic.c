/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;
struct struct2;
struct struct3;

/* Typedefs */
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
int64_t _1503_main(void);

/* Function definitions */
int64_t _1503_main(void){
    struct struct0 _1503_t1;
    int64_t _1503_t2;
    struct struct1 _1504_a;
    struct struct2 _1503_t4;
    int64_t _1503_t5;
    struct struct3 _1504_b;
    struct struct3* _1503_t6;
    uint64_t _1503_t8;
    int64_t _1503_$retval;
    _1503_t1 = (struct struct0) {.tag=1};
    _1503_t2 = 200;
    _1504_a = (struct struct1) {_1503_t1, _1503_t2};
    _1503_t4 = (struct struct2) {.tag=1};
    _1503_t5 = 86;
    _1504_b = (struct struct3) {_1503_t4, _1503_t5};
    _1503_t6 = &_1504_b;
    _1504_a._0 = (struct struct0) {.tag=0, ._0=_1503_t6};
    _1503_t8 = _1504_a._0.tag;
    $tag_check(_1503_t8, 0, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    _1503_$retval = $add_int64_t(_1504_a._1, (*_1504_a._0._0)._1, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    return _1503_$retval;
}

int main(void) {
  printf("%ld",_1503_main());
  return 0;
}
