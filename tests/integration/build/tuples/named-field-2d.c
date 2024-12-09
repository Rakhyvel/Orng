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
int64_t _1894_main(void);


/* Function definitions */
int64_t _1894_main(void){
    int64_t _1894_t2;
    int64_t _1894_t3;
    struct struct0 _1894_t1;
    int64_t _1894_t5;
    int64_t _1894_t6;
    struct struct0 _1894_t4;
    struct struct1 _1895_x;
    int64_t _1894_t8;
    int64_t _1894_t9;
    int64_t _1894_$retval;
    _1894_t2 = 25;
    _1894_t3 = 75;
    _1894_t1 = (struct struct0) {_1894_t2, _1894_t3};
    _1894_t5 = 5;
    _1894_t6 = 90;
    _1894_t4 = (struct struct0) {_1894_t5, _1894_t6};
    _1895_x = (struct struct1) {_1894_t1, _1894_t4};
    _1894_t8 = $add_int64_t(_1895_x._0._0, _1895_x._0._1, "tests/integration/tuples/named-field-2d.orng:10:12:\n    x.a.c + x.a.d + x.b.e + x.b.f\n          ^");
    _1894_t9 = $add_int64_t(_1894_t8, _1895_x._1._0, "tests/integration/tuples/named-field-2d.orng:10:20:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                  ^");
    _1894_$retval = $add_int64_t(_1894_t9, _1895_x._1._1, "tests/integration/tuples/named-field-2d.orng:10:28:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                          ^");
    return _1894_$retval;
}


int main(void) {
  printf("%ld",_1894_main());
  return 0;
}
