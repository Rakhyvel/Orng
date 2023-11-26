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
int64_t _876_main(void);
int64_t _878_first(struct1 _878_xs);

/* Function definitions */
int64_t _876_main(void) {
    function0 _876_t0;
    int64_t _876_t3;
    int64_t _876_t5;
    struct2 _876_t4;
    int64_t* _876_t6;
    int64_t _876_t7;
    struct1 _876_t2;
    int64_t _876_t1;
    int64_t _876_$retval;
    _876_t0 = _878_first;
    _876_t3 = 0;
    _876_t5 = 233;
    _876_t4 = (struct2) {_876_t5};
    _876_t6 = ((int64_t*)&_876_t4 + _876_t3);
    _876_t7 = 1;
    _876_t2 = (struct1) {_876_t6, _876_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _876_t1 = _876_t0(_876_t2);
    $line_idx--;
    _876_$retval = _876_t1;
    return _876_$retval;
}

int64_t _878_first(struct1 _878_xs) {
    int64_t _878_t0;
    int64_t _878_$retval;
    _878_t0 = 0;
    _878_$retval = *((int64_t*)_878_xs._0 + _878_t0);
    return _878_$retval;
}

int main(void) {
  printf("%ld",_876_main());
  return 0;
}
