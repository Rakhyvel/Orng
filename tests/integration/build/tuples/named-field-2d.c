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
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _1859_main(void);


/* Function definitions */
int64_t _1859_main(void){
    int64_t _1859_t2;
    int64_t _1859_t3;
    struct struct0 _1859_t1;
    int64_t _1859_t5;
    int64_t _1859_t6;
    struct struct0 _1859_t4;
    struct struct1 _1860_x;
    int64_t _1859_t8;
    int64_t _1859_t9;
    int64_t _1859_$retval;
    _1859_t2 = 25;
    _1859_t3 = 75;
    _1859_t1 = (struct struct0) {_1859_t2, _1859_t3};
    _1859_t5 = 5;
    _1859_t6 = 90;
    _1859_t4 = (struct struct0) {_1859_t5, _1859_t6};
    _1860_x = (struct struct1) {_1859_t1, _1859_t4};
    _1859_t8 = $add_int64_t(_1860_x._0._0, _1860_x._0._1, "tests/integration/tuples/named-field-2d.orng:10:12:\n    x.a.c + x.a.d + x.b.e + x.b.f\n          ^");
    _1859_t9 = $add_int64_t(_1859_t8, _1860_x._1._0, "tests/integration/tuples/named-field-2d.orng:10:20:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                  ^");
    _1859_$retval = $add_int64_t(_1859_t9, _1860_x._1._1, "tests/integration/tuples/named-field-2d.orng:10:28:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                          ^");
    return _1859_$retval;
}


int main(void) {
  printf("%ld",_1859_main());
  return 0;
}
