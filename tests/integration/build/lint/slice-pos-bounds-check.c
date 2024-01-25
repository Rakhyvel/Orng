/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1103_main(void);
int64_t _1105_f(void);


/* Function definitions */
int64_t _1103_main(void){
    int64_t _1103_t1;
    int64_t _1103_t2;
    int64_t _1103_t3;
    int64_t _1103_t4;
    struct struct0 _1104_x;
    int64_t _1103_t6;
    int64_t _1103_t7;
    int64_t* _1103_t8;
    int64_t _1103_t9;
    struct struct1 _1104_y;
    function2 _1103_t10;
    int64_t _1103_t11;
    int64_t _1103_$retval;
    _1103_t1 = 0;
    _1103_t2 = 0;
    _1103_t3 = 0;
    _1103_t4 = 0;
    _1104_x = (struct struct0) {_1103_t1, _1103_t2, _1103_t3, _1103_t4};
    _1103_t6 = 0;
    _1103_t7 = 4;
    $bounds_check(_1103_t6, _1103_t7, "tests/integration/lint/slice-pos-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1103_t8 = ((int64_t*)&_1104_x + _1103_t6);
    _1103_t9 = 4;
    _1104_y = (struct struct1) {_1103_t8, _1103_t9};
    _1103_t10 = _1105_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1103_t11 = _1103_t10();
    $line_idx--;
    $bounds_check(_1103_t11, _1104_y._1, "tests/integration/lint/slice-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1103_$retval = *((int64_t*)_1104_y._0 + _1103_t11);
    return _1103_$retval;
}

int64_t _1105_f(void){
    int64_t _1105_$retval;
    _1105_$retval = 100;
    return _1105_$retval;
}


int main(void) {
  printf("%ld",_1103_main());
  return 0;
}
