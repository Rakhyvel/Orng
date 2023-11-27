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
int64_t _1114_main(void);
int64_t _1116_f(struct1 _1116_a);

/* Function definitions */
int64_t _1114_main(void) {
    int64_t _1114_t2;
    int64_t _1114_t3;
    struct0 _1114_t1;
    int64_t _1114_t4;
    struct1 _1115_x;
    function2 _1114_t5;
    int64_t _1114_t6;
    int64_t _1114_$retval;
    _1114_t2 = 50;
    _1114_t3 = 150;
    _1114_t1 = (struct0) {_1114_t2, _1114_t3};
    _1114_t4 = 300;
    _1115_x = (struct1) {_1114_t1, _1114_t4};
    _1114_t5 = _1116_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1114_t6 = _1114_t5(_1115_x);
    $line_idx--;
    _1114_$retval = _1114_t6;
    return _1114_$retval;
}

int64_t _1116_f(struct1 _1116_a) {
    int64_t _1116_$retval;
    _1116_$retval = _1116_a._1;
    return _1116_$retval;
}

int main(void) {
  printf("%ld",_1114_main());
  return 0;
}
