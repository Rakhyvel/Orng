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
int64_t _48_main(void);
int64_t _50_f(struct1 _50_a);

/* Function definitions */
int64_t _48_main(void) {
    int64_t _48_t2;
    int64_t _48_t3;
    struct0 _48_t1;
    int64_t _48_t4;
    struct1 _49_x;
    function2 _48_t5;
    int64_t _48_t6;
    int64_t _48_$retval;
    _48_t2 = 50;
    _48_t3 = 150;
    _48_t1 = (struct0) {_48_t2, _48_t3};
    _48_t4 = 300;
    _49_x = (struct1) {_48_t1, _48_t4};
    _48_t5 = _50_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _48_t6 = _48_t5(_49_x);
    $line_idx--;
    _48_$retval = _48_t6;
    return _48_$retval;
}

int64_t _50_f(struct1 _50_a) {
    int64_t _50_$retval;
    _50_$retval = _50_a._1;
    return _50_$retval;
}

int main(void) {
  printf("%ld",_48_main());
  return 0;
}
