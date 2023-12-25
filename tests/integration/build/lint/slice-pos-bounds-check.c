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

typedef struct {
        int64_t* _0;
        int64_t _1;
} struct1;

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1040_main(void);
int64_t _1042_f(void);

/* Function definitions */
int64_t _1040_main(void){
    int64_t _1040_t1;
    int64_t _1040_t2;
    int64_t _1040_t3;
    int64_t _1040_t4;
    struct0 _1041_x;
    int64_t _1040_t6;
    int64_t _1040_t7;
    int64_t* _1040_t8;
    int64_t _1040_t9;
    struct1 _1041_y;
    function2 _1040_t10;
    int64_t _1040_t11;
    int64_t _1040_$retval;
    _1040_t1 = 0;
    _1040_t2 = 0;
    _1040_t3 = 0;
    _1040_t4 = 0;
    _1041_x = (struct0) {_1040_t1, _1040_t2, _1040_t3, _1040_t4};
    _1040_t6 = 0;
    _1040_t7 = 4;
    $bounds_check(_1040_t6, _1040_t7, "tests/integration/lint/slice-pos-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1040_t8 = ((int64_t*)&_1041_x + _1040_t6);
    _1040_t9 = 4;
    _1041_y = (struct1) {_1040_t8, _1040_t9};
    _1040_t10 = _1042_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1040_t11 = _1040_t10();
    $line_idx--;
    $bounds_check(_1040_t11, _1041_y._1, "tests/integration/lint/slice-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1040_$retval = *((int64_t*)_1041_y._0 + _1040_t11);
    return _1040_$retval;
}

int64_t _1042_f(void){
    int64_t _1042_$retval;
    _1042_$retval = 100;
    return _1042_$retval;
}

int main(void) {
  printf("%ld",_1040_main());
  return 0;
}
