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
int64_t _1842_main(void);


/* Function definitions */
int64_t _1842_main(void){
    struct struct0 _1842_t2;
    int64_t _1842_t3;
    struct struct1 _1843_a;
    struct struct2 _1842_t7;
    int64_t _1842_t8;
    struct struct3 _1843_b;
    struct struct3* _1842_t10;
    uint64_t _1842_t12;
    int64_t _1842_$retval;
    _1842_t2 = (struct struct0) {.tag=1};
    _1842_t3 = 200;
    _1843_a = (struct struct1) {_1842_t2, _1842_t3};
    _1842_t7 = (struct struct2) {.tag=1};
    _1842_t8 = 86;
    _1843_b = (struct struct3) {_1842_t7, _1842_t8};
    _1842_t10 = &_1843_b;
    _1843_a._0 = (struct struct0) {.tag=0, ._0=_1842_t10};
    _1842_t12 = _1843_a._0.tag;
    $tag_check(_1842_t12, 0, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    _1842_$retval = $add_int64_t(_1843_a._1, (*_1843_a._0._0)._1, "tests/integration/tuples/cyclic.orng:9:10:\n    a.y + a.x.some.y\n        ^");
    return _1842_$retval;
}


int main(void) {
  printf("%ld",_1842_main());
  return 0;
}
