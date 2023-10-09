/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t4;
    struct1 _2_x;
    int64_t _1_$retval;
    _1_t1 = (struct0) {25, 75};
    _1_t4 = (struct0) {5, 90};
    _2_x = (struct1) {_1_t1, _1_t4};
    _1_$retval = $add_int64_t($add_int64_t($add_int64_t(_2_x._0._0, _2_x._0._1, "tests/integration/tuples/named-field-2d.orng:10:12:\n    x.a.c + x.a.d + x.b.e + x.b.f\n          ^"), _2_x._1._0, "tests/integration/tuples/named-field-2d.orng:10:20:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                  ^"), _2_x._1._1, "tests/integration/tuples/named-field-2d.orng:10:28:\n    x.a.c + x.a.d + x.b.e + x.b.f\n                          ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
