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
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _72_main(void);

/* Function definitions */
int64_t _72_main(void){
    int64_t _72_t2;
    int64_t _72_t3;
    struct0 _72_t1;
    int64_t _72_t5;
    int64_t _72_t6;
    struct0 _72_t4;
    int64_t _72_t8;
    int64_t _72_t9;
    struct0 _72_t7;
    struct1 _73_x;
    int64_t _72_t11;
    int64_t _72_t12;
    int64_t _72_t13;
    int64_t _72_t14;
    int64_t _72_$retval;
    _72_t2 = 1;
    _72_t3 = 2;
    _72_t1 = (struct0) {_72_t2, _72_t3};
    _72_t5 = 3;
    _72_t6 = 4;
    _72_t4 = (struct0) {_72_t5, _72_t6};
    _72_t8 = 5;
    _72_t9 = 6;
    _72_t7 = (struct0) {_72_t8, _72_t9};
    _73_x = (struct1) {_72_t1, _72_t4, _72_t7};
    _72_t11 = 1;
    _72_t12 = 3;
    $bounds_check(_72_t11, _72_t12, "tests/integration/arrays/array-select.orng:7:16:\n    x[1].a = 73\n              ^");
    (*((struct0*)&_73_x + _72_t11))._0 = 73;
    _72_t13 = 1;
    _72_t14 = 3;
    $bounds_check(_72_t13, _72_t14, "tests/integration/arrays/array-select.orng:2:3:\nfn main() -> Int {\n ^");
    _72_$retval = (*((struct0*)&_73_x + _72_t13))._0;
    return _72_$retval;
}

int main(void) {
  printf("%ld",_72_main());
  return 0;
}
