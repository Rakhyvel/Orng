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
int64_t _51_main(void);
int64_t _53_f(struct1 _53_a);

/* Function definitions */
int64_t _51_main(void) {
    int64_t _51_t2;
    int64_t _51_t3;
    struct0 _51_t1;
    int64_t _51_t4;
    struct1 _52_x;
    function2 _51_t5;
    int64_t _51_t6;
    int64_t _51_$retval;
    _51_t2 = 50;
    _51_t3 = 150;
    _51_t1 = (struct0) {_51_t2, _51_t3};
    _51_t4 = 300;
    _52_x = (struct1) {_51_t1, _51_t4};
    _51_t5 = _53_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _51_t6 = _51_t5(_52_x);
    $line_idx--;
    _51_$retval = _51_t6;
    return _51_$retval;
}

int64_t _53_f(struct1 _53_a) {
    int64_t _53_$retval;
    _53_$retval = _53_a._1;
    return _53_$retval;
}

int main(void) {
  printf("%ld",_51_main());
  return 0;
}
