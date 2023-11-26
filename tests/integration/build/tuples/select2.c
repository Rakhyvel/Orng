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
int64_t _1083_main(void);
int64_t _1085_f(struct1 _1085_a);

/* Function definitions */
int64_t _1083_main(void) {
    int64_t _1083_t2;
    int64_t _1083_t3;
    struct0 _1083_t1;
    int64_t _1083_t4;
    struct1 _1084_x;
    function2 _1083_t5;
    int64_t _1083_t6;
    int64_t _1083_$retval;
    _1083_t2 = 50;
    _1083_t3 = 150;
    _1083_t1 = (struct0) {_1083_t2, _1083_t3};
    _1083_t4 = 300;
    _1084_x = (struct1) {_1083_t1, _1083_t4};
    _1083_t5 = _1085_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1083_t6 = _1083_t5(_1084_x);
    $line_idx--;
    _1083_$retval = _1083_t6;
    return _1083_$retval;
}

int64_t _1085_f(struct1 _1085_a) {
    int64_t _1085_$retval;
    _1085_$retval = _1085_a._1;
    return _1085_$retval;
}

int main(void) {
  printf("%ld",_1083_main());
  return 0;
}
