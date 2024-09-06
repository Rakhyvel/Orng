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
int64_t _1814_main(void);


/* Function definitions */
int64_t _1814_main(void){
    int64_t _1814_t2;
    int64_t _1814_t3;
    struct struct0 _1814_t1;
    int64_t _1814_t5;
    int64_t _1814_t6;
    struct struct0 _1814_t4;
    struct struct1 _1815_x;
    int64_t _1814_t8;
    int64_t _1814_t9;
    int64_t _1814_$retval;
    _1814_t2 = 25;
    _1814_t3 = 75;
    _1814_t1 = (struct struct0) {_1814_t2, _1814_t3};
    _1814_t5 = 5;
    _1814_t6 = 90;
    _1814_t4 = (struct struct0) {_1814_t5, _1814_t6};
    _1815_x = (struct struct1) {_1814_t1, _1814_t4};
    _1814_t8 = $add_int64_t(_1815_x._0._0, _1815_x._0._1, "tests/integration/tuples/named-field-2d.orng:10:12:\n    x.a.c + x.a.d + x.b.e + x.b.f\n          ^");
    _1814_t9 = $add_int64_t(_1814_t8, _1815_x._1._0, "tests/integration/tuples/named-field-2d.orng:10:20:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                  ^");
    _1814_$retval = $add_int64_t(_1814_t9, _1815_x._1._1, "tests/integration/tuples/named-field-2d.orng:10:28:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                          ^");
    return _1814_$retval;
}


int main(void) {
  printf("%ld",_1814_main());
  return 0;
}
