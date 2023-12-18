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
    int64_t _2;
    int64_t _3;
} struct0;

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _1126_main(void);
int64_t _1132_f(void);

/* Function definitions */
int64_t _1126_main(void){
    int64_t _1126_t1;
    int64_t _1126_t2;
    int64_t _1126_t3;
    int64_t _1126_t4;
    struct0 _1127_x;
    function1 _1126_t6;
    int64_t _1126_t7;
    int64_t _1126_t8;
    int64_t _1126_$retval;
    _1126_t1 = 0;
    _1126_t2 = 0;
    _1126_t3 = 0;
    _1126_t4 = 0;
    _1127_x = (struct0) {_1126_t1, _1126_t2, _1126_t3, _1126_t4};
    _1126_t6 = _1132_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-neg-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1126_t7 = _1126_t6();
    $line_idx--;
    _1126_t8 = 4;
    $bounds_check(_1126_t7, _1126_t8, "tests/integration/lint/array-copy-neg-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1127_x + _1126_t7) = 0;
    _1126_$retval = 0;
    return _1126_$retval;
}

int64_t _1132_f(void){
    int64_t _1132_$retval;
    _1132_$retval = -100;
    return _1132_$retval;
}

int main(void) {
  printf("%ld",_1126_main());
  return 0;
}
