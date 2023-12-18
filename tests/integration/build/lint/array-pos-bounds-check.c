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
int64_t _1161_main(void);
int64_t _1167_f(void);

/* Function definitions */
int64_t _1161_main(void){
    int64_t _1161_t1;
    int64_t _1161_t2;
    int64_t _1161_t3;
    int64_t _1161_t4;
    struct0 _1162_x;
    function1 _1161_t5;
    int64_t _1161_t6;
    int64_t _1161_t7;
    int64_t _1161_$retval;
    _1161_t1 = 0;
    _1161_t2 = 0;
    _1161_t3 = 0;
    _1161_t4 = 0;
    _1162_x = (struct0) {_1161_t1, _1161_t2, _1161_t3, _1161_t4};
    _1161_t5 = _1167_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1161_t6 = _1161_t5();
    $line_idx--;
    _1161_t7 = 4;
    $bounds_check(_1161_t6, _1161_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1161_$retval = *((int64_t*)&_1162_x + _1161_t6);
    return _1161_$retval;
}

int64_t _1167_f(void){
    int64_t _1167_$retval;
    _1167_$retval = 100;
    return _1167_$retval;
}

int main(void) {
  printf("%ld",_1161_main());
  return 0;
}
