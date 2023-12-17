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
int64_t _73_main(void);
int64_t _79_f(void);

/* Function definitions */
int64_t _73_main(void){
    int64_t _73_t1;
    int64_t _73_t2;
    int64_t _73_t3;
    int64_t _73_t4;
    struct0 _74_x;
    int64_t _73_t6;
    int64_t _73_t7;
    int64_t* _73_t8;
    int64_t _73_t9;
    struct1 _74_y;
    function2 _73_t10;
    int64_t _73_t11;
    int64_t _73_$retval;
    _73_t1 = 0;
    _73_t2 = 0;
    _73_t3 = 0;
    _73_t4 = 0;
    _74_x = (struct0) {_73_t1, _73_t2, _73_t3, _73_t4};
    _73_t6 = 0;
    _73_t7 = 4;
    $bounds_check(_73_t6, _73_t7, "tests/integration/lint/slice-pos-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _73_t8 = ((int64_t*)&_74_x + _73_t6);
    _73_t9 = 4;
    _74_y = (struct1) {_73_t8, _73_t9};
    _73_t10 = _79_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _73_t11 = _73_t10();
    $line_idx--;
    $bounds_check(_73_t11, _74_y._1, "tests/integration/lint/slice-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _73_$retval = *((int64_t*)_74_y._0 + _73_t11);
    return _73_$retval;
}

int64_t _79_f(void){
    int64_t _79_$retval;
    _79_$retval = 100;
    return _79_$retval;
}

int main(void) {
  printf("%ld",_73_main());
  return 0;
}
