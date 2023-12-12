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
int64_t _1184_main(void);
int64_t _1186_f(struct1 _1186_a);

/* Function definitions */
int64_t _1184_main(void) {
    int64_t _1184_t2;
    int64_t _1184_t3;
    struct0 _1184_t1;
    int64_t _1184_t4;
    struct1 _1185_x;
    function2 _1184_t5;
    int64_t _1184_t6;
    int64_t _1184_$retval;
    _1184_t2 = 50;
    _1184_t3 = 150;
    _1184_t1 = (struct0) {_1184_t2, _1184_t3};
    _1184_t4 = 300;
    _1185_x = (struct1) {_1184_t1, _1184_t4};
    _1184_t5 = _1186_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1184_t6 = _1184_t5(_1185_x);
    $line_idx--;
    _1184_$retval = _1184_t6;
    return _1184_$retval;
}

int64_t _1186_f(struct1 _1186_a) {
    int64_t _1186_$retval;
    _1186_$retval = _1186_a._1;
    return _1186_$retval;
}

int main(void) {
  printf("%ld",_1184_main());
  return 0;
}
