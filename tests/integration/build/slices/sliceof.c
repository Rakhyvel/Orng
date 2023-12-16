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
    int64_t _2;
    int64_t _3;
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1376_main(void);

/* Function definitions */
int64_t _1376_main(void){
    int64_t _1376_t1;
    int64_t _1376_t2;
    int64_t _1376_t3;
    int64_t _1376_t4;
    int64_t _1376_t5;
    struct0 _1377_x;
    int64_t _1376_t7;
    int64_t* _1376_t8;
    int64_t _1376_t9;
    struct1 _1377_y;
    int64_t _1376_t10;
    int64_t _1376_t11;
    int64_t _1376_$retval;
    _1376_t1 = 1;
    _1376_t2 = 2;
    _1376_t3 = 3;
    _1376_t4 = 4;
    _1376_t5 = 5;
    _1377_x = (struct0) {_1376_t1, _1376_t2, _1376_t3, _1376_t4, _1376_t5};
    _1376_t7 = 0;
    _1376_t8 = ((int64_t*)&_1377_x + _1376_t7);
    _1376_t9 = 5;
    _1377_y = (struct1) {_1376_t8, _1376_t9};
    _1376_t10 = 2;
    _1376_t11 = 77;
    _1376_$retval = $add_int64_t(*((int64_t*)_1377_y._0 + _1376_t10), _1376_t11, "tests/integration/slices/sliceof.orng:5:11:\n    y[2] + 77\n         ^");
    return _1376_$retval;
}

int main(void) {
  printf("%ld",_1376_main());
  return 0;
}
