/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    function0 _0;
    int64_t _1;
};

typedef int64_t(*function1)(function0, int64_t);

/* Function forward definitions */
int64_t _929_main(void);
int64_t _931_$anon93(int64_t _931_x);
int64_t _933_apply(function0 _933_f, int64_t _933_x);


/* Function definitions */
int64_t _929_main(void){
    function0 _930_id;
    function1 _929_t2;
    int64_t _929_t4;
    int64_t _929_t3;
    int64_t _929_$retval;
    _930_id = (function0) _931_$anon93;
    _929_t2 = (function1) _933_apply;
    _929_t4 = 43;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:4:11:\n    apply(id, 43)\n         ^";
    _929_t3 = _929_t2(_930_id, _929_t4);
    $line_idx--;
    _929_$retval = _929_t3;
    return _929_$retval;
}

int64_t _931_$anon93(int64_t _931_x){
    int64_t _931_$retval;
    goto BB1110;
BB1110:
    _931_$retval = _931_x;
    return _931_$retval;
}

int64_t _933_apply(function0 _933_f, int64_t _933_x){
    int64_t _933_t0;
    int64_t _933_$retval;
    $lines[$line_idx++] = "tests/integration/functions/anon.orng:7:39:\nfn apply(f: Int->Int, x: Int)->Int {f(x)}\n                                     ^";
    _933_t0 = _933_f(_933_x);
    $line_idx--;
    _933_$retval = _933_t0;
    return _933_$retval;
}


int main(void) {
  printf("%ld",_929_main());
  return 0;
}
