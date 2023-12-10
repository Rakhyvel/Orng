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
int64_t _966_main(void);
int64_t _968_first(struct1 _968_xs);

/* Function definitions */
int64_t _966_main(void) {
    function0 _966_t0;
    int64_t _966_t3;
    int64_t _966_t5;
    struct2 _966_t4;
    int64_t* _966_t6;
    int64_t _966_t7;
    struct1 _966_t2;
    int64_t _966_t1;
    int64_t _966_$retval;
    _966_t0 = _968_first;
    _966_t3 = 0;
    _966_t5 = 233;
    _966_t4 = (struct2) {_966_t5};
    _966_t6 = ((int64_t*)&_966_t4 + _966_t3);
    _966_t7 = 1;
    _966_t2 = (struct1) {_966_t6, _966_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _966_t1 = _966_t0(_966_t2);
    $line_idx--;
    _966_$retval = _966_t1;
    return _966_$retval;
}

int64_t _968_first(struct1 _968_xs) {
    int64_t _968_t0;
    int64_t _968_$retval;
    _968_t0 = 0;
    _968_$retval = *((int64_t*)_968_xs._0 + _968_t0);
    return _968_$retval;
}

int main(void) {
  printf("%ld",_966_main());
  return 0;
}
