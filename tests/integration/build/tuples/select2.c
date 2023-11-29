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
int64_t _1235_main(void);
int64_t _1237_f(struct1 _1237_a);

/* Function definitions */
int64_t _1235_main(void) {
    int64_t _1235_t2;
    int64_t _1235_t3;
    struct0 _1235_t1;
    int64_t _1235_t4;
    struct1 _1236_x;
    function2 _1235_t5;
    int64_t _1235_t6;
    int64_t _1235_$retval;
    _1235_t2 = 50;
    _1235_t3 = 150;
    _1235_t1 = (struct0) {_1235_t2, _1235_t3};
    _1235_t4 = 300;
    _1236_x = (struct1) {_1235_t1, _1235_t4};
    _1235_t5 = _1237_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1235_t6 = _1235_t5(_1236_x);
    $line_idx--;
    _1235_$retval = _1235_t6;
    return _1235_$retval;
}

int64_t _1237_f(struct1 _1237_a) {
    int64_t _1237_$retval;
    _1237_$retval = _1237_a._1;
    return _1237_$retval;
}

int main(void) {
  printf("%ld",_1235_main());
  return 0;
}
