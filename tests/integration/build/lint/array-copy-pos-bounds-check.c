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
int64_t _1143_main(void);
int64_t _1149_f(void);

/* Function definitions */
int64_t _1143_main(void){
    int64_t _1143_t1;
    int64_t _1143_t2;
    int64_t _1143_t3;
    int64_t _1143_t4;
    struct0 _1144_x;
    function1 _1143_t6;
    int64_t _1143_t7;
    int64_t _1143_t8;
    int64_t _1143_$retval;
    _1143_t1 = 0;
    _1143_t2 = 0;
    _1143_t3 = 0;
    _1143_t4 = 0;
    _1144_x = (struct0) {_1143_t1, _1143_t2, _1143_t3, _1143_t4};
    _1143_t6 = _1149_f;
    $lines[$line_idx++] = "tests/integration/lint/array-copy-pos-bounds-check.orng:4:9:\n    x[f()] = 0\n       ^";
    _1143_t7 = _1143_t6();
    $line_idx--;
    _1143_t8 = 4;
    $bounds_check(_1143_t7, _1143_t8, "tests/integration/lint/array-copy-pos-bounds-check.orng:4:15:\n    x[f()] = 0\n             ^");
    *((int64_t*)&_1144_x + _1143_t7) = 0;
    _1143_$retval = 0;
    return _1143_$retval;
}

int64_t _1149_f(void){
    int64_t _1149_$retval;
    _1149_$retval = 100;
    return _1149_$retval;
}

int main(void) {
  printf("%ld",_1143_main());
  return 0;
}
