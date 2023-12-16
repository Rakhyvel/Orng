/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
} struct2;

/* Function forward definitions */
int64_t _1223_main(void);
int64_t _1225_first(struct1 _1225_xs);

/* Function definitions */
int64_t _1223_main(void) {
    function0 _1223_t0;
    int64_t _1223_t3;
    int64_t _1223_t5;
    struct2 _1223_t4;
    int64_t* _1223_t6;
    int64_t _1223_t7;
    struct1 _1223_t2;
    int64_t _1223_t1;
    int64_t _1223_$retval;
    _1223_t0 = _1225_first;
    _1223_t3 = 0;
    _1223_t5 = 233;
    _1223_t4 = (struct2) {_1223_t5};
    _1223_t6 = ((int64_t*)&_1223_t4 + _1223_t3);
    _1223_t7 = 1;
    _1223_t2 = (struct1) {_1223_t6, _1223_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1223_t1 = _1223_t0(_1223_t2);
    $line_idx--;
    _1223_$retval = _1223_t1;
    return _1223_$retval;
}

int64_t _1225_first(struct1 _1225_xs) {
    int64_t _1225_t0;
    int64_t _1225_$retval;
    _1225_t0 = 0;
    _1225_$retval = *((int64_t*)_1225_xs._0 + _1225_t0);
    return _1225_$retval;
}

int main(void) {
  printf("%ld",_1223_main());
  return 0;
}
