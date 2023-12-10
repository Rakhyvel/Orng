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
int64_t _1176_main(void);
int64_t _1178_f(struct1 _1178_a);

/* Function definitions */
int64_t _1176_main(void) {
    int64_t _1176_t2;
    int64_t _1176_t3;
    struct0 _1176_t1;
    int64_t _1176_t4;
    struct1 _1177_x;
    function2 _1176_t5;
    int64_t _1176_t6;
    int64_t _1176_$retval;
    _1176_t2 = 50;
    _1176_t3 = 150;
    _1176_t1 = (struct0) {_1176_t2, _1176_t3};
    _1176_t4 = 300;
    _1177_x = (struct1) {_1176_t1, _1176_t4};
    _1176_t5 = _1178_f;
    $lines[$line_idx++] = "tests/integration/tuples/select2.orng:4:7:\n    f(x)\n     ^";
    _1176_t6 = _1176_t5(_1177_x);
    $line_idx--;
    _1176_$retval = _1176_t6;
    return _1176_$retval;
}

int64_t _1178_f(struct1 _1178_a) {
    int64_t _1178_$retval;
    _1178_$retval = _1178_a._1;
    return _1178_$retval;
}

int main(void) {
  printf("%ld",_1176_main());
  return 0;
}
