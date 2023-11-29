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
int64_t _999_main(void);
int64_t _1001_first(struct1 _1001_xs);

/* Function definitions */
int64_t _999_main(void) {
    function0 _999_t0;
    int64_t _999_t3;
    int64_t _999_t5;
    struct2 _999_t4;
    int64_t* _999_t6;
    int64_t _999_t7;
    struct1 _999_t2;
    int64_t _999_t1;
    int64_t _999_$retval;
    _999_t0 = _1001_first;
    _999_t3 = 0;
    _999_t5 = 233;
    _999_t4 = (struct2) {_999_t5};
    _999_t6 = ((int64_t*)&_999_t4 + _999_t3);
    _999_t7 = 1;
    _999_t2 = (struct1) {_999_t6, _999_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _999_t1 = _999_t0(_999_t2);
    $line_idx--;
    _999_$retval = _999_t1;
    return _999_$retval;
}

int64_t _1001_first(struct1 _1001_xs) {
    int64_t _1001_t0;
    int64_t _1001_$retval;
    _1001_t0 = 0;
    _1001_$retval = *((int64_t*)_1001_xs._0 + _1001_t0);
    return _1001_$retval;
}

int main(void) {
  printf("%ld",_999_main());
  return 0;
}
