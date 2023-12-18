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
int64_t _1153_main(void);
int64_t _1159_f(void);

/* Function definitions */
int64_t _1153_main(void){
    int64_t _1153_t1;
    int64_t _1153_t2;
    int64_t _1153_t3;
    int64_t _1153_t4;
    struct0 _1154_x;
    function1 _1153_t5;
    int64_t _1153_t6;
    int64_t _1153_t7;
    int64_t _1153_$retval;
    _1153_t1 = 0;
    _1153_t2 = 0;
    _1153_t3 = 0;
    _1153_t4 = 0;
    _1154_x = (struct0) {_1153_t1, _1153_t2, _1153_t3, _1153_t4};
    _1153_t5 = _1159_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1153_t6 = _1153_t5();
    $line_idx--;
    _1153_t7 = 4;
    $bounds_check(_1153_t6, _1153_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1153_$retval = *((int64_t*)&_1154_x + _1153_t6);
    return _1153_$retval;
}

int64_t _1159_f(void){
    int64_t _1159_$retval;
    _1159_$retval = 100;
    return _1159_$retval;
}

int main(void) {
  printf("%ld",_1153_main());
  return 0;
}
