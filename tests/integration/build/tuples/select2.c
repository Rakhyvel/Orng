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
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1588_main(void);
int64_t _1590_f(struct1 _1590_a);

/* Function definitions */
int64_t _1588_main(void) {
    int64_t _1588_t2;
    int64_t _1588_t3;
    struct0 _1588_t1;
    int64_t _1588_t4;
    struct1 _1589_x;
    function2 _1588_t5;
    int64_t _1588_t6;
    int64_t _1588_$retval;
    _1588_t2 = 50;
    _1588_t3 = 150;
    _1588_t1 = (struct0) {_1588_t2, _1588_t3};
    _1588_t4 = 300;
    _1589_x = (struct1) {_1588_t1, _1588_t4};
    _1588_t5 = _1590_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1588_t6 = _1588_t5(_1589_x);
    $line_idx--;
    _1588_$retval = _1588_t6;
    return _1588_$retval;
}

int64_t _1590_f(struct1 _1590_a) {
    int64_t _1590_$retval;
    _1590_$retval = _1590_a._1;
    return _1590_$retval;
}

int main(void) {
  printf("%ld",_1588_main());
  return 0;
}
