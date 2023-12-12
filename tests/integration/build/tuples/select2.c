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
int64_t _1203_main(void);
int64_t _1205_f(struct1 _1205_a);

/* Function definitions */
int64_t _1203_main(void) {
    int64_t _1203_t2;
    int64_t _1203_t3;
    struct0 _1203_t1;
    int64_t _1203_t4;
    struct1 _1204_x;
    function2 _1203_t5;
    int64_t _1203_t6;
    int64_t _1203_$retval;
    _1203_t2 = 50;
    _1203_t3 = 150;
    _1203_t1 = (struct0) {_1203_t2, _1203_t3};
    _1203_t4 = 300;
    _1204_x = (struct1) {_1203_t1, _1203_t4};
    _1203_t5 = _1205_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1203_t6 = _1203_t5(_1204_x);
    $line_idx--;
    _1203_$retval = _1203_t6;
    return _1203_$retval;
}

int64_t _1205_f(struct1 _1205_a) {
    int64_t _1205_$retval;
    _1205_$retval = _1205_a._1;
    return _1205_$retval;
}

int main(void) {
  printf("%ld",_1203_main());
  return 0;
}
