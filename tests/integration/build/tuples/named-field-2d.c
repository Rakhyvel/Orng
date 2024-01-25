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
int64_t _1624_main(void);


/* Function definitions */
int64_t _1624_main(void){
    int64_t _1624_t2;
    int64_t _1624_t3;
    struct struct0 _1624_t1;
    int64_t _1624_t5;
    int64_t _1624_t6;
    struct struct0 _1624_t4;
    struct struct1 _1625_x;
    int64_t _1624_t7;
    int64_t _1624_t8;
    int64_t _1624_$retval;
    _1624_t2 = 25;
    _1624_t3 = 75;
    _1624_t1 = (struct struct0) {_1624_t2, _1624_t3};
    _1624_t5 = 5;
    _1624_t6 = 90;
    _1624_t4 = (struct struct0) {_1624_t5, _1624_t6};
    _1625_x = (struct struct1) {_1624_t1, _1624_t4};
    _1624_t7 = $add_int64_t(_1625_x._0._0, _1625_x._0._1, "tests/integration/tuples/named-field-2d.orng:10:12:\n    x.a.c + x.a.d + x.b.e + x.b.f\n          ^");
    _1624_t8 = $add_int64_t(_1624_t7, _1625_x._1._0, "tests/integration/tuples/named-field-2d.orng:10:20:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                  ^");
    _1624_$retval = $add_int64_t(_1624_t8, _1625_x._1._1, "tests/integration/tuples/named-field-2d.orng:10:28:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                          ^");
    return _1624_$retval;
}


int main(void) {
  printf("%ld",_1624_main());
  return 0;
}
